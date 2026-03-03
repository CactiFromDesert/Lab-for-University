#include "set.hpp"

//set для автоматической сортировки!!!!!!!!!!!!

/*int main()
{
    setlocale(LC_ALL,"");
    
    std::set<std::string> processed_students;
    std::vector<std::pair<std::string, int>> results;
    
    std::cout << "\n\nВведите фамилию(НА АНГЛИЙСКОМ) и баллы через пробел (Enter на пустой строке = конец):\n";
    std::cout << "Пример: Ivanov 85\n";
    
    std::string line;
    while (true)
    {
        std::cout << "\n";
        std::getline(std::cin, line);
        
        if (line.empty()) 
            break;
        
        //находим пробел
        size_t space_pos = line.find(' ');
        if (space_pos == std::string::npos)
        {
            std::cout << "  Ошибка: нужен пробел между фамилией и баллами\n";
            continue;
        }
        
        std::string surname = line.substr(0, space_pos);
        if (surname.empty())
        {
            std::cout << "  Ошибка: фамилия не может быть пустой\n";
            continue;
        }
        
        std::string score_str = line.substr(space_pos + 1);
        // Удаляем пробелы в начале
        score_str.erase(0, score_str.find_first_not_of(" \t"));
        
        int score = 0;
        try
        {
            score = std::stoi(score_str);
        }
        catch (...)
        {
            std::cout << "  Ошибка: некорректное значение баллов\n";
            continue;
        }
        
        // Приводим к нижнему регистру для проверки
        std::string lower_surname = toLower(surname);
        
        // Проверяем уникальность
        if (processed_students.find(lower_surname) != processed_students.end())
        {
            std::cout << "  Студент " << surname << " уже был! (повтор)\n";
        }
        else
        {
            processed_students.insert(lower_surname);
            results.push_back({surname, score});
            std::cout << "  Добавлено: " << surname << " " << score << "\n";
        }
    }
    
    // Вывод результатов
    std::cout << "\n========== РЕЗУЛЬТАТЫ ==========\n";
    if (results.empty())
    {
        std::cout << "Нет данных\n";
    }
    else
    {
        for (const auto& result : results)
        {
            std::cout << result.first << " - " << result.second << "\n";
        }
        std::cout << "\n\n";
    }
    
    return 0;
}*/


//unordered_set!!!!!!!!!!!!!!!!!!!!!!!!1



int main()
{
    std::unordered_set<std::string> processed_students;
    std::vector<std::pair<std::string, int>> results;
    
    std::cout << "\n\nВведите фамилию(НА АНГЛИЙСКОМ) и баллы через пробел (Enter на пустой строке = конец):\n";
    std::cout << "Пример: Ivanov 85\n";
    
    std::string line;
    while (true)
    {
        std::cout << "\n> ";
        std::getline(std::cin, line);
        
        if (line.empty()) 
            break;
        
        size_t space_pos = line.find(' ');

        if (space_pos == std::string::npos)
        {
            std::cout << "  Ошибка: нужен пробел\n";
            continue;
        }
        
        std::string surname = line.substr(0, space_pos);
        std::string score_str = line.substr(space_pos + 1);
        
        // Удаляем пробелы в начале
        score_str.erase(0, score_str.find_first_not_of(" \t"));
        
        int score = 0;
        try
        {
            score = std::stoi(score_str);
        }
        catch (...)
        {
            std::cout << "  Ошибка: некорректные баллы\n";
            continue;
        }
        
        std::string lower = toLower(surname);
        
        if (processed_students.find(lower) != processed_students.end())
        {
            std::cout << "  Студент " << surname << " уже был!\n";
        }
        else
        {
            processed_students.insert(lower);
            results.push_back({surname, score});
            std::cout << "  Добавлено: " << surname << " " << score << "\n";
        }
    }
    
    std::cout << "\n========== РЕЗУЛЬТАТЫ ==========\n";
    for (const auto& result : results)
    {
        std::cout << result.first << " - " << result.second << "\n";
    }
    std::cout << "\n\n";
    
    return 0;
}