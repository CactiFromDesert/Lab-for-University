#pragma once

#include <iostream>
#include <algorithm>
#include <cstring>
#include <filesystem>
#include <optional>
#include <string>
#include <vector>
#include <fstream>

#include "utilits.hpp"

namespace fs = std::filesystem;

std::optional<std::string> file_format(const std::string& file_path_full);

std::optional<std::string> file_path(const std::string& file_path_full);

std::optional<std::string> file_name(const std::string& file_path_full);

std::optional<std::string> file_disk(const std::string& file_path_full);

bool file_rename(std::string& file_path_full);

bool close_correct(const std::string &str, std::ifstream& source_file, 
                                           std::ofstream& dest_file, const std::string& mes);

bool file_copy(const std::string& file_path_full);