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
CMAKE_COMMAND = /snap/clion/17/bin/cmake/bin/cmake

# The command to remove a file.
RM = /snap/clion/17/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/raytracer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/raytracer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raytracer.dir/flags.make

CMakeFiles/raytracer.dir/bmp_io.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/bmp_io.cpp.o: ../bmp_io.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/raytracer.dir/bmp_io.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/bmp_io.cpp.o -c "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/bmp_io.cpp"

CMakeFiles/raytracer.dir/bmp_io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/bmp_io.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/bmp_io.cpp" > CMakeFiles/raytracer.dir/bmp_io.cpp.i

CMakeFiles/raytracer.dir/bmp_io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/bmp_io.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/bmp_io.cpp" -o CMakeFiles/raytracer.dir/bmp_io.cpp.s

CMakeFiles/raytracer.dir/bmp_io.cpp.o.requires:

.PHONY : CMakeFiles/raytracer.dir/bmp_io.cpp.o.requires

CMakeFiles/raytracer.dir/bmp_io.cpp.o.provides: CMakeFiles/raytracer.dir/bmp_io.cpp.o.requires
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/bmp_io.cpp.o.provides.build
.PHONY : CMakeFiles/raytracer.dir/bmp_io.cpp.o.provides

CMakeFiles/raytracer.dir/bmp_io.cpp.o.provides.build: CMakeFiles/raytracer.dir/bmp_io.cpp.o


CMakeFiles/raytracer.dir/light_source.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/light_source.cpp.o: ../light_source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/raytracer.dir/light_source.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/light_source.cpp.o -c "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/light_source.cpp"

CMakeFiles/raytracer.dir/light_source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/light_source.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/light_source.cpp" > CMakeFiles/raytracer.dir/light_source.cpp.i

CMakeFiles/raytracer.dir/light_source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/light_source.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/light_source.cpp" -o CMakeFiles/raytracer.dir/light_source.cpp.s

CMakeFiles/raytracer.dir/light_source.cpp.o.requires:

.PHONY : CMakeFiles/raytracer.dir/light_source.cpp.o.requires

CMakeFiles/raytracer.dir/light_source.cpp.o.provides: CMakeFiles/raytracer.dir/light_source.cpp.o.requires
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/light_source.cpp.o.provides.build
.PHONY : CMakeFiles/raytracer.dir/light_source.cpp.o.provides

CMakeFiles/raytracer.dir/light_source.cpp.o.provides.build: CMakeFiles/raytracer.dir/light_source.cpp.o


CMakeFiles/raytracer.dir/main.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/raytracer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/main.cpp.o -c "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/main.cpp"

CMakeFiles/raytracer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/main.cpp" > CMakeFiles/raytracer.dir/main.cpp.i

CMakeFiles/raytracer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/main.cpp" -o CMakeFiles/raytracer.dir/main.cpp.s

CMakeFiles/raytracer.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/raytracer.dir/main.cpp.o.requires

CMakeFiles/raytracer.dir/main.cpp.o.provides: CMakeFiles/raytracer.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/raytracer.dir/main.cpp.o.provides

CMakeFiles/raytracer.dir/main.cpp.o.provides.build: CMakeFiles/raytracer.dir/main.cpp.o


CMakeFiles/raytracer.dir/raytracer.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/raytracer.cpp.o: ../raytracer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/raytracer.dir/raytracer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/raytracer.cpp.o -c "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/raytracer.cpp"

CMakeFiles/raytracer.dir/raytracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/raytracer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/raytracer.cpp" > CMakeFiles/raytracer.dir/raytracer.cpp.i

CMakeFiles/raytracer.dir/raytracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/raytracer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/raytracer.cpp" -o CMakeFiles/raytracer.dir/raytracer.cpp.s

CMakeFiles/raytracer.dir/raytracer.cpp.o.requires:

