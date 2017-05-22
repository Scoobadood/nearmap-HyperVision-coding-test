#ifndef TEST_HISTOGRAMMER_H
#define TEST_HISTOGRAMMER_H

#include <QtTest>
#include "../src/histogram_tool.h"

class TestHistogramTool : public QObject {
        Q_OBJECT

private:
    QImage *makeImage( QColor fillColour ) const;

private slots:
    // When image is 256x256 and red, red[255] should be 65536
    void red256x256( );

    // When image is 256x256 and green, green[255] should be 65536
    void green256x256( );

    // When image is 256x256 and blue, blue[255] should be 65536
    void blue256x256( );

    // When image is 256x256 and white, all buckets [255] should be 65536
    void white256x256( );

    // When we use two threads, this should still work
    void white256x256_2_threads( );

    // When we use two hundred threads, this should still work
    void white256x256_200_threads( );

    // When we use grey scales, counts of red, green and blue values should all be 256
    void grey256x256( );
};

#endif // TEST_HISTOGRAMMER_H
