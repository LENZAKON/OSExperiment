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
CMAKE_SOURCE_DIR = /home/linzikang/code/code/os/RAM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/linzikang/code/code/os/RAM/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RAM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RAM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RAM.dir/flags.make

CMakeFiles/RAM.dir/main.c.o: CMakeFiles/RAM.dir/flags.make
CMakeFiles/RAM.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linzikang/code/code/os/RAM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/RAM.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RAM.dir/main.c.o   -c /home/linzikang/code/code/os/RAM/main.c

CMakeFiles/RAM.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RAM.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/linzikang/code/code/os/RAM/main.c > CMakeFiles/RAM.dir/main.c.i

CMakeFiles/RAM.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RAM.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/linzikang/code/code/os/RAM/main.c -o CMakeFiles/RAM.dir/main.c.s

CMakeFiles/RAM.dir/main.c.o.requires:

.PHONY : CMakeFiles/RAM.dir/main.c.o.requires

CMakeFiles/RAM.dir/main.c.o.provides: CMakeFiles/RAM.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/RAM.dir/build.make CMakeFiles/RAM.dir/main.c.o.provides.build
.PHONY : CMakeFiles/RAM.dir/main.c.o.provides

CMakeFiles/RAM.dir/main.c.o.provides.build: CMakeFiles/RAM.dir/main.c.o


# Object files for target RAM
RAM_OBJECTS = \
"CMakeFiles/RAM.dir/main.c.o"

# External object files for target RAM
RAM_EXTERNAL_OBJECTS =

RAM: CMakeFiles/RAM.dir/main.c.o
RAM: CMakeFiles/RAM.dir/build.make
RAM: CMakeFiles/RAM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linzikang/code/code/os/RAM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable RAM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RAM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RAM.dir/build: RAM

.PHONY : CMakeFiles/RAM.dir/build

CMakeFiles/RAM.dir/requires: CMakeFiles/RAM.dir/main.c.o.requires

.PHONY : CMakeFiles/RAM.dir/requires

CMakeFiles/RAM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RAM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RAM.dir/clean

CMakeFiles/RAM.dir/depend:
	cd /home/linzikang/code/code/os/RAM/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linzikang/code/code/os/RAM /home/linzikang/code/code/os/RAM /home/linzikang/code/code/os/RAM/cmake-build-debug /home/linzikang/code/code/os/RAM/cmake-build-debug /home/linzikang/code/code/os/RAM/cmake-build-debug/CMakeFiles/RAM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RAM.dir/depend

