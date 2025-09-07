#ifndef SPAN_TPP
#define SPAN_TPP

template <typename InputIterator>
void Span::addRange(InputIterator first, InputIterator last) {
    size_t distance = std::distance(first, last);
    if (_numbers.size() + distance > _maxSize)
        throw std::out_of_range("Span will exceed max size");
    _numbers.insert(_numbers.end(), first, last);
}

#endif
