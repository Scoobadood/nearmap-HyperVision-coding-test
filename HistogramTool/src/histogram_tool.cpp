#include "histogram_tool.h"

#include <thread>
#include <sstream>

/**
 * Build a HistogramTool configured to use the given number of threads.
 * @param numThreads The number of threads to use to compute the histogram.
 * The input image data is divided into blocks and each thread handles a block
 * So long as there are multiple cores, each thread will run on its own core.
 */
HistogramTool::HistogramTool( uint32_t numThreads) {
    mNumThreads = numThreads;
}


/**
 * Compute the histogram for a given block of pixels within the image.
 * @param imageData The entire image data.
 * @param firstPixel The offset of the first pixel in the block to consider.
 * @param lastPixel The offset of the last pixel in the block to consider.
 * @param red Histogram into which red values will be stored.
 * @param green Histogram into whihc green values will be stored.
 * @param blue Histogram into whihc blue values will be stored.
 */
void HistogramTool::computePartialHistogram( const QRgb * const imageData, uint32_t firstPixel, uint32_t lastPixel, Histogram& red, Histogram& green, Histogram& blue ) {

    for( uint32_t i=firstPixel; i<=lastPixel; i++ ) {
        QRgb rgb = imageData[i];

        red.increment(   static_cast<size_t>( qRed(rgb) ) );
        green.increment( static_cast<size_t>( qGreen(rgb) ) );
        blue.increment(  static_cast<size_t>( qBlue(rgb) ) );
    }
}


/**
 * Compute the histogram for the given image.
 * The image is split into multiple blocks and each block is processed by a different thread.
 * Each thread uses its own Histogram and all Histograms are then merged into a single
 * Histogram once all threads have finished executing.
 * @param image The image. Expected to be RGB data.
 * @param red The overall Histogram of red values in the image.
 * @param green The overall Histogram of green values in the image.
 * @param blue The overall Histogram of blue values in the image.
 */
void HistogramTool::computeHistogram( const QImage& image, Histogram& red, Histogram& green, Histogram& blue) {

    // Work out how many blocks to carve this into
    uint32_t numPixels = static_cast<uint32_t>( image.width() * image.height() );
    uint32_t blockSize = numPixels / mNumThreads;

    // Get reference to data
    const QRgb* const imageData = reinterpret_cast<const QRgb * const> ( image.constBits() );

    // Allocate Histogram storage per thread
    Histogram *redHistograms = new Histogram[ mNumThreads];
    Histogram *greenHistograms = new Histogram[ mNumThreads];
    Histogram *blueHistograms = new Histogram[ mNumThreads];

    // Launch a thread per block
    std::thread*  threads = new std::thread[ mNumThreads ];

    uint32_t firstPixel = 0;

    for( uint32_t tIndex=0; tIndex<mNumThreads; tIndex++ ) {
        uint32_t lastPixel = firstPixel + blockSize - 1;

        // Fix for final block in case image cannot be neatly divided into equal blocks
        if( tIndex == mNumThreads - 1 ) {
            lastPixel = numPixels - 1;
        }

        Histogram& r = redHistograms[tIndex];
        Histogram& g = greenHistograms[tIndex];
        Histogram& b = blueHistograms[tIndex];

        // Kick off a new thread. Capture pixel indices and 'this' by copying, r, g and b by reference
        threads[tIndex] = std::thread{ [firstPixel, lastPixel, this, &imageData, &r, &g, &b]{ computePartialHistogram(imageData, firstPixel, lastPixel, r, g, b); } };

        // Next block
        firstPixel += blockSize;
    }

    // Wait for all threads to finish execution
    for( uint32_t tIndex=0; tIndex<mNumThreads; ++tIndex ) {
        threads[tIndex].join();
    }

    // Merge all outputs into provided Histograms
    for( uint32_t tIndex = 0; tIndex< mNumThreads; tIndex++ ) {

        red += redHistograms[tIndex];
        green += greenHistograms[tIndex];
        blue += blueHistograms[tIndex];
    }


    // And free memory
    delete[] redHistograms;
    delete[] greenHistograms;
    delete[] blueHistograms;
    delete[] threads;
}
