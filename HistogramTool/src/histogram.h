#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <iostream>
#include <QImage>

//
// A class for constructing histograms
//
class Histogram
{
private:
    // Number of buckets allocated
    uint32_t    mNumBuckets;

    // the buckets themselves
    uint32_t    *mBuckets;

public:
    /*
     * numBuckets The number of buckets
     */
    Histogram( uint32_t numBuckets = 256 );

    /*
     * Tidy up
     */
    ~Histogram( );


    /*
     * Reset the histogram counts to 0
     */
    void reset( );

    /*
     * Return the count at one bucket
     */
    uint32_t operator[]( size_t index) const;

    /*
     * Increment the count at a given bucket
     */
    void increment( size_t index );

    /*
     * Return the total count across all buckets
     */
    uint32_t total( ) const;

    /*
     * Return the number of buckets
     */
    uint32_t numBuckets( ) const;

    /*
     * Add another Histogram into this one assuming they are the same size
     */
    Histogram& operator+=( const Histogram& rhs ) {
        if( rhs.numBuckets() != mNumBuckets ) {
            throw std::invalid_argument( "Can't add Histograms of different sizes.");
        }

        for( size_t i=0; i<rhs.numBuckets(); ++i ) {
            mBuckets[i] += rhs[i];
        }

        return *this;
    }
};

/*
 * Print to stream
 */
std::ostream& operator<<( std::ostream& out, Histogram& h );


#endif // HISTOGRAM_H
