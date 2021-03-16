#include <iostream>
#include "events.h"

using namespace std;

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

bool Event::operator < (const Event &a) {
            if(arrTime < a.arrTime) return true;
            else return false;
        }

bool Event::operator > (const Event &a) {
            if(arrTime > a.arrTime) return true;
            else return false;
        }
bool Event::operator == (const Event &a) {
            if(arrTime == a.arrTime) return true;
            else return false;
        }
void Event::addArrTime(int a){
    arrTime = a;
}

void Event::addTransTime(int a){
    transTime = a;
}