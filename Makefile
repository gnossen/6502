bin/emulator: src/emulator_main.cpp src/emulator.cpp src/emulator.hpp src/register.hpp src/instruction.cpp src/instruction.hpp
	mkdir -p bin
	g++ -std=c++14 -Wall src/emulator_main.cpp src/emulator.cpp src/instruction.cpp -o bin/emulator

test: register_test emulator_test instruction_test

.PHONY: register_test
register_test: bin/test/register_test
	./bin/test/register_test

bin/test/register_test: src/register.hpp test/register_test.cpp
	mkdir -p bin/test
	g++ -std=c++14 -Wall -I src/ test/register_test.cpp src/emulator.cpp -o bin/test/register_test

.PHONY: emulator_test
emulator_test: bin/test/emulator_test
	./bin/test/emulator_test

bin/test/emulator_test: src/emulator.hpp src/emulator.cpp src/instruction.cpp test/emulator_test.cpp
	mkdir -p bin/test
	g++ -std=c++14 -Wall -I src/ test/emulator_test.cpp src/emulator.cpp -o bin/test/emulator_test

.PHONY: instruction_test
instruction_test: bin/test/instruction_test
	./bin/test/instruction_test

bin/test/instruction_test: src/emulator.hpp src/emulator.cpp src/register.hpp src/instruction.cpp src/instruction.hpp test/instruction_test.cpp
	mkdir -p bin/test
	g++ -std=c++14 -Wall -I src/ test/instruction_test.cpp src/emulator.cpp src/instruction.cpp -o bin/test/instruction_test

.PHONY: stats
stats:
	find . -\( -name "*.cpp" -o -name "*.hpp" \) | xargs wc -l
