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
CMAKE_COMMAND = /opt/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/linzikang/code/code/os/FCFS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/linzikang/code/code/os/FCFS/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FCFS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FCFS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FCFS.dir/flags.make

CMakeFiles/FCFS.dir/main.c.o: CMakeFiles/FCFS.dir/flags.make
CMakeFiles/FCFS.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linzikang/code/code/os/FCFS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/FCFS.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FCFS.dir/main.c.o   -c /home/linzikang/code/code/os/FCFS/main.c

CMakeFiles/FCFS.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FCFS.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/linzikang/code/code/os/FCFS/main.c > CMakeFiles/FCFS.dir/main.c.i

CMakeFiles/FCFS.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FCFS.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/linzikang/code/code/os/FCFS/main.c -o CMakeFiles/FCFS.dir/main.c.s

CMakeFiles/FCFS.dir/main.c.o.requires:

.PHONY : CMakeFiles/FCFS.dir/main.c.o.requires

CMakeFiles/FCFS.dir/main.c.o.provides: CMakeFiles/FCFS.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/FCFS.dir/build.make CMakeFiles/FCFS.dir/main.c.o.provides.build
.PHONY : CMakeFiles/FCFS.dir/main.c.o.provides

CMakeFiles/FCFS.dir/main.c.o.provides.build: CMakeFiles/FCFS.dir/main.c.o


# Object files for target FCFS
FCFS_OBJECTS = \
"CMakeFiles/FCFS.dir/main.c.o"

# External object files for target FCFS
FCFS_EXTERNAL_OBJECTS =

FCFS: CMakeFiles/FCFS.dir/main.c.o
FCFS: CMakeFiles/FCFS.dir/build.make
FCFS: CMakeFiles/FCFS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linzikang/code/code/os/FCFS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable FCFS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FCFS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FCFS.dir/build: FCFS

.PHONY : CMakeFiles/FCFS.dir/build

CMakeFiles/FCFS.dir/requires: CMakeFiles/FCFS.dir/main.c.o.requires

.PHONY : CMakeFiles/FCFS.dir/requires

CMakeFiles/FCFS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FCFS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FCFS.dir/clean

CMakeFiles/FCFS.dir/depend:
	cd /home/linzikang/code/code/os/FCFS/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linzikang/code/code/os/FCFS /home/linzikang/code/code/os/FCFS /home/linzikang/code/code/os/FCFS/cmake-build-debug /home/linzikang/code/code/os/FCFS/cmake-build-debug /home/linzikang/code/code/os/FCFS/cmake-build-debug/CMakeFiles/FCFS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FCFS.dir/depend

