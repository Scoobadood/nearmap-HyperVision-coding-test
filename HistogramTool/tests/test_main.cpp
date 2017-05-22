#include <QTest>

#include "test_histogram.h"
#include "test_histogram_tool.h"

int main( int argc, char * argv[] ) {
    TestHistogram       t1;
    TestHistogramTool   t2;

    QTest::qExec( &t1 );
    QTest::qExec(&t2 );

    return 0;
}
