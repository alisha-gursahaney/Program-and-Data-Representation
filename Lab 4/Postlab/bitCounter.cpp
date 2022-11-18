
#include <iostream>

using namespace std;

#include <string>

#include <climits>

#include <stdlib.h>

#include <cmath>

// include math

// Alisha Meena Gursahaney
// amg9zd
// post lab 4

int binaryrecurs(unsigned int x) {
	if ( x == 0 ) {	
		return 0;
	}
	else if ( x == 1) {
		return 1;
	}
	else if ( x%2 == 0) {
		return binaryrecurs(x/2);
	}

	else {
		return binaryrecurs(floor(x/2)) + 1;
	}

}

string baseconverter(string s, int start, int end) {

	// convert letters to numbers
	int sum;
	if (start != 10) {
		sum = 0;
		int j=0;
		int num;
		for (int a = s.length()-1; a >= 0; a--) {
			if (s[j] >= '0' && s[j] <= '9') {
				num = s[j] - 48;
				}
			else {
				num = s[j] - 55;
				
				}
			sum += num * pow(start, a);
			j++;
			
		}
	}
	else {
		sum = std::stoi(s);
	}

	string baseconvert = "";

	if (end != 10) {
		while (sum != 0) {
			int remainder = sum % end;
			if (remainder >= 9 && remainder <= 36) {
				char c1 = (char) (remainder + 55);
				baseconvert += std::to_string(c1);
			}
			else {
				baseconvert += std::to_string(remainder);
			}
			sum /= end;
		}
		if (end == 2) {
			for (int i = 0; i < baseconvert.length() /2; i++) {
				swap(baseconvert[i], baseconvert[baseconvert.length()-i-1]);
			}
		}
		
		return baseconvert;
		}
	// else if (end > 10) {
	// 	while (sum != 0) {
	// 		int remainder = sum % end;
	// 		if (remainder >= 9) {
	// 			char c1 = (char) remainder + 48;
	// 			baseconvert += std::to_string(c1);
	// 		}
	// 		else {
	// 			baseconvert += std::to_string(remainder);
	// 		}
	// 		sum /= end;
	// 	}
	// }
	else {
		return std::to_string(sum);
		}
	}

int main (int argc, char **argv) {
	// take in command line inputs

	for (int i = 1; i < argc; i++) {
		string s(argv[i]);
	}

	int x = std::atoi(argv[1]);
	string stringbase = argv[2];
	int startbase = std::atoi(argv[3]);
	int endbase = std::atoi(argv[4]);

	cout << x << " has " << binaryrecurs(x) << " bit(s)" << endl;
	cout << stringbase << " (base " << startbase 
	<< ") = " << baseconverter(stringbase, startbase, endbase) << " (base " << endbase
	<< ")" << endl;

}

