#include <iostream>
#include <fstream>

using namespace std;

void printField(char** arr, int rows, int cols) {
	
	for(int r = 0; r < rows + 2; ++r) {
		for(int c = 0; c < cols + 2; ++c) {
			cout << arr[r][c] << "  ";
		}
		cout << endl;
	}
}

void addFrame(char** arr, int rows, int cols)  {

	int rowSize = rows + 2; 
	int colSize = cols + 2;
	for(int i = 0; i < rowSize; ++i) {
		for(int j = 0; j < colSize; ++j) {
			arr[i][j] = '#';
		}
	}
}

void findMines(string inputFile) {

	ifstream readInput;
	readInput.open(inputFile);
	int rows = 0;
	int columns = 0;
	char value;
	readInput >> rows >> columns;
	char** field;

	field = new char*[rows + 2];
	for(int i = 0; i < rows + 2; ++i)
		field[i] = new char[columns + 2]();

	addFrame(field, rows, columns);
	for(int r = 1; r < rows + 1; ++r) {
		for(int c = 1; c < columns + 1; ++c) {
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