#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;

class Customer{
    public:
        Customer();
        Customer(int startTime, string code);
        ~Customer();
        int getWaitTime();
        int timeToStart;
        bool isFree;
        int officeNumber;
        int *timeAtOffice;
        int *waitTimeAtOffice;
        char *officeOrder;
        int waitTime;
        int howManyOffices;
    
    private:
};


#endif