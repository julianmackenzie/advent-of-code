#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    ifstream inputFile;
    inputFile.open("input.txt");

    string line;
    vector<pair<char, int>> instructions;

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            char direction = line[0];
            int distance = stoi(line.substr(1));
            instructions.push_back({direction, distance});
        }
        inputFile.close();
    }

    int dialAcc = 50;
    int dialPos = 50; // will be a % 100 of the dialAcc--handles "wrapping"
    int numZeroes = 0;
    int numZeroesToAdd = 0;

    for (int i=0; i<instructions.size(); i++) {
        
        if (dialPos == 0) {
            // turns starting at 0 only matter if they're 100 or more
            if (instructions[i].second >= 100) {
                numZeroesToAdd = (instructions[i].second / 100);
                // cout << "Starting at 0, turned " << instructions[i].second << " from " << dialPos << ", added " << numZeroesToAdd << endl;
                numZeroes += numZeroesToAdd;
            }
        }
        else if (instructions[i].first == 'R') {
            if (dialPos + instructions[i].second >= 100) {
                numZeroesToAdd = (abs(instructions[i].second + dialPos) / 100);
                // cout << "Turned right " << instructions[i].second << " from " << dialPos << ", added " << numZeroesToAdd << endl;
                numZeroes += numZeroesToAdd;
            }
        } else if (instructions[i].first == 'L') {
            if (dialPos - instructions[i].second <= 0) {
                numZeroesToAdd = (abs(instructions[i].second - dialPos) / 100) + 1;
                // cout << "Turned left " << instructions[i].second << " from " << dialPos << ", added " << numZeroesToAdd << endl;
                numZeroes += numZeroesToAdd;
            }
        }

        if (instructions[i].first == 'R') {
            dialAcc += instructions[i].second;
        } else if (instructions[i].first == 'L') {
            dialAcc -= instructions[i].second;
        }

        dialPos = dialAcc % 100;
        // make left turns still count down when negative
        if (dialPos < 0) dialPos = 100 + dialPos;
        
        // cout << dialPos << endl;
    }

    cout << "Number of times the dial touched zero: " << numZeroes << endl;


    return 0;
}

