# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /Users/Athos/Documents/GitHub/ProvaProgetto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Athos/Documents/GitHub/ProvaProgetto

# Include any dependencies generated for this target.
include Test/lib/googletest/CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include Test/lib/googletest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include Test/lib/googletest/CMakeFiles/gtest_main.dir/flags.make

Test/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: Test/lib/googletest/CMakeFiles/gtest_main.dir/flags.make
Test/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: Test/lib/googletest/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Athos/Documents/GitHub/ProvaProgetto/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Test/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd /Users/Athos/Documents/GitHub/ProvaProgetto/Test/lib/googletest && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c /Users/Athos/Documents/GitHub/ProvaProgetto/Test/lib/googletest/src/gtest_main.cc

Test/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /Users/Athos/Documents/GitHub/ProvaProgetto/Test/lib/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Athos/Documents/GitHub/ProvaProgetto/Test/lib/googletest/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

Test/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /Users/Athos/Documents/GitHub/ProvaProgetto/Test/lib/googletest && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Athos/Documents/GitHub/ProvaProgetto/Test/lib/googletest/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

Test/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires:

.PHONY : Test/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

Test/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides: Test/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires
	$(MAKE) -f Test/lib/googletest/CMakeFiles/gtest_main.dir/build.make Test/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build
.PHONY : Test/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides

Test/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build: Test/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o


# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

lib/libgtest_maind.a: Test/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
lib/libgtest_maind.a: Test/lib/googletest/CMakeFiles/gtest_main.dir/build.make
lib/libgtest_maind.a: Test/lib/googletest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Athos/Documents/GitHub/ProvaProgetto/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libgtest_maind.a"
	cd /Users/Athos/Documents/GitHub/ProvaProgetto/Test/lib/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd /Users/Athos/Documents/GitHub/ProvaProgetto/Test/lib/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Test/lib/googletest/CMakeFiles/gtest_main.dir/build: lib/libgtest_maind.a

.PHONY : Test/lib/googletest/CMakeFiles/gtest_main.dir/build

Test/lib/googletest/CMakeFiles/gtest_main.dir/requires: Test/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

.PHONY : Test/lib/googletest/CMakeFiles/gtest_main.dir/requires

Test/lib/googletest/CMakeFiles/gtest_main.dir/clean:
	cd /Users/Athos/Documents/GitHub/ProvaProgetto/Test/lib/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : Test/lib/googletest/CMakeFiles/gtest_main.dir/clean

Test/lib/googletest/CMakeFiles/gtest_main.dir/depend:
	cd /Users/Athos/Documents/GitHub/ProvaProgetto && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Athos/Documents/GitHub/ProvaProgetto /Users/Athos/Documents/GitHub/ProvaProgetto/Test/lib/googletest /Users/Athos/Documents/GitHub/ProvaProgetto /Users/Athos/Documents/GitHub/ProvaProgetto/Test/lib/googletest /Users/Athos/Documents/GitHub/ProvaProgetto/Test/lib/googletest/CMakeFiles/gtest_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Test/lib/googletest/CMakeFiles/gtest_main.dir/depend

