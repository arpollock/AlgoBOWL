# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/arpollock/Dropbox/C++/AlgoBOWL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/arpollock/Dropbox/C++/AlgoBOWL/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AlgoBOWL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AlgoBOWL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AlgoBOWL.dir/flags.make

CMakeFiles/AlgoBOWL.dir/main.cpp.o: CMakeFiles/AlgoBOWL.dir/flags.make
CMakeFiles/AlgoBOWL.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arpollock/Dropbox/C++/AlgoBOWL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AlgoBOWL.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AlgoBOWL.dir/main.cpp.o -c /Users/arpollock/Dropbox/C++/AlgoBOWL/main.cpp

CMakeFiles/AlgoBOWL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgoBOWL.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arpollock/Dropbox/C++/AlgoBOWL/main.cpp > CMakeFiles/AlgoBOWL.dir/main.cpp.i

CMakeFiles/AlgoBOWL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgoBOWL.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arpollock/Dropbox/C++/AlgoBOWL/main.cpp -o CMakeFiles/AlgoBOWL.dir/main.cpp.s

CMakeFiles/AlgoBOWL.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/AlgoBOWL.dir/main.cpp.o.requires

CMakeFiles/AlgoBOWL.dir/main.cpp.o.provides: CMakeFiles/AlgoBOWL.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/AlgoBOWL.dir/build.make CMakeFiles/AlgoBOWL.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/AlgoBOWL.dir/main.cpp.o.provides

CMakeFiles/AlgoBOWL.dir/main.cpp.o.provides.build: CMakeFiles/AlgoBOWL.dir/main.cpp.o


# Object files for target AlgoBOWL
AlgoBOWL_OBJECTS = \
"CMakeFiles/AlgoBOWL.dir/main.cpp.o"

# External object files for target AlgoBOWL
AlgoBOWL_EXTERNAL_OBJECTS =

AlgoBOWL: CMakeFiles/AlgoBOWL.dir/main.cpp.o
AlgoBOWL: CMakeFiles/AlgoBOWL.dir/build.make
AlgoBOWL: CMakeFiles/AlgoBOWL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/arpollock/Dropbox/C++/AlgoBOWL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AlgoBOWL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AlgoBOWL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AlgoBOWL.dir/build: AlgoBOWL

.PHONY : CMakeFiles/AlgoBOWL.dir/build

CMakeFiles/AlgoBOWL.dir/requires: CMakeFiles/AlgoBOWL.dir/main.cpp.o.requires

.PHONY : CMakeFiles/AlgoBOWL.dir/requires

CMakeFiles/AlgoBOWL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AlgoBOWL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AlgoBOWL.dir/clean

CMakeFiles/AlgoBOWL.dir/depend:
	cd /Users/arpollock/Dropbox/C++/AlgoBOWL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/arpollock/Dropbox/C++/AlgoBOWL /Users/arpollock/Dropbox/C++/AlgoBOWL /Users/arpollock/Dropbox/C++/AlgoBOWL/cmake-build-debug /Users/arpollock/Dropbox/C++/AlgoBOWL/cmake-build-debug /Users/arpollock/Dropbox/C++/AlgoBOWL/cmake-build-debug/CMakeFiles/AlgoBOWL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AlgoBOWL.dir/depend
