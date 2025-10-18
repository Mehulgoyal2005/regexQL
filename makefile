CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra
SRC = src
OBJS = $(SRC)/main.o $(SRC)/lexer.o $(SRC)/parser.o $(SRC)/translator.o $(SRC)/executor.o

all: regexql

regexql: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(SRC)/main.o: $(SRC)/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SRC)/lexer.o: $(SRC)/lexer.cpp $(SRC)/lexer.h $(SRC)/utils.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SRC)/parser.o: $(SRC)/parser.cpp $(SRC)/parser.h $(SRC)/lexer.h $(SRC)/utils.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SRC)/translator.o: $(SRC)/translator.cpp $(SRC)/translator.h $(SRC)/parser.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SRC)/executor.o: $(SRC)/executor.cpp $(SRC)/executor.h $(SRC)/translator.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f regexql $(SRC)/*.o
