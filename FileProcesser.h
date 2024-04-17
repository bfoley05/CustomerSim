#ifndef FILE_PROCESSER
#define FILE_PROCESSER

#include <iostream>
#include <fstream>
#include "Customer.h"
using namespace std;

class FileProcesser{
    public:
        FileProcesser(string file_in);
        ~FileProcesser();
        Customer** processFile();
        int RegistrarWindows();
        int CashierWindows();
        int FincanicalAidWindows();
        int sizeOfList;

    
    private:
        string file_in;
        ofstream ofs;
};



#endif