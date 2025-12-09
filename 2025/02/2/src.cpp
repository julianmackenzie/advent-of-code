#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

 
int main() {

    ifstream inputFile;
    inputFile.open("input.txt");

    string range;
    long rangeStart;
    long rangeEnd;
    long invalidTotal;

    if (inputFile.is_open()) {
        while (getline(inputFile, range, ',')) {
            rangeStart = stol(range.substr(0, range.find("-")));
            rangeEnd = stol(range.substr(range.find("-") + 1));
            // cout << "From " << rangeStart << " to " << rangeEnd << ": " << endl;

            for (long i=rangeStart; i <= rangeEnd; i++) {
                string number = to_string(i);
                int length = number.length();
                string curSubstr = "";
                string potentialPattern;
                
                for (int substrLength = 1; substrLength <= length/2; substrLength++) {
                    potentialPattern = "";
                    if (length % substrLength == 0) {  // if the length isn't divisible by the substrLength, it can't be a repeat
                        curSubstr = number.substr(0, substrLength);
                        for (int j = 0; j < length / substrLength; j++) {
                            potentialPattern += curSubstr;
                        }

                        if (potentialPattern == number) {
                            // cout << number << " is an invalid id!" << endl;
                            invalidTotal += i;
                            break;
                        }

                    }
                }
                
            }

        }
        inputFile.close();
    }

    cout << "Sum of invalid ids: " << invalidTotal << endl;
    
    




    return 1;
}