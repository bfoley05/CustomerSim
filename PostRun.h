#ifndef POSTRUN_H
#define POSTRUN_H

#include "Customer.h"
#include <iostream>
using namespace std;

class PostRun{
    public:
        PostRun(Customer **list, int num);
        ~PostRun();
        void printResults();
    private:
        Customer **ListOfCustomers;
        int numCustomers;
        int timeAtRegistrar;
        int timeAtCashier;
        int timeAtFA;

        int maxRegistrar;
        int maxCashier;
        int maxFA;
        int tenPlus;
};


#endif