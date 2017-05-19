#include "../src/histogram.h"

class TestHistogram : public QObject {
    Q_OBJECT

private slots:
    // Utility function to increment each bucket once
    void incrementBuckets( Histogram& h );

    // When constructing a histogram with a positive integer number of buckets then buckets should be created
    void constructWithValidBuckets();

    // When constructing a histogram with 0 number of buckets, throws an std::invalid_argument exception
    void constructWithZeroBuckets();

    // When constructing a histogram with no buckets specified, generates 256 buckets
    void constructWithDefaultBuckets();

    // When incrementing a bucket, it changes value
    void incrementBucketChangesValues();

    // When buckets are incremented, total is accurate
    void computeBucketTotals();

    // When (matched) histograms are added, the totals are accurate
    void addSameSizedHistograms();

    // When (unmatched) histograms are added, throws a std::invaid_argument
    void addDifferentSizedHistograms();

    // When a histogram is reset, values revert to zero
    void resetBuckets();
};
