bin/emulator: src/emulator_main.cpp src/emulator.cpp src/emulator.hpp
	g++ -std=c++14 -Wall src/emulator_main.cpp src/emulator.cpp -o bin/emulator