.PHONY : CMakeFiles/raytracer.dir/raytracer.cpp.o.requires

CMakeFiles/raytracer.dir/raytracer.cpp.o.provides: CMakeFiles/raytracer.dir/raytracer.cpp.o.requires
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/raytracer.cpp.o.provides.build
.PHONY : CMakeFiles/raytracer.dir/raytracer.cpp.o.provides

CMakeFiles/raytracer.dir/raytracer.cpp.o.provides.build: CMakeFiles/raytracer.dir/raytracer.cpp.o


CMakeFiles/raytracer.dir/scene_object.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/scene_object.cpp.o: ../scene_object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/raytracer.dir/scene_object.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/scene_object.cpp.o -c "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/scene_object.cpp"

CMakeFiles/raytracer.dir/scene_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/scene_object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/scene_object.cpp" > CMakeFiles/raytracer.dir/scene_object.cpp.i

CMakeFiles/raytracer.dir/scene_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/scene_object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/scene_object.cpp" -o CMakeFiles/raytracer.dir/scene_object.cpp.s

CMakeFiles/raytracer.dir/scene_object.cpp.o.requires:

.PHONY : CMakeFiles/raytracer.dir/scene_object.cpp.o.requires

CMakeFiles/raytracer.dir/scene_object.cpp.o.provides: CMakeFiles/raytracer.dir/scene_object.cpp.o.requires
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/scene_object.cpp.o.provides.build
.PHONY : CMakeFiles/raytracer.dir/scene_object.cpp.o.provides

CMakeFiles/raytracer.dir/scene_object.cpp.o.provides.build: CMakeFiles/raytracer.dir/scene_object.cpp.o


CMakeFiles/raytracer.dir/util.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/util.cpp.o: ../util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/raytracer.dir/util.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/util.cpp.o -c "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/util.cpp"

CMakeFiles/raytracer.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/util.cpp" > CMakeFiles/raytracer.dir/util.cpp.i

CMakeFiles/raytracer.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/util.cpp" -o CMakeFiles/raytracer.dir/util.cpp.s

CMakeFiles/raytracer.dir/util.cpp.o.requires:

.PHONY : CMakeFiles/raytracer.dir/util.cpp.o.requires

CMakeFiles/raytracer.dir/util.cpp.o.provides: CMakeFiles/raytracer.dir/util.cpp.o.requires
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/util.cpp.o.provides.build
.PHONY : CMakeFiles/raytracer.dir/util.cpp.o.provides

CMakeFiles/raytracer.dir/util.cpp.o.provides.build: CMakeFiles/raytracer.dir/util.cpp.o


CMakeFiles/raytracer.dir/scenes.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/scenes.cpp.o: ../scenes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/raytracer.dir/scenes.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/scenes.cpp.o -c "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/scenes.cpp"

CMakeFiles/raytracer.dir/scenes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/scenes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/scenes.cpp" > CMakeFiles/raytracer.dir/scenes.cpp.i

CMakeFiles/raytracer.dir/scenes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/scenes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/scenes.cpp" -o CMakeFiles/raytracer.dir/scenes.cpp.s

CMakeFiles/raytracer.dir/scenes.cpp.o.requires:

.PHONY : CMakeFiles/raytracer.dir/scenes.cpp.o.requires

CMakeFiles/raytracer.dir/scenes.cpp.o.provides: CMakeFiles/raytracer.dir/scenes.cpp.o.requires
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/scenes.cpp.o.provides.build
.PHONY : CMakeFiles/raytracer.dir/scenes.cpp.o.provides

CMakeFiles/raytracer.dir/scenes.cpp.o.provides.build: CMakeFiles/raytracer.dir/scenes.cpp.o


CMakeFiles/raytracer.dir/experiments.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/experiments.cpp.o: ../experiments.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/raytracer.dir/experiments.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/experiments.cpp.o -c "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/experiments.cpp"

