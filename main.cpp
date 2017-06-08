#include <iostream>
#include <fstream>

using namespace std;

void printField(string** arr, int rows, int cols) {

	for(int r = 0; r < rows + 2; ++r) {
		for(int c = 0; c < cols + 2; ++c) {
			cout << arr[r][c] << "  ";
		}
		cout << endl;
	}
}

void addFrame(string** arr, int rows, int cols)  {

	int rowSize = rows + 2; 
	int colSize = cols + 2;
	for(int i = 0; i < rowSize; ++i) {
		for(int j = 0; j < colSize; ++j) {
			arr[i][j] = "#";
		}
	}
}

void countAdjMines(string** arr, int rows, int cols) {
	int count = 0;
	int tempVal = 0;
	string value = "";
	for(int r = 1; r < rows; ++r) {
		for(int c = 1; c < cols; ++c) {
			if(arr[r][c] != "*") {
				if(arr[r - 1][c - 1] == "*" )
					count++;
				if(arr[r - 1][c] == "*") 
					count++;
				if(arr[r - 1][c + 1] == "*") 
					count++;
				if(arr[r][c - 1] == "*") 
					count++;
				if(arr[r][c + 1] == "*")
					count++;
				if(arr[r + 1][c - 1] == "*")
					count++;
				if(arr[r + 1][c] == "*")
					count++;
				if(arr[r + 1][c + 1] == "*")
					count++;
				tempVal = count;
				value = to_string(tempVal);
				arr[r][c] = value;
				count = 0;
			}//if

		}//for columns
	}//for rows
}

void findMines(string inputFile) {

	ifstream readInput;
	readInput.open(inputFile);
	int rows = 0;
	int columns = 0;
	char value;
	readInput >> rows >> columns;
	string** field;

	field = new string*[rows + 2];
	for(int i = 0; i < rows + 2; ++i)
		field[i] = new string[columns + 2]();

	addFrame(field, rows, columns);
	for(int r = 1; r < rows + 1; ++r) {
		for(int c = 1; c < columns + 1; ++c) {
			readInput >> value;
			field[r][c] = value;
		}
	}
	countAdjMines(field, rows + 1, columns + 1);
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