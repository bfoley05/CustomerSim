#include "Window.h"
#include "Customer.h"

Window::Window(){
    time = 0;
    idleTime = 0;
}

Window::~Window(){

}

void Window::setTime(Customer *customer, int officeNumber){
    currentCustomer = customer;
    time = customer->timeAtOffice[officeNumber];
}

bool Window::isTaken(){
    return (time>0);
}

int Window::waitTime(){
    return time;
}

void Window::decreaseTime(){
    if(time == 0){
        idleTime++;
    }else{
        time--;
    }
    if(currentCustomer != nullptr && time == 0){
        currentCustomer->isFree = true;
        currentCustomer = nullptr;
    }
}

int Window::getIdleTime(){
    return idleTime;
}
