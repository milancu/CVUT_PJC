//
// Created by nagyoing on 26.10.21.
//

#ifndef POM_VECTOR_HPP
#define POM_VECTOR_HPP

#include <iostream>
#include <memory>

class vector {
public:
    vector();

    vector(size_t sz, double value);

    vector(const vector &rhs);

    vector(vector &&rhs);

    vector &operator=(const vector &rhs);

    vector &operator=(vector &&rhs);

//    ~vector();
    void print_vector() const;

    void reserve(size_t capacity);

    void push_back(double value);

    void pop_back();

    double at(size_t i) const;

    double &at(size_t i);

    double operator[](size_t i) const { return data[i]; };

    double &operator[](size_t i) { return data[i]; };

    size_t size() const;

    size_t capacity() const;

    void clear();

    void resize(size_t size, double value);

    void resize(size_t size);

    friend std::ostream &operator<<(std::ostream &out, const vector &v);

    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = double;
        using reference = double &;
        using pointer = double *;

        iterator() = default;

        iterator(const iterator &) = default;

        iterator(double *d) : ptr(d) {};

        bool operator==(const iterator &rhs) const { return ptr == rhs.ptr; };

        bool operator!=(const iterator &rhs) const { return ptr != rhs.ptr; };

        bool operator>(const iterator &rhs) const { return ptr > rhs.ptr; };

        bool operator>=(const iterator &rhs) const { return ptr >= rhs.ptr; };

        bool operator<(const iterator &rhs) const { return ptr < rhs.ptr; };

        bool operator<=(const iterator &rhs) const { return ptr <= rhs.ptr; };

        iterator operator+(size_t sz) const { return iterator(ptr + sz); };

        iterator operator-(size_t sz) const { return iterator(ptr - sz); };

        iterator &operator+=(size_t sz) {
            ptr += sz;
            return *this;
        };

        iterator &operator-=(size_t sz) {
            ptr -= sz;
            return *this;
        };

        double &operator[](size_t sz) { return ptr[sz]; }

        size_t operator-(const iterator &rhs) { return ptr - rhs.ptr; };

        double *operator->() { return ptr; };

        double &operator*() { return *ptr; };

        iterator &operator++() {
            ++ptr;
            return *this;
        };

        iterator operator++(int) {
            iterator tmp(*this);
            ++ptr;
            return tmp;
        };

        iterator &operator--() {
            --ptr;
            return *this;
        };

        iterator operator--(int) {
            iterator tmp(*this);
            --ptr;
            return tmp;
        };


    private:
        double *ptr;
    };

    using const_iterator = const double *;

    iterator begin() { return iterator(data.get()); };

    iterator end() { return iterator(data.get() + m_size); }

private:
    std::unique_ptr<double[]> data = nullptr;
    size_t m_capacity = 0;
    size_t m_size = 0;
};

std::ostream &operator<<(std::ostream &out, const vector &v);

#endif //POM_VECTOR_HPP