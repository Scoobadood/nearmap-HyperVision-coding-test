# Submission

## Build
Builds under QtCreator

## Run
From the command line run `HistogramTool <image_file>`

Other command line options include:

	Options
	 -h, --help                   Displays this help.
	 -s, --self-test              Show self test results
	 -o, --output-file <file>     Write output to file
	 -t, --num-threads <threads>  Use specified number of threads. Overrides automatic setting

	Arguments:
	  image                        Image file to compute histogram for.

## Tests
From the command line run `TestHistogramTool`

Test runs unit tests against the underlying histogram and tool classes.

## Performance
Performance was tested on two machines.  The tool was run 5 times and timings were averaged over runs then rounded to nearest ms.

### Machine 1
MacBook Pro 15" mid 2015
2.8 GHz Intel Core i7
16 GB Memory
macos Sierra 10.12.5

	+------------+--------+--------+--------+--------+--------+--------+--------+--------+
	| Threads    |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |
	+------------+--------+--------+--------+--------+--------+--------+--------+--------+
	| Time Taken | 140 ms |  72 ms |  49 ms |  36 ms |  39 ms |  39 ms |  38 ms |  37 ms |
	+------------+--------+--------+--------+--------+--------+--------+--------+--------+

	+------------+--------+--------+
	| Threads    |   10   |  100   |
	+------------+--------+--------+
	| Time Taken |  38 ms |  37 ms |
	+------------+--------+--------+

When the number of threads is not specified, the OS reports 8 available cores.

### Machine 2
PC, Ubuntu  Pro 15" mid 2015 with 2.8 GHz Intel Core i7 against the test image.


# Requirements

## Constraints

* Must be written in C++
* Recommended to build and run on Linux (Ubuntu).
* Recommended to use the Qt SDK (http://qt-project.org/downloads).  Stub project provided.

## Task

* Create a command line tool that can calculate a red, green and blue histogram for an image and write to an output file in the format described below.
  * It should be optimized for performance (e.g. multi-threaded) and should ultilize all processing cores.
   (Please **don't** use third-party libraries such as Intel TBB or OpenMP.)
* Create a unit test to validate the results.  To simplify the build process it is sufficient to include the test case in the command line tool.

## Output format

An ascii text file containing one line for each colour band in the image (in the order red, green, blue).  Each line is a comma separated list of the pixel count for each value (256 per line).

## Submission instructions

* A zip file containing the following - submitted to your agent or nearmap contact.
  * Full source code and project files required to build.  It should compile with no errors or warnings.
  * The output histogram file for the provided sample image.
  * DO NOT include any build intermediate files in the zip file.
  * DO NOT include the provided sample image in the zip file.

* DO NOT send pull requests against this repository for two reasons:
  * We don't want executables checked into source control
  * We don't want other candidates to see your solution.
