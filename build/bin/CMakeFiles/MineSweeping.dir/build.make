# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hanxi/cpp/MineSweeping

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hanxi/cpp/MineSweeping/build

# Include any dependencies generated for this target.
include bin/CMakeFiles/MineSweeping.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/MineSweeping.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/MineSweeping.dir/flags.make

bin/CMakeFiles/MineSweeping.dir/main.o: bin/CMakeFiles/MineSweeping.dir/flags.make
bin/CMakeFiles/MineSweeping.dir/main.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hanxi/cpp/MineSweeping/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/CMakeFiles/MineSweeping.dir/main.o"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MineSweeping.dir/main.o -c /home/hanxi/cpp/MineSweeping/src/main.cpp

bin/CMakeFiles/MineSweeping.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MineSweeping.dir/main.i"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hanxi/cpp/MineSweeping/src/main.cpp > CMakeFiles/MineSweeping.dir/main.i

bin/CMakeFiles/MineSweeping.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MineSweeping.dir/main.s"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hanxi/cpp/MineSweeping/src/main.cpp -o CMakeFiles/MineSweeping.dir/main.s

bin/CMakeFiles/MineSweeping.dir/main.o.requires:
.PHONY : bin/CMakeFiles/MineSweeping.dir/main.o.requires

bin/CMakeFiles/MineSweeping.dir/main.o.provides: bin/CMakeFiles/MineSweeping.dir/main.o.requires
	$(MAKE) -f bin/CMakeFiles/MineSweeping.dir/build.make bin/CMakeFiles/MineSweeping.dir/main.o.provides.build
.PHONY : bin/CMakeFiles/MineSweeping.dir/main.o.provides

bin/CMakeFiles/MineSweeping.dir/main.o.provides.build: bin/CMakeFiles/MineSweeping.dir/main.o
.PHONY : bin/CMakeFiles/MineSweeping.dir/main.o.provides.build

bin/CMakeFiles/MineSweeping.dir/globalVal.o: bin/CMakeFiles/MineSweeping.dir/flags.make
bin/CMakeFiles/MineSweeping.dir/globalVal.o: ../src/globalVal.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hanxi/cpp/MineSweeping/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/CMakeFiles/MineSweeping.dir/globalVal.o"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MineSweeping.dir/globalVal.o -c /home/hanxi/cpp/MineSweeping/src/globalVal.cpp

bin/CMakeFiles/MineSweeping.dir/globalVal.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MineSweeping.dir/globalVal.i"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hanxi/cpp/MineSweeping/src/globalVal.cpp > CMakeFiles/MineSweeping.dir/globalVal.i

bin/CMakeFiles/MineSweeping.dir/globalVal.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MineSweeping.dir/globalVal.s"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hanxi/cpp/MineSweeping/src/globalVal.cpp -o CMakeFiles/MineSweeping.dir/globalVal.s

bin/CMakeFiles/MineSweeping.dir/globalVal.o.requires:
.PHONY : bin/CMakeFiles/MineSweeping.dir/globalVal.o.requires

bin/CMakeFiles/MineSweeping.dir/globalVal.o.provides: bin/CMakeFiles/MineSweeping.dir/globalVal.o.requires
	$(MAKE) -f bin/CMakeFiles/MineSweeping.dir/build.make bin/CMakeFiles/MineSweeping.dir/globalVal.o.provides.build
.PHONY : bin/CMakeFiles/MineSweeping.dir/globalVal.o.provides

bin/CMakeFiles/MineSweeping.dir/globalVal.o.provides.build: bin/CMakeFiles/MineSweeping.dir/globalVal.o
.PHONY : bin/CMakeFiles/MineSweeping.dir/globalVal.o.provides.build

bin/CMakeFiles/MineSweeping.dir/core/Mines.o: bin/CMakeFiles/MineSweeping.dir/flags.make
bin/CMakeFiles/MineSweeping.dir/core/Mines.o: ../src/core/Mines.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hanxi/cpp/MineSweeping/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/CMakeFiles/MineSweeping.dir/core/Mines.o"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MineSweeping.dir/core/Mines.o -c /home/hanxi/cpp/MineSweeping/src/core/Mines.cpp

bin/CMakeFiles/MineSweeping.dir/core/Mines.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MineSweeping.dir/core/Mines.i"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hanxi/cpp/MineSweeping/src/core/Mines.cpp > CMakeFiles/MineSweeping.dir/core/Mines.i

