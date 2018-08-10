all: minesweeper

minesweeper: minesweeper.cpp
	g++ minesweeper.cpp -Wall -o minesweeper
clean:
	rm -f minesweeper
