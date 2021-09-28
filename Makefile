# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.21.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.21.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/tonywu/Library/Mobile Documents/com~apple~CloudDocs/Programming/C-PDOS"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/tonywu/Library/Mobile Documents/com~apple~CloudDocs/Programming/C-PDOS"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/opt/homebrew/Cellar/cmake/3.21.2/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/opt/homebrew/Cellar/cmake/3.21.2/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/tonywu/Library/Mobile Documents/com~apple~CloudDocs/Programming/C-PDOS/CMakeFiles" "/Users/tonywu/Library/Mobile Documents/com~apple~CloudDocs/Programming/C-PDOS//CMakeFiles/progress.marks"
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/tonywu/Library/Mobile Documents/com~apple~CloudDocs/Programming/C-PDOS/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named dband_mp.o

# Build rule for target.
dband_mp.o: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 dband_mp.o
.PHONY : dband_mp.o

# fast build rule for target.
dband_mp.o/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dband_mp.o.dir/build.make CMakeFiles/dband_mp.o.dir/build
.PHONY : dband_mp.o/fast

src/calc_band.o: src/calc_band.c.o
.PHONY : src/calc_band.o

# target to build an object file
src/calc_band.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dband_mp.o.dir/build.make CMakeFiles/dband_mp.o.dir/src/calc_band.c.o
.PHONY : src/calc_band.c.o

src/calc_band.i: src/calc_band.c.i
.PHONY : src/calc_band.i

# target to preprocess a source file
src/calc_band.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dband_mp.o.dir/build.make CMakeFiles/dband_mp.o.dir/src/calc_band.c.i
.PHONY : src/calc_band.c.i

src/calc_band.s: src/calc_band.c.s
.PHONY : src/calc_band.s

# target to generate assembly for a file
src/calc_band.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dband_mp.o.dir/build.make CMakeFiles/dband_mp.o.dir/src/calc_band.c.s
.PHONY : src/calc_band.c.s

src/file.o: src/file.c.o
.PHONY : src/file.o

# target to build an object file
src/file.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dband_mp.o.dir/build.make CMakeFiles/dband_mp.o.dir/src/file.c.o
.PHONY : src/file.c.o

src/file.i: src/file.c.i
.PHONY : src/file.i

# target to preprocess a source file
src/file.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dband_mp.o.dir/build.make CMakeFiles/dband_mp.o.dir/src/file.c.i
.PHONY : src/file.c.i

src/file.s: src/file.c.s
.PHONY : src/file.s

# target to generate assembly for a file
src/file.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dband_mp.o.dir/build.make CMakeFiles/dband_mp.o.dir/src/file.c.s
.PHONY : src/file.c.s

src/main.o: src/main.c.o
.PHONY : src/main.o

# target to build an object file
src/main.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dband_mp.o.dir/build.make CMakeFiles/dband_mp.o.dir/src/main.c.o
.PHONY : src/main.c.o

src/main.i: src/main.c.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dband_mp.o.dir/build.make CMakeFiles/dband_mp.o.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dband_mp.o.dir/build.make CMakeFiles/dband_mp.o.dir/src/main.c.s
.PHONY : src/main.c.s

src/parse_xy.o: src/parse_xy.c.o
.PHONY : src/parse_xy.o

# target to build an object file
src/parse_xy.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dband_mp.o.dir/build.make CMakeFiles/dband_mp.o.dir/src/parse_xy.c.o
.PHONY : src/parse_xy.c.o

src/parse_xy.i: src/parse_xy.c.i
.PHONY : src/parse_xy.i

# target to preprocess a source file
src/parse_xy.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dband_mp.o.dir/build.make CMakeFiles/dband_mp.o.dir/src/parse_xy.c.i
.PHONY : src/parse_xy.c.i

src/parse_xy.s: src/parse_xy.c.s
.PHONY : src/parse_xy.s

# target to generate assembly for a file
src/parse_xy.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dband_mp.o.dir/build.make CMakeFiles/dband_mp.o.dir/src/parse_xy.c.s
.PHONY : src/parse_xy.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... dband_mp.o"
	@echo "... src/calc_band.o"
	@echo "... src/calc_band.i"
	@echo "... src/calc_band.s"
	@echo "... src/file.o"
	@echo "... src/file.i"
	@echo "... src/file.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/parse_xy.o"
	@echo "... src/parse_xy.i"
	@echo "... src/parse_xy.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

