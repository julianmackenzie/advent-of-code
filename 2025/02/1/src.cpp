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
            cout << "From " << rangeStart << " to " << rangeEnd << ": " << endl;

            for (long i=rangeStart; i <= rangeEnd; i++) {
                string number = to_string(i);
                if (number.size() % 2 == 0) {
                    int midpoint = (number.size()/2);
                    if (number.substr(0, (midpoint)) == number.substr(midpoint)) {
                        cout << i << " is an invalid id!" << endl;
                        invalidTotal += i;
                    }
                }
            }

        }
        inputFile.close();
    }

    cout << "Sum of invalid ids: " << invalidTotal << endl;
    
    




    return 1;
}