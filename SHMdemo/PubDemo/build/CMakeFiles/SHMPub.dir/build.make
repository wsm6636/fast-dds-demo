# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/cmake-3.16.8/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.16.8/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wsm/test/SHMdemo/PubDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wsm/test/SHMdemo/PubDemo/build

# Include any dependencies generated for this target.
include CMakeFiles/SHMPub.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SHMPub.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SHMPub.dir/flags.make

CMakeFiles/SHMPub.dir/SHMDemo.cxx.o: CMakeFiles/SHMPub.dir/flags.make
CMakeFiles/SHMPub.dir/SHMDemo.cxx.o: ../SHMDemo.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wsm/test/SHMdemo/PubDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SHMPub.dir/SHMDemo.cxx.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SHMPub.dir/SHMDemo.cxx.o -c /home/wsm/test/SHMdemo/PubDemo/SHMDemo.cxx

CMakeFiles/SHMPub.dir/SHMDemo.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SHMPub.dir/SHMDemo.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wsm/test/SHMdemo/PubDemo/SHMDemo.cxx > CMakeFiles/SHMPub.dir/SHMDemo.cxx.i

CMakeFiles/SHMPub.dir/SHMDemo.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SHMPub.dir/SHMDemo.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wsm/test/SHMdemo/PubDemo/SHMDemo.cxx -o CMakeFiles/SHMPub.dir/SHMDemo.cxx.s

CMakeFiles/SHMPub.dir/SHMDemoPubSubTypes.cxx.o: CMakeFiles/SHMPub.dir/flags.make
CMakeFiles/SHMPub.dir/SHMDemoPubSubTypes.cxx.o: ../SHMDemoPubSubTypes.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wsm/test/SHMdemo/PubDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SHMPub.dir/SHMDemoPubSubTypes.cxx.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SHMPub.dir/SHMDemoPubSubTypes.cxx.o -c /home/wsm/test/SHMdemo/PubDemo/SHMDemoPubSubTypes.cxx

CMakeFiles/SHMPub.dir/SHMDemoPubSubTypes.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SHMPub.dir/SHMDemoPubSubTypes.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wsm/test/SHMdemo/PubDemo/SHMDemoPubSubTypes.cxx > CMakeFiles/SHMPub.dir/SHMDemoPubSubTypes.cxx.i

CMakeFiles/SHMPub.dir/SHMDemoPubSubTypes.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SHMPub.dir/SHMDemoPubSubTypes.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wsm/test/SHMdemo/PubDemo/SHMDemoPubSubTypes.cxx -o CMakeFiles/SHMPub.dir/SHMDemoPubSubTypes.cxx.s

CMakeFiles/SHMPub.dir/SHMPubPublisher.cpp.o: CMakeFiles/SHMPub.dir/flags.make
CMakeFiles/SHMPub.dir/SHMPubPublisher.cpp.o: ../SHMPubPublisher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wsm/test/SHMdemo/PubDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SHMPub.dir/SHMPubPublisher.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SHMPub.dir/SHMPubPublisher.cpp.o -c /home/wsm/test/SHMdemo/PubDemo/SHMPubPublisher.cpp

CMakeFiles/SHMPub.dir/SHMPubPublisher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SHMPub.dir/SHMPubPublisher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wsm/test/SHMdemo/PubDemo/SHMPubPublisher.cpp > CMakeFiles/SHMPub.dir/SHMPubPublisher.cpp.i

CMakeFiles/SHMPub.dir/SHMPubPublisher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SHMPub.dir/SHMPubPublisher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wsm/test/SHMdemo/PubDemo/SHMPubPublisher.cpp -o CMakeFiles/SHMPub.dir/SHMPubPublisher.cpp.s

CMakeFiles/SHMPub.dir/SHMPub_main.cpp.o: CMakeFiles/SHMPub.dir/flags.make
CMakeFiles/SHMPub.dir/SHMPub_main.cpp.o: ../SHMPub_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wsm/test/SHMdemo/PubDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SHMPub.dir/SHMPub_main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SHMPub.dir/SHMPub_main.cpp.o -c /home/wsm/test/SHMdemo/PubDemo/SHMPub_main.cpp

CMakeFiles/SHMPub.dir/SHMPub_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SHMPub.dir/SHMPub_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wsm/test/SHMdemo/PubDemo/SHMPub_main.cpp > CMakeFiles/SHMPub.dir/SHMPub_main.cpp.i

CMakeFiles/SHMPub.dir/SHMPub_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SHMPub.dir/SHMPub_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wsm/test/SHMdemo/PubDemo/SHMPub_main.cpp -o CMakeFiles/SHMPub.dir/SHMPub_main.cpp.s

# Object files for target SHMPub
SHMPub_OBJECTS = \
"CMakeFiles/SHMPub.dir/SHMDemo.cxx.o" \
"CMakeFiles/SHMPub.dir/SHMDemoPubSubTypes.cxx.o" \
"CMakeFiles/SHMPub.dir/SHMPubPublisher.cpp.o" \
"CMakeFiles/SHMPub.dir/SHMPub_main.cpp.o"

# External object files for target SHMPub
SHMPub_EXTERNAL_OBJECTS =

SHMPub: CMakeFiles/SHMPub.dir/SHMDemo.cxx.o
SHMPub: CMakeFiles/SHMPub.dir/SHMDemoPubSubTypes.cxx.o
SHMPub: CMakeFiles/SHMPub.dir/SHMPubPublisher.cpp.o
SHMPub: CMakeFiles/SHMPub.dir/SHMPub_main.cpp.o
SHMPub: CMakeFiles/SHMPub.dir/build.make
SHMPub: /home/wsm/Fast-DDS/install/lib/libfastrtps.so.2.7.0
SHMPub: /home/wsm/Fast-DDS/install/lib/libfastcdr.so.1.0.24
SHMPub: /home/wsm/Fast-DDS/install/lib/libfoonathan_memory-0.7.1.so
SHMPub: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
SHMPub: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
SHMPub: /usr/lib/x86_64-linux-gnu/libssl.so
SHMPub: /usr/lib/x86_64-linux-gnu/libcrypto.so
SHMPub: CMakeFiles/SHMPub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wsm/test/SHMdemo/PubDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable SHMPub"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SHMPub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SHMPub.dir/build: SHMPub

.PHONY : CMakeFiles/SHMPub.dir/build

CMakeFiles/SHMPub.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SHMPub.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SHMPub.dir/clean

CMakeFiles/SHMPub.dir/depend:
	cd /home/wsm/test/SHMdemo/PubDemo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wsm/test/SHMdemo/PubDemo /home/wsm/test/SHMdemo/PubDemo /home/wsm/test/SHMdemo/PubDemo/build /home/wsm/test/SHMdemo/PubDemo/build /home/wsm/test/SHMdemo/PubDemo/build/CMakeFiles/SHMPub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SHMPub.dir/depend

