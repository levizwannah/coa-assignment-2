// questionbAssignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<random>
#include<string>
#include<iomanip>

using namespace std;

/**
* Generates thirty random floating points numbers and print to the console their
* conversions to binary and the comment as specified by the assignment.
*/

string convertDecToBin(double input, bool &comment) {
    comment = false;

    int integerPart = (int)trunc(input);
    double fractionPart = input - (int)input;
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
            fracOutput += to_string((int)product);
            fractionPart = product - (int)product;
            if (fractionPart == 0) {
                comment = true;
                foundFrac = true;
            }
        }

        if ((precisionCounter >= 4 || foundFrac) && foundWhole) {
            string finalOutput = intOutput + ".";
            if (fracOutput == "") {
                finalOutput += "0";
            }
            else {
                finalOutput += fracOutput;
            }
            return finalOutput;
        }

        precisionCounter++;
    }
}

double roundOff(double num, int places) {
    return ((int)(num * pow(10, places) + 0.5)) * 1.0 / pow(10.0, places);
}

int main()
{
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<double> distr(0, 100);

    //todo
    bool comment = false;

    double decimalNum;
    string remark;

    cout << "Enter the number of numbers to convert: " << endl;
    int numCount;
    cin >> numCount;

    //TABLE
    cout << setw(7) << "S/No. " << setw(10) << " Decimal Number " << setw(10) << " Binary Number " << setw(7) << " Remark" << endl;
    cout << "-------------------------------------------------------" << endl;

    for (int i = 0; i < numCount; i++)
    {
        decimalNum = roundOff(distr(eng), 2);
        //todo
        bool comment = false;
        
        string converted = convertDecToBin(decimalNum, comment);
        if (comment) {
            remark = "Exact";
        }
        else {
            remark = "Approximate";
        }


        //TABLE OUTPUT
        cout << setw(5) << i << setw(10) << decimalNum << setw(18) << converted << setw(13) << remark << endl;
    }

    //cout << convertDecToBin(decimalNum, comment) << endl;
   
    
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
