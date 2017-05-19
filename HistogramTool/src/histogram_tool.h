#ifndef HISTOGRAMMER_H
#define HISTOGRAMMER_H

#include <vector>
#include "histogram.h"

class HistogramTool {
private:
    // Number of threads to use
    uint32_t        mThreadsToUse;

    // Histogram buckets
    Histogram        mRedCount;
    Histogram        mGreenCount;
    Histogram        mBlueCount;

    /*
     * Given an array of pointers to histogram buckets, sum the results into
     * the built in buckets
     */
    void mergeBuckets( std::vector<std::shared_ptr<Histogram>>& redBuckets,
                       std::vector<std::shared_ptr<Histogram>>& greenBuckets,
                       std::vector<std::shared_ptr<Histogram>>& blueBuckets );


    /*
     * Compute the histogram for a given pixel block
     */
    void computeHistogram( const QRgb * const imageData, uint32_t firstPixel, uint32_t lastPixel, std::shared_ptr<Histogram> red, std::shared_ptr<Histogram> green, std::shared_ptr<Histogram> blue );

public:
    /*
     * Construct one
     * @param threadsToUse the number of threads to use to compute the
     * histogram. Each thread handles a block of input pixels. So long as there
     * are multiple cores, each thread will run on its own core.
     */
    HistogramTool( uint32_t threadsToUse = 1 );


    /*
     * Reset the histogram buckets
     */
    void reset( );

    /*
     * Compute the histogram for the given image and store outputs in the given red, green and blue buckets
     */
    void computeHistogram( const QImage& image );
};
#endif // HISTOGRAMMER_H
