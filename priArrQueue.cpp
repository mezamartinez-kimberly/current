#include "priArrQueue.h"
#include "events.h"

using namespace std;

template<class ItemType>
PriorityArrayQueue<ItemType>::PriorityArrayQueue(){
    froInd = -1;
    backInd = -1;
    itemCount = 0;
}

template<class ItemType>
bool PriorityArrayQueue<ItemType>::isEmpty() const{
    return(froInd == -1);
}
//implement dif from arrQueue; easiest way to input logic around priority
template<class ItemType>
bool PriorityArrayQueue<ItemType>::enqueue(const ItemType& newEntry){
    if(froInd == ((backInd+1) % DEFAULT_CAPACITY)){      //if full
        cout << "Queue is full" << endl;
        return false;
    }
    else if(isEmpty()){ //checks if nothing is in 
        froInd++;
        backInd++;
        items[backInd] = newEntry;
        itemCount++;
        return true;
    }
    else if(froInd == backInd){                         // if only 1
        backInd = ((backInd + 1) % DEFAULT_CAPACITY);
        items[backInd] = newEntry;
        if(items[backInd] < items[froInd]){
            ItemType temp = items[froInd];
            items[froInd] = items[backInd];
            items[backInd] = temp;
            itemCount++;
            return true;
        }
    }
    else{ //compare elements to check priority 
        backInd = ((backInd + 1) % DEFAULT_CAPACITY); // put in back of queue
        items[backInd] = newEntry;
        int i = ((backInd - 1) % DEFAULT_CAPACITY);
        while(i != froInd){                                         // bubble sort
            if(items[i] > items[(i+1) % DEFAULT_CAPACITY]){
                ItemType temp = items[i];
                items[i] = items[(i+1) % DEFAULT_CAPACITY];
                items[(i + 1) % DEFAULT_CAPACITY] = temp;
            }
            i = ((i - 1) % DEFAULT_CAPACITY);
        }
        itemCount++;
        return true;
    }
    return true;
}

template<class ItemType>
bool PriorityArrayQueue<ItemType>::dequeue(){
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
ItemType PriorityArrayQueue<ItemType>::peekFront() const{
    if(!isEmpty()) return items[froInd];
    else throw;
}
