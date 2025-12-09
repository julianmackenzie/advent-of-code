#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


/*
void swap(char &first, char &second) {
    int temp = first;
    first = second;
    second = temp;
    return;
}
*/


int main() {

    string line;
    int joltage = 0;

    ifstream inFile("input.txt");
    if (inFile.is_open()) {

        while(getline(inFile, line)) {

            /*
                En memoria:
                I neglected to read those damned four fated words:
                "You cannot rearrange batteries."
            */

            // cout << line << endl;
            // bool isSorted = false;
            // while (isSorted == false) {
            //     isSorted = true;
            //     for (int i=0; i < line.size()-1; i++) {
            //         if (line[i] < line[i+1]) {
            //             isSorted = false;
            //             swap(line[i], line[i+1]);
            //         }
            //     }
            // }
            // cout << "Sorted: " << line << endl;
            // cout << "Highest joltage in bank: " << line.substr(0,2) << endl;

            // joltage += stoi(line.substr(0,2));



            // cout << line << endl;

            int maxTens = 0;
            for (int i=1; i < line.length()-1; i++) {
                if (line[i] > line[maxTens]) {
                    maxTens = i;
                }
            }
            int maxOnes = maxTens + 1;
            for (int i=maxTens+1; i < line.length(); i++) {
                if (line[i] > line[maxOnes]) {
                    maxOnes = i;
                }
            }
            // cout << to_string(line[maxTens]-48) + to_string(line[maxOnes]-48) << endl;
            joltage += stoi(to_string(line[maxTens]-48) + to_string(line[maxOnes]-48));

        }

        inFile.close();
    }

    cout << "Total joltage: " << joltage << endl;


    return 1;
}