#ifndef SINGLELINEFILE_H
#define SINGLELINEFILE_H

#include "Entry.h"

using namespace std;

class SingleLineFile : public Entry {
private:
    string content;

public:
    SingleLineFile(string n) : Entry(n) {}

    void edit() override {
        cout << "Enter new content (single line): ";
        cin >> content;
        cout << "File updated." << endl;
    }

    void print() override {
        cout << "[FILE] " << name << ": " << content << endl;
    }

    string getContent() { return content; }
};

#endif