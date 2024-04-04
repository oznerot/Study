#include "Queue.h"
#include <iostream>

using TYPE = int;

void queue_status(Queue<TYPE>& Q)
{
    std::cout << "Queue capacity: " << Q.capacity() << std::endl;
    std::cout << "Queue size: " << Q.size() << std::endl;
    std::cout << "Queue emptiness: " << Q.empty() << std::endl;

    for(size_t i = 0; i < Q.size(); i++)
        std::cout << Q[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    Queue<TYPE> q;
    std::cout << "Queue default constructed" << std::endl;
    queue_status(q);

    std::cout << "Enqueue 69" << std::endl;
    q.enqueue(69);
    queue_status(q);

    std::cout << "Enqueue 420, resize expected" << std::endl;
    q.enqueue(420);
    queue_status(q);

    std::cout << "Enqueue 420, resize expected" << std::endl;
    q.enqueue(420);
    queue_status(q); 



    std::cout << std::endl;
    return 0;
}
