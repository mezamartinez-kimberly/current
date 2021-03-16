#include "arrayQueue.h"
using namespace std;

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue(){
    froInd = -1;
    backInd = -1;
    itemCount = 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const{
    return (froInd == -1);
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType &newEntry){
    if(froInd == ((backInd+1) % DEFAULT_CAPACITY)) return false; //checks if full
    else if(isEmpty()){                                          // checks if empty
        froInd++;
    }

    backInd = (backInd + 1) % DEFAULT_CAPACITY;
    items[backInd] = newEntry;
    itemCount++;
    return true;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue(){
    if(isEmpty()) return false;
    if(backInd == froInd){
        // items[froInd] = nullptr;
        backInd = -1;
        froInd = -1;
    }
    else{
        //items[froInd] = nullptr;
        froInd = (froInd + 1) % DEFAULT_CAPACITY;
    }
    itemCount--;
    return true;
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const{
    if(!isEmpty()) return items[froInd];
    else throw;
}