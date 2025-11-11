#include "task.hpp"

bool palindrome(char* str)
{
    if (!str) return false;
    
    for (char* p = str; *p != '\0'; ++p)
    {
        *p = std::tolower(*p);
    }
    
    size_t i = 0, k = strlen(str) - 1;
    
    while (i < k)
    {
        while (i < k && str[i] == ' ')
        {
            ++i;
        }
        
        while (i < k && str[k] == ' ')
        {
            --k;
        }
        
        if (i >= k)
        {
            break;
        }
        
        if (str[i] != str[k])
        {
            return false;
        }
        
        ++i;
        --k;
    }
    
    return true;
}


void ceasar(char* str_for_encrypt, int key)
{
    key %= 26;
    if(key < 0)
    {
        key += 26;
    }

    for(size_t i = 0; i < strlen(str_for_encrypt); ++i)
    {
        if(std::isalpha(str_for_encrypt[i]))
        {
            char base = std::isupper(str_for_encrypt[i]) ? 'A' : 'a';
            str_for_encrypt[i] = static_cast<char>((str_for_encrypt[i] + key - base) % 26 + base);
        }
    }
}


void out_str(const char* str) 
{
    bool inside_quotes = false;
    size_t start = std::numeric_limits<size_t>::max(), size = strlen(str);
    
    for (size_t i = 0; i < size; ++i) 
    {
        if  (str[i] == '"') 
        {
            if (inside_quotes) 
            {
                if (start != std::numeric_limits<size_t>::max()) 
                {
                    for (size_t j = start; j < i; ++j) 
                    {
                        std::cout << str[j];
                    }
                    std::cout << " | ";
                }
                inside_quotes = false;
                start = std::numeric_limits<size_t>::max();
            } 
            else 
            {
                inside_quotes = true;
                start = i + 1;
            }
        }
    }
    std::cout << "\n";
}



int find_substring1(const char* str, const char* substr, int start_pos) 
{
    try 
    {
        if (!str || !substr || start_pos < 0) 
            return -1;

        size_t n = strlen(str);
        size_t m = strlen(substr);
        if (m == 0 || static_cast<size_t>(start_pos) >= n) 
            return -1;

        size_t combined_len = m + 1 + (n - start_pos);
        char* combined = new char[combined_len + 1];  // +1 для '\0'
        strcpy(combined, substr);
        combined[m] = '#';
        strcpy(combined + m + 1, str + start_pos);

        int* z = new int[combined_len];
        compute_z(combined, z, combined_len);

        // Ищем вхождения (где z[i] == m)
        for (size_t i = m + 1; i < combined_len; ++i) 
        {
            if (z[i] == static_cast<int>(m)) 
            {
                delete[] combined;
                delete[] z;
                return start_pos + (i - m - 1);
            }
        }
        delete[] combined;
        delete[] z;
        return -1;
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';//!!!!!!!!!!!!!!!!!
    }
}

std::pair<int*, size_t> find_substring2(const char* str, const char* substr) 
{
    try
    {
        int* array_pos = new int[strlen(str)];

        size_t need_i = 0;
        int current = 0;
        int found_pos = 0;


        while((found_pos = find_substring1(str, substr, current)) != -1)
        {
            array_pos[need_i] = found_pos;
            current = found_pos + 1;
            ++need_i;
        }

        int* b = new int[need_i];
        std::copy(array_pos, array_pos + need_i, b);
        delete[] array_pos;
        array_pos = b;

        return {array_pos,need_i};
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';//!!!!!!!!!!!!!!!!!
    }
}