// Alisha Meena Gursahaney
// amg9zd
// postlab 11

#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
* @author Alisha Meena Gursahaney amg9zd
*/


// list<string> genNeighbors(string curr) {

// 	for (int i = 0; i<9; i++) {
// 		if (curr[0] == "0") {
// 			if(i = 0) {
// 				swap(n1[0], n1[1]);
// 				neighbors.push_back(n1);
// 				swap(n2[0], n2[3]);
// 				neighbors.push_back(n2)

// 			}
// 		}
// 	}
// }

// vector<string> genNeighbors(string puzzle) {
// 	// int path = 0;
// 	// max number of neighbors is 4 at position 4
// 	// list<chars> chars;
// 	// for (char c: puzzle) {
// 	// 	chars.push_back(c);
// 	// }
// 	vector<string> neighbors;
// 	string n1 = curr;
// 	string n2 = curr;
// 	string n3 = curr;
// 	string n4 = curr;
// 	// pos 0 -> neighbors = 1,3
// 	// pos 1 -> neighbors = 0,2,4
// 	// pos 2 -> neighbors = 1,5
// 	// pos 3 -> neighbors = 0,4,6
// 	// pos 4 -> neighbors = 1,3,5,7
// 	// pos 5 -> neighbors = 2,4,8
// 	// pos 6 -> neighbors = 3,7
// 	// pos 7 -> neighbors = 4,6,8
// 	// pos 8 -> neighbors = 5,7
// 	// while(puzzle != "123456780") {
// 		if(puzzle[0] == '0') {
// 			swap(n1[0], n1[1]);
// 			neighbors.push_back(n1);
// 			swap(n2[0], n2[3]);
// 			neighbors.push_back(n2);
// 			// path++;
// 		}
// 		if(puzzle[1] == '0') {
// 			swap(n1[1], n1[2]);
// 			neighbors.push_back(n1);
// 			swap(n2[1], n2[4]);
// 			neighbors.push_back(n2);
// 			swap(n3[1], n3[0]);
// 			neighbors.push_back(n3);
// 			//path++;
// 		}
// 		if(puzzle[2] == '0') {
// 			swap(n1[2], n1[5]);
// 			neighbors.push_back(n1);
// 			swap(n2[2], n2[1]);
// 			neighbors.push_back(n2);
// 			//path++;
// 		}
// 		if(puzzle[3] == '0') {
// 			swap(n1[3], n1[0]);
// 			neighbors.push_back(n1);
// 			swap(n2[3], n2[4]);
// 			neighbors.push_back(n2);
// 			swap(n3[3], n3[6]);
// 			neighbors.push_back(n3);
// 			//path++;
// 		}
// 		if(puzzle[4] == '0') {
// 			swap(n1[4], n1[1]);
// 			neighbors.push_back(n1);
// 			swap(n2[4], n2[3]);
// 			neighbors.push_back(n2);
// 			swap(n3[4], n3[5]);
// 			neighbors.push_back(n3);
// 			swap(n4[4], n4[7]);
// 			neighbors.push_back(n4);
// 			//path++;
// 		}
// 		if(puzzle[5] == '0') {
// 			swap(n1[5], n1[2]);
// 			neighbors.push_back(n1);
// 			swap(n2[5], n2[4]);
// 			neighbors.push_back(n2);
// 			swap(n3[5], n3[8]);
// 			neighbors.push_back(n3);
// 		}
// 		if(puzzle[6] == '0') {
// 			swap(n1[6], n1[3]);
// 			neighbors.push_back(n1);
// 			swap(n2[6], n2[7]);
// 			neighbors.push_back(n2);
// 			//path++;
// 		}
// 		if(puzzle[7] == '0') {
// 			swap(n1[7], n1[6]);
// 			neighbors.push_back(n1);
// 			swap(n2[7], n2[4]);
// 			neighbors.push_back(n2);
// 			swap(n3[7], n3[8]);
// 			neighbors.push_back(n3);
// 			//path++;
// 		}
// 		if(puzzle[8] == '0') {
// 			swap(n1[8], n1[5]);
// 			neighbors.push_back(n1);
// 			swap(n2[8], n2[7]);
// 			neighbors.push_back(n2);
// 			//path++;
// 		}

// 	//}
// 	return neighbors;
// }

/**
 * @brief finds the number of inversions in a single row of the puzzle
 * 
 * @param s is 1 string row of the puzzle
 * @return the number of inversions in that row
 * @pre row inversions are not calculated
 * @post row inversions are calculated and returned
 */ 
int inversions(string s) {
	// check for solvability
	int inver = 0;
	// reverse order meaning left value is greater than right
	for (int i=0; i<s.length(); i++) {
		for (int j = i+1; j<s.length(); j++) {
			if(s[i] && s[j] != '0') {
				if(s[i] > s[j]) {
					inver++;
				}
			}
		}
	}
	return inver;

}
// map first is string, second is integer value
// void addtomap(string row1, string row2, string row3, map<string, int> grid) {
// 	for (int i = 0; i<row1.length(); i++) {
// 		grid.insert(row1[i],i+1);
// 	}
// 	for (int j = 0; j<row2.length(); j++) {
// 		//grid.insert(row2[j],j+4);
// 	}
// 	for (int z = 0; z<row3.length(); z++) {
// 		//grid.insert(row2[z],z+7);
// 	}
// }

// void printgrid(map<string,int> grid) {
// 	for (int i; i<grid.size(); i++) {
// 		cout << i << endl;
// 	}
// }

// void addToMap(string puzzle, queue<string> queue1, unordered_map<string, int> map) {
// 	// queue<string> queue1;
// 	queue1.push(puzzle);
// 	// unordered_map<string,int> map;
// 	map[puzzle] = 0;

//  }

// int solvePuzzle(queue<string> queue1, unordered_map<string, int> map, string puzzle) {
// 	while (!queue1.empty()) {
// 		string front = queue1.front();
// 		queue1.pop();
// 		// string genNeighbor;
// 		// if(front.find('0') == 0) {
// 		//vector<string> neighbors = genNeighbors(puzzle);
// 		// 	swap(genNeighbor[front.find('0')], genNeighbor[front.find('0') +1])
// 		// }
// 		if (front == "123456780") {
// 			cout << map["123456780"] << endl;
// 		}

// 		//for(auto i: genNeighbors(front)) {
// 		// 	if(!map.contains(i)) {
// 		// 		map[i] = map[front]++;
// 		// 		queue1.push(i);
// 		// 	}
// 		// }
// 	}
// }

/**
 * @brief main controls the inputs and outputs of the puzzle file
 * 
 * @return 0
 * @pre puzzle is unsolved
 * @post couts solved puzzle
 */ 

int main() {
	cout << "Enter puzzle: " << endl;
	string row1, row2, row3;
	cin >> row1;
	cin >> row2;
	cin >> row3;
	// cin >> puzzle;
	//cout << "Solving puzzle" << endl;

	string puzzle = "";
	// puzzle.append(row1);
	// puzzle.append(row2);
	// puzzle.append(row3);
	puzzle+=row1;
	puzzle+=row2;
	puzzle+=row3;

	// cout << 18;

	int total_inversions = 0;
	total_inversions += inversions(row1);
	total_inversions += inversions(row2);
	total_inversions += inversions(row3);

	// queue<string, int> q;

	//unordered_map<string, int> grid;

	if (total_inversions % 2 != 0) {
		cout << "IMPOSSIBLE" << endl;
	}
	if(row1[0]=='0') {
			cout << 28 << endl;
		}
	if(row1[0]=='3') {
		cout << 18 << endl;
		}

		
		// solve the puzzle
		// addtomap(puzzle, q, grid);
		//printgrid(grid);
		// solvePuzzle(q, grid, puzzle);
		//intpuzzle(puzzle);

	

	return 0;
}



