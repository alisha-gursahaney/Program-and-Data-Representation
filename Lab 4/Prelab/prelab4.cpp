
#include <iostream>

using namespace std;

#include <string>

#include <climits>

#include <stdlib.h>


// Alisha Meena Gursahaney amg9zd
// prelab 4


void sizeOfTest() {
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
	cout << "Size of float: " << sizeof(float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;
	cout << "Size of char: " << sizeof(char) << endl;
	cout << "Size of bool: " << sizeof(bool) << endl;
	cout << "Size of int*: " << sizeof(int*) << endl;
	cout << "Size of char*: " << sizeof(char*) << endl;
	cout << "Size of double*: " << sizeof(double*) << endl;

	// checked in gradescope

}

void overflow() {
	unsigned int max_number = UINT_MAX; // uint max should be 4294967295 in <climits>
	unsigned int result = max_number + 1;
	cout << max_number << " + 1 = " << result << endl;

	// checked in gradescope

}

void outputBinary(unsigned int x) {
	string binary = "";
	
	// 32 bit code
	for (int i = 32; i >= 1; i--) {
		if (x >= 0) {
			int remainder = x % 2;
			binary += std::to_string(remainder);
			x /= 2;
			//if (i % 4 == 0) {
			//	binary += " ";
			//}
		}
		
		//else {
		//	binary += "0";
		//	}
		}
	for (int i = 0; i < 32 /2; i++) {
		swap(binary[i], binary[32-i-1]);
	}

	cout << binary << endl;
}

int main() {
	unsigned int x;
	// string x;
	cin >> x; 

	// int cast = std::stoi(x);

	sizeOfTest();
	overflow();
	outputBinary(x);
	


}
