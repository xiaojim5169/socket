# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


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
CMAKE_COMMAND = /home/jin/cmake-3.17.0-rc1/bin/cmake

# The command to remove a file.
RM = /home/jin/cmake-3.17.0-rc1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/26451/Desktop/socket

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/26451/Desktop/socket/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/client4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client4.dir/flags.make

CMakeFiles/client4.dir/client.cpp.o: CMakeFiles/client4.dir/flags.make
CMakeFiles/client4.dir/client.cpp.o: ../client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/26451/Desktop/socket/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client4.dir/client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client4.dir/client.cpp.o -c /mnt/c/Users/26451/Desktop/socket/client.cpp

CMakeFiles/client4.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client4.dir/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/26451/Desktop/socket/client.cpp > CMakeFiles/client4.dir/client.cpp.i

CMakeFiles/client4.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client4.dir/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/26451/Desktop/socket/client.cpp -o CMakeFiles/client4.dir/client.cpp.s

CMakeFiles/client4.dir/common.cpp.o: CMakeFiles/client4.dir/flags.make
CMakeFiles/client4.dir/common.cpp.o: ../common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/26451/Desktop/socket/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/client4.dir/common.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client4.dir/common.cpp.o -c /mnt/c/Users/26451/Desktop/socket/common.cpp

CMakeFiles/client4.dir/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client4.dir/common.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/26451/Desktop/socket/common.cpp > CMakeFiles/client4.dir/common.cpp.i

CMakeFiles/client4.dir/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client4.dir/common.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/26451/Desktop/socket/common.cpp -o CMakeFiles/client4.dir/common.cpp.s

# Object files for target client4
client4_OBJECTS = \
"CMakeFiles/client4.dir/client.cpp.o" \
"CMakeFiles/client4.dir/common.cpp.o"

# External object files for target client4
client4_EXTERNAL_OBJECTS =

client4: CMakeFiles/client4.dir/client.cpp.o
client4: CMakeFiles/client4.dir/common.cpp.o
client4: CMakeFiles/client4.dir/build.make
client4: CMakeFiles/client4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/26451/Desktop/socket/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable client4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client4.dir/build: client4

.PHONY : CMakeFiles/client4.dir/build

CMakeFiles/client4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client4.dir/clean

CMakeFiles/client4.dir/depend:
	cd /mnt/c/Users/26451/Desktop/socket/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/26451/Desktop/socket /mnt/c/Users/26451/Desktop/socket /mnt/c/Users/26451/Desktop/socket/cmake-build-debug /mnt/c/Users/26451/Desktop/socket/cmake-build-debug /mnt/c/Users/26451/Desktop/socket/cmake-build-debug/CMakeFiles/client4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client4.dir/depend

