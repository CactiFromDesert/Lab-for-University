Task №5.2
Перегрузить методы класса матриц. 

Matrix(int i, int j); -//констуктор, i - количество строк, j - количество столбцов, элементы определяются 0;

Matrix(int i, int j, const double* arr); //констуктор, i - количество строк, j - количество столбцов, элементы определяются массивом arr;

Matrix sum(const double * arr), или void sum(const double * arr), или Matrix sum(const double * arr, int size), или void sum(const double * arr, int size)  - сложения матриц, результат возвращается или записывается в текущую матрицу соответственно; 

Matrix mult(const double * arr), или void mult(const double * arr), или 
Matrix mult(const double * arr, int size), или void mult(const double * arr, int size) - умножения двух матриц, результат возвращается или записывается в текущую матрицу соответственно; 

void input(int i, int j) - ввести матрицу с клавиатуры c заданными размерами, i - количество строк, j - количество столбцов;

void input(int i, int j, double * arr) - инициализировать матрицу заданным массивом arr, i - количество строк, j - количество столбцов.

**компиляция Valgrind происходит через "make vallg"(мое вольное сокращение)
