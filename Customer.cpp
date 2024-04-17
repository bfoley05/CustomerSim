#include "Customer.h"
#include <sstream>

Customer::Customer(int startTime, string code){
    waitTime = 0;
    timeToStart = startTime;
    officeNumber = 0;
    isFree = true;
    stringstream ss(code);

    // Allocate memory for timeAtOffice and officeOrder
    timeAtOffice = new int[3];
    officeOrder = new char[3];
    waitTimeAtOffice = new int[3];


    for (int i = 0; i < 3; ++i) {
        waitTimeAtOffice[i] = 0;
    }

    // Read values from the stringstream and store them in the arrays
    for (int i = 0; i < 3; ++i) {
        ss >> timeAtOffice[i];

    }

    for (int i = 0; i < 3; ++i) {
        ss >> officeOrder[i];
    }
}


Customer::~Customer(){
    delete[] timeAtOffice;
    delete[] officeOrder;
}

int Customer::getWaitTime(){
    return waitTime;
}
