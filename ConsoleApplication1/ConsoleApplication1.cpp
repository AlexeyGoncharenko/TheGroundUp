/* That's a temporary repository for testing some ideas.
 * Any description and comments may be absent.
 * But there is room for improvement.
 */

#include "stdafx.h"
#include <string>
#include <Windows.h>
#include <locale.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Difference {
	private:
		std::vector<int> elements;

	public:
		int maximumDifference;
		std::vector<int> diffArray;

		Difference(std::vector<int> data) {
			elements = data;
		}

		void computeDifference() {
			for (int i = 0; i < elements.size() - 1; i++) {
				for (int j = i + 1; j < elements.size(); j++) {
					diffArray.push_back(std::abs(elements[i] - elements[j]));
				}
			}
			maximumDifference = *std::max_element(diffArray.begin(), diffArray.end());
		}
}; 

int main(int argc, char** argv) {
// How find out C++ compiler version by means of comparison size of primitive data type.
	std::cout << "Compiler's version: " << __cplusplus << std::endl;
	char  *answer = "This is ";
	std::strcat(answer, ((sizeof(char) == sizeof('c')) ? "C++ program!\n" : "C program!\n"));
	std::cout << answer << std::endl;

	int N1;
	std::cin >> N1;
	std::vector<int> a;

	for (int i = 0; i < N1; i++) {
		int e;
		std::cin >> e;
		a.push_back(e);
	}

	Difference d(a);
	d.computeDifference();
	std::cout << d.maximumDifference;

	std::vector<std::vector<int>> arr(6);
	for (int i = 0; i < 6; i++) {
		arr[i].resize(6);
		for (int j = 0; j < 6; j++) {
			std::cin >> arr[i][j];
		}
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	}

	int mask_size = 3;
	int index{};
	std::vector<int> sumMatrices;
	sumMatrices.resize(16);
	for (int i = 0; i <= mask_size; i++) {
		for (int j = 0; j <= mask_size; j++) {
			for (int k = i; k < i + mask_size; k++) {
				for (int l = j; l < j + mask_size; l++) {
					if ((k == (i + mask_size / 2)) && ((l == (j + mask_size / 2) - 1) || (l == (j + mask_size / 2) + 1))) continue;
					else sumMatrices[index] += arr[k][l];
				}
			}
			index++;
		}
	}
	std::cout << *std::max_element(sumMatrices.begin(), sumMatrices.end());
	
	const int DEFAULT_LENGTH = 100;
	int decimalN{}, counter{};
	std::vector<int> binaryN = std::vector<int>();
	std::vector<int> consecutiveOnes = std::vector<int>();
	
	binaryN.reserve(DEFAULT_LENGTH);
	consecutiveOnes.reserve(DEFAULT_LENGTH);

	std::cin >> decimalN;
	std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	if (decimalN >= 1 && decimalN <= 1000000) {
		while (decimalN > 0) {
			binaryN.push_back(decimalN % 2);
			decimalN /= 2;
		}
		int size = binaryN.size();
		for (int i = 0; i < size; i++) {
			if (binaryN[i] == 1 && (counter == 0 || counter > 0)) {
				counter++;
			}
			else if (binaryN[i] == 0 && counter > 0) {
				consecutiveOnes.push_back(counter);
				counter = 0;
			}
		}
		consecutiveOnes.push_back(counter);
		std::cout << *std::max_element(consecutiveOnes.begin(), consecutiveOnes.end());
	}
	

	
// What Structure object it is. In comparison with Class object.
// Ex.1
	struct Person {
		private:
			std::string fName;
			std::string lName;
			int age;
		public:
			Person(std::string fN, std::string lN, int a):  fName(fN), lName(lN), age(a) {}
			std::string output() {
				std::ostringstream os;
				os << "Name: " << fName << ", Surname: " << lName << ", Age: " << age << std::endl;
				return os.str();
			}
	};

	Person staff[] = { {"James", "Bond", 50}, {"Marta", "Shepard", 35}, {"Nick", "Hillton", 22} };
	for (auto &obj : staff) std::cout << obj.output();		

// Ex.2
	struct s1 {
		int x;
		int y;
		struct s2 {
		public:
			int x;
		private:
			int y;
			struct s3 {
				int x;
				int y;
				union {
					int iValue;
					char character;
					bool isTrue;
					class c1 {
						public:
							bool getState(void) { return state; }
						private:
							bool state;
					};
					c1 c1Class;
				} u1;
			};
		public:
			s3 s3Struct;
		};
		s2 s2Struct;
	};

	s1 someStruct;
	someStruct.s2Struct.s3Struct.u1.c1Class.getState();

// How to work with std::cin object when it read some data from stream
	int N{};
	std::cin >> N;
	std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	for (int i = 0; i < N; i++) {
		std::string someString = std::basic_string<char>();
		std::getline(std::cin >> std::ws, someString);
		for (int i = 0; i < someString.length(); i++) {
			if (i % 2 == 0)
				std::cout << someString[i];
		}
		std::cout << ' ';
		for (int i = 0; i < someString.length(); i++) {
			if (i % 2 != 0)
				std::cout << someString[i];
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}
