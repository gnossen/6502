bin/emulator: src/emulator_main.cpp src/emulator.cpp src/emulator.hpp src/register.hpp
	mkdir -p bin
	g++ -std=c++14 -Wall src/emulator_main.cpp src/emulator.cpp -o bin/emulator

test: register_test emulator_test

.PHONY: register_test
register_test: bin/test/register_test
	./bin/test/register_test

bin/test/register_test: src/register.hpp test/register_test.cpp
	mkdir -p bin/test
	g++ -std=c++14 -Wall -I src/ test/register_test.cpp src/emulator.cpp -o bin/test/register_test

.PHONY: emulator_test
emulator_test: bin/test/emulator_test
	./bin/test/emulator_test

bin/test/emulator_test: src/emulator.hpp src/emulator.cpp test/emulator_test.cpp
	mkdir -p bin/test
	g++ -std=c++14 -Wall -I src/ test/emulator_test.cpp src/emulator.cpp -o bin/test/emulator_test

.PHONY: stats
stats:
	find . -\( -name "*.cpp" -o -name "*.hpp" \) | xargs wc -l
