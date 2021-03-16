#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

#include "queueInterface.h"

template<class ItemType>
class ArrayQueue: public QueueInterface<ItemType>{
    private:
        static const int DEFAULT_CAPACITY = 100;
        int froInd, backInd, itemCount;
        ItemType items[DEFAULT_CAPACITY - 1];

    public:
        ArrayQueue();
        bool isEmpty() const;
        bool enqueue(const ItemType& newEntry);
        bool dequeue();
        ItemType peekFront() const;
        ~ArrayQueue() { }
};
//#include "arrayQueue.cpp"
#endif