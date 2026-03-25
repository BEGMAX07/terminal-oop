#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "Entry.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Directory : public Entry {
private:
    vector<Entry*> children; 
    Directory* parent;       

public:
    Directory(string n, Directory* p = nullptr) : Entry(n), parent(p) {}

    ~Directory() {
        for (auto child : children) {
            delete child;
        }
    }

    bool isDirectory() override { return true; }

    void addEntry(Entry* e) {
        children.push_back(e);
    }

    Entry* findChild(string n) override {
        for (auto child : children) {
            if (child->getName() == n && !child->getHidden()) {
                return child;
            }
        }
        return nullptr;
    }

    Entry* findChildIncludingHidden(string n) {
        for (auto child : children) {
            if (child->getName() == n) {
                return child;
            }
        }
        return nullptr;
    }

    void print() override {
        cout << "[DIR] " << name << endl;
        for (auto child : children) {
            if (!child->getHidden()) {  
                child->print();
            }
        }
    }

    Directory* getParent() { return parent; }

    void removeEntry(string n) override {
        Entry* target = findChildIncludingHidden(n);
        if (target) {
            target->hide();  
        }
    }

    void restoreEntry(string n) {
        Entry* target = findChildIncludingHidden(n);
        if (target) {
            target->restore();
        }
    }
};

#endif