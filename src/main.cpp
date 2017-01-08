#include <iostream>
#include <string>
#include "dictionary.h"

using namespace std;

int main() {
    try {
        cout << "scheck version 0.1" << endl;

        //Dictionary d("data/mydict.dat");
        //Dictionary d("data/not-there.dat");
        Dictionary d("data/dict.dat");

        string word;
        
        while (getline(cin, word)) {
            if (d.Check(word)) {
                cout << word << " is OK\n";
            }
            else {
                cout << word << " is misspelt \n";
            }
        }
    }

    catch (const ScheckError & e) {
        cerr << "Error: " << e.what() << endl;

        return 1;
    }

    catch (...) {
        cerr << "Error: unknown exception" << endl;

        return 2;
    }
}
