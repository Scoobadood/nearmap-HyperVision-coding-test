#include "histogram.h"

Histogram::Histogram( uint32_t numBuckets ) {
    std::cout << "Creating histogram with " << numBuckets << " buckets" << std::endl;
    if( numBuckets == 0 ) {
        throw std::invalid_argument( "Number of buckets must be positive");
    }

    mNumBuckets = numBuckets;
    mBuckets = new uint32_t[ numBuckets];

    if( mBuckets == 0 ) {
        throw std::bad_alloc();
    }

    reset();
}


Histogram::~Histogram( ) {
    std::cout << "Destroying histogram with " << mNumBuckets << std::endl;
    delete [] mBuckets;
}

/*
 * Reset the histogram counts to 0
 */
void Histogram::reset( ) {
    for( size_t i=0; i<mNumBuckets; ++i ) {
        mBuckets[i] = 0;
    }
}

/*
 * Return the count at one bucket
 */
uint32_t Histogram::operator[]( size_t index) const {
    return mBuckets[index];
}

/*
 * Increment the count at a given bucket
 */
void Histogram::increment( size_t index ) {
    mBuckets[index] ++;
}

/*
 * Return the total count across all buckets
 */
uint32_t Histogram::total( ) const {
    uint32_t total = 0;
    for( size_t i  = 0; i < mNumBuckets; ++i ) {
        total += mBuckets[i];
    }
    return total;
}

/*
 * Return the number of buckets
 */
uint32_t Histogram::numBuckets( ) const {
    return mNumBuckets;
}

/*
 * Print to stream
 */
std::ostream& operator<<( std::ostream& out, Histogram& h ) {
    for( size_t i=0; i<h.numBuckets(); ++i ) {
        out << h[i];
        if( i == h.numBuckets() - 1 ) {
            out << std::endl;
        } else {
            out << ", ";
        }
    }
    return out;
}
