//
// Created by nagyoing on 26.10.21.
//

#include "vector.hpp"
#include "array.hpp"
// prace s vektorem

vector::vector() :
        data(nullptr),
        m_size(0),
        m_capacity(0) { std::cout << "Ja jsem konstruktor" << std::endl; }

vector::vector(size_t sz, double value) :
        m_size(sz),
        data(std::make_unique<double[]>(sz)),
        m_capacity(sz) {
    for (size_t i = 0; i < m_size; i++)
        data[i] = value;
}

vector::vector(const vector &rhs) :
        data(std::make_unique<double[]>(rhs.m_capacity)),
        m_capacity(rhs.m_capacity),
        m_size(rhs.m_size) {
    copy_array(rhs.data.get(), data.get(), rhs.m_size);
}

vector::vector(vector &&rhs) :
        data(std::move(rhs.data)),
        m_size(rhs.m_size),
        m_capacity(rhs.m_capacity) {
    rhs.data = nullptr;
    rhs.m_size = 0;
    rhs.m_capacity = 0;
}

vector &vector::operator=(const vector &rhs) {
    data = std::make_unique<double[]>(rhs.m_capacity);
    m_capacity = rhs.m_capacity;
    m_size = rhs.m_size;
    copy_array(rhs.data.get(), data.get(), rhs.m_size);
    return *this;
}

vector &vector::operator=(vector &&rhs) {
    data = std::move(rhs.data);
    m_capacity = rhs.m_capacity;
    m_size = rhs.m_size;
    rhs.data = nullptr;
    rhs.m_size = 0;
    rhs.m_capacity = 0;
    return *this;
}

/*vector::~vector() {
//    delete [] data;
    std::cout << "~ fajront" << std::endl;
}*/
void vector::print_vector() const {
    if (m_size > 0) {
        std::cout << "Velikost: " << m_size << " Kapacita: " << m_capacity << " Data: ";
        print_array(data.get(), m_size);
    } else
        std::cout << "Ja jsem prazdny" << std::endl;
}

void vector::reserve(size_t capacity) {
    if (m_capacity == 0)
        capacity = 1;
    if (m_capacity < capacity) {
        resize_array(data, m_capacity, capacity);
        m_capacity = capacity;
    }
}

void vector::push_back(double value) {
    if (m_size == m_capacity)
        reserve(m_capacity * 2);
    data[m_size] = value;
    m_size++;
}

void vector::pop_back() {
    if (m_size > 0)
        m_size--;
}

double vector::at(size_t i) const {   // vrati hodnotu i-teho prvku
    return data[i];
}

double &vector::at(size_t i) {        // hodnotu lze i zmenit
    return data[i];
}

size_t vector::size() const {
    return m_size;
}

size_t vector::capacity() const {
    return m_capacity;
}

void vector::clear() {
    m_size = 0;
}

void vector::resize(size_t size, double value) {  // zmeni velikost vektoru
    while (size > m_capacity)                       // na volna mista zapise hodnotu value
        reserve(m_capacity * 2);
    for (size_t i = m_size; i < size; i++) {
        data[i] = value;
    }
    m_size = size;
}

void vector::resize(size_t size) {                // volna mista vynuluje
    resize(size, 0);
}

std::ostream &operator<<(std::ostream &out, const vector &v) {
    if (v.size() > 0) {
        out << "=== Velikost: " << v.size() << " Kapacita: " << v.capacity() << " Data: ";
        for (size_t i = 0; i < v.size() - 1; i++) {
            out << v[i] << " ";
        }
    } else
        out << "Ja jsem prazdny" << std::endl;
    return out;
}
