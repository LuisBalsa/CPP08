#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include "Span.hpp"

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

void testAddNumberOverflow() {
    titleHeader("Test: addNumber overflow");
    Span sp(2);
    try {
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
    } catch (const std::exception& e) {
        std::cout << "Exception (expected): " << e.what() << std::endl;
    }
    pressEnter();
}

void testSpanWithZeroElements() {
    titleHeader("Test: span with zero elements");
    Span sp(5);
    try {
        std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception (expected): " << e.what() << std::endl;
    }
    try {
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception (expected): " << e.what() << std::endl;
    }
    pressEnter();
}

void testSpanWithOneElement() {
    titleHeader("Test: span with one element");
    Span sp(5);
    sp.addNumber(42);
    try {
        std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception (expected): " << e.what() << std::endl;
    }
    try {
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception (expected): " << e.what() << std::endl;
    }
    pressEnter();
}

void testAddRangeOverflow() {
    titleHeader("Test: addRange overflow");
    Span sp(3);
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    try {
        sp.addRange(v.begin(), v.end());
    } catch (const std::exception& e) {
        std::cout << "Exception (expected): " << e.what() << std::endl;
    }
    pressEnter();
}

void testBasicSpan() {
    Span sp(5);
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    } catch (const std::exception& e) {
        std::cout << "Exception on addNumber: " << e.what() << std::endl;
    }
    titleHeader("Basic Span Test");
    std::cout << "Numbers added: 6, 3, 17, 9, 11" << std::endl;
    try {
        std::cout << "Shortest span (should be 2): ";
        std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception on shortestSpan: " << e.what() << std::endl;
    }
    try {
        std::cout << "Longest span (should be 14): ";
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception on longestSpan: " << e.what() << std::endl;
    }
    pressEnter();
}

void testLargeSpan() {
    Span sp(10000);
    std::list<int> l;
    for (int i = 0; i < 10000; ++i)
        l.push_back(i * 2);
    try {
        sp.addRange(l.begin(), l.end());
    } catch (const std::exception& e) {
        std::cout << "Exception on addRange: " << e.what() << std::endl;
    }
    titleHeader("Large Span Test (std::list<int>)");
    try {
        std::cout << "Shortest span (should be 2): " << sp.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception on shortestSpan: " << e.what() << std::endl;
    }
    try {
        std::cout << "Longest span (should be 19998): " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception on longestSpan: " << e.what() << std::endl;
    }
    pressEnter();
}

int main() {
	std::cout << "\033[2J\033[1;1H";
    testBasicSpan();
    testLargeSpan();
    testAddNumberOverflow();
    testSpanWithZeroElements();
    testSpanWithOneElement();
    testAddRangeOverflow();
    return 0;
}
