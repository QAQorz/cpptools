# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /snap/clion/81/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/81/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/qaqorz/pikagu/cpptools/csapp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qaqorz/pikagu/cpptools/csapp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/csapp10-7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/csapp10-7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/csapp10-7.dir/flags.make

CMakeFiles/csapp10-7.dir/csapp.c.o: CMakeFiles/csapp10-7.dir/flags.make
CMakeFiles/csapp10-7.dir/csapp.c.o: ../csapp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qaqorz/pikagu/cpptools/csapp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/csapp10-7.dir/csapp.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/csapp10-7.dir/csapp.c.o   -c /home/qaqorz/pikagu/cpptools/csapp/csapp.c

CMakeFiles/csapp10-7.dir/csapp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/csapp10-7.dir/csapp.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qaqorz/pikagu/cpptools/csapp/csapp.c > CMakeFiles/csapp10-7.dir/csapp.c.i

CMakeFiles/csapp10-7.dir/csapp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/csapp10-7.dir/csapp.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qaqorz/pikagu/cpptools/csapp/csapp.c -o CMakeFiles/csapp10-7.dir/csapp.c.s

CMakeFiles/csapp10-7.dir/10-7.c.o: CMakeFiles/csapp10-7.dir/flags.make
CMakeFiles/csapp10-7.dir/10-7.c.o: ../10-7.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qaqorz/pikagu/cpptools/csapp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/csapp10-7.dir/10-7.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/csapp10-7.dir/10-7.c.o   -c /home/qaqorz/pikagu/cpptools/csapp/10-7.c

CMakeFiles/csapp10-7.dir/10-7.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/csapp10-7.dir/10-7.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qaqorz/pikagu/cpptools/csapp/10-7.c > CMakeFiles/csapp10-7.dir/10-7.c.i

CMakeFiles/csapp10-7.dir/10-7.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/csapp10-7.dir/10-7.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qaqorz/pikagu/cpptools/csapp/10-7.c -o CMakeFiles/csapp10-7.dir/10-7.c.s

# Object files for target csapp10-7
csapp10__7_OBJECTS = \
"CMakeFiles/csapp10-7.dir/csapp.c.o" \
"CMakeFiles/csapp10-7.dir/10-7.c.o"

# External object files for target csapp10-7
csapp10__7_EXTERNAL_OBJECTS =

csapp10-7: CMakeFiles/csapp10-7.dir/csapp.c.o
csapp10-7: CMakeFiles/csapp10-7.dir/10-7.c.o
csapp10-7: CMakeFiles/csapp10-7.dir/build.make
csapp10-7: CMakeFiles/csapp10-7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qaqorz/pikagu/cpptools/csapp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable csapp10-7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/csapp10-7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/csapp10-7.dir/build: csapp10-7

.PHONY : CMakeFiles/csapp10-7.dir/build

CMakeFiles/csapp10-7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/csapp10-7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/csapp10-7.dir/clean

CMakeFiles/csapp10-7.dir/depend:
	cd /home/qaqorz/pikagu/cpptools/csapp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qaqorz/pikagu/cpptools/csapp /home/qaqorz/pikagu/cpptools/csapp /home/qaqorz/pikagu/cpptools/csapp/cmake-build-debug /home/qaqorz/pikagu/cpptools/csapp/cmake-build-debug /home/qaqorz/pikagu/cpptools/csapp/cmake-build-debug/CMakeFiles/csapp10-7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/csapp10-7.dir/depend

