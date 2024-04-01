#include <vector>
#include <iostream>
#include "Stack.h"

#define TYPE char
#define SIZE 100
void stack_status(Stack<TYPE>& S)
{
    std::cout << "Stack capacity: " << S.capacity() << std::endl;
    std::cout << "Stack size: " << S.size() << std::endl;
    std::cout << "Is Stack empty: " << S.empty() << std::endl;

    for(size_t i = 0; i < S.size(); i++)
        std::cout << S[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    Stack<TYPE> stack(10, 5);
    stack_status(stack);

    for(size_t i = 0; i < stack.size(); i++)
        stack[i] = (static_cast<int>(i) + 'a');
    
    stack_status(stack);

    std::cout << "Pushing 420" << std::endl;
    stack.push_back('z');

    stack_status(stack);
    std::cout << std::endl;

    std::cout << "Popping everything but index = 0" << std::endl;
    std::cout << stack.size() << std::endl;
    size_t sz = stack.size() + 1;
    for(size_t i = 0; i < sz; i++){
        stack.pop_back();
        std::cout << "Size: " << stack.size() << std::endl;
    }
    
    stack_status(stack);
    return 0;
}