#include "ServiceCenter.h"
#include <iostream>
#include "FileProcesser.h"
#include "Customer.h"
#include "PostRun.h"
using namespace std;

int main(){
    FileProcesser *fp = new FileProcesser("input.txt");
    int registrarWindows = fp->RegistrarWindows();
    int cashierWindows = fp->CashierWindows();
    int financialWindows = fp->FincanicalAidWindows();
    Customer** list = fp->processFile();

    int maxTime = 1;
    for(int i = 0; i < fp->sizeOfList; ++i){
        if(list[i]->timeToStart > maxTime){
            int maxTime = list[i]->timeToStart;
        }
    }

    ServiceCenter *SC = new ServiceCenter(registrarWindows, cashierWindows, financialWindows, list);
    SC->operate(fp->sizeOfList, maxTime);

    PostRun *pr = new PostRun(list, fp->sizeOfList);
    pr->printResults();
    SC->printIdleTime();

    delete fp;
    delete SC;

    return 0;
}