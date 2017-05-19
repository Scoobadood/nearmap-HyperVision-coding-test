#include "histogram_tool.h"

#include <thread>

/*
 * Given an array of pointers to histogram buckets, sum the results into
 * the built in buckets
 */
void HistogramTool::mergeBuckets( std::vector<std::shared_ptr<Histogram>>& redBuckets,
                                  std::vector<std::shared_ptr<Histogram>>& greenBuckets,
                                  std::vector<std::shared_ptr<Histogram>>& blueBuckets ) {
    // Clear before we start
    mRedCount.reset( );
    for( auto h : redBuckets ) {
        mRedCount += *h;
    }

    mGreenCount.reset( );
    for( auto h : greenBuckets ) {
        mGreenCount += *h;
    }

    mBlueCount.reset( );
    for( auto h : blueBuckets ) {
        mBlueCount += *h;
    }
}

/*
 * Construct one
 * @param threadsToUse the number of threads to use to compute the
 * histogram. Each thread handles a block of input pixels. So long as there
 * are multiple cores, each thread will run on its own core.
 */
HistogramTool::HistogramTool( uint32_t threadsToUse ) {
    mThreadsToUse = threadsToUse;
}


/*
 * Reset the histogram buckets
 */
void HistogramTool::reset( ) {
    mRedCount.reset();
    mGreenCount.reset();
    mBlueCount.reset();
}

/*
 * Compute the histogram for a given pixel block
 */
void HistogramTool::computeHistogram( const QRgb * const imageData, uint32_t firstPixel, uint32_t lastPixel,
                                      std::shared_ptr<Histogram> red,
                                      std::shared_ptr<Histogram> green,
                                      std::shared_ptr<Histogram> blue ) {
    for( uint32_t i=firstPixel; i<=lastPixel; i++ ) {
        QRgb rgb = imageData[i];

        red->increment(   static_cast<size_t>( qRed(rgb) ) );
        green->increment( static_cast<size_t>( qGreen(rgb) ) );
        blue->increment(  static_cast<size_t>( qBlue(rgb) ) );
    }
}

/*
 * Compute the histogram for the given image and store outputs in the given red, green and blue buckets
 */
void HistogramTool::computeHistogram( const QImage& image ) {

    const QRgb* imageData = reinterpret_cast<const QRgb*> ( image.constBits() );

    // Naive, single threaded code
    uint32_t num_pixels = static_cast<uint32_t>( image.width() * image.height() );

    reset();

    uint32_t pixel_block_size = num_pixels / mThreadsToUse;


    std::vector<std::shared_ptr<Histogram>> redBuckets, greenBuckets, blueBuckets;


    for( uint32_t tIndex=0; tIndex<mThreadsToUse; ++tIndex ) {
        auto red = std::make_shared<Histogram>();
        auto green= std::make_shared<Histogram>();
        auto blue= std::make_shared<Histogram>();

        uint32_t firstPixel = tIndex * pixel_block_size;
        uint32_t lastPixel = firstPixel + pixel_block_size - 1;

        std::thread t{ [&]{ this->computeHistogram( imageData, firstPixel, lastPixel, red, green, blue); } };

        redBuckets.push_back( red );
        greenBuckets.push_back( green );
        blueBuckets.push_back( blue );

        t.join();
    }

    // Done
    mergeBuckets( redBuckets, greenBuckets, blueBuckets);
}
