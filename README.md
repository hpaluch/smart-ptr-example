vector of shared_ptr example
============================

Demo, how to use std::vector with boost::shared_ptr and iterate it.

Installation
============

CentOS 6.x
----------
Just issue as root:

	yum install make binutils gcc gcc-c++ libstdc++-devel boost-devel boost-system valgrind


Ubuntu 14.04 LTS (with Eclipse CDT)
-----------------------------------

As root or via sudo install:

	apt-get install eclipse-cdt eclipse-cdt-valgrind libboost-system-dev libstdc++-4.8-dev make g++

As non-root user:

	mkdir ~/projects
	cd ~/projects
	git clone https://github.com/hpaluch/smart-ptr-example.git

* Run eclipse (for example using command 'eclpse')
* In project explorer choose Import ...
* Select C/C++ -> Existing Code as Makefile Project
* Select ~/projects/smart-ptr-example as your project dir
* Select "Linux GCC" as Indexer
* Open new View named C/C++ -> Make Targets
* Double click on "run" or "valgrind" target




Build and Run (Command Line)
============================

To build:

	make

To run:

	make run

To run with mem leak detector:

	make valgrind


