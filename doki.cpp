#include <iostream>

/*class MyClass 
{
private:
    int value;
public:
    MyClass(int v = 0) : value(v) {}
    
    std::ostream& operator<<(std::ostream& os) 
    {
        os << "Value: " << value;
        return os;
    }
};

int main() 
{
    MyClass obj(42);
    
    std::cout << obj;
    
    return 0;
}///OШИБКА*/


/*class MyClass 
{
private:
    int value;
public:
    MyClass(int v = 0) : value(v) {}

    friend std::ostream &operator<<(std::ostream &os, MyClass &m); //Нужен, чтобы не писать getter-ы 
};

std::ostream& operator<<(std::ostream &os, MyClass& m) 
{
    os << "Value: " << m.value;
    return os;
}

int main() 
{
    MyClass obj(42);
    
    std::cout << obj;
    
    return 0;
}//Работает */



class MyClass 
{
private:
    int value;
public:
    MyClass(int v = 0) : value(v) {}

    int get_value() const
    {
        return value;
    }
    
};

std::ostream &operator<<(std::ostream &os, MyClass& m) 
{
    os << "Value: " << m.get_value();
    return os;
}

int main() 
{
    MyClass obj(42);
    
    std::cout << obj;
    
    return 0;
}//тоже работает