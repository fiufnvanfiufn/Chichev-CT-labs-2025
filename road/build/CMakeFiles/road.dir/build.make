# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/van/git/Chichev-CT-labs-2025/road

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/van/git/Chichev-CT-labs-2025/road/build

# Include any dependencies generated for this target.
include CMakeFiles/road.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/road.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/road.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/road.dir/flags.make

CMakeFiles/road.dir/road.cpp.o: CMakeFiles/road.dir/flags.make
CMakeFiles/road.dir/road.cpp.o: /home/van/git/Chichev-CT-labs-2025/road/road.cpp
CMakeFiles/road.dir/road.cpp.o: CMakeFiles/road.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/van/git/Chichev-CT-labs-2025/road/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/road.dir/road.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/road.dir/road.cpp.o -MF CMakeFiles/road.dir/road.cpp.o.d -o CMakeFiles/road.dir/road.cpp.o -c /home/van/git/Chichev-CT-labs-2025/road/road.cpp

CMakeFiles/road.dir/road.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/road.dir/road.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/van/git/Chichev-CT-labs-2025/road/road.cpp > CMakeFiles/road.dir/road.cpp.i

CMakeFiles/road.dir/road.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/road.dir/road.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/van/git/Chichev-CT-labs-2025/road/road.cpp -o CMakeFiles/road.dir/road.cpp.s

# Object files for target road
road_OBJECTS = \
"CMakeFiles/road.dir/road.cpp.o"

# External object files for target road
road_EXTERNAL_OBJECTS =

libroad.a: CMakeFiles/road.dir/road.cpp.o
libroad.a: CMakeFiles/road.dir/build.make
libroad.a: CMakeFiles/road.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/van/git/Chichev-CT-labs-2025/road/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libroad.a"
	$(CMAKE_COMMAND) -P CMakeFiles/road.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/road.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/road.dir/build: libroad.a
.PHONY : CMakeFiles/road.dir/build

CMakeFiles/road.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/road.dir/cmake_clean.cmake
.PHONY : CMakeFiles/road.dir/clean

CMakeFiles/road.dir/depend:
	cd /home/van/git/Chichev-CT-labs-2025/road/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/van/git/Chichev-CT-labs-2025/road /home/van/git/Chichev-CT-labs-2025/road /home/van/git/Chichev-CT-labs-2025/road/build /home/van/git/Chichev-CT-labs-2025/road/build /home/van/git/Chichev-CT-labs-2025/road/build/CMakeFiles/road.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/road.dir/depend

