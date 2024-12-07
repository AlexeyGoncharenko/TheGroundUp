/* CHAP1.cpp
 * implicit data type conversion
 */
#include <iostream>

int main(int argc, char** argv) 
{
    int iVal = 4;
    std::cout << "iVal = " << iVal << std::endl;
    iVal = 'A'; // get ASCII decimal code
    std::cout << "iVal = " << iVal << std::endl;
    iVal = 5.85f; // static_cast<int>(5.85F)
	std::cout << "iVal = " << iVal << std::endl;
	return 0;
}
