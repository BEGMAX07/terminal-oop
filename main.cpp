#include <iostream>
#include <string>
#include "Entry.h"
#include "Directory.h"
#include "SingleLineFile.h"
#include "MultiLineFile.h"

using namespace std;

int main() {
    cout << "Terminal v0.4 started..." << endl;

    Directory* root = new Directory("root");

    SingleLineFile* file1 = new SingleLineFile("note.txt");
    root->addEntry(file1);

    MultiLineFile* file2 = new MultiLineFile("doc.txt");
    root->addEntry(file2);

    Directory* docs = new Directory("docs", root);
    root->addEntry(docs);

    cout << "Root directory:" << endl;
    root->print();

    cout << "\nTesting polymorphic edit:" << endl;
    file1->edit();  
    file2->edit();  

    cout << "\nAfter edit:" << endl;
    root->print();

    cout << "\nType 'exit' to quit." << endl;

    string command;
    while (true) {
        cout << "> ";
        cin >> command;
        if (command == "exit") {
            break;
        }
        cout << "Unknown command." << endl;
    }

    delete root;

    cout << "Terminal stopped." << endl;
    return 0;
}