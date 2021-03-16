//Joey Isola & Kimberly Meza Martinez
//HW 3: Array based queue
//3.14.21


#include <iostream>
#include <fstream>
#include "events.h"
#include "arrayQueue.cpp"
#include "priArrQueue.cpp"

using namespace std;

int main(){
    fstream file("text2.txt");
    int size = 200;
    int arr[size];

    int read, count = 0;
    
    //ArrayQueue<Event> a;
    PriorityArrayQueue<Event> a;

    cout << "hi" << endl;
    while(count < size && file >> read){
        Event b;
        b.addArrTime(read);
        file >> read;
        b.addTransTime(read);
        a.enqueue(b);
        count++;
    }
    cout << "hi" << endl;

    for(int i=0; i<count; i++){
        Event c = a.peekFront();
        cout << i + 1 << ": Arrival: " << c.getArrTime() << " Transaction Time: " << c.getTransTime() << endl;
        a.dequeue();
    }


    // Event t;
    // Event s;

    // t.addArrTime(1);
    // s.addArrTime(2);

    // if(t > s) cout << "yes";
    // else cout << "no";



}