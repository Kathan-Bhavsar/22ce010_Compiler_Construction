#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int numSymbols, numStates, startState, numAcceptingStates;

    cout << "Enter the number of input symbols: ";
    cin >> numSymbols;

    cout << "Enter the input symbols: ";
    vector<char> symbols(numSymbols);
    for (int i = 0; i < numSymbols; i++) {
        cin >> symbols[i];
    }

    cout << "Enter the number of states: ";
    cin >> numStates;

    cout << "Enter the initial state: ";
    cin >> startState;

    cout << "Enter the number of accepting states: ";
    cin >> numAcceptingStates;
    vector<int> acceptingStates(numAcceptingStates);
    cout << "Enter the accepting states: ";
    for (int i = 0; i < numAcceptingStates; i++) {
        cin >> acceptingStates[i];
    }

    vector<vector<int>> transitionTable(numStates + 1, vector<int>(numSymbols));
    for (int i = 1; i <= numStates; i++) {
        for (int j = 0; j < numSymbols; j++) {
            cout << "Enter transition for state " << i << " and symbol " << symbols[j] << ": ";
            cin >> transitionTable[i][j];
        }
    }

    string inputString;
    int continueFlag;
    do {
        cout << "Enter the input string: ";
        cin >> inputString;

        int currentState = startState;
        bool isValid = true;

        for (char c : inputString) {
            int symbolIndex = -1;
            for (int i = 0; i < numSymbols; i++) {
                if (c == symbols[i]) {
                    symbolIndex = i;
                    break;
                }
            }

            if (symbolIndex == -1) {
                isValid = false;
                break;
            }

            currentState = transitionTable[currentState][symbolIndex];
        }

        bool isAcceptingState = false;
        for (int i = 0; i < numAcceptingStates; i++) {
            if (currentState == acceptingStates[i]) {
                isAcceptingState = true;
                break;
            }
        }

        if (isValid && isAcceptingState) {
            cout << "Valid string\n";
        } else {
            cout << "Invalid string\n";
        }

        cout << "Enter 1 to validate another string, 0 to exit: ";
        cin >> continueFlag;
    } while (continueFlag != 0);

    return 0;
}
