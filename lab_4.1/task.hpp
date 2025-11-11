#pragma once

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <limits>

#include "utilits.hpp"

bool palindrome(char* str);

void ceasar(char* str_for_encrypt, int key);

void out_str(const char* str);

int find_substring1(const char* str, const char* substr, int start_pos);

std::pair<int*, size_t> find_substring2(const char* str, const char* substr);