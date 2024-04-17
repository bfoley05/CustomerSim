#include "PostRun.h"

PostRun::PostRun(Customer **list, int num){
    ListOfCustomers = list;
    numCustomers = num;
    maxCashier = 0;
    maxFA = 0;
    maxRegistrar = 0;
    timeAtCashier = 0;
    timeAtFA = 0;
    timeAtRegistrar = 0;
    tenPlus = 0;
}

PostRun::~PostRun(){

}

void PostRun::printResults(){
    int time = 0;
    for(int i = 0; i < numCustomers; ++i){
        for(int j = 0; j < 3; ++j){
            char temp = ListOfCustomers[i]->officeOrder[j];
            if (temp == 'R'){
                time = ListOfCustomers[i]->waitTimeAtOffice[j+1];
                timeAtRegistrar += time;
                if(time >= 10){
                    tenPlus++;
                }
                if(time > maxRegistrar){
                    maxRegistrar = time;
                }
            }else if (temp == 'C'){
                time = ListOfCustomers[i]->waitTimeAtOffice[j+1];
                timeAtCashier += time;
                if(time >= 10){
                    tenPlus++;
                }
                if(time > maxCashier){
                    maxCashier = time;
                }
            }else if(temp == 'F'){
                time = ListOfCustomers[i]->waitTimeAtOffice[j+1];
                timeAtFA += time;
                if(time >= 10){
                    tenPlus++;
                }
                if(time > maxFA){
                    maxFA = time;
                }
            }
        }
    }

    cout << "Average student wait time: " << endl;
    cout << "   Registrar: " << timeAtRegistrar/double(numCustomers) << endl << "   Cashier: " << timeAtCashier/double(numCustomers) <<  endl << "   Financial Aid: " << timeAtFA/double(numCustomers) << endl;
    cout << "----------------------------------------------------" << endl;

    cout << "Longest wait time for each office: " << endl;
    cout << "   Registrar: " << maxRegistrar << endl << "   Cashier: " << maxCashier <<  endl << "   Financial Aid: " << maxFA << endl;
    cout << "----------------------------------------------------" << endl;

    cout << "Number of students waiting over ten minutes: " << endl;
    cout << "   " << tenPlus << endl;
    cout << "----------------------------------------------------" << endl;


}