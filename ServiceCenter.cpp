#include "ServiceCenter.h"

ServiceCenter::ServiceCenter(int r, int c, int fa, Customer **CustomerList){
    Registrar = new Office(r);
    Cashier = new Office(c);
    Financial_aid = new Office(fa);
    ListOfCustomers = CustomerList;
}

ServiceCenter::~ServiceCenter(){
    delete Registrar;
    delete Financial_aid;
    delete Cashier;
    delete[] ListOfCustomers;
}


void ServiceCenter::operate(int nc, int clockTick){
    int numCustomers = nc;
    for(int i = 1; i <= clockTick; ++i){
        // each clock tick
        for(int j = 0; j < 60; ++j){
            // represents each minute in an hour
            for(int k = 0; k < numCustomers; ++k){
                Customer *curr = ListOfCustomers[k];
                if(curr->timeToStart <= i && curr->isFree && curr->officeNumber<3){
                    if(curr == ListOfCustomers[2]){
                        cout << curr->officeNumber << endl;
                    }
                    int officeNumber = curr->officeNumber;
                    char whereToGo = curr->officeOrder[officeNumber];
                    if(whereToGo == 'R'){
                        Registrar->addCustomerToQueue(curr, officeNumber);
                    }else if(whereToGo == 'C'){
                        Cashier->addCustomerToQueue(curr, officeNumber);
                    }else{
                        Financial_aid->addCustomerToQueue(curr, officeNumber);
                    }
                    curr->officeNumber++;
                    curr->isFree = false;
                }
            }
            Registrar->checkQueue();
            Cashier->checkQueue();
            Financial_aid->checkQueue();
            Registrar->increaseTime();
            Cashier->increaseTime();
            Financial_aid->increaseTime();
        }
    }

    while(Registrar->continueGoing() || Cashier->continueGoing() || Financial_aid->continueGoing()){
        for(int k = 0; k < numCustomers; ++k){
                Customer *curr = ListOfCustomers[k];
                if(curr->isFree && curr->officeNumber<3){
                    if(curr == ListOfCustomers[2]){
                        cout << curr->officeNumber << endl;
                    }
                    int officeNumber = curr->officeNumber;
                    char whereToGo = curr->officeOrder[officeNumber];
                    if(whereToGo == 'R'){
                        Registrar->addCustomerToQueue(curr, officeNumber);
                    }else if(whereToGo == 'C'){
                        Cashier->addCustomerToQueue(curr, officeNumber);
                    }else{
                        Financial_aid->addCustomerToQueue(curr, officeNumber);
                    }
                    curr->officeNumber++;
                    curr->isFree = false;
                }
            }
            Registrar->checkQueue();
            Cashier->checkQueue();
            Financial_aid->checkQueue();
            Registrar->increaseTime();
            Cashier->increaseTime();
            Financial_aid->increaseTime();
    }
}


void ServiceCenter::printIdleTime(){
    int rIdle = Registrar->getIdleTime();
    int cIdle = Cashier->getIdleTime();
    int fIdle = Financial_aid->getIdleTime();

    cout << "Average idle time for each office: " << endl;
    cout << "   Registrar: " << rIdle/double(Registrar->numWindows) << endl << "   Cashier: " << cIdle/double(Cashier->numWindows) <<  endl << "   Financial Aid: " << fIdle/double(Financial_aid->numWindows) << endl;
    cout << "----------------------------------------------------" << endl;


    int rMaxIdle = Registrar->getMaxIdleTime();
    int cMaxIdle = Cashier->getMaxIdleTime();
    int fMaxIdle = Financial_aid->getMaxIdleTime();

    cout << "Max idle time for each office: " << endl;
    cout << "   Registrar: " << rMaxIdle << endl << "   Cashier: " << cMaxIdle <<  endl << "   Financial Aid: " << fMaxIdle << endl;
    cout << "----------------------------------------------------" << endl;

    int overFive = Registrar->getOverFive() + Cashier->getOverFive() +Financial_aid->getOverFive();
    cout << "Number of windows idle over 5 mins: " << endl;
    cout << "   " << overFive << endl;
    cout << "----------------------------------------------------" << endl;


}
