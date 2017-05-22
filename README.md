# Submission
This is my submission for the nearmap coding project.  I'm unfamiliar with the Qt framework but to avoid including
lots of extra image processing I have tried to use the Qt stuff where it makes sense - mostly to parse arguments, time
execution and read the image as well as for unit tests because it seemed to work better that way.

I've used std::thread because I understand it better. This means it needs to be compiled with C++ 11 support.

## Code Structure and Build
Builds using QtCreator 4.2.2  and GCC 64 bit 
Based on Qt 5.8.0 (GCC 5.3.1 20160406 (Red Hat 5.3.1-6), 64 bit)
From revision 991f5eb6a5
Requires c++ 11

	+-- app
	|   +-- main.cpp                             Main application entry point
	|
	+-- src
	|   |-- histogram.cpp                        Class representing a histogram
	|   |-- histogram.h
	|   |-- histogram_tool.cpp                   Class representing the Histogram computation tool
	|   +-- histogram_tool.h
	|
	+-- tests
	    |-- test_histogram.cpp                   Unit tests for Histogram class
	    |-- test_histogram.h
	    |-- test_histogram_tool.cpp              Unit tests for HistogramTool class
	    +-- test_histogram_tool.h



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

When the number of threads is not specified, the OS reports 8 available cores however the i7 has only 4 cores.

### Machine 2
PC Home build,
Intel® Pentium(R) CPU G4400 @ 3.30GHz × 2,
4 GB Memory
Ubuntu 16.04 LTS

	+------------+--------+--------+--------+--------+
	| Threads    |   1    |   2    |   3    |   4    |
	+------------+--------+--------+--------+--------+
	| Time Taken | 150 ms |  80 ms |  81 ms |  79 ms |
	+------------+--------+--------+--------+--------+

	+------------+--------+--------+
	| Threads    |   10   |  100   |
	+------------+--------+--------+
	| Time Taken |  78 ms |  78 ms |
	+------------+--------+--------+

## Comments
### Improving performance
Profiling shows that the bulk of the time the application spends in Histogram::increment().  

A quick test shows that dropping the bounds check result in a 30ms improvement in performance on Linux with a 2 thread run taking 48ms. This is significant.

I suspect that performance could be greatly increased by swapping out the Histogram class entirely and using simple arrays of uint32_ts at the cost of slightly more opaque/less maintainable code.
