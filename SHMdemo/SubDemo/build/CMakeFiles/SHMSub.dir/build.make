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
CMAKE_SOURCE_DIR = /home/wsm/test/SHMdemo/SubDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wsm/test/SHMdemo/SubDemo/build

# Include any dependencies generated for this target.
include CMakeFiles/SHMSub.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SHMSub.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SHMSub.dir/flags.make

CMakeFiles/SHMSub.dir/SHMDemo.cxx.o: CMakeFiles/SHMSub.dir/flags.make
CMakeFiles/SHMSub.dir/SHMDemo.cxx.o: ../SHMDemo.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wsm/test/SHMdemo/SubDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SHMSub.dir/SHMDemo.cxx.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SHMSub.dir/SHMDemo.cxx.o -c /home/wsm/test/SHMdemo/SubDemo/SHMDemo.cxx

CMakeFiles/SHMSub.dir/SHMDemo.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SHMSub.dir/SHMDemo.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wsm/test/SHMdemo/SubDemo/SHMDemo.cxx > CMakeFiles/SHMSub.dir/SHMDemo.cxx.i

CMakeFiles/SHMSub.dir/SHMDemo.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SHMSub.dir/SHMDemo.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wsm/test/SHMdemo/SubDemo/SHMDemo.cxx -o CMakeFiles/SHMSub.dir/SHMDemo.cxx.s

CMakeFiles/SHMSub.dir/SHMDemoPubSubTypes.cxx.o: CMakeFiles/SHMSub.dir/flags.make
CMakeFiles/SHMSub.dir/SHMDemoPubSubTypes.cxx.o: ../SHMDemoPubSubTypes.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wsm/test/SHMdemo/SubDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SHMSub.dir/SHMDemoPubSubTypes.cxx.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SHMSub.dir/SHMDemoPubSubTypes.cxx.o -c /home/wsm/test/SHMdemo/SubDemo/SHMDemoPubSubTypes.cxx

CMakeFiles/SHMSub.dir/SHMDemoPubSubTypes.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SHMSub.dir/SHMDemoPubSubTypes.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wsm/test/SHMdemo/SubDemo/SHMDemoPubSubTypes.cxx > CMakeFiles/SHMSub.dir/SHMDemoPubSubTypes.cxx.i

CMakeFiles/SHMSub.dir/SHMDemoPubSubTypes.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SHMSub.dir/SHMDemoPubSubTypes.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wsm/test/SHMdemo/SubDemo/SHMDemoPubSubTypes.cxx -o CMakeFiles/SHMSub.dir/SHMDemoPubSubTypes.cxx.s

CMakeFiles/SHMSub.dir/SHMSubSubscriber.cpp.o: CMakeFiles/SHMSub.dir/flags.make
CMakeFiles/SHMSub.dir/SHMSubSubscriber.cpp.o: ../SHMSubSubscriber.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wsm/test/SHMdemo/SubDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SHMSub.dir/SHMSubSubscriber.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SHMSub.dir/SHMSubSubscriber.cpp.o -c /home/wsm/test/SHMdemo/SubDemo/SHMSubSubscriber.cpp

CMakeFiles/SHMSub.dir/SHMSubSubscriber.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SHMSub.dir/SHMSubSubscriber.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wsm/test/SHMdemo/SubDemo/SHMSubSubscriber.cpp > CMakeFiles/SHMSub.dir/SHMSubSubscriber.cpp.i

CMakeFiles/SHMSub.dir/SHMSubSubscriber.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SHMSub.dir/SHMSubSubscriber.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wsm/test/SHMdemo/SubDemo/SHMSubSubscriber.cpp -o CMakeFiles/SHMSub.dir/SHMSubSubscriber.cpp.s

CMakeFiles/SHMSub.dir/SHMSub_main.cpp.o: CMakeFiles/SHMSub.dir/flags.make
CMakeFiles/SHMSub.dir/SHMSub_main.cpp.o: ../SHMSub_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wsm/test/SHMdemo/SubDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SHMSub.dir/SHMSub_main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SHMSub.dir/SHMSub_main.cpp.o -c /home/wsm/test/SHMdemo/SubDemo/SHMSub_main.cpp

CMakeFiles/SHMSub.dir/SHMSub_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SHMSub.dir/SHMSub_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wsm/test/SHMdemo/SubDemo/SHMSub_main.cpp > CMakeFiles/SHMSub.dir/SHMSub_main.cpp.i

CMakeFiles/SHMSub.dir/SHMSub_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SHMSub.dir/SHMSub_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wsm/test/SHMdemo/SubDemo/SHMSub_main.cpp -o CMakeFiles/SHMSub.dir/SHMSub_main.cpp.s

# Object files for target SHMSub
SHMSub_OBJECTS = \
"CMakeFiles/SHMSub.dir/SHMDemo.cxx.o" \
"CMakeFiles/SHMSub.dir/SHMDemoPubSubTypes.cxx.o" \
"CMakeFiles/SHMSub.dir/SHMSubSubscriber.cpp.o" \
"CMakeFiles/SHMSub.dir/SHMSub_main.cpp.o"

# External object files for target SHMSub
SHMSub_EXTERNAL_OBJECTS =

SHMSub: CMakeFiles/SHMSub.dir/SHMDemo.cxx.o
SHMSub: CMakeFiles/SHMSub.dir/SHMDemoPubSubTypes.cxx.o
SHMSub: CMakeFiles/SHMSub.dir/SHMSubSubscriber.cpp.o
SHMSub: CMakeFiles/SHMSub.dir/SHMSub_main.cpp.o
SHMSub: CMakeFiles/SHMSub.dir/build.make
SHMSub: /home/wsm/Fast-DDS/install/lib/libfastrtps.so.2.7.0
SHMSub: /home/wsm/Fast-DDS/install/lib/libfastcdr.so.1.0.24
SHMSub: /home/wsm/Fast-DDS/install/lib/libfoonathan_memory-0.7.1.so
SHMSub: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
SHMSub: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
SHMSub: /usr/lib/x86_64-linux-gnu/libssl.so
SHMSub: /usr/lib/x86_64-linux-gnu/libcrypto.so
SHMSub: CMakeFiles/SHMSub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wsm/test/SHMdemo/SubDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable SHMSub"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SHMSub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SHMSub.dir/build: SHMSub

.PHONY : CMakeFiles/SHMSub.dir/build

CMakeFiles/SHMSub.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SHMSub.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SHMSub.dir/clean

CMakeFiles/SHMSub.dir/depend:
	cd /home/wsm/test/SHMdemo/SubDemo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wsm/test/SHMdemo/SubDemo /home/wsm/test/SHMdemo/SubDemo /home/wsm/test/SHMdemo/SubDemo/build /home/wsm/test/SHMdemo/SubDemo/build /home/wsm/test/SHMdemo/SubDemo/build/CMakeFiles/SHMSub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SHMSub.dir/depend

