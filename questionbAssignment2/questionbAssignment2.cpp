// questionbAssignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;

/**
* Generates thirty random floating points numbers and print to the console their
* conversions to binary and the comment as specified by the assignment.
*/

string convertDecToBin(double input, bool &comment) {
    comment = false;

    int integerPart = (int)trunc(input);
    double fractionPart = input - trunc(input);
    string intOutput = "";
    string fracOutput = "";

    //controls
    bool foundWhole = false, foundFrac = false;
    int precisionCounter = 0;

    while (true) {
        //converting the whole part
        if (!foundWhole) {
            intOutput = to_string(integerPart % 2) + intOutput;
            integerPart /= 2;

            if (integerPart < 2) {
                intOutput = (integerPart > 0)?to_string(integerPart % 2) + intOutput: intOutput;
                foundWhole = true;
            }
        }

        //converting the fractional part
        if (!foundFrac) {
            double product = 2 * fractionPart;
            fracOutput += to_string(trunc(product));
            fractionPart = product - trunc(product);
            if (fractionPart == 0) {
                comment = true;
                foundFrac = true;
            }
        }

        if (precisionCounter >= 5 || (foundFrac && foundWhole)) {
            string finalOutput = intOutput + ".";
            finalOutput += (fracOutput != "") ? fracOutput : "0";
            return finalOutput;
        }

        precisionCounter++;
        
    }
}

int main()
{
    //todo
    bool comment = false;
    cout << convertDecToBin(21.25, comment) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
