#pragma once

#include <iostream>
#include <algorithm>

#include "utilits.hpp"

void bubble(int* arr, size_t size);

void count_sort(char* array, size_t size);

void selection_sort(int* arr, size_t n);

void merge_sort(int* array, size_t size);

void merge_sort_impl(int* array, int left, int right);

void merge(int* array, int left, int mid, int right);