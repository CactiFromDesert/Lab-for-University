#include "task.hpp"
#include "Stack.hpp"

/*bool check_brackets(const std::string& str)
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
}*/

bool check_brackets(const std::string& str)
{
    DynamicCharStack br;
    int kolvo = str.size();
    initDynamicStack(&br, kolvo);
    
    for(char i : str)
    {
        if(i == '{' || i == '[' || i == '(')
            push(&br, i);
        else if(i == '}' || i == ']' || i == ')')
        {
            if(isEmpty(&br))
            {
                clear(&br);
                return false;
            }
            
            char top_char = top(&br);
            if((i == ')' && top_char == '(') || 
               (i == '}' && top_char == '{') || 
               (i == ']' && top_char == '['))
            {
                pop(&br);
            }
            else
            {
                clear(&br);
                return false;
            }
        }
    }
    
    bool result = isEmpty(&br);
    clear(&br);
    return result;
}