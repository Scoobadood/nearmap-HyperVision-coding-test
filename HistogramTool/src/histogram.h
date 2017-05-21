#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <iostream>
#include <cstdint>
#include <QImage>

/**
 * Histogram.
 *
 * Represents a histogram with a given number of 'buckets'.
 * The Histogram is created empty. If no bucket count is specified it defaults to
 * 256.  Buckets are created empty (with 0 value).
 *
 * Individual buckets can be incremented using increment(bucket_number)
 *
 * All buckets are reset to 0 using reset()
 *
 * Values in buckets can be returned using the '[]' operator
 *
 * Histograms can be added to each other provided that they have the same number of buckets.
 *
 * total() sums the contents of all buckets in the histogram and so is the total number of samples seen so far.
 *
 * Histograms can be written to ostream instances where they will write all values to a singel line,
 * separated by commas, and terminated with a new line
 */
class Histogram
{
private:
    // Number of buckets allocated
    uint32_t    mNumBuckets;

    // the buckets themselves
    uint32_t    *mBuckets;

public:
    /**
     * Construct a Histogram with the given number of buckets.
     * @param numBuckets The number of buckets. Defaults to 256 if not specified. May not be zero.
     * @throws std::bad_alloc if memory cannot be allocated for buckets.
     * @throws std::invalid_argument if numBuckets is 0.
     */
    Histogram( uint32_t numBuckets = 256 );

    /**
     * Copy constructor, deep copies the bucket array.
     * @param h Another Histogram.
     * @throws std::bad_alloc if memory cannot be allocated for buckets.
     */
    Histogram( const Histogram& h );

    /**
     * Frees bucket memory.
     */
    ~Histogram( );


    /**
     * Reset the histogram counts to 0 for all buckets
     */
    void reset( );

    /**
     * Return the count at the specified bucket.
     * @param index The index of bucket whose content is required.
     * @return The content of the given bucket.
     * @throws std::invalid_argument if the bucket index provided is out of range.
     */
    uint32_t operator[]( size_t index) const;

    /**
     * Increment the count at a given bucket.
     * @param index The index of bucket to increment
     * @throws std::invalid_argument if the bucket index provided is out of range.
     */
    void increment( size_t index );

    /**
     * @return The total of all bucket counts.
     */
    uint32_t total( ) const;

    /**
     * @return The number of buckets.
     */
    uint32_t numBuckets( ) const;

    /**
     * Add another Histogram into this one.
     * Adds the contents of each bucket of the other histogram into the corresponding
     * bucket in this one.  This only works if the Histograms have the same number of buckets
     * @param rhs The other Histogram to be added to this one
     * @return a reference to this Histogram post addition.
     * @throws std::invalid_argument if rhs has a different number of buckets to this Histogram.
     */
    Histogram& operator+=( const Histogram& rhs );


    /**
     * Assign this histogram from another
     * @param rhs The other Histogram to be assigned to this one
     * @throws std::bad_alloc if memory cannot be allocated
     */
    void operator= ( const Histogram& rhs );

    /**
     * Support addition of Histograms
     * @param h1 A Histogram.
     * @param h2 Another Histogram to add to the first.
     * @return A third Histogram being the sum of the first two.
     * @throws std::invalid_argument if the Histograms do not have the same size
     */
    friend Histogram operator+(const Histogram &c1, const Histogram &c2);
};

/**
 * Print Histogram to stream.
 * The Histogram bucket contents are all written to one line, separated by commas and with a
 * new line character at the end of the buckets.
 * @param out An output stream.
 * @param h A Histogram instance.
 * @returns The output stream.
 */
std::ostream& operator<<( std::ostream& out, Histogram& h );


#endif // HISTOGRAM_H
