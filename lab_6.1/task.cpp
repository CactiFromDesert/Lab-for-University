#include "task.hpp"

bool check_brackets(const std::string& str)
{
    std::stack<char> br;
    for(char i : str)
    {
        if(i == '{' || i == '[' || i == '(')
            br.push(i);
        else if(i == '}' || i == ']' || i == ')')
        {
            if(br.empty())
                return false;
            char top = br.top();
            if((i == ')' && top == '(') || (i == '}' && top == '{') || (i == ']' && top == '['))
                br.pop();
            else
                return false;

        }
    }
    return br.empty();
}