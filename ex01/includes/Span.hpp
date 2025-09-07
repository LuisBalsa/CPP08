#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    template <typename InputIterator>
    void addRange(InputIterator first, InputIterator last);
    int shortestSpan() const;
    int longestSpan() const;

private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
};

#include "Span.tpp"

#endif
