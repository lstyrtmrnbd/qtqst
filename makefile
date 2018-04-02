CC = g++
DEVCFLAGS = -std=c++11 -Wpedantic -Wall -Wextra -Werror -ggdb -O0

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = qtqst_dev

SOURCES = $(wildcard src/*.cpp)

OBJ = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJ)

	$(CC) $(DEVCFLAGS) -o $@.exe $^ $(LDFLAGS)
