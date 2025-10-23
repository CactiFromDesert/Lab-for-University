#include "task.hpp"

//namespace fs = std::filesystem;

std::optional<std::string> file_format(const std::string& file_path_full) 
{
    fs::path path(file_path_full);
    if (path.filename().string().find_first_of("/\\:*?\"<>|") != std::string::npos)
    {
        return std::nullopt;
    }
    return path.extension();
}

std::optional<std::string> file_name(const std::string& file_path_full) 
{
    fs::path path(file_path_full);
    if (path.filename().string().find_first_of("/\\:*?\"<>|") != std::string::npos)
    {
        return std::nullopt;
    }
    //return path.filename(); 
    return path.stem();
}

std::optional<std::string> file_path(const std::string& file_path_full) 
{
    fs::path path(file_path_full);
    if (path.filename().string().find_first_of("/\\:*?\"<>|") != std::string::npos)
    {
        return std::nullopt;
    }
    //return path.root_path(); 
    //return path.native();
    //return path.string();
    return path.generic_string();
}

std::optional<std::string> file_disk(const std::string& file_path_full) 
{
    fs::path path(file_path_full);
    if (path.filename().string().find_first_of("/\\:*?\"<>|") != std::string::npos)
    {
        return std::nullopt;
    }
    return path.root_path();
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!

bool file_rename(std::string& file_path_full)
{
    fs::path path(file_path_full);
    if (path.filename().string().find_first_of("/\\:*?\"<>|") != std::string::npos)
        return false;
        
    if (file_path_full.empty())
        return false;
    try
    {
        fs::path old_path(file_path_full);

        if (old_path.filename().empty())
            return false;

        fs::path parent_path = old_path.parent_path();
        std::string extension = old_path.extension().string(), new_filename;
        std::cout << "Input new file name:\n";
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, new_filename);
        //проверка на знаки в новом имени
        new_filename.erase(0, new_filename.find_first_not_of(" \t"))
                    .erase(new_filename.find_last_not_of(" \t") + 1);

        if (new_filename.empty())
            return false;

        if (new_filename.back() == '/' || new_filename.back() == '\\') 
        {
            std::cerr << "Error: Filename cannot end with path separator\n";
            return false;
        }

        fs::path new_filename_path(new_filename);
        std::string clean_filename = new_filename_path.filename().string();

        fs::path new_path = parent_path / clean_filename;

        if (!extension.empty()) {
            fs::path new_filename_check(clean_filename);
            if (new_filename_check.extension().empty())
                new_path.replace_extension(extension);
        }

        file_path_full = new_path.string();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}


bool close_correct(const std::string &str, std::ifstream& source_file, 
                                           std::ofstream& dest_file, const std::string& mes) 
{
    std::cerr << mes << '\n';
    source_file.close();
    dest_file.close();
    fs::remove(str);
    return false;
}

bool file_copy(const std::string& file_path_full) 
{
    if (!fs::exists(file_path_full) || !fs::is_regular_file(file_path_full)) 
    {
        std::cerr << "Error: Source file does not exist or is not a regular file\n";
        return false;
    }

    std::ifstream source_file(file_path_full, std::ios::binary);
    if (!source_file.is_open()) 
    {
        std::cerr << "Error: Cannot open source file for reading\n";
        return false;
    }

    try 
    {
        fs::path source_path(file_path_full);
        fs::path copy_path = source_path.parent_path() / 
                            (source_path.stem().string() + "_copy" + 
                             source_path.extension().string());

        std::string copy_path_str = copy_path.string();

        if (fs::exists(copy_path_str)) 
        {
            std::cerr << "Error: Copy file already exists: " << copy_path_str << '\n';
            source_file.close();
            return false;
        }

        std::ofstream dest_file(copy_path_str, std::ios::binary);
        if (!dest_file.is_open()) {
            std::cerr << "Error: Cannot create copy file for writing\n";
            source_file.close();
            return false;
        }

        auto file_size = fs::file_size(file_path_full);
        
        const size_t buffer_size = std::min<std::uintmax_t>(
            std::max<std::uintmax_t>(4096, file_size), 
            file_size
        );//!!!

        std::vector<char> buffer(buffer_size);

        while (source_file) 
        {
            source_file.read(buffer.data(), buffer.size());
            auto bytes_read = source_file.gcount();
            
            if (bytes_read > 0) 
            {
                dest_file.write(buffer.data(), bytes_read);
                
                if (!dest_file) 
                    return close_correct(copy_path_str, source_file, dest_file, "Error copy");
            }
        }
        

        if (source_file.bad()) 
        {
            return close_correct(copy_path_str, source_file, dest_file, 
                                 "Error: Read from source file failed");
        }
        source_file.close();
        dest_file.close();

        if (fs::file_size(file_path_full) != fs::file_size(copy_path_str)) 
        {
            std::cerr << "Error: Copy file size doesn't match original\n";
            fs::remove(copy_path_str);
            return false;
        }

        std::cout << "File copied successfully: " << copy_path_str << '\n';
        return true;

    } 
    catch (const fs::filesystem_error& e) 
    {
        std::cerr << "Filesystem error: " << e.what() << '\n';
        source_file.close();
        return false;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << '\n';
        source_file.close();
        return false;
    }
}

