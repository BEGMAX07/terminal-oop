#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Terminal v0.1 started..." << endl;
    cout << "Type 'exit' to quit." << endl;
    
    string command;
    while (true) {
        cout << "> ";
        cin >> command;
        if (command == "exit") {
            break;
        }
        cout << "Command received: " << command << endl;
    }

    cout << "Terminal stopped." << endl;
    return 0;
}