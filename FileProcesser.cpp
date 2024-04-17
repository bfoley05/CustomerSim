#include "FileProcesser.h"
#include <iostream>
#include <string>

FileProcesser::FileProcesser(string file){
    file_in = file;
}

FileProcesser::~FileProcesser() {}

Customer** FileProcesser::processFile() {
    ifstream infile(file_in);
    if (!infile.is_open()) {
        cerr << "Error: Unable to open input file " << file_in << endl;
        return nullptr;
    }

    // Determine the number of lines in the file
    int totalCustomers = 0;
    string line;
    while (getline(infile, line)) { // Read each line from the file
        if (line.size() > 3) { // Check if the line has more than 3 characters
            totalCustomers++;
        }
    }

    // // Reset file pointer to the beginning
    infile.clear();
    infile.seekg(0, ios::beg);

    // // Skip the lines containing window numbers
    getline(infile, line); // Skip registrar windows
    getline(infile, line); // Skip cashier windows
    getline(infile, line); // Skip financial aid windows

    // // Create an array to store customers
    Customer** customers = new Customer*[totalCustomers];
    int index = 0;
    int numPeople;
    // // Read customer data
    while (getline(infile, line)) { // Read each line from the file
        int time = stoi(line);
        getline(infile,line);
        numPeople = stoi(line);
        for(int i = 0; i < numPeople; ++i){
            getline(infile, line);
            customers[index] = new Customer(time, line);
            index++;
        }
    }
    sizeOfList = index;

    infile.close();
    return customers;
}

int FileProcesser::RegistrarWindows() {
    int registrar;
    ifstream infile(file_in);
    string line;
    infile.clear();
    infile.seekg(0, ios::beg);
    getline(infile, line);
    registrar = stoi(line);
    infile.close();
    return registrar;
}

int FileProcesser::CashierWindows() {
    int cashier;
    ifstream infile(file_in);
    string line;
    infile.clear();
    infile.seekg(0, ios::beg);
    getline(infile, line);
    getline(infile, line);
    cashier = stoi(line);
    infile.close();
    return cashier;
}

int FileProcesser::FincanicalAidWindows() {
    int FA;
    ifstream infile(file_in);
    string line;
    infile.clear();
    infile.seekg(0, ios::beg);
    getline(infile, line);
    getline(infile, line);
    getline(infile, line);
    FA = stoi(line);
    infile.close();
    return FA;
}
