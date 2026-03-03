#include "task.hpp"
//#include "else.hpp"

//Функции ориентации
int orientation(const Point& A, const Point& B, const Point& C)
{
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

//Проверка полиндрома
bool isPalindrome(const char* str)
{
    Deque<char> dq;
    
    for (int i = 0; str[i] != '\0'; i++)
        dq.push_back(str[i]);
    
    while (dq.size() > 1)
    {
        char first = dq.front();
        char last = dq.back();
        
        if (first != last)
            return false;
        
        dq.pop_front();
        dq.pop_back();
    }
    
    return true;
}

//ФУНКЦИИ ДЛЯ АЛГОРИТМА ГРЭХЕМА

//Нахождение индекса самой левой точки
int findLeftmostPointIndex(const Deque<Point>& points)
{
    int min_idx = 0;
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i].x < points[min_idx].x)
            min_idx = i;
        else if (points[i].x == points[min_idx].x && points[i].y < points[min_idx].y)
            min_idx = i;
    }
    return min_idx;
}

// Функция сравнения для сортировки точек по полярному углу
bool comparePoints(const Point& pivot, const Point& a, const Point& b)
{
    int orient = orientation(pivot, a, b);
    
    if (orient == 0)
    {
        int dist_a = (a.x - pivot.x) * (a.x - pivot.x) + (a.y - pivot.y) * (a.y - pivot.y);
        int dist_b = (b.x - pivot.x) * (b.x - pivot.x) + (b.y - pivot.y) * (b.y - pivot.y);
        return dist_a < dist_b;
    }
    
    return orient > 0; // Сортировка против часовой стрелки
}

// Перемещение точки с индексом idx в начало дека
void movePointToFront(Deque<Point>& points, int idx)
{
    if (idx == 0) return;
    
    Point temp = points[idx];
    for (int i = idx; i > 0; i--) 
        points[i] = points[i - 1];
    points[0] = temp;
}

// Сортировка точек (кроме первой) по полярному углу (пузырьковм)
void sortPointsByAngle(Deque<Point>& points)
{
    int n = points.size();
    if (n <= 2) return;
    
    Point pivot = points[0];
    
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (!comparePoints(pivot, points[j], points[j + 1]))
            {
                Point temp = points[j];
                points[j] = points[j + 1];
                points[j + 1] = temp;
            }
        }
    }
}

// Удаление коллинеарных точек 
Deque<Point> removeCollinearPoints(const Deque<Point>& points)
{
    Deque<Point> result;
    int n = points.size();
    
    if (n < 3) return points;
    
    result.push_back(points[0]);
    
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && orientation(points[0], points[i], points[i + 1]) == 0)
            i++;
        result.push_back(points[i]);
    }
    
    return result;
}

// АЛГОРИТМ ГРЭХЕМА 

Deque<Point> grahamScan(Deque<Point> points)
{
    int n = points.size();
    
    // Если точек меньше 3, возвращаем все точки
    if (n < 3) 
        return points;
    

    int leftmost_idx = findLeftmostPointIndex(points);
    movePointToFront(points, leftmost_idx);
    
    sortPointsByAngle(points);

    points = removeCollinearPoints(points);
    
    n = points.size();
    if (n < 3) 
        return points;
    
    Deque<Point> hull;

    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);
    

    for (int i = 3; i < n; i++)
    {
        while (hull.size() >= 2)
        {
            Point C = points[i];
            Point B = hull.back();
            hull.pop_back();
            Point A = hull.back();
            hull.push_back(B); 
            
            // Если точка C справа от вектора AB (правый поворот)
            if (orientation(A, B, C) <= 0) 
                hull.pop_back(); 
            else 
                break;
            
        }
        hull.push_back(points[i]);
    }
    
    return hull;
}


void printPoints(const Deque<Point>& points)
{
    std::cout << "Points of the convex hull: ";
    for (int i = 0; i < points.size(); i++) 
        std::cout << "(" << points[i].x << ", " << points[i].y << ") ";

    std::cout << std::endl;
}

void addPoint(Deque<Point>& points, int x, int y)
{
    static int point_id = 0;
    points.push_back(Point(x, y, point_id++));
}
