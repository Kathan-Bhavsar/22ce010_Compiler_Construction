#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int numSymbols = 36;
    int numStates = 3;
    int startState = 0;
    int numAcceptingStates = 1;

    vector<char> symbols = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<int> acceptingStates = {1};

    vector<vector<int>> transitionTable(numStates, vector<int>(numSymbols));
    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numSymbols; j++) {
            if (i == 0 && j < 26) {
                transitionTable[i][j] = 1;
            } else if (i == 0 && j >= 26) {
                transitionTable[i][j] = 2;
            } else if (i == 1) {
                transitionTable[i][j] = 1;
            } else if (i == 2) {
                transitionTable[i][j] = 2;
            }
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

        if (isValid) {
            bool isAccepting = false;
            for (int i = 0; i < numAcceptingStates; i++) {
                if (currentState == acceptingStates[i]) {
                    isAccepting = true;
                    break;
                }
            }
            if (isAccepting) {
                cout << "Valid string\n";
            } else {
                cout << "Invalid string\n";
            }
        } else {
            cout << "Invalid string: contains unsupported symbols\n";
        }

        cout << "Enter 1 to validate another string, 0 to exit: ";
        cin >> continueFlag;
    } while (continueFlag != 0);

    return 0;
}
