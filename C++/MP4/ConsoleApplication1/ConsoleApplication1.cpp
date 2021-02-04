// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include <ctime>
using namespace std; 
struct ScoreEntry {
	string scoreName;
	int scoreValue;
};
ScoreEntry databaseEntries[100];
void loadFromFile() {
    ifstream input("scores.txt");
    if (!input.fail()) {
        cout << "File detected, loading data..." << endl;
        for (int i = 0; i < 100; i++) {
            input >> databaseEntries[i].scoreName;
            input >> databaseEntries[i].scoreValue;
        }
        input.close();
    }
    else {
        cout << "No file detected..." << endl;
    }
}
void outputData() {
    for (int i = 0; i < 100; i++) {
        if (databaseEntries[i].scoreName == "") { break; }
        cout << databaseEntries[i].scoreName << " " << databaseEntries[i].scoreValue <<" / ";
        if (i % 9 == 0 && i != 0) { cout << endl; }
    }
    cout << endl;
}
void sortData() {
    cout << "Sorting data..." << endl;
    for (int i = 0; i < 100; i++) {
        for (int ii = 0; ii < 100; ii++) {
            if (databaseEntries[i].scoreValue > databaseEntries[ii].scoreValue) {
                ScoreEntry temp = databaseEntries[i];
                databaseEntries[i] = databaseEntries[ii];
                databaseEntries[ii] = temp;
            }
       }
    }
}
void appendData(ScoreEntry data) {
    ofstream output("scores.txt", ios::app);rand()%2+1
    if (!output.fail()) {
        cout << "File loaded, adding score..." << endl;
        output << data.scoreName << "\t" << data.scoreValue << endl;
    }
    else { cout << "File could not load..." << endl; }
}
int main()
{
    srand(time(NULL));
    loadFromFile();
    outputData();
    cout << endl << endl;
    sortData();
    outputData();
    ScoreEntry input1, input2;
    input1.scoreName = "asdasdsa";
    input1.scoreValue = 12;
    input2.scoreName = "eqeqeqweqe";
    input2.scoreValue = 64;
    appendData(input1);
    appendData(input2);

}

