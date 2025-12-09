#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {

    vector<vector<char>> cafeteria;
    int width;
    int height = 0;

    int numAccessible = 1;
    int numRemoved = 0;

    string line;
    ifstream inFile("input.txt");
    while (getline(inFile, line)) {
        vector<char> row;
        for (int i=0; i<line.length(); i++) {
            row.push_back(line[i]);
        }
        cafeteria.push_back(row);
        height++;
    }

    width = cafeteria[0].size();

    // cout << width << "x" << height << endl;

    // for (int i=0; i<height; i++) {
    //     for (int j=0; j<width; j++) {
    //         cout << cafeteria[i][j];
    //     }
    //     cout << endl;
    // }

    while (numAccessible != 0) {
        numAccessible = 0;
        for (int y=0; y<height; y++) {
            for (int x=0; x<width; x++) {
                if (cafeteria[y][x] != '@') continue;
                int numAdjacent = 0;

                // If Up is safe
                if (y>0) {
                    numAdjacent += (cafeteria[y-1][x] == '@');
                    if (x>0) {
                        numAdjacent += (cafeteria[y-1][x-1] == '@');
                    }
                    if (x<width-1) {
                        numAdjacent += (cafeteria[y-1][x+1] == '@');
                    }
                }
                if (x>0) {
                    numAdjacent += (cafeteria[y][x-1] == '@');
                }
                if (x<width-1) {
                    numAdjacent += (cafeteria[y][x+1] == '@');
                }
                // If Down is safe
                if (y<height-1) {
                    numAdjacent += (cafeteria[y+1][x] == '@');

                    if (x>0) {
                        numAdjacent += (cafeteria[y+1][x-1] == '@');
                    }
                    if (x<width-1) {
                        numAdjacent += (cafeteria[y+1][x+1] == '@');
                    }
                }
                
                // if (numAdjacent < 4) cout << x << "," << y << " is accessible" << endl;
                if (numAdjacent < 4) {
                    cafeteria[y][x] = 'x';
                    numAccessible++;
                }
            }
        }

        for (int y=0; y<height; y++) {
            for (int x=0; x<width; x++) {
                if (cafeteria[y][x] == 'x') cafeteria[y][x] = '.';
                // cout << cafeteria[y][x];
            }
            // cout << endl;
        }
        numRemoved += numAccessible;
        // cout << numAccessible << " rolls have been removed" << endl;
    }
    
    
    cout << "Total number of removed rolls: " << numRemoved << endl;

    return 1;
}