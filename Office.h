#ifndef OFFICE_H
#define OFFICE_H

#include <iostream>
#include "Window.h"
#include "Customer.h"
#include "GenQueue.h"
using namespace std;

class Office{
    public:
        Office(int n);
        ~Office();
        void addCustomerToQueue(Customer* customer, int officeNumber);
        int isOpenWindow();
        void increaseTime();
        void checkQueue();
        int getIdleTime();
        int getMaxIdleTime();
        int getOverFive();
        int numWindows;
    
    private:
        GenQueue<Customer> *queue;
        Window **windows;
        Customer *temp;
        int idleTime;
        int maxIdleTime;



};


#endif