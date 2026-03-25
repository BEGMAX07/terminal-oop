#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <iostream>

using namespace std;

class Entry {
protected:
    string name;
    bool isHidden;

public:
    Entry(string n) : name(n), isHidden(false) {}
    
    virtual ~Entry() {}

    virtual string getName() { return name; }
    virtual bool getHidden() { return isHidden; }

    virtual void print() { 
        cout << name << (isHidden ? " (hidden)" : "") << endl; 
    }
    
    virtual void edit() { 
        cout << "Cannot edit this entry type." << endl; 
    }
    
    virtual bool isDirectory() { return false; } 
    
    virtual Entry* findChild(string n) { return nullptr; } 
    virtual void addEntry(Entry* e) {}
    virtual void removeEntry(string n) {}
    
    virtual void hide() { isHidden = true; }
    virtual void restore() { isHidden = false; }
    
    virtual void rename(string newName) { name = newName; }
};

#endif