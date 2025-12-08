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
    int dialPos = 50; // Will be a % 100 of the dialAcc--will handle wrapping for me
    int numZeroes = 0;

    for (int i=0; i<instructions.size(); i++) {
        if (instructions[i].first == 'R') {
            dialAcc += instructions[i].second;
        } else {
            dialAcc -= instructions[i].second;
        }

        dialPos = dialAcc % 100;

        if (dialPos == 0) {
            numZeroes++;
        }
    }

    cout << "Number of times the dial landed on zero: " << numZeroes << endl;







    return 0;
}

