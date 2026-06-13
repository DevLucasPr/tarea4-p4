IDIR = include
SDIR = src
ODIR = obj

CXX = g++
CXXFLAGS = -I$(IDIR) -std=c++98 -Wall -Wextra -pedantic

BIN = main

SRCS = main.cpp $(wildcard $(SDIR)/*.cpp)
OBJS = $(ODIR)/main.o $(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(wildcard $(SDIR)/*.cpp))

.PHONY: all clean entrega valgrind

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(ODIR)/%.o: %.cpp | $(ODIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR)/%.o: $(SDIR)/%.cpp | $(ODIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(ODIR):
	mkdir -p $(ODIR)

entrega:
	tar -czvf 03_lab4.tar.gz $(SRCS) $(IDIR) Makefile

clean:
	rm -rf $(ODIR) $(BIN)

valgrind: $(BIN)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BIN)