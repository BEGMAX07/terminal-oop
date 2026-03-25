#ifndef TERMINAL_H
#define TERMINAL_H

#include "Entry.h"
#include "Directory.h"
#include "SingleLineFile.h"
#include "MultiLineFile.h"
#include <sstream>

using namespace std;

class Terminal {
private:
    Directory* root;
    Directory* cwd;  

public:
    Terminal() {
        root = new Directory("root");
        cwd = root;
    }

    ~Terminal() {
        delete root;
    }

    void run() {
        string command;
        while (true) {
            cout << "term:> ";
            cin >> command;

            if (command == "exit") break;
            else if (command == "help") showHelp();
            else if (command == "ls") cmdLs();
            else if (command == "cd") cmdCd();
            else if (command == "mkdir") cmdMkdir();
            else if (command == "touch") cmdTouch();
            else if (command == "cat") cmdCat();
            else if (command == "edit") cmdEdit();
            else if (command == "rm") cmdRm();
            else if (command == "restore") cmdRestore();
            else if (command == "mv") cmdMv();
            else cout << "Unknown command. Type 'help' for list." << endl;
        }
    }

    void showHelp() {
        cout << "Commands: help, exit, ls, cd, mkdir, touch, cat, edit, rm, restore, mv" << endl;
    }

    void cmdLs() {
        cwd->print();
    }

    void cmdMkdir() {
        string name; cin >> name;
        if (cwd->findChild(name)) {
            cout << "Error: Already exists." << endl;
            return;
        }
        cwd->addEntry(new Directory(name, cwd));
        cout << "Directory created." << endl;
    }

    void cmdTouch() {
        string name; cin >> name;
        if (cwd->findChild(name)) {
            cout << "Error: Already exists." << endl;
            return;
        }
        cwd->addEntry(new SingleLineFile(name));
        cout << "File created." << endl;
    }

    void cmdCd() {
        string name; cin >> name;
        if (name == "..") {
            if (cwd->getParent() != nullptr) {
                cwd = cwd->getParent();
            } else {
                cout << "Already at root." << endl;
            }
        } else {
            Entry* target = cwd->findChild(name);
            if (target && target->isDirectory()) {
                cwd = (Directory*)target;
            } else {
                cout << "Error: Invalid directory." << endl;
            }
        }
    }

    void cmdCat() {
        string name; cin >> name;
        Entry* target = cwd->findChild(name);
        if (target && !target->isDirectory()) {
            target->print();
        } else {
            cout << "Error: File not found." << endl;
        }
    }

    void cmdEdit() {
        string name; cin >> name;
        Entry* target = cwd->findChild(name);
        if (target && !target->isDirectory()) {
            target->edit();  
        } else {
            cout << "Error: File not found." << endl;
        }
    }

    void cmdRm() {
        string name; cin >> name;
        Entry* target = cwd->findChildIncludingHidden(name);
        if (target) {
            target->hide();
            cout << "Entry hidden." << endl;
        } else {
            cout << "Error: Not found." << endl;
        }
    }

    void cmdRestore() {
        string name; cin >> name;
        Entry* target = cwd->findChildIncludingHidden(name);
        if (target) {
            target->restore();
            cout << "Entry restored." << endl;
        } else {
            cout << "Error: Not found." << endl;
        }
    }

    void cmdMv() {
        string oldName, newName;
        cin >> oldName >> newName;
        Entry* target = cwd->findChildIncludingHidden(oldName);
        if (target) {
            target->rename(newName);
            cout << "Renamed." << endl;
        } else {
            cout << "Error: Not found." << endl;
        }
    }
};

#endif