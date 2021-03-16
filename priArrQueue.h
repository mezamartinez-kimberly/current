#ifndef PRIORITY_ARRAY_QUEUE
#define PRIORITY_ARRAY_QUEUE

#include "queueInterface.h"

template<class ItemType>
class PriorityArrayQueue: public QueueInterface<ItemType>{
    private:
        static const int DEFAULT_CAPACITY = 100;
        int froInd, backInd, itemCount;
        ItemType items[DEFAULT_CAPACITY - 1];

    public:
        PriorityArrayQueue();
        bool isEmpty() const;
        bool enqueue(const ItemType& newEntry); //implement dif from arrQueue; easiest way to input logic around priority
        bool dequeue();
        ItemType peekFront() const;
        ~PriorityArrayQueue() { }
};
// #include "priArrQueue.cpp"
#endif