#include <QCoreApplication>
#include <QTime>
#include <QImage>
#include <QStringList>
#include <QCommandLineParser>

#include <iostream>
#include <fstream>

#include "histogram.h"
#include "histogram_tool.h"

const int ERR_NO_ERROR = 0;
const int ERR_IMAGE_FILE_NOT_FOUND = 1;
const int ERR_COULDNT_WRITE_FILE = 2;
const int ERR_ILLEGAL_ARGS= 3;


/*
 * Self test checks that the total number of red, green and blue samples
 * in the histograms match each other and the total number of pixels
 * Displays results to stdout.
 * It writes the results to stdout.
 */
void selfTest( QImage& img, Histogram& red, Histogram& green, Histogram& blue ) {
    using namespace std;

    uint32_t redSamples = red.total();
    uint32_t greenSamples = green.total();
    uint32_t blueSamples = blue.total();
    uint32_t numPixels = static_cast<uint32_t>( img.width() * img.height() );

    cout << "   Red samples : " << redSamples << endl;
    cout << " Green samples : " << greenSamples << endl;
    cout << "  Blue samples : " << blueSamples << endl;
    cout << "  Image Pixels : " << numPixels << endl;
    if( redSamples == greenSamples && redSamples == blueSamples && redSamples == numPixels ) {
        cout << "PASSED" << endl;
    }
    else {
        cout << "** FAILED **" << endl;
    }
}


/*
 * Parse command line arguments
 * -h, --help                   Displays this help.
 * -s, --self-test              Show self test results
 * -o, --output-file <file>     Write output to file
 * -t, --num-threads <threads>  Use specified number of threads. Overrides
 *                              automatic setting
 * Arguments:
 * image                        Image file to compute histogram for.
 */
void parseCommandLine( int argc, char * argv[], std::string& imageFileName, std::string& outputFileName, bool& runSelfTest, uint32_t& numThreads ) {

    using namespace std;

    QCoreApplication app(argc, argv);
    QCommandLineParser parser;


    // Set up the Parser
    parser.setApplicationDescription("HistogramTool");
    parser.addHelpOption();
    parser.addOptions( {
        // Self test option, t
        { {"s", "self-test"},  "Show self test results" },
        { {"o", "output-file"}, "Write output to file", "file" },
        { {"t", "num-threads"}, "Use specified number of threads. Overrides automatic setting", "threads" }
    });
    parser.addPositionalArgument( "image", "Image file to compute histogram for.");


    // Parse the arguments
    parser.process( app );


    // Validate the output

    // Do self test ?
    if( parser.isSet( "s" ) ) {
        runSelfTest = true;
    }

    // Number of threads specified ? Should be non-zero
    QString threadCount = parser.value( "t" );
    if( threadCount.length() > 0 ) {
        numThreads = threadCount.toUInt();
        if( numThreads == 0 ) {
            cerr << "If specified, threads must be a positive integer" << endl;
            parser.showHelp(ERR_ILLEGAL_ARGS );
        }
    }


    // Output file name; optional
    QString fileName = parser.value( "o");
    if( fileName.length() > 0 ) {
        outputFileName = fileName.toStdString();
    }


    // Image file name is mandatory
    QStringList positionalArguments = parser.positionalArguments();
    if( positionalArguments.length() != 1 ) {
        cerr << "Must specify input image file" << endl;
        parser.showHelp( ERR_ILLEGAL_ARGS );
    } else {
        imageFileName = positionalArguments[0].toStdString();
    }
}


/*
 *
 *
 */
int main(int argc, char *argv[])
{
    using namespace std;

    //
    // Set up some default values for run
    //
    bool runSelfTest = false;
    uint32_t numThreads = 0;
    string imageFileName = "";
    string outputFileName = "";


    //
    // Parse command line to see if any of these are overridden
    //
    parseCommandLine( argc, argv, imageFileName, outputFileName, runSelfTest, numThreads );

    //
    // Try to load the image
    //
    QImage img;
    if( ! img.load( QString::fromStdString(imageFileName) ) ) {
        cerr << "Unable to load image " << imageFileName << endl;
        exit( ERR_IMAGE_FILE_NOT_FOUND );
    }

    //
    // Convert image to ARGB32 format for consistency
    //
    img = img.convertToFormat(QImage::Format_ARGB32);

    //
    // If numThreads is not been specified, ask how many cores there are
    // and use that value.
    //
    if( numThreads == 0 ) {
        // Determine the number of cores available on this machine. May return 0 if librarty can't tell
        unsigned numberOfCores= thread::hardware_concurrency();
        if( numberOfCores == 0 ) {
            cout << "Warning: Couldn't detect number of cores. Using 1." << endl;
            numberOfCores = 1;
        }
        else {
            cout << "Detected " << numberOfCores << endl;
        }
        numThreads = numberOfCores;
    }

    HistogramTool htool{numThreads};

    // Start timer
    QTime time;
    time.start();

    //
    // Do the actual work
    //
    Histogram red, green, blue;
    htool.computeHistogram( img, red, green, blue );

    //
    // Compute elapsed time
    //
    int time_taken = time.elapsed();
    cout << " Time Taken : " << time_taken << "ms" << endl;


    //
    // Write output to file if name provided ...
    //
    if( outputFileName.length() > 0 ) {
        ofstream output{outputFileName};
        if( output.good()) {
            output<< red << green << blue;
        }
        else {
            cerr << "Couldn't write histogram to " << outputFileName << endl;
            exit( ERR_COULDNT_WRITE_FILE );
        }
    }

    // .. or else stdout
    else {
        cout << red << green << blue;
    }

    //
    // Optionally print self-test diagnostics
    //
    if( runSelfTest ) {
        selfTest(img, red, green, blue );
    }

    return ERR_NO_ERROR;
}
