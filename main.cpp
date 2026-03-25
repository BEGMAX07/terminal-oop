#include <iostream>
#include <string>
#include "Entry.h"  // Подключаем наш класс

using namespace std;

int main() {
    cout << "Terminal v0.2 started..." << endl;

    Entry* testEntry = new Entry("test_file.txt");
    
    cout << "Created entry: ";
    testEntry->print(); 

    cout << "Type 'exit' to quit." << endl;
    
    string command;
    while (true) {
        cout << "> ";
        cin >> command;
        if (command == "exit") {
            break;
        }
        cout << "Unknown command." << endl;
    }

    delete testEntry;

    cout << "Terminal stopped." << endl;
    return 0;
}