#ifndef HISTOGRAM_TOOL_H
#define HISTOGRAM_TOOL_H

#include <vector>
#include <thread>
#include "histogram.h"

/**
 * HistogramTool.
 *
 * Process an image and extract the RGB histograms from it.
 * On construction, specify the number of threads to use to process images. The image data is
 * divided into blocks and partial histograms computed for each part on separate threads.
 *
 * The resulting histograms are merged together once all threads have exited.
 */

class HistogramTool {
private:
    // Number of threads to use
    uint32_t        mNumThreads;

    /**
     * Compute the histogram for a given block of pixels within the image.
     * @param imageData The entire image data.
     * @param firstPixel The offset of the first pixel in the block to consider.
     * @param lastPixel The offset of the last pixel in the block to consider.
     * @param red Histogram into which red values will be stored.
     * @param green Histogram into whihc green values will be stored.
     * @param blue Histogram into whihc blue values will be stored.
     */
    void computePartialHistogram( const QRgb * const imageData, uint32_t firstPixel, uint32_t lastPixel, Histogram& red, Histogram& green, Histogram& blue );

public:
    /**
     * Build a HistogramTool configured to use the given number of threads.
     * @param numThreads The number of threads to use to compute the histogram.
     * The input image data is divided into blocks and each thread handles a block
     * So long as there are multiple cores, each thread will run on its own core. Defaults to 1 thread.
     */
    HistogramTool( uint32_t threadsToUse = 1 );


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
    void computeHistogram(const QImage& image, Histogram& red, Histogram& green, Histogram& blue );
};
#endif // HISTOGRAM_TOOL_H