CMakeFiles/raytracer.dir/experiments.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/experiments.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/experiments.cpp" > CMakeFiles/raytracer.dir/experiments.cpp.i

CMakeFiles/raytracer.dir/experiments.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/experiments.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/experiments.cpp" -o CMakeFiles/raytracer.dir/experiments.cpp.s

CMakeFiles/raytracer.dir/experiments.cpp.o.requires:

.PHONY : CMakeFiles/raytracer.dir/experiments.cpp.o.requires

CMakeFiles/raytracer.dir/experiments.cpp.o.provides: CMakeFiles/raytracer.dir/experiments.cpp.o.requires
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/experiments.cpp.o.provides.build
.PHONY : CMakeFiles/raytracer.dir/experiments.cpp.o.provides

CMakeFiles/raytracer.dir/experiments.cpp.o.provides.build: CMakeFiles/raytracer.dir/experiments.cpp.o


# Object files for target raytracer
raytracer_OBJECTS = \
"CMakeFiles/raytracer.dir/bmp_io.cpp.o" \
"CMakeFiles/raytracer.dir/light_source.cpp.o" \
"CMakeFiles/raytracer.dir/main.cpp.o" \
"CMakeFiles/raytracer.dir/raytracer.cpp.o" \
"CMakeFiles/raytracer.dir/scene_object.cpp.o" \
"CMakeFiles/raytracer.dir/util.cpp.o" \
"CMakeFiles/raytracer.dir/scenes.cpp.o" \
"CMakeFiles/raytracer.dir/experiments.cpp.o"

# External object files for target raytracer
raytracer_EXTERNAL_OBJECTS =

raytracer: CMakeFiles/raytracer.dir/bmp_io.cpp.o
raytracer: CMakeFiles/raytracer.dir/light_source.cpp.o
raytracer: CMakeFiles/raytracer.dir/main.cpp.o
raytracer: CMakeFiles/raytracer.dir/raytracer.cpp.o
raytracer: CMakeFiles/raytracer.dir/scene_object.cpp.o
raytracer: CMakeFiles/raytracer.dir/util.cpp.o
raytracer: CMakeFiles/raytracer.dir/scenes.cpp.o
raytracer: CMakeFiles/raytracer.dir/experiments.cpp.o
raytracer: CMakeFiles/raytracer.dir/build.make
raytracer: CMakeFiles/raytracer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable raytracer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raytracer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raytracer.dir/build: raytracer

.PHONY : CMakeFiles/raytracer.dir/build

CMakeFiles/raytracer.dir/requires: CMakeFiles/raytracer.dir/bmp_io.cpp.o.requires
CMakeFiles/raytracer.dir/requires: CMakeFiles/raytracer.dir/light_source.cpp.o.requires
CMakeFiles/raytracer.dir/requires: CMakeFiles/raytracer.dir/main.cpp.o.requires
CMakeFiles/raytracer.dir/requires: CMakeFiles/raytracer.dir/raytracer.cpp.o.requires
CMakeFiles/raytracer.dir/requires: CMakeFiles/raytracer.dir/scene_object.cpp.o.requires
CMakeFiles/raytracer.dir/requires: CMakeFiles/raytracer.dir/util.cpp.o.requires
CMakeFiles/raytracer.dir/requires: CMakeFiles/raytracer.dir/scenes.cpp.o.requires
CMakeFiles/raytracer.dir/requires: CMakeFiles/raytracer.dir/experiments.cpp.o.requires

.PHONY : CMakeFiles/raytracer.dir/requires

CMakeFiles/raytracer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raytracer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raytracer.dir/clean

CMakeFiles/raytracer.dir/depend:
	cd "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer" "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer" "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/cmake-build-debug" "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/cmake-build-debug" "/media/logan/Shared/code/school/CSC418/Assignment 3/Part B/raytracer/cmake-build-debug/CMakeFiles/raytracer.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/raytracer.dir/depend

