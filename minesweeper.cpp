//Eddie Velasco


#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

int** createBoard(int width, int height, int mines) {
	int** board = 0;
	board = new int*[height];
	for (int i=0; i < width; i++) {
		board[i] = new int[width];
		for (int j=0; j < height; j++) {
			board[i][j] = 0;
		}
	}
	for (int n = 0; n < mines; n++) {
		int x = rand()%width-1+1;
		int y = rand()%height-1+1;
		do {
			x = rand()%width-1+1;
			y = rand()%height-1+1;
		} while (board[x][y] == 1);
		board[x][y] = 1;
	}	
	return board;
}

void printBoard(int** board, int height, int width) {	
	for (int i = 0; i < width; i++) {
		printf("\n");
		for (int j = 0; j < height; j++) {
			printf("%d", *((int*)(&board[i][j])));
		}
	}
	printf("\n");
}


int main (void) 
{
	int width;
	int height;
	int mines;
	cout << "Enter Board Width/Height: ";
	cin >> width;
	height = width;
	cout << "Enter Number of Mines: ";
	cin >> mines;
	int area = height * width;
	if (mines > area) {
		cout << "\nError: number of mines must be smaller than board.\n";
		return 0;
	}
	srand(time(0));
	if (width > 0 && height > 0 && mines > 0) {
		cout << "Building board...\n";
		int **gameBoard = createBoard(width, height, mines);
		printBoard(gameBoard, height, width);
		free(gameBoard);
	} else {
		cout << "Error: all input values must be positive integers above 0\n";
	}
	return 0;
}

