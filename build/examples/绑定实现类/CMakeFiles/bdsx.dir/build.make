# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /code/my/RCF/RCF_Example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /code/my/RCF/RCF_Example/build

# Include any dependencies generated for this target.
include examples/绑定实现类/CMakeFiles/bdsx.dir/depend.make

# Include the progress variables for this target.
include examples/绑定实现类/CMakeFiles/bdsx.dir/progress.make

# Include the compile flags for this target's objects.
include examples/绑定实现类/CMakeFiles/bdsx.dir/flags.make

examples/绑定实现类/CMakeFiles/bdsx.dir/main.cpp.o: examples/绑定实现类/CMakeFiles/bdsx.dir/flags.make
examples/绑定实现类/CMakeFiles/bdsx.dir/main.cpp.o: ../examples/绑定实现类/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/code/my/RCF/RCF_Example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/绑定实现类/CMakeFiles/bdsx.dir/main.cpp.o"
	cd /code/my/RCF/RCF_Example/build/examples/绑定实现类 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bdsx.dir/main.cpp.o -c /code/my/RCF/RCF_Example/examples/绑定实现类/main.cpp

examples/绑定实现类/CMakeFiles/bdsx.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bdsx.dir/main.cpp.i"
	cd /code/my/RCF/RCF_Example/build/examples/绑定实现类 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /code/my/RCF/RCF_Example/examples/绑定实现类/main.cpp > CMakeFiles/bdsx.dir/main.cpp.i

examples/绑定实现类/CMakeFiles/bdsx.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bdsx.dir/main.cpp.s"
	cd /code/my/RCF/RCF_Example/build/examples/绑定实现类 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /code/my/RCF/RCF_Example/examples/绑定实现类/main.cpp -o CMakeFiles/bdsx.dir/main.cpp.s

# Object files for target bdsx
bdsx_OBJECTS = \
"CMakeFiles/bdsx.dir/main.cpp.o"

# External object files for target bdsx
bdsx_EXTERNAL_OBJECTS =

examples/绑定实现类/bdsx: examples/绑定实现类/CMakeFiles/bdsx.dir/main.cpp.o
examples/绑定实现类/bdsx: examples/绑定实现类/CMakeFiles/bdsx.dir/build.make
examples/绑定实现类/bdsx: source/libRCF.a
examples/绑定实现类/bdsx: examples/绑定实现类/CMakeFiles/bdsx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/code/my/RCF/RCF_Example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bdsx"
	cd /code/my/RCF/RCF_Example/build/examples/绑定实现类 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bdsx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/绑定实现类/CMakeFiles/bdsx.dir/build: examples/绑定实现类/bdsx

.PHONY : examples/绑定实现类/CMakeFiles/bdsx.dir/build

examples/绑定实现类/CMakeFiles/bdsx.dir/clean:
	cd /code/my/RCF/RCF_Example/build/examples/绑定实现类 && $(CMAKE_COMMAND) -P CMakeFiles/bdsx.dir/cmake_clean.cmake
.PHONY : examples/绑定实现类/CMakeFiles/bdsx.dir/clean

examples/绑定实现类/CMakeFiles/bdsx.dir/depend:
	cd /code/my/RCF/RCF_Example/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /code/my/RCF/RCF_Example /code/my/RCF/RCF_Example/examples/绑定实现类 /code/my/RCF/RCF_Example/build /code/my/RCF/RCF_Example/build/examples/绑定实现类 /code/my/RCF/RCF_Example/build/examples/绑定实现类/CMakeFiles/bdsx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/绑定实现类/CMakeFiles/bdsx.dir/depend

