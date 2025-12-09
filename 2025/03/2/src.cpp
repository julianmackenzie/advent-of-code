#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main() {

    string line;
    long joltage = 0;

    ifstream inFile("input.txt");
    if (inFile.is_open()) {

        while(getline(inFile, line)) {

            // cout << line << endl;

            int remainingBatteries = 12;
            int maxIndex = 0;
            string batteryConfig = "";
            while (remainingBatteries > 0) {
                for (int i=maxIndex; i < line.length()-(remainingBatteries-1); i++) {
                    if (line[i] > line[maxIndex]) {
                        maxIndex = i;
                    }
                }
                batteryConfig += to_string(line[maxIndex]-48);
                maxIndex++;
                remainingBatteries--;
            }

            // cout << to_string(line[maxTens]-48) + to_string(line[maxOnes]-48) << endl;
            joltage += stol(batteryConfig);

        }

        inFile.close();
    }

    cout << "Total joltage: " << joltage << endl;


    return 1;
}