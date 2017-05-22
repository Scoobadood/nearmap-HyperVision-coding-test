#include <QtTest>

#include "test_histogram_tool.h"

QImage *TestHistogramTool::makeImage( QColor fillColour ) const {
    QImage *img = new QImage{ 256, 256, QImage::Format_ARGB32};
    if( img ) {
        img->fill( fillColour );
    }
    return img;
}


// When image is 256x256 and red, red[255] should be 65536
void TestHistogramTool::red256x256( ) {
    QImage *image = makeImage( QColor( 255, 0, 0 ) );
    HistogramTool tool{1};
    Histogram red, green, blue;
    tool.computeHistogram(*image, red, green, blue);

    uint32_t expected = 256 * 256;

    // Right number of pixels seen?
    QCOMPARE( red.total(), expected );
    QCOMPARE( green.total(), expected );
    QCOMPARE( blue.total(), expected );

    // Values in right buckets ?
    QCOMPARE( red[255], expected );
    QCOMPARE( green[0],  expected);
    QCOMPARE( blue[0], expected);
}

// When image is 256x256 and green, green[255] should be 65536
void TestHistogramTool::green256x256(  ) {
    QImage *image = makeImage( QColor( 0, 255, 0 ) );
    HistogramTool tool{1};
    Histogram red, green, blue;
    tool.computeHistogram(*image, red, green, blue);

    uint32_t expected = 256 * 256;

    // Right number of pixels seen?
    QCOMPARE( red.total(), expected );
    QCOMPARE( green.total(), expected );
    QCOMPARE( blue.total(), expected );

    // Values in right buckets ?
    QCOMPARE( red[0], expected );
    QCOMPARE( green[255],  expected);
    QCOMPARE( blue[0], expected);
}

// When image is 256x256 and blue, blue[255] should be 65536
void TestHistogramTool::blue256x256( ) {
    QImage *image = makeImage( QColor( 0, 0, 255 ) );
    HistogramTool tool{1};
    Histogram red, green, blue;
    tool.computeHistogram(*image, red, green, blue);

    uint32_t expected = 256 * 256;

    // Right number of pixels seen?
    QCOMPARE( red.total(), expected );
    QCOMPARE( green.total(), expected );
    QCOMPARE( blue.total(), expected );

    // Values in right buckets ?
    QCOMPARE( red[0], expected );
    QCOMPARE( green[0],  expected);
    QCOMPARE( blue[255], expected);
}

// When image is 256x256 and white, all buckets [255] should be 65536
void TestHistogramTool::white256x256( ) {
    QImage *image = makeImage( QColor( 255, 255, 255 ) );
    HistogramTool tool{1};
    Histogram red, green, blue;
    tool.computeHistogram(*image, red, green, blue);

    uint32_t expected = 256 * 256;

    // Right number of pixels seen?
    QCOMPARE( red.total(), expected );
    QCOMPARE( green.total(), expected );
    QCOMPARE( blue.total(), expected );

    // Values in right buckets ?
    QCOMPARE( red[255], expected );
    QCOMPARE( green[255],  expected);
    QCOMPARE( blue[255], expected);
}

// When we use two threads, this should still work
void TestHistogramTool::white256x256_2_threads( ) {
    QImage *image = makeImage( QColor( 255, 255, 255 ) );
    HistogramTool tool{2};
    Histogram red, green, blue;
    tool.computeHistogram(*image, red, green, blue);

    uint32_t expected = 256 * 256;

    // Right number of pixels seen?
    QCOMPARE( red.total(), expected );
    QCOMPARE( green.total(), expected );
    QCOMPARE( blue.total(), expected );

    // Values in right buckets ?
    QCOMPARE( red[255], expected );
    QCOMPARE( green[255],  expected);
    QCOMPARE( blue[255], expected);
}


// When we use two hundred threads, this should still work
void TestHistogramTool::white256x256_200_threads( ) {
    QImage *image = makeImage( QColor( 255, 255, 255 ) );
    HistogramTool tool{200};
    Histogram red, green, blue;
    tool.computeHistogram(*image, red, green, blue);

    uint32_t expected = 256 * 256;

    // Right number of pixels seen?
    QCOMPARE( red.total(), expected );
    QCOMPARE( green.total(), expected );
    QCOMPARE( blue.total(), expected );

    // Values in right buckets ?
    QCOMPARE( red[255], expected );
    QCOMPARE( green[255],  expected);
    QCOMPARE( blue[255], expected);
}

// When we use grey scales, counts of red, green and blue values should all be 256
void TestHistogramTool::grey256x256( ) {
    QImage image( 256, 256, QImage::Format_ARGB32);
    for( int y=0; y<256; y++ ) {
        for( int x=0; x<256; x++ ) {
            image.setPixelColor(x, y, QColor( x, x, x));
        }
    }
    HistogramTool tool{1};
    Histogram red, green, blue;
    tool.computeHistogram(image, red, green, blue);

    uint32_t expected = 256 * 256;

    // Right number of pixels seen?
    QCOMPARE( red.total(), expected );
    QCOMPARE( green.total(), expected );
    QCOMPARE( blue.total(), expected );

    // Values in right buckets ?
    expected = 256;
    for( size_t i=0; i<256; i++ ) {
        QCOMPARE( red[i], expected);
        QCOMPARE( green[i],  expected);
        QCOMPARE( blue[i],  expected);
    }
}
