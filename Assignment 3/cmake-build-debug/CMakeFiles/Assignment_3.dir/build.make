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
CMAKE_SOURCE_DIR = "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Assignment_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment_3.dir/flags.make

CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.o: CMakeFiles/Assignment_3.dir/flags.make
CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.o: ../Part\ A/raytracer/bmp_io.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.o -c "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/bmp_io.cpp"

CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/bmp_io.cpp" > CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.i

CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/bmp_io.cpp" -o CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.s

CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.o.requires:

.PHONY : CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.o.requires

CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.o.provides: CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.o.requires
	$(MAKE) -f CMakeFiles/Assignment_3.dir/build.make CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.o.provides.build
.PHONY : CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.o.provides

CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.o.provides.build: CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.o


CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.o: CMakeFiles/Assignment_3.dir/flags.make
CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.o: ../Part\ A/raytracer/light_source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.o -c "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/light_source.cpp"

CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/light_source.cpp" > CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.i

CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/light_source.cpp" -o CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.s

CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.o.requires:

.PHONY : CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.o.requires

CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.o.provides: CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.o.requires
	$(MAKE) -f CMakeFiles/Assignment_3.dir/build.make CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.o.provides.build
.PHONY : CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.o.provides

CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.o.provides.build: CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.o


CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.o: CMakeFiles/Assignment_3.dir/flags.make
CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.o: ../Part\ A/raytracer/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.o -c "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/main.cpp"

CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/main.cpp" > CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.i

CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/main.cpp" -o CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.s

CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.o.requires:

.PHONY : CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.o.requires

CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.o.provides: CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Assignment_3.dir/build.make CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.o.provides.build
.PHONY : CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.o.provides

CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.o.provides.build: CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.o


CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.o: CMakeFiles/Assignment_3.dir/flags.make
CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.o: ../Part\ A/raytracer/raytracer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.o -c "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/raytracer.cpp"

CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/raytracer.cpp" > CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.i

CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/raytracer.cpp" -o CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.s

CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.o.requires:

.PHONY : CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.o.requires

CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.o.provides: CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.o.requires
	$(MAKE) -f CMakeFiles/Assignment_3.dir/build.make CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.o.provides.build
.PHONY : CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.o.provides

CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.o.provides.build: CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.o


CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.o: CMakeFiles/Assignment_3.dir/flags.make
CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.o: ../Part\ A/raytracer/scene_object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.o -c "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/scene_object.cpp"

CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/scene_object.cpp" > CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.i

CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/scene_object.cpp" -o CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.s

CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.o.requires:

.PHONY : CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.o.requires

CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.o.provides: CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.o.requires
	$(MAKE) -f CMakeFiles/Assignment_3.dir/build.make CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.o.provides.build
.PHONY : CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.o.provides

CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.o.provides.build: CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.o


CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.o: CMakeFiles/Assignment_3.dir/flags.make
CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.o: ../Part\ A/raytracer/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.o -c "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/util.cpp"

CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/util.cpp" > CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.i

CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part A/raytracer/util.cpp" -o CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.s

CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.o.requires:

.PHONY : CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.o.requires

CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.o.provides: CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.o.requires
	$(MAKE) -f CMakeFiles/Assignment_3.dir/build.make CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.o.provides.build
.PHONY : CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.o.provides

CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.o.provides.build: CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.o


CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.o: CMakeFiles/Assignment_3.dir/flags.make
CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.o: ../Part\ B/raytracer/bmp_io.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.o -c "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/bmp_io.cpp"

CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/bmp_io.cpp" > CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.i

CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/bmp_io.cpp" -o CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.s

CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.o.requires:

.PHONY : CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.o.requires

CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.o.provides: CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.o.requires
	$(MAKE) -f CMakeFiles/Assignment_3.dir/build.make CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.o.provides.build
.PHONY : CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.o.provides

CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.o.provides.build: CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.o


CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.o: CMakeFiles/Assignment_3.dir/flags.make
CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.o: ../Part\ B/raytracer/light_source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.o -c "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/light_source.cpp"

CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/light_source.cpp" > CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.i

CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/light_source.cpp" -o CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.s

CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.o.requires:

.PHONY : CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.o.requires

CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.o.provides: CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.o.requires
	$(MAKE) -f CMakeFiles/Assignment_3.dir/build.make CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.o.provides.build
.PHONY : CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.o.provides

CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.o.provides.build: CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.o


CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.o: CMakeFiles/Assignment_3.dir/flags.make
CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.o: ../Part\ B/raytracer/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.o -c "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/main.cpp"

CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/main.cpp" > CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.i

CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/main.cpp" -o CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.s

CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.o.requires:

.PHONY : CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.o.requires

CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.o.provides: CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Assignment_3.dir/build.make CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.o.provides.build
.PHONY : CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.o.provides

CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.o.provides.build: CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.o


CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.o: CMakeFiles/Assignment_3.dir/flags.make
CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.o: ../Part\ B/raytracer/raytracer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.o -c "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/raytracer.cpp"

CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/raytracer.cpp" > CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.i

CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/raytracer.cpp" -o CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.s

CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.o.requires:

.PHONY : CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.o.requires

CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.o.provides: CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.o.requires
	$(MAKE) -f CMakeFiles/Assignment_3.dir/build.make CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.o.provides.build
.PHONY : CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.o.provides

CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.o.provides.build: CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.o


CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.o: CMakeFiles/Assignment_3.dir/flags.make
CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.o: ../Part\ B/raytracer/scene_object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.o -c "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/scene_object.cpp"

CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/scene_object.cpp" > CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.i

CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/scene_object.cpp" -o CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.s

CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.o.requires:

.PHONY : CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.o.requires

CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.o.provides: CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.o.requires
	$(MAKE) -f CMakeFiles/Assignment_3.dir/build.make CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.o.provides.build
.PHONY : CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.o.provides

CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.o.provides.build: CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.o


CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.o: CMakeFiles/Assignment_3.dir/flags.make
CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.o: ../Part\ B/raytracer/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.o -c "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/util.cpp"

CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/util.cpp" > CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.i

CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/Part B/raytracer/util.cpp" -o CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.s

CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.o.requires:

.PHONY : CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.o.requires

CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.o.provides: CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.o.requires
	$(MAKE) -f CMakeFiles/Assignment_3.dir/build.make CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.o.provides.build
.PHONY : CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.o.provides

CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.o.provides.build: CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.o


# Object files for target Assignment_3
Assignment_3_OBJECTS = \
"CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.o" \
"CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.o" \
"CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.o" \
"CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.o" \
"CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.o" \
"CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.o" \
"CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.o" \
"CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.o" \
"CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.o" \
"CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.o" \
"CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.o" \
"CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.o"

# External object files for target Assignment_3
Assignment_3_EXTERNAL_OBJECTS =

Assignment_3: CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.o
Assignment_3: CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.o
Assignment_3: CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.o
Assignment_3: CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.o
Assignment_3: CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.o
Assignment_3: CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.o
Assignment_3: CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.o
Assignment_3: CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.o
Assignment_3: CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.o
Assignment_3: CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.o
Assignment_3: CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.o
Assignment_3: CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.o
Assignment_3: CMakeFiles/Assignment_3.dir/build.make
Assignment_3: CMakeFiles/Assignment_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable Assignment_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment_3.dir/build: Assignment_3

.PHONY : CMakeFiles/Assignment_3.dir/build

CMakeFiles/Assignment_3.dir/requires: CMakeFiles/Assignment_3.dir/Part_A/raytracer/bmp_io.cpp.o.requires
CMakeFiles/Assignment_3.dir/requires: CMakeFiles/Assignment_3.dir/Part_A/raytracer/light_source.cpp.o.requires
CMakeFiles/Assignment_3.dir/requires: CMakeFiles/Assignment_3.dir/Part_A/raytracer/main.cpp.o.requires
CMakeFiles/Assignment_3.dir/requires: CMakeFiles/Assignment_3.dir/Part_A/raytracer/raytracer.cpp.o.requires
CMakeFiles/Assignment_3.dir/requires: CMakeFiles/Assignment_3.dir/Part_A/raytracer/scene_object.cpp.o.requires
CMakeFiles/Assignment_3.dir/requires: CMakeFiles/Assignment_3.dir/Part_A/raytracer/util.cpp.o.requires
CMakeFiles/Assignment_3.dir/requires: CMakeFiles/Assignment_3.dir/Part_B/raytracer/bmp_io.cpp.o.requires
CMakeFiles/Assignment_3.dir/requires: CMakeFiles/Assignment_3.dir/Part_B/raytracer/light_source.cpp.o.requires
CMakeFiles/Assignment_3.dir/requires: CMakeFiles/Assignment_3.dir/Part_B/raytracer/main.cpp.o.requires
CMakeFiles/Assignment_3.dir/requires: CMakeFiles/Assignment_3.dir/Part_B/raytracer/raytracer.cpp.o.requires
CMakeFiles/Assignment_3.dir/requires: CMakeFiles/Assignment_3.dir/Part_B/raytracer/scene_object.cpp.o.requires
CMakeFiles/Assignment_3.dir/requires: CMakeFiles/Assignment_3.dir/Part_B/raytracer/util.cpp.o.requires

.PHONY : CMakeFiles/Assignment_3.dir/requires

CMakeFiles/Assignment_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assignment_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assignment_3.dir/clean

CMakeFiles/Assignment_3.dir/depend:
	cd "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3" "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3" "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug" "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug" "/Users/loganrooks/Google Drive/Programming/git/CSC418/Assignment 3/cmake-build-debug/CMakeFiles/Assignment_3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Assignment_3.dir/depend

