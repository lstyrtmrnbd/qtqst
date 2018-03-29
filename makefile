CC = g++
DEVCFLAGS = -Wall -Wextra -ggdb

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = qtqst_dev

SOURCES = $(wildcard src/*.cpp)

OBJ = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJ)

	$(CC) $(DEVCFLAGS) -o $@.exe $^ $(LDFLAGS)
