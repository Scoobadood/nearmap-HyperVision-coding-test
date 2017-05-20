#include "histogram.h"


/*
 * Construct with a given number of buckets
 */
Histogram::Histogram( uint32_t numBuckets )
{
    if( numBuckets == 0 ) {
        throw std::invalid_argument( "Number of buckets must be positive");
    }

    mBuckets = new uint32_t[ numBuckets];
    mNumBuckets = numBuckets;
    reset();
}

/*
 * Copy constructor, deep copies the bucket array.
 */
Histogram::Histogram( const Histogram& h )
{
    mBuckets = new uint32_t[ h.numBuckets() ];
    mNumBuckets = h.numBuckets();
}


/*
 * Delete the buckets
 */
Histogram::~Histogram( )
{
    mNumBuckets = 0;
    delete[] mBuckets;
}

/*
 * Reset the histogram counts to 0
 */
void Histogram::reset( )
{
    for( size_t i=0; i<mNumBuckets; ++i ) {
        mBuckets[i] = 0;
    }
}

/*
 * Return the count at one bucket
 */
uint32_t Histogram::operator[]( size_t index) const
{
    if( index >= mNumBuckets) {
        throw std::invalid_argument( "Bucket index out of range" );
    }

    return mBuckets[index];
}

/*
 * Increment the count at a given bucket
 */
void Histogram::increment( size_t index )
{
    if( index >= mNumBuckets) {
        throw std::invalid_argument( "Bucket index out of range" );
    }

    mBuckets[index] ++;
}

/*
 * Return the total count across all buckets
 */
uint32_t Histogram::total( ) const
{
    uint32_t total = 0;
    for( size_t i  = 0; i < mNumBuckets; ++i ) {
        total += mBuckets[i];
    }
    return total;
}

/*
 * Return the number of buckets
 */
uint32_t Histogram::numBuckets( ) const
{
    return mNumBuckets;
}

/*
 * Add another Histogram to this one
 */
Histogram& Histogram::operator+=( const Histogram& rhs )
{
    if( rhs.numBuckets() != mNumBuckets ) {
        throw std::invalid_argument( "Can't add Histograms of different sizes.");
    }

    for( size_t i=0; i<mNumBuckets; ++i ) {
        mBuckets[i] += rhs[i];
    }

    return *this;
}

/*
 * Assigment operator
 */
void Histogram::operator= ( const Histogram& rhs ) {
    // Create a copy first
    uint32_t *tempBuckets = new uint32_t[rhs.numBuckets()];
    for( size_t i=0; i<rhs.numBuckets(); i++ ) {
        tempBuckets[i] = rhs[i];
    }

    // Delete and switch to make it exception safe
    delete[] mBuckets;
    mBuckets = tempBuckets;
    mNumBuckets = rhs.numBuckets();
}


/*
 * Support addition of Histograms
 */
Histogram operator+(const Histogram& h1, const Histogram& h2)
{
    Histogram h = h1;
    h += h2;
    return h;
}

/*
 * Print to stream
 */
std::ostream& operator<<( std::ostream& out, Histogram& h )
{
    for( size_t i=0; i<h.numBuckets(); ++i ) {
        out << h[i];

        if( i == h.numBuckets() - 1 ) {
            out << std::endl;
        }
        else {
            out << ", ";
        }

    }
    return out;
}
