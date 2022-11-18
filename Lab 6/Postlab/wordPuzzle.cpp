// Alisha Meena Gursahaney
// amg9zd
// prelab 6


#include <iostream>
#include <fstream>
#include <stdio.h>
	// to go through text files
#include <string>
using namespace std;

#include "hashTable.h"
#include "timer.h"

//#include <unordered_set> // to test word puzzle without hashtable code


// copied and pasted from getWordInGrid.cpp
// We create a 2-D array of some big size, and assume that the grid
// read in will be less than this size (a valid assumption for lab 6)
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// Forward declarations
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);



/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columns as specified in the input file;
 *             as this is a reference, it is set by the function.
 */
bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    string temp;

    // first comes the number of rows
    file >> rows;
    // cout << "There are " << rows << " rows." << endl;
    getline(file, temp);

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;
    getline(file, temp);

    // and finally the grid itself
    getline(file, temp);
    //string data;
    //file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = temp[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    return true;
}

/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static string variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A STATIC string containing the letters in the provided direction.
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */

// change to char* because we are going by each letter
string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.

    // change to char
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}


/** The main() function shows how to call both the readInGrid()
 * function as well as the getWordInGrid() function.
 */
int main(int argc, char **argv) {

	// command line parameters
	for (int i=1; i < argc; i++) {
		// convert from cstyle to c++ (given in lab 3)
		string s(argv[i]);
	}

	// first argument read in is the dictionary text file
	string dictionary = argv[1];
	// second argument read in is the grid text file
	// string grid = argv[2];


	// find the size of the dictionary
	// googled to help with reading file lines

	// fstream
	ifstream dictionaryfile;

	// open the file to read it
	dictionaryfile.open(dictionary);

	string temporary;

	// keeps track of current line
	int numlines = 0;
	// while not at the end of the file
	while (getline(dictionaryfile, temporary)) {
		// looks at first line then reads to next to keep track
		//getline(dictionaryfile, temporary);
		numlines++;

	}
	// string dictstring;
	// close the file after reading through
	dictionaryfile.close();

	// use dictionary size to initialize a hash table with found size
	hashTable* hasht = new hashTable(numlines);
	// std::unordered_set<string> hasht; // to test word puzzle without hashtable code and check which one is the error
	
	// fstream
	ifstream dictionaryfile1;

	// open the file to read it
	dictionaryfile1.open(dictionary);

	string temporary1;

	while (getline(dictionaryfile1, temporary1)) {
		//hasht.insert(temporary1);
		hasht->insert(temporary1);
	}

	dictionaryfile1.close();


	//int dictionarysize = numlines;
	
	// ifstream gridfile(grid);
	// gridfile.open(grid);

	// string gridstring;

	//while(getline(gridfile, gridstring) && gridstring.length() >= 3) {
	//	hasht->insert(gridstring);
	//}

	// to hold the number of rows and cols in the input file
    int rows, cols;

    readInGrid(argv[2], rows, cols);
    // cout << rows << cols << endl;

    timer* timer1 = new timer();


	string direction;

	// 4 for loops to check all direction and length combinations
	// check for all 8 directions and then lengths 3 to 22
	timer1->start();

	int numWords = 0;	// keeping track of the number of words found
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			for (int dir = 0; dir <= 7; dir ++) {
				for (int length = 3; length <= 22; length++) {
					string temp = getWordInGrid(row, col, dir, length, rows, cols);

					//string y = hasht->search(temp);
					// hasht.find(temp) != hasht.end();
					// hasht->search(temp) != "";
					if (temp.length() >= 3 && hasht->search(temp)) {
					// hashtable search
					// if (hasht.find(temp) == "") break;
					numWords++; // add 1 to number of words found tracker

					// taken from below in getWordinGrid
					// changing int directions to their equivalent string
					switch (dir) { 
            			case 0:
                			direction = "N";
                			break; // north
            			case 1:
           					direction = "NE";
                			break; // north-east
            			case 2:
            				direction = "E";
                			break; // east
            			case 3:
                			direction = "SE";
                			break; // south-east
            			case 4:
                			direction = "S";
                			break; // south
            			case 5:
                			direction = "SW";
                			break; // south-west
            			case 6:
                			direction = "W";
                			break; // west
            			case 7:
                			direction = "NW";
                			break; // north-west
                
						}
				cout << direction << " (" << row << ", " << col << "): \t " << temp << endl;
				}
				// account for repeats when at the end of the grid and keeps printing the same word for same length
				string temp1 = getWordInGrid(row, col, dir, length+1, rows, cols);
				if (temp.length() == temp1.length()) break;

			}
		}
	}


    // attempt to read in the file
    // bool result = readInGrid(grid, rows, cols);
    // if there is an error, report it
    // if (!result) {
    //     cout << "Error reading in file!" << endl;
    //     return 1;
    // }

    // output test

    // // Get a word (of length 10), starting at position (2,2) in the
    // // array, in each of the 8 directions
    // cout << endl;
    // for (int i = 0; i < 8; i++) {
    //     cout << i << ": " << getWordInGrid(2, 2, i, 10, rows, cols) << endl;
    // }

     
	}
	cout << numWords << " words found" << endl;
	timer1->stop();
	//cout << timer1->getTime() << endl;
return 0;
}
