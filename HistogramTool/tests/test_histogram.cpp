#include <QtTest/QtTest>

#include "test_histogram.h"

// When incrementing a bucket, it changes value
void TestHistogram::incrementBuckets( Histogram& h ) {
    // Increment all buckets
    for( uint32_t i=0; i<h.numBuckets(); i++ ) {
        h.increment( i );
    }
}

// When constructing a histogram with a positive integer number of buckets then buckets should be created
void TestHistogram::constructWithValidBuckets() {
    Histogram h{10};

    // Ensure we have 10 buckets
    QVERIFY( h.numBuckets() == 10);

    // Ensure buckets are empty
    for( uint32_t i=0; i<10; i++ ) {
        QVERIFY( h[i] == 0 );
    }
}

// When constructing a histogram with 0 number of buckets, throws an std::invalid_argument exception
void TestHistogram::constructWithZeroBuckets() {
    QVERIFY_EXCEPTION_THROWN( Histogram h{0}, std::invalid_argument);
}

// When constructing a histogram with no buckets specified, generates 256 buckets
void TestHistogram::constructWithDefaultBuckets() {
    Histogram h;

    // Ensure we have 256 buckets
    QVERIFY( h.numBuckets() == 256);

    // Ensure buckets are empty
    for( uint32_t i=0; i<10; i++ ) {
        QVERIFY( h[i] == 0 );
    }
}

// When incrementing a bucket, it changes value
void TestHistogram::incrementBucketChangesValues() {
    Histogram h{ 10 };

    // Increment all buckets
    for( uint32_t i=0; i<h.numBuckets(); i++ ) {
        uint32_t oldValue = h[i];
        h.increment( i );
        uint32_t newValue = h[i];

        QCOMPARE( newValue, oldValue + 1 );
    }
}

// When buckets are incremented, total is accurate
void TestHistogram::computeBucketTotals() {
    Histogram h{ 10 };

    incrementBuckets(h);
    uint32_t expectedValue = h.numBuckets();
    uint32_t actualValue   = h.total();

    QCOMPARE( actualValue, expectedValue );
}

// When (matched) histograms are added, the totals are accurate
void TestHistogram::addSameSizedHistograms() {
    Histogram h1{10};
    Histogram h2{10};

   incrementBuckets(h1);
   incrementBuckets(h2);
   incrementBuckets(h2);

   h1 += h2;

   // Each bucket in h1 should contain 3, each bucket in h2 contains 2
   for( uint32_t i=0; i<h1.numBuckets(); i++ ) {
       QCOMPARE( h1[i], static_cast<uint32_t>( 3 ) );
       QCOMPARE( h2[i], static_cast<uint32_t>( 2 ) );
   }
}

// When (unmatched) histograms are added, throws a std::invaid_argument
void TestHistogram::addDifferentSizedHistograms() {
    Histogram h1{5};
    Histogram h2{6};

    QVERIFY_EXCEPTION_THROWN(h1 += h2, std::invalid_argument);
}

// When a histogram is reset, values revert to zero
void TestHistogram::resetBuckets() {
    Histogram h{ 10 };

    incrementBuckets(h);

    // Reset and check
    h.reset( );

    // Ensure buckets are empty
    for( uint32_t i=0; i<h.numBuckets(); i++ ) {
        QVERIFY( h[i] == 0 );
    }
}

// When bucket out of range is requested, thows a std::invalid_argument
void TestHistogram::requestInvalidBucket( ) {
    Histogram h{10};

    QVERIFY_EXCEPTION_THROWN( h[10], std::invalid_argument);
}

// When bucket out of range is incremented, thows a std::invalid_argument
void TestHistogram::incrementInvalidBucket( ) {
    Histogram h{10};

    QVERIFY_EXCEPTION_THROWN( h.increment(10), std::invalid_argument);
}
