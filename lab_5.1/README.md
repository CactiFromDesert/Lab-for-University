Task №5.1
Написать класс матриц. 

Свойства класса: число строк, число столбцов, одномерный динамический массив для хранения элементов.

Реализовать методы 
matr* sum(const matr * mat2) или sum(const matr * mat2) - сложения матриц, 
matr* mult(const matr * mat2) или void mult(const matr * mat2) - умножения двух матриц, 
double trace() - след матрицы (сумма диагональных элементов квадратной матрицы),
double det()  - определитель матрицы (для квадратных),
matr* mult_by_num(double num)  или void mult_by_num(double num)   - умножение матрицы на число,
void input() - ввести матрицу с клавиатуры, 
void print() - печать матрицы в консоль, 
int get_columns() - количество столбцов,
int get_rows() - количество строк
double get_elem(int i, int j) - вернуть (i,j) элемент 

**компиляция Valgrind происходит через "make vallg"(мое вольное сокращение)