bin/CMakeFiles/MineSweeping.dir/core/Mines.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MineSweeping.dir/core/Mines.s"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hanxi/cpp/MineSweeping/src/core/Mines.cpp -o CMakeFiles/MineSweeping.dir/core/Mines.s

bin/CMakeFiles/MineSweeping.dir/core/Mines.o.requires:
.PHONY : bin/CMakeFiles/MineSweeping.dir/core/Mines.o.requires

bin/CMakeFiles/MineSweeping.dir/core/Mines.o.provides: bin/CMakeFiles/MineSweeping.dir/core/Mines.o.requires
	$(MAKE) -f bin/CMakeFiles/MineSweeping.dir/build.make bin/CMakeFiles/MineSweeping.dir/core/Mines.o.provides.build
.PHONY : bin/CMakeFiles/MineSweeping.dir/core/Mines.o.provides

bin/CMakeFiles/MineSweeping.dir/core/Mines.o.provides.build: bin/CMakeFiles/MineSweeping.dir/core/Mines.o
.PHONY : bin/CMakeFiles/MineSweeping.dir/core/Mines.o.provides.build

bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.o: bin/CMakeFiles/MineSweeping.dir/flags.make
bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.o: ../src/core/SweepInterface.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hanxi/cpp/MineSweeping/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.o"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MineSweeping.dir/core/SweepInterface.o -c /home/hanxi/cpp/MineSweeping/src/core/SweepInterface.cpp

bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MineSweeping.dir/core/SweepInterface.i"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hanxi/cpp/MineSweeping/src/core/SweepInterface.cpp > CMakeFiles/MineSweeping.dir/core/SweepInterface.i

bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MineSweeping.dir/core/SweepInterface.s"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hanxi/cpp/MineSweeping/src/core/SweepInterface.cpp -o CMakeFiles/MineSweeping.dir/core/SweepInterface.s

bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.o.requires:
.PHONY : bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.o.requires

bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.o.provides: bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.o.requires
	$(MAKE) -f bin/CMakeFiles/MineSweeping.dir/build.make bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.o.provides.build
.PHONY : bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.o.provides

bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.o.provides.build: bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.o
.PHONY : bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.o.provides.build

bin/CMakeFiles/MineSweeping.dir/gui/GameObject.o: bin/CMakeFiles/MineSweeping.dir/flags.make
bin/CMakeFiles/MineSweeping.dir/gui/GameObject.o: ../src/gui/GameObject.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hanxi/cpp/MineSweeping/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/CMakeFiles/MineSweeping.dir/gui/GameObject.o"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MineSweeping.dir/gui/GameObject.o -c /home/hanxi/cpp/MineSweeping/src/gui/GameObject.cpp

bin/CMakeFiles/MineSweeping.dir/gui/GameObject.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MineSweeping.dir/gui/GameObject.i"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hanxi/cpp/MineSweeping/src/gui/GameObject.cpp > CMakeFiles/MineSweeping.dir/gui/GameObject.i

bin/CMakeFiles/MineSweeping.dir/gui/GameObject.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MineSweeping.dir/gui/GameObject.s"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hanxi/cpp/MineSweeping/src/gui/GameObject.cpp -o CMakeFiles/MineSweeping.dir/gui/GameObject.s

bin/CMakeFiles/MineSweeping.dir/gui/GameObject.o.requires:
.PHONY : bin/CMakeFiles/MineSweeping.dir/gui/GameObject.o.requires

bin/CMakeFiles/MineSweeping.dir/gui/GameObject.o.provides: bin/CMakeFiles/MineSweeping.dir/gui/GameObject.o.requires
	$(MAKE) -f bin/CMakeFiles/MineSweeping.dir/build.make bin/CMakeFiles/MineSweeping.dir/gui/GameObject.o.provides.build
.PHONY : bin/CMakeFiles/MineSweeping.dir/gui/GameObject.o.provides

bin/CMakeFiles/MineSweeping.dir/gui/GameObject.o.provides.build: bin/CMakeFiles/MineSweeping.dir/gui/GameObject.o
.PHONY : bin/CMakeFiles/MineSweeping.dir/gui/GameObject.o.provides.build

bin/CMakeFiles/MineSweeping.dir/gui/gui.o: bin/CMakeFiles/MineSweeping.dir/flags.make
bin/CMakeFiles/MineSweeping.dir/gui/gui.o: ../src/gui/gui.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hanxi/cpp/MineSweeping/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/CMakeFiles/MineSweeping.dir/gui/gui.o"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MineSweeping.dir/gui/gui.o -c /home/hanxi/cpp/MineSweeping/src/gui/gui.cpp

