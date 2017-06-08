#include <iostream>
#include <fstream>

using namespace std;

void printField(char** arr, int rows, int cols) {
	for(int r = 0; r < rows; ++r) {
		for(int c = 0; c < cols; ++c) {
			cout << arr[r][c] << "  ";
		}
		cout << endl;
	}
}

void addFrame()  {
	
}

void findMines(string inputFile) {
	ifstream readInput;
	readInput.open(inputFile);
	int rows = 0;
	int columns = 0;
	char value;
	readInput >> rows >> columns;
	char** field;
	field = new char*[rows];
	for(int i = 0; i < rows; ++i)
		field[i] = new char[columns]();

	for(int r = 0; r < rows; ++r) {
		for(int c = 0; c < columns; ++c) {
			readInput >> value;
			field[r][c] = value;
		}
	}
	printField(field, rows, columns);
}

int main(int argc, char* argv[]) {

	if(argc != 2) {
		cout << "Needs an inputFile, Terminating\n";
		return 0;
	}

	findMines(argv[1]);
	return 0;
}