//
// Created by ingrid on 21.10.21.
//

#ifndef CV01_ARRAY_HPP
#define CV01_ARRAY_HPP

#include <iostream>
#include <memory>

void print_array(const double* arr, size_t size);
void copy_array(const double* from, double* to, size_t size);
void resize_array(double*& arr, size_t oldSize, size_t newSize);
void resize_array(std::unique_ptr<double[]>& arr, size_t oldSize, size_t newSize);

#endif //CV01_ARRAY_HPP