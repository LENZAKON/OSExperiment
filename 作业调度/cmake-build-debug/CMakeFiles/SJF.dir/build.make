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
CMAKE_SOURCE_DIR = /home/linzikang/code/code/os/SJF

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/linzikang/code/code/os/SJF/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SJF.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SJF.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SJF.dir/flags.make

CMakeFiles/SJF.dir/main.c.o: CMakeFiles/SJF.dir/flags.make
CMakeFiles/SJF.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linzikang/code/code/os/SJF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SJF.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SJF.dir/main.c.o   -c /home/linzikang/code/code/os/SJF/main.c

CMakeFiles/SJF.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SJF.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/linzikang/code/code/os/SJF/main.c > CMakeFiles/SJF.dir/main.c.i

CMakeFiles/SJF.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SJF.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/linzikang/code/code/os/SJF/main.c -o CMakeFiles/SJF.dir/main.c.s

CMakeFiles/SJF.dir/main.c.o.requires:

.PHONY : CMakeFiles/SJF.dir/main.c.o.requires

CMakeFiles/SJF.dir/main.c.o.provides: CMakeFiles/SJF.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/SJF.dir/build.make CMakeFiles/SJF.dir/main.c.o.provides.build
.PHONY : CMakeFiles/SJF.dir/main.c.o.provides

CMakeFiles/SJF.dir/main.c.o.provides.build: CMakeFiles/SJF.dir/main.c.o


# Object files for target SJF
SJF_OBJECTS = \
"CMakeFiles/SJF.dir/main.c.o"

# External object files for target SJF
SJF_EXTERNAL_OBJECTS =

SJF: CMakeFiles/SJF.dir/main.c.o
SJF: CMakeFiles/SJF.dir/build.make
SJF: CMakeFiles/SJF.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linzikang/code/code/os/SJF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SJF"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SJF.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SJF.dir/build: SJF

.PHONY : CMakeFiles/SJF.dir/build

CMakeFiles/SJF.dir/requires: CMakeFiles/SJF.dir/main.c.o.requires

.PHONY : CMakeFiles/SJF.dir/requires

CMakeFiles/SJF.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SJF.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SJF.dir/clean

CMakeFiles/SJF.dir/depend:
	cd /home/linzikang/code/code/os/SJF/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linzikang/code/code/os/SJF /home/linzikang/code/code/os/SJF /home/linzikang/code/code/os/SJF/cmake-build-debug /home/linzikang/code/code/os/SJF/cmake-build-debug /home/linzikang/code/code/os/SJF/cmake-build-debug/CMakeFiles/SJF.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SJF.dir/depend

