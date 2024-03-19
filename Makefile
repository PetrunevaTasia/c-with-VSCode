.PHONY: clean

CXX = clang++
# FILE := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
# $(eval $(FILE):;@:)
# FILE := $(FILE)/$(FILE)

ASAN := -fsanitize=address
UBSAN := -fsanitize=undefined
SAN := -fsanitize=undefined,address
TEST_FLAGS := -lgtest -lgmock -pthread

ifeq (test,$(firstword $(MAKECMDGOALS)))
  TEST_NUMBER := $(word 2, $(MAKECMDGOALS))
  TEST_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  TEST_RUN := $(foreach arg, $(TEST_ARGS), $(arg).cpp)
  TEST_OUT := $(foreach arg, $(TEST_ARGS), $(arg).o)
  $(eval $(TEST_ARGS):;@:)
endif

use-clang: 
	$(CXX) tasks/$(FILE).cpp -o tasks/$(FILE).out
	./tasks/$(FILE).out

use-asan:
	$(CXX) tasks/$(FILE).cpp -o tasks/$(FILE).out $(ASAN)
	./tasks/$(FILE).out

use-ubsan:
	$(CXX) tasks/$(FILE).cpp -o tasks/$(FILE).out $(UBSAN)
	./tasks/$(FILE).out

use-san:
	$(CXX) tasks/$(FILE).cpp -o tasks/$(FILE).out $(SAN)
	./tasks/$(FILE).out

run-tests:
	$(CXX) tests/$(FILE).cpp -o tests/$(FILE).out $(TEST_FLAGS)
	./tests/$(FILE).out

test_1:
	$(CXX) -c tasks/task_1/task_1.cpp  $(SAN) -o tests/task_1/task_1.o 
	$(CXX) -c tests/task_1/task_1_test.cpp $(SAN) -o tests/task_1/test_1.o
	$(CXX) tests/task_1/task_1.o tests/task_1/test_1.o -o tests/task_1/result.out $(TEST_FLAGS) $(SAN)
	rm tests/task_1/*.o
	./tests/task_1/result.out

test_2:
	$(CXX) -c tasks/task_2/task_2.cpp  $(SAN) -o tests/task_2/task_2.o -std=c++17
	$(CXX) -c tests/task_2/task_2_test.cpp $(SAN) -o tests/task_2/test_2.o -std=c++17
	$(CXX) tests/task_2/task_2.o tests/task_2/test_2.o -o tests/task_2/result.out $(TEST_FLAGS) $(SAN)
	rm tests/task_2/*.o
	./tests/task_2/result.out

test_3:
	$(CXX) -c tasks/task_3/task_3.cpp  $(SAN) -o tests/task_3/task_3.o 
	$(CXX) -c tests/task_3/task_3_test.cpp $(SAN) -o tests/task_3/test_3.o
	$(CXX) tests/task_3/task_3.o tests/task_3/test_3.o -o tests/task_3/result.out $(TEST_FLAGS) $(SAN)
	rm tests/task_3/*.o
	./tests/task_3/result.out

test_4:
	$(CXX) -c tasks/task_4/task_4.cpp  $(SAN) -o tests/task_4/task_4.o 
	$(CXX) -c tests/task_4/task_4_test.cpp $(SAN) -o tests/task_4/test_4.o
	$(CXX) tests/task_4/task_4.o tests/task_4/test_4.o -o tests/task_4/result.out $(TEST_FLAGS) $(SAN)
	rm tests/task_4/*.o
	./tests/task_4/result.out

test:
	echo $(TEST_NUMBER)
	echo $(TEST_ARGS)
	echo $(TEST_OUT)


clean: