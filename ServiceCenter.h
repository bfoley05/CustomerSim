#ifndef SERVICECENTER_H
#define SERVICECENTER_H

#include <iostream>
#include "Office.h"
#include "Customer.h"
using namespace std;

class ServiceCenter{
    public:
        ServiceCenter(int r, int c, int fa, Customer **CustomerList);
        ~ServiceCenter();
        void operate(int nc, int clockTick);
        void printIdleTime();
        bool isMoreOffices();
    private:
        Office *Registrar;
        Office *Cashier;
        Office *Financial_aid;
        Customer **ListOfCustomers;
        int counter;
        int numCustomers;
};


#endif