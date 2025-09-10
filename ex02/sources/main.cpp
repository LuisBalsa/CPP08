#include <iostream>
#include <list>
#include <sstream>
#include <cstdio>
#include <queue>
#include "MutantStack.hpp"

void testMutantStack() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

void testSideBySide() {

    MutantStack<int> mstack;
    std::stringstream msStream;
    mstack.push(5); mstack.push(17);
    msStream << mstack.top() << ' '; mstack.pop(); msStream << mstack.size() << ' ';
    mstack.push(3); mstack.push(5); mstack.push(737); mstack.push(0);

    std::list<int> lList;
    std::stringstream lsStream;
    lList.push_back(5); lList.push_back(17);
    lsStream << lList.back() << ' '; lList.pop_back(); lsStream << lList.size() << ' ';
    lList.push_back(3); lList.push_back(5); lList.push_back(737); lList.push_back(0);

    std::string msVal, lsVal;
    while (msStream >> msVal && lsStream >> lsVal) {
        std::cout << "MutantStack: " << msVal << " |\tstd::list: " << lsVal << std::endl;
    }
    if (msStream >> msVal || lsStream >> lsVal) {
        std::cout << "Containers have different sizes!" << std::endl;
    }

    MutantStack<int>::iterator mIt = mstack.begin();
    MutantStack<int>::iterator mIte = mstack.end();
    std::list<int>::iterator lIt = lList.begin();
    std::list<int>::iterator lIte = lList.end();
    while (mIt != mIte && lIt != lIte) {
        std::cout << "MutantStack: " << *mIt << " |\tstd::list: " << *lIt << std::endl;
        ++mIt;
        ++lIt;
    }
    if (mIt != mIte || lIt != lIte) {
        std::cout << "Containers have different sizes!" << std::endl;
    }
}

int main() {
    std::cout << "MutantStack test:" << std::endl;
    testMutantStack();
    std::cout << "\nstd::list equivalent test:" << std::endl;
    testSideBySide();
    return 0;
}
