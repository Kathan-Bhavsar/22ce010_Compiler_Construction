#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int numSymbols, numStates, initialState, numAcceptingStates;

    cout << "Enter the number of input symbols: ";
    cin >> numSymbols;
    vector<char> symbols(numSymbols);
    cout << "Enter the input symbols: ";
    for (char &symbol : symbols) cin >> symbol;

    cout << "Enter the number of states: ";
    cin >> numStates;
    cout << "Enter the initial state: ";
    cin >> initialState;

    cout << "Enter the number of accepting states: ";
    cin >> numAcceptingStates;
    vector<int> acceptingStates(numAcceptingStates);
    cout << "Enter the accepting states: ";
    for (int &state : acceptingStates) cin >> state;

    vector<vector<int>> transitions(numStates, vector<int>(numSymbols));
    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numSymbols; j++) {
            cout << "Transition for state " << i << " and symbol " << symbols[j] << ": ";
            cin >> transitions[i][j];
        }
    }

    int choice;
    do {
        string input;
        cout << "Enter the input string: ";
        cin >> input;

        int currentState = initialState;
        for (char c : input) {
            int index = find(symbols.begin(), symbols.end(), c) - symbols.begin();
            if (index >= numSymbols) {
                currentState = -1;
                break;
            }
            currentState = transitions[currentState][index];
        }

        bool valid = (currentState != -1 && find(acceptingStates.begin(), acceptingStates.end(), currentState) != acceptingStates.end());
        cout << (valid ? "Valid string" : "Invalid string") << endl;

        cout << "Enter 1 to validate another string, or 0 to exit: ";
        cin >> choice;
    } while (choice != 0);

    return 0;
}
