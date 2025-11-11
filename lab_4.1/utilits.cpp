#include "utilits.hpp"

char* getline_cstyle() 
{
    try 
    {
        size_t capacity = 256, size = 0;       
        char* buffer = new char[capacity];  
        
        while (true)
        {
            int c = std::getchar();  
            
            if (c == EOF || c == '\n') 
            {
                buffer[size] = '\0'; 
                break;
            }
            
            buffer[size++] = static_cast<char>(c);
            
            if (size >= capacity - 1) 
            {
                capacity *= 2; 
                char* new_buffer = new char[capacity];
                std::memcpy(new_buffer, buffer, size);
                delete[] buffer;
                buffer = new_buffer;
            }
        }
        
        char* result = new char[size + 1];
        std::strcpy(result, buffer);
        delete[] buffer;
 
        return result;
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';//!!!!!!!!!!!!!!!!!
    }
}


void compute_z(const char* s, int* z, size_t n) 
{
    size_t l = 0, r = 0;  // Границы самого правого Z-блока
    z[0] = 0;         

    for (size_t i = 1; i < n; ++i) 
    {
        if (i <= r) 
            z[i] = (static_cast<int>(r - i + 1) < z[i - l]) ? static_cast<int>(r - i + 1) : z[i - l];
        else
            z[i] = 0;
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) 
            ++z[i];
    
        if (i + z[i] - 1 > r) 
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