bin/CMakeFiles/MineSweeping.dir/gui/gui.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MineSweeping.dir/gui/gui.i"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hanxi/cpp/MineSweeping/src/gui/gui.cpp > CMakeFiles/MineSweeping.dir/gui/gui.i

bin/CMakeFiles/MineSweeping.dir/gui/gui.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MineSweeping.dir/gui/gui.s"
	cd /home/hanxi/cpp/MineSweeping/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hanxi/cpp/MineSweeping/src/gui/gui.cpp -o CMakeFiles/MineSweeping.dir/gui/gui.s

bin/CMakeFiles/MineSweeping.dir/gui/gui.o.requires:
.PHONY : bin/CMakeFiles/MineSweeping.dir/gui/gui.o.requires

bin/CMakeFiles/MineSweeping.dir/gui/gui.o.provides: bin/CMakeFiles/MineSweeping.dir/gui/gui.o.requires
	$(MAKE) -f bin/CMakeFiles/MineSweeping.dir/build.make bin/CMakeFiles/MineSweeping.dir/gui/gui.o.provides.build
.PHONY : bin/CMakeFiles/MineSweeping.dir/gui/gui.o.provides

bin/CMakeFiles/MineSweeping.dir/gui/gui.o.provides.build: bin/CMakeFiles/MineSweeping.dir/gui/gui.o
.PHONY : bin/CMakeFiles/MineSweeping.dir/gui/gui.o.provides.build

# Object files for target MineSweeping
MineSweeping_OBJECTS = \
"CMakeFiles/MineSweeping.dir/main.o" \
"CMakeFiles/MineSweeping.dir/globalVal.o" \
"CMakeFiles/MineSweeping.dir/core/Mines.o" \
"CMakeFiles/MineSweeping.dir/core/SweepInterface.o" \
"CMakeFiles/MineSweeping.dir/gui/GameObject.o" \
"CMakeFiles/MineSweeping.dir/gui/gui.o"

# External object files for target MineSweeping
MineSweeping_EXTERNAL_OBJECTS =

bin/MineSweeping: bin/CMakeFiles/MineSweeping.dir/main.o
bin/MineSweeping: bin/CMakeFiles/MineSweeping.dir/globalVal.o
bin/MineSweeping: bin/CMakeFiles/MineSweeping.dir/core/Mines.o
bin/MineSweeping: bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.o
bin/MineSweeping: bin/CMakeFiles/MineSweeping.dir/gui/GameObject.o
bin/MineSweeping: bin/CMakeFiles/MineSweeping.dir/gui/gui.o
bin/MineSweeping: bin/CMakeFiles/MineSweeping.dir/build.make
bin/MineSweeping: bin/CMakeFiles/MineSweeping.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable MineSweeping"
	cd /home/hanxi/cpp/MineSweeping/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MineSweeping.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/MineSweeping.dir/build: bin/MineSweeping
.PHONY : bin/CMakeFiles/MineSweeping.dir/build

bin/CMakeFiles/MineSweeping.dir/requires: bin/CMakeFiles/MineSweeping.dir/main.o.requires
bin/CMakeFiles/MineSweeping.dir/requires: bin/CMakeFiles/MineSweeping.dir/globalVal.o.requires
bin/CMakeFiles/MineSweeping.dir/requires: bin/CMakeFiles/MineSweeping.dir/core/Mines.o.requires
bin/CMakeFiles/MineSweeping.dir/requires: bin/CMakeFiles/MineSweeping.dir/core/SweepInterface.o.requires
bin/CMakeFiles/MineSweeping.dir/requires: bin/CMakeFiles/MineSweeping.dir/gui/GameObject.o.requires
bin/CMakeFiles/MineSweeping.dir/requires: bin/CMakeFiles/MineSweeping.dir/gui/gui.o.requires
.PHONY : bin/CMakeFiles/MineSweeping.dir/requires

bin/CMakeFiles/MineSweeping.dir/clean:
	cd /home/hanxi/cpp/MineSweeping/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/MineSweeping.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/MineSweeping.dir/clean

bin/CMakeFiles/MineSweeping.dir/depend:
	cd /home/hanxi/cpp/MineSweeping/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hanxi/cpp/MineSweeping /home/hanxi/cpp/MineSweeping/src /home/hanxi/cpp/MineSweeping/build /home/hanxi/cpp/MineSweeping/build/bin /home/hanxi/cpp/MineSweeping/build/bin/CMakeFiles/MineSweeping.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/MineSweeping.dir/depend
