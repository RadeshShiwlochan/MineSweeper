#include <iostream>
#include <fstream>

using namespace std;

void printField(int** arr, int rows, int cols) {
	for(int r = 0; r < rows; ++r) {
		for(int c = 0; c < cols; ++c) {
			cout << arr[r][c] << "  ";
		}
		cout << endl;
	}
}

void findMines(string inputFile) {
	ifstream readInput;
	readInput.open(inputFile);
	int rows = 0;
	int columns = 0;
	string value = "";
	readInput >> rows >> columns;
	string* field = new int[rows];
	for(int i = 0; i < rows; ++i)
		field[i] = new int[columsn]();

	for(int r = 0; r < rows; ++r) {
		for(int c = 0; c < columns; ++c) {
			readInput >> value;
			field[r][c] = value;
		}
	}
	printField(field);

}

int main(int argc, char* argv[]) {

	if(argc != 1) {
		cout << "Needs an inputFile, Terminating\n";
		return 0;
	}

	findMines(argv[1]);
	return 0;
}