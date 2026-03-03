//#include "else.hpp"
#include "task.hpp"


int main()
{
    std::cout << "Task 1: Palindrom\n";
    
    char input_str[100];
    std::cout << "Entrer the line: ";
    std::cin.getline(input_str, 100);
    
    if (isPalindrome(input_str))
        std::cout << "Is palindrom\n";
    else
        std::cout << "is NOT palindrome\n";
    

    std::cout << "Task 2: Graham's algorithm: \n";
    
    Deque<Point> points;
    
    // Добавляем тестовые точки
    addPoint(points, 0, 0);
    addPoint(points, 2, 0);
    addPoint(points, 3, -2);
    addPoint(points, 3, 3);
    addPoint(points, 4, 1);
    addPoint(points, 4, 4);
    addPoint(points, 5, 4);
    
    std::cout << "Starting points:\n";
    for (int i = 0; i < points.size(); i++)
        std::cout << "  " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ")\n";
    
    Deque<Point> convex_hull = grahamScan(points);

    printPoints(convex_hull);
    
    return 0;
}

/*0 0
2 0
3 -2
3 3
4 1
4 4
5 4*/

