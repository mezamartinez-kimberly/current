#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

using namespace std;

class Event{
    private:
        char eveType;
        int arrTime;
        int transTime;
    public:
        Event(); 
        Event(int arrTime, int transTime);
        Event(char eveType, int arrTime, int transTime);
        void addArrTime(int a);
        void addTransTime(int a);
        char getEveType() const;
        int getArrTime() const;
        int getTransTime() const;
        friend bool operator < (const Event &a, const Event &b);
        friend bool operator > (const Event &a, const Event &b);
        friend bool operator == (const Event &a, const Event &b);
};
Event::Event(){
    eveType = ' ';
    arrTime = 0;
    transTime = 0;
}

Event::Event(int conArrTime, int conTransTime){
    arrTime = conArrTime;
    transTime = conTransTime;
    eveType = 'A'; //? unsure and why
}

Event::Event(char inEveType, int inArrTime, int inTransTime){
    eveType = inEveType;
    arrTime = inArrTime;
    transTime = inTransTime;
}

char Event::getEveType() const{
    return eveType;
}

int Event::getArrTime() const{
    return arrTime;
}

int Event::getTransTime() const{
    return transTime;
}

bool operator < (const Event &a, const Event &b) {
            if(a.arrTime < b.arrTime) return true;
            else return false;
        }

bool operator > (const Event &a, const Event &b) {
            if(a.arrTime > b.arrTime) return true;
            else return false;
        }
bool operator == (const Event &a, const Event &b) {
            if(a.arrTime == b.arrTime) return true;
            else return false;
        }
void Event::addArrTime(int a) {
    arrTime = a;
}

void Event::addTransTime(int a) {
    transTime = a;
}
#endif