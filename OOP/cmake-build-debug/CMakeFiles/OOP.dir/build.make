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


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shakhinn/CLionProjects/OOP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shakhinn/CLionProjects/OOP/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OOP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OOP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OOP.dir/flags.make

CMakeFiles/OOP.dir/main.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OOP.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/main.cpp.o -c /home/shakhinn/CLionProjects/OOP/main.cpp

CMakeFiles/OOP.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/main.cpp > CMakeFiles/OOP.dir/main.cpp.i

CMakeFiles/OOP.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/main.cpp -o CMakeFiles/OOP.dir/main.cpp.s

CMakeFiles/OOP.dir/Model/Field.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/Model/Field.cpp.o: ../Model/Field.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OOP.dir/Model/Field.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/Model/Field.cpp.o -c /home/shakhinn/CLionProjects/OOP/Model/Field.cpp

CMakeFiles/OOP.dir/Model/Field.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/Model/Field.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/Model/Field.cpp > CMakeFiles/OOP.dir/Model/Field.cpp.i

CMakeFiles/OOP.dir/Model/Field.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/Model/Field.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/Model/Field.cpp -o CMakeFiles/OOP.dir/Model/Field.cpp.s

CMakeFiles/OOP.dir/Model/Cell.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/Model/Cell.cpp.o: ../Model/Cell.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OOP.dir/Model/Cell.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/Model/Cell.cpp.o -c /home/shakhinn/CLionProjects/OOP/Model/Cell.cpp

CMakeFiles/OOP.dir/Model/Cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/Model/Cell.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/Model/Cell.cpp > CMakeFiles/OOP.dir/Model/Cell.cpp.i

CMakeFiles/OOP.dir/Model/Cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/Model/Cell.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/Model/Cell.cpp -o CMakeFiles/OOP.dir/Model/Cell.cpp.s

CMakeFiles/OOP.dir/Model/Player.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/Model/Player.cpp.o: ../Model/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OOP.dir/Model/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/Model/Player.cpp.o -c /home/shakhinn/CLionProjects/OOP/Model/Player.cpp

CMakeFiles/OOP.dir/Model/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/Model/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/Model/Player.cpp > CMakeFiles/OOP.dir/Model/Player.cpp.i

CMakeFiles/OOP.dir/Model/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/Model/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/Model/Player.cpp -o CMakeFiles/OOP.dir/Model/Player.cpp.s

CMakeFiles/OOP.dir/Model/Object.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/Model/Object.cpp.o: ../Model/Object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OOP.dir/Model/Object.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/Model/Object.cpp.o -c /home/shakhinn/CLionProjects/OOP/Model/Object.cpp

CMakeFiles/OOP.dir/Model/Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/Model/Object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/Model/Object.cpp > CMakeFiles/OOP.dir/Model/Object.cpp.i

CMakeFiles/OOP.dir/Model/Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/Model/Object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/Model/Object.cpp -o CMakeFiles/OOP.dir/Model/Object.cpp.s

CMakeFiles/OOP.dir/Controller/Controller.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/Controller/Controller.cpp.o: ../Controller/Controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/OOP.dir/Controller/Controller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/Controller/Controller.cpp.o -c /home/shakhinn/CLionProjects/OOP/Controller/Controller.cpp

CMakeFiles/OOP.dir/Controller/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/Controller/Controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/Controller/Controller.cpp > CMakeFiles/OOP.dir/Controller/Controller.cpp.i

CMakeFiles/OOP.dir/Controller/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/Controller/Controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/Controller/Controller.cpp -o CMakeFiles/OOP.dir/Controller/Controller.cpp.s

CMakeFiles/OOP.dir/View/View.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/View/View.cpp.o: ../View/View.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/OOP.dir/View/View.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/View/View.cpp.o -c /home/shakhinn/CLionProjects/OOP/View/View.cpp

CMakeFiles/OOP.dir/View/View.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/View/View.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/View/View.cpp > CMakeFiles/OOP.dir/View/View.cpp.i

CMakeFiles/OOP.dir/View/View.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/View/View.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/View/View.cpp -o CMakeFiles/OOP.dir/View/View.cpp.s

CMakeFiles/OOP.dir/Model/Objects/CoinObject.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/Model/Objects/CoinObject.cpp.o: ../Model/Objects/CoinObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/OOP.dir/Model/Objects/CoinObject.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/Model/Objects/CoinObject.cpp.o -c /home/shakhinn/CLionProjects/OOP/Model/Objects/CoinObject.cpp

CMakeFiles/OOP.dir/Model/Objects/CoinObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/Model/Objects/CoinObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/Model/Objects/CoinObject.cpp > CMakeFiles/OOP.dir/Model/Objects/CoinObject.cpp.i

CMakeFiles/OOP.dir/Model/Objects/CoinObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/Model/Objects/CoinObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/Model/Objects/CoinObject.cpp -o CMakeFiles/OOP.dir/Model/Objects/CoinObject.cpp.s

CMakeFiles/OOP.dir/Model/Objects/ExitObject.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/Model/Objects/ExitObject.cpp.o: ../Model/Objects/ExitObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/OOP.dir/Model/Objects/ExitObject.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/Model/Objects/ExitObject.cpp.o -c /home/shakhinn/CLionProjects/OOP/Model/Objects/ExitObject.cpp

CMakeFiles/OOP.dir/Model/Objects/ExitObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/Model/Objects/ExitObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/Model/Objects/ExitObject.cpp > CMakeFiles/OOP.dir/Model/Objects/ExitObject.cpp.i

CMakeFiles/OOP.dir/Model/Objects/ExitObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/Model/Objects/ExitObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/Model/Objects/ExitObject.cpp -o CMakeFiles/OOP.dir/Model/Objects/ExitObject.cpp.s

CMakeFiles/OOP.dir/Model/Objects/EntranceObject.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/Model/Objects/EntranceObject.cpp.o: ../Model/Objects/EntranceObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/OOP.dir/Model/Objects/EntranceObject.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/Model/Objects/EntranceObject.cpp.o -c /home/shakhinn/CLionProjects/OOP/Model/Objects/EntranceObject.cpp

CMakeFiles/OOP.dir/Model/Objects/EntranceObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/Model/Objects/EntranceObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/Model/Objects/EntranceObject.cpp > CMakeFiles/OOP.dir/Model/Objects/EntranceObject.cpp.i

CMakeFiles/OOP.dir/Model/Objects/EntranceObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/Model/Objects/EntranceObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/Model/Objects/EntranceObject.cpp -o CMakeFiles/OOP.dir/Model/Objects/EntranceObject.cpp.s

CMakeFiles/OOP.dir/Model/Objects/BombObject.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/Model/Objects/BombObject.cpp.o: ../Model/Objects/BombObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/OOP.dir/Model/Objects/BombObject.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/Model/Objects/BombObject.cpp.o -c /home/shakhinn/CLionProjects/OOP/Model/Objects/BombObject.cpp

CMakeFiles/OOP.dir/Model/Objects/BombObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/Model/Objects/BombObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/Model/Objects/BombObject.cpp > CMakeFiles/OOP.dir/Model/Objects/BombObject.cpp.i

CMakeFiles/OOP.dir/Model/Objects/BombObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/Model/Objects/BombObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/Model/Objects/BombObject.cpp -o CMakeFiles/OOP.dir/Model/Objects/BombObject.cpp.s

CMakeFiles/OOP.dir/Model/Objects/TeleportObject.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/Model/Objects/TeleportObject.cpp.o: ../Model/Objects/TeleportObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/OOP.dir/Model/Objects/TeleportObject.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/Model/Objects/TeleportObject.cpp.o -c /home/shakhinn/CLionProjects/OOP/Model/Objects/TeleportObject.cpp

CMakeFiles/OOP.dir/Model/Objects/TeleportObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/Model/Objects/TeleportObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/Model/Objects/TeleportObject.cpp > CMakeFiles/OOP.dir/Model/Objects/TeleportObject.cpp.i

CMakeFiles/OOP.dir/Model/Objects/TeleportObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/Model/Objects/TeleportObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/Model/Objects/TeleportObject.cpp -o CMakeFiles/OOP.dir/Model/Objects/TeleportObject.cpp.s

CMakeFiles/OOP.dir/Model/Loggers/logger.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/Model/Loggers/logger.cpp.o: ../Model/Loggers/logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/OOP.dir/Model/Loggers/logger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/Model/Loggers/logger.cpp.o -c /home/shakhinn/CLionProjects/OOP/Model/Loggers/logger.cpp

CMakeFiles/OOP.dir/Model/Loggers/logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/Model/Loggers/logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/Model/Loggers/logger.cpp > CMakeFiles/OOP.dir/Model/Loggers/logger.cpp.i

CMakeFiles/OOP.dir/Model/Loggers/logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/Model/Loggers/logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/Model/Loggers/logger.cpp -o CMakeFiles/OOP.dir/Model/Loggers/logger.cpp.s

CMakeFiles/OOP.dir/Model/Loggers/ConsolLogger.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/Model/Loggers/ConsolLogger.cpp.o: ../Model/Loggers/ConsolLogger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/OOP.dir/Model/Loggers/ConsolLogger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/Model/Loggers/ConsolLogger.cpp.o -c /home/shakhinn/CLionProjects/OOP/Model/Loggers/ConsolLogger.cpp

CMakeFiles/OOP.dir/Model/Loggers/ConsolLogger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/Model/Loggers/ConsolLogger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/Model/Loggers/ConsolLogger.cpp > CMakeFiles/OOP.dir/Model/Loggers/ConsolLogger.cpp.i

CMakeFiles/OOP.dir/Model/Loggers/ConsolLogger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/Model/Loggers/ConsolLogger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/Model/Loggers/ConsolLogger.cpp -o CMakeFiles/OOP.dir/Model/Loggers/ConsolLogger.cpp.s

CMakeFiles/OOP.dir/Model/Loggers/FileLogger.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/Model/Loggers/FileLogger.cpp.o: ../Model/Loggers/FileLogger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/OOP.dir/Model/Loggers/FileLogger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/Model/Loggers/FileLogger.cpp.o -c /home/shakhinn/CLionProjects/OOP/Model/Loggers/FileLogger.cpp

CMakeFiles/OOP.dir/Model/Loggers/FileLogger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/Model/Loggers/FileLogger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/Model/Loggers/FileLogger.cpp > CMakeFiles/OOP.dir/Model/Loggers/FileLogger.cpp.i

CMakeFiles/OOP.dir/Model/Loggers/FileLogger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/Model/Loggers/FileLogger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/Model/Loggers/FileLogger.cpp -o CMakeFiles/OOP.dir/Model/Loggers/FileLogger.cpp.s

CMakeFiles/OOP.dir/Model/Loggers/Publisher.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/Model/Loggers/Publisher.cpp.o: ../Model/Loggers/Publisher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/OOP.dir/Model/Loggers/Publisher.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/Model/Loggers/Publisher.cpp.o -c /home/shakhinn/CLionProjects/OOP/Model/Loggers/Publisher.cpp

CMakeFiles/OOP.dir/Model/Loggers/Publisher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/Model/Loggers/Publisher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/Model/Loggers/Publisher.cpp > CMakeFiles/OOP.dir/Model/Loggers/Publisher.cpp.i

CMakeFiles/OOP.dir/Model/Loggers/Publisher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/Model/Loggers/Publisher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/Model/Loggers/Publisher.cpp -o CMakeFiles/OOP.dir/Model/Loggers/Publisher.cpp.s

CMakeFiles/OOP.dir/Model/Loggers/ObjectPublisher.cpp.o: CMakeFiles/OOP.dir/flags.make
CMakeFiles/OOP.dir/Model/Loggers/ObjectPublisher.cpp.o: ../Model/Loggers/ObjectPublisher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/OOP.dir/Model/Loggers/ObjectPublisher.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP.dir/Model/Loggers/ObjectPublisher.cpp.o -c /home/shakhinn/CLionProjects/OOP/Model/Loggers/ObjectPublisher.cpp

CMakeFiles/OOP.dir/Model/Loggers/ObjectPublisher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP.dir/Model/Loggers/ObjectPublisher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shakhinn/CLionProjects/OOP/Model/Loggers/ObjectPublisher.cpp > CMakeFiles/OOP.dir/Model/Loggers/ObjectPublisher.cpp.i

