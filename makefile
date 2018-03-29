qtqst: *.cpp

	g++ -ggdb -Wall -Wextra qtqst.cpp -o qtqst.exe -lsfml-graphics -lsfml-window -lsfml-system
