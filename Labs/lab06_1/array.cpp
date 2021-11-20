//
// Created by ingrid on 21.10.21.
//

#include "array.hpp"

// prace s polem
void print_array(const double* arr, size_t size) {
    if (size > 0)
        for (size_t i = 0; i < size - 1; i++)
            std::cout << arr[i] << " ";
    if (size > 0)
        std::cout << arr[size - 1] << std::endl;
}
void copy_array(const double* from, double* to, size_t size) {
    for (size_t i = 0; i < size; i++)
        to[i] = from[i];
}
void resize_array(double*& arr, size_t oldSize, size_t newSize) {
    double* newArr = new double[newSize];
    size_t minSize = oldSize > newSize ? newSize : oldSize;
    copy_array(arr, newArr, minSize);
    delete [] arr;
    arr = newArr;
}
void resize_array(std::unique_ptr<double[]>& arr, size_t oldSize, size_t newSize) {
    auto newArr = std::make_unique<double[]>(newSize);
    size_t minSize = oldSize > newSize ? newSize : oldSize;
    copy_array(arr.get(), newArr.get(), minSize);
    newArr.swap(arr);
}