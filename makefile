CC = g++
CFLAGS = -Wall -g -std=c++11
LDFLAGS = -IINCLUDE
EXC = tp
OBJDIR = obj
SRCDIR = src
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)



all: $(EXC)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)
 
$(OBJDIR)/main.o: main.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

$(EXC): $(OBJ) $(OBJDIR)/main.o
	echo "Compilation avec succes !"
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf $(OBJDIR)/*.o

cleantp: clean
	rm -rf $(EXC)

