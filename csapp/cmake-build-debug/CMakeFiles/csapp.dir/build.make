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
include CMakeFiles/csapp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/csapp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/csapp.dir/flags.make

CMakeFiles/csapp.dir/main.cpp.o: CMakeFiles/csapp.dir/flags.make
CMakeFiles/csapp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qaqorz/pikagu/cpptools/csapp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/csapp.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/csapp.dir/main.cpp.o -c /home/qaqorz/pikagu/cpptools/csapp/main.cpp

CMakeFiles/csapp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/csapp.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qaqorz/pikagu/cpptools/csapp/main.cpp > CMakeFiles/csapp.dir/main.cpp.i

CMakeFiles/csapp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/csapp.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qaqorz/pikagu/cpptools/csapp/main.cpp -o CMakeFiles/csapp.dir/main.cpp.s

# Object files for target csapp
csapp_OBJECTS = \
"CMakeFiles/csapp.dir/main.cpp.o"

# External object files for target csapp
csapp_EXTERNAL_OBJECTS =

csapp: CMakeFiles/csapp.dir/main.cpp.o
csapp: CMakeFiles/csapp.dir/build.make
csapp: CMakeFiles/csapp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qaqorz/pikagu/cpptools/csapp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable csapp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/csapp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/csapp.dir/build: csapp

.PHONY : CMakeFiles/csapp.dir/build

CMakeFiles/csapp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/csapp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/csapp.dir/clean

CMakeFiles/csapp.dir/depend:
	cd /home/qaqorz/pikagu/cpptools/csapp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qaqorz/pikagu/cpptools/csapp /home/qaqorz/pikagu/cpptools/csapp /home/qaqorz/pikagu/cpptools/csapp/cmake-build-debug /home/qaqorz/pikagu/cpptools/csapp/cmake-build-debug /home/qaqorz/pikagu/cpptools/csapp/cmake-build-debug/CMakeFiles/csapp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/csapp.dir/depend

