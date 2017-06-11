#include <iostream>
#include <fstream>
using namespace std;

void printField(ofstream& printToFile, string** arr, int rows, 
	                                     int cols, int count) {
/**
	This function prints the result of the field array. The field
	array is initialize with amount of rows + 2 and amount of
	columns + 2. Here the for loop prints the array without the 
	frame hence why it prints from 1 to number of rows + 1 and 
	number of columns + 1
*/
	printToFile << "Field #" << count << ":\n";
	for(int r = 1; r < rows + 1; ++r) {
		for(int c = 1; c < cols + 1; ++c) {
			printToFile << arr[r][c];
		}
		printToFile << endl;
	}
	printToFile << endl;
}

void initializeField(string** arr, int rows, int cols)  {
/**
	This function is used to initialize the values of 
	the field array to empty strings.
*/
	int rowSize = rows + 2; 
	int colSize = cols + 2;
	for(int i = 0; i < rowSize; ++i) {
		for(int j = 0; j < colSize; ++j) {
			arr[i][j] = "";
		}
	}
}

void countAdjMines(string** arr, int rows, int cols) {
/**
	This function counts the amount of adjacent mines at
	a current position in the field array. It uses a brute
	force method of using if statements to check the eight
	adjacent positions to the current position. This makes
	use of the two extra rows and columns so that extra test
	cases do no have to added for edge cases. 
	-count: used to keep track of the number of input and
			to print the field number
	-value; used to take the integer value of adjacent mines
			at a current position and represent that value in 
			the field array.		
*/
	int count = 0;
	//int tempVal = 0;
	string value = "";
	for(int r = 1; r < rows; ++r) {
		for(int c = 1; c < cols; ++c) {
			if(arr[r][c] != "*") {
				if(arr[r - 1][c - 1] == "*" )
					count++;
				if(arr[r - 1][c]     == "*") 
					count++;
				if(arr[r - 1][c + 1] == "*") 
					count++;
				if(arr[r][c - 1]     == "*") 
					count++;
				if(arr[r][c + 1]     == "*")
					count++;
				if(arr[r + 1][c - 1] == "*")
					count++;
				if(arr[r + 1][c]     == "*")
					count++;
				if(arr[r + 1][c + 1] == "*")
					count++;
				//tempVal = count;
				value = to_string(count);
				arr[r][c] = value;
				count = 0;
			}//if
		}//for columns
	}//for rows
}

void findMines(string inputFile, string outputFile) {
/**
	primary function that finds all mines in adjacent positions
	-read in number of rows and columns
	-initialize the field array
	-use initalizeFrame to initialize all positons of fieldArray 
	-read in the input to the field array
	-use countAdjMines to count the number of adjacent mines
	-use printField to print result
	-after all input is process, delete field array
*/
	ifstream readInput;
	readInput.open(inputFile);
	ofstream printToFile;
	printToFile.open(outputFile);
	int rows = 0;
	int columns = 0;
	int countOfField = 0;
	char value;
	string** field;

	while(readInput >> rows >> columns) {
		//if rows and columns are 0, quit program, end of input
		if(rows == 0 && columns == 0)
			return;	
		//countOfField: keeps track of the amount of input,field number
		countOfField++;
		/**
			initialize the array with two extra rows and columns to 
			create a "frame". The frame allows for less test cases 
			for edge cases.
		*/
		field = new string*[rows + 2];
		for(int i = 0; i < rows + 2; ++i)
			field[i] = new string[columns + 2]();

		//initalize the field to empty strings
		initializeField(field, rows, columns);
		//read in the input from file
		for(int r = 1; r < rows + 1; ++r) {
			for(int c = 1; c < columns + 1; ++c) {
				readInput >> value;
				field[r][c] = value;
			}
		}
		//count the mines in the input read in
		countAdjMines(field, rows + 1, columns + 1);
		//print the result
		printField(printToFile, field, rows, columns, countOfField);
	}
		//delete the field array
	    delete field;
	    //close the file
	    readInput.close();
}

int main(int argc, char* argv[]) {
	//check to make sure an input and output file is provided
	if(argc != 3) {
		cout << "Needs an inputFile, Terminating\n";
		return 0;
	}
	//call the findMines with the input file
	findMines(argv[1], argv[2]);
	return 0;
}