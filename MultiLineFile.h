#ifndef MULTILINEFILE_H
#define MULTILINEFILE_H

#include "Entry.h"
#include <vector>

using namespace std;

class MultiLineFile : public Entry {
private:
    vector<string> lines;

public:
    MultiLineFile(string n) : Entry(n) {}

    void edit() override {
        cout << "Enter content (type END on new line to finish):" << endl;
        string line;
        lines.clear();
        while (true) {
            cin >> line;
            if (line == "END") break;
            lines.push_back(line);
        }
        cout << "File updated." << endl;
    }

    void print() override {
        cout << "[MULTI] " << name << endl;
        for (const auto& l : lines) {
            cout << l << endl;
        }
    }
};

#endif