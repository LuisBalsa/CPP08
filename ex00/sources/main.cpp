#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <list>
#include "easyfind.hpp"

void	titleHeader(const std::string& message)
{
	const short standartSize = 34;
	short messageSize = message.length();
	short spacesBefore = (standartSize - messageSize) / 2 + messageSize;
	short spacesAfter = (standartSize - messageSize) / 2 + 2 + messageSize % 2;

	std::cout << "\n************************************\n*";
	std::cout << std::setw(spacesBefore) << message;
	std::cout << std::setw(spacesAfter) << "*\n";
	std::cout << "************************************\n" << std::endl;
}

void	pressEnter(void)
{
	std::string enter;
	std::cout << "\033[1;31m\nPress enter to continue...\033[0m";
	std::getline(std::cin, enter);
	std::cout << "\033[2J\033[1;1H";
}

void testEasyFind(std::vector<int>& v, int value) {
    std::ostringstream oss;
    oss << "Searching for " << value << " in vector:";
    titleHeader(oss.str());
    try {
        std::vector<int>::iterator it = easyfind(v, value);
        std::cout << "Found " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << e.what() << std::endl;
    }
    pressEnter();
}

int main() {
    std::cout << "\033[2J\033[1;1H";
    std::vector<int> v;
    for (int i = 0; i < 5; ++i)
        v.push_back(i * 10);

    testEasyFind(v, 20);
    testEasyFind(v, 25);
    testEasyFind(v, 40);
}
