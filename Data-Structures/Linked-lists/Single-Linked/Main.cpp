#include <iostream>
#include "SinglyLinked.h"

int main(int argc, char** argv)
{
    List L;

    for(int i = 0; i < 10; i++)
        L.prepend(i);

    L.print();

    L.insert(420, 3);
    L.print();

    L.append(69);
    L.print();

    L.remove(420);
    L.print();

    std::cout << std::endl;
    return 0;
}