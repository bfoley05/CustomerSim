#include "Office.h"

Office::Office(int n){
    numWindows = n;
    idleTime = 0;
    maxIdleTime = 0;
    windows = new Window*[n];
    queue = new GenQueue<Customer>();
    for(int i = 0; i < n; ++i){
        windows[i] = new Window();
    }
}

Office::~Office() {
    delete queue;
}



void Office::addCustomerToQueue(Customer *customer, int officeNumber) {
    queue->insert(customer);
    int windowNum = isOpenWindow();
    if(windowNum>=0){
        temp = queue->dequeue();
        windows[windowNum]->setTime(temp, officeNumber);
    }
}

void Office::checkQueue(){
    if(queue->getSize() != 0){
        int windowNum = isOpenWindow();
        if(windowNum>=0){
            temp = queue->dequeue();
            windows[windowNum]->setTime(temp, temp->officeNumber);
        }
    }
}

int Office::isOpenWindow(){
    for(int i = 0; i < numWindows; ++i){

        if(!windows[i]->isTaken()){
            return i;
        }
    }
    return -1;
}

void Office::increaseTime(){
    for(int i = 0; i < numWindows; ++i){
        windows[i]->decreaseTime();
    }
    int size = queue->getSize();
    for(int i = 0; i < size; ++i){
        Customer *curr = queue->dequeue();
        curr->waitTime++;
        curr->waitTimeAtOffice[curr->officeNumber]++;
        queue->insert(curr);
    }
}

int Office::getIdleTime(){
    for(int i = 0; i < numWindows; ++i){
        idleTime += windows[i]->getIdleTime();
    }
    return idleTime;
}

int Office::getMaxIdleTime(){
    for(int i = 0; i < numWindows; ++i){
        if(maxIdleTime < windows[i]->getMaxIdleTime()){
            maxIdleTime = windows[i]->getMaxIdleTime();
        }
    }
    return maxIdleTime;
}

int Office::getOverFive(){
    int overFive = 0;
    for(int i = 0; i < numWindows; ++i){
        if(windows[i]->getIdleTime() > 5){
            overFive++;
        }
    }
    return overFive;
}