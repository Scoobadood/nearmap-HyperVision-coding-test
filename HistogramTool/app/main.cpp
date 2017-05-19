#include <QCoreApplication>
#include <QTime>
#include <QImage>
#include <QStringList>
#include <iostream>

#include "histogram.h"
#include "histogram_tool.h"

int main(int argc, char *argv[])
{

    // load an image
    QImage img;
    if( img.load("/Users/Dave/Software_Development/nearmap-HyperVision-coding-test/data/DSC_0278.JPG") ) {

        HistogramTool h{};

        // Start timer
        QTime time;
        time.start();

        h.computeHistogram( img );

        // Compute elapsed time
        int time_taken = time.elapsed();
        std::cout << " Time Taken : " << time_taken << "ms" << std::endl;
    }

    // Else badness
    else {}

    return 0;
}
