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

    using iterator = double *;
    using const_iterator = const double *;
    iterator begin(){return data.get();}
    iterator end(){return data.get() + m_size; }
private:
    std::unique_ptr<double[]> data = nullptr;
    size_t m_capacity = 0;
    size_t m_size = 0;
};

std::ostream &operator<<(std::ostream &out, const vector &v);

#endif //POM_VECTOR_HPP