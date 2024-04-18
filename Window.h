#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include "Customer.h"
using namespace std;

class Window{
    public:
        Window();
        ~Window();
        bool isTaken();
        void setTime(Customer *customer, int officeNumber);
        int waitTime();
        void decreaseTime();
        int getIdleTime();
    
    private:
        Customer *currentCustomer;
        int time;
        int idleTime;
};

#endif