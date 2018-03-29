qtqst: *.cpp

	g++ -ggdb -Wall -Wextra AnimatedSprite.cpp Animation.cpp qtqst.cpp -o qtqst.exe -lsfml-graphics -lsfml-window -lsfml-system