CMakeFiles/OOP.dir/Model/Loggers/ObjectPublisher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP.dir/Model/Loggers/ObjectPublisher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shakhinn/CLionProjects/OOP/Model/Loggers/ObjectPublisher.cpp -o CMakeFiles/OOP.dir/Model/Loggers/ObjectPublisher.cpp.s

# Object files for target OOP
OOP_OBJECTS = \
"CMakeFiles/OOP.dir/main.cpp.o" \
"CMakeFiles/OOP.dir/Model/Field.cpp.o" \
"CMakeFiles/OOP.dir/Model/Cell.cpp.o" \
"CMakeFiles/OOP.dir/Model/Player.cpp.o" \
"CMakeFiles/OOP.dir/Model/Object.cpp.o" \
"CMakeFiles/OOP.dir/Controller/Controller.cpp.o" \
"CMakeFiles/OOP.dir/View/View.cpp.o" \
"CMakeFiles/OOP.dir/Model/Objects/CoinObject.cpp.o" \
"CMakeFiles/OOP.dir/Model/Objects/ExitObject.cpp.o" \
"CMakeFiles/OOP.dir/Model/Objects/EntranceObject.cpp.o" \
"CMakeFiles/OOP.dir/Model/Objects/BombObject.cpp.o" \
"CMakeFiles/OOP.dir/Model/Objects/TeleportObject.cpp.o" \
"CMakeFiles/OOP.dir/Model/Loggers/logger.cpp.o" \
"CMakeFiles/OOP.dir/Model/Loggers/ConsolLogger.cpp.o" \
"CMakeFiles/OOP.dir/Model/Loggers/FileLogger.cpp.o" \
"CMakeFiles/OOP.dir/Model/Loggers/Publisher.cpp.o" \
"CMakeFiles/OOP.dir/Model/Loggers/ObjectPublisher.cpp.o"

# External object files for target OOP
OOP_EXTERNAL_OBJECTS =

OOP: CMakeFiles/OOP.dir/main.cpp.o
OOP: CMakeFiles/OOP.dir/Model/Field.cpp.o
OOP: CMakeFiles/OOP.dir/Model/Cell.cpp.o
OOP: CMakeFiles/OOP.dir/Model/Player.cpp.o
OOP: CMakeFiles/OOP.dir/Model/Object.cpp.o
OOP: CMakeFiles/OOP.dir/Controller/Controller.cpp.o
OOP: CMakeFiles/OOP.dir/View/View.cpp.o
OOP: CMakeFiles/OOP.dir/Model/Objects/CoinObject.cpp.o
OOP: CMakeFiles/OOP.dir/Model/Objects/ExitObject.cpp.o
OOP: CMakeFiles/OOP.dir/Model/Objects/EntranceObject.cpp.o
OOP: CMakeFiles/OOP.dir/Model/Objects/BombObject.cpp.o
OOP: CMakeFiles/OOP.dir/Model/Objects/TeleportObject.cpp.o
OOP: CMakeFiles/OOP.dir/Model/Loggers/logger.cpp.o
OOP: CMakeFiles/OOP.dir/Model/Loggers/ConsolLogger.cpp.o
OOP: CMakeFiles/OOP.dir/Model/Loggers/FileLogger.cpp.o
OOP: CMakeFiles/OOP.dir/Model/Loggers/Publisher.cpp.o
OOP: CMakeFiles/OOP.dir/Model/Loggers/ObjectPublisher.cpp.o
OOP: CMakeFiles/OOP.dir/build.make
OOP: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
OOP: /usr/lib/x86_64-linux-gnu/libsfml-audio.so.2.5.1
OOP: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
OOP: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
OOP: CMakeFiles/OOP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable OOP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OOP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OOP.dir/build: OOP

.PHONY : CMakeFiles/OOP.dir/build

CMakeFiles/OOP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OOP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OOP.dir/clean

CMakeFiles/OOP.dir/depend:
	cd /home/shakhinn/CLionProjects/OOP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shakhinn/CLionProjects/OOP /home/shakhinn/CLionProjects/OOP /home/shakhinn/CLionProjects/OOP/cmake-build-debug /home/shakhinn/CLionProjects/OOP/cmake-build-debug /home/shakhinn/CLionProjects/OOP/cmake-build-debug/CMakeFiles/OOP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OOP.dir/depend

