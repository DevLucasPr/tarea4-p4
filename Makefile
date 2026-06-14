IDIR = include
SDIR = src
ODIR = obj
CXX = g++
CXXFLAGS = -I$(IDIR) -std=c++11 -Wall -Wextra -pedantic
BIN = main
SRCS = $(wildcard $(SDIR)/*.cpp)
OBJS = $(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(SRCS))

.PHONY: all clean entrega valgrind

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

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