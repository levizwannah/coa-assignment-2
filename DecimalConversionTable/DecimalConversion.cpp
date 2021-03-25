
using namespace std;
#include <iostream>
#include <iomanip>

void decimalToBinary(int number)

{
	int Binary[100];


	int i = 0;
	while (number > 0) {


		Binary[i] = number % 2;
		number = number / 2;
		i++;
	}


	for (int j = i - 1; j >= 0; j--)
		cout << Binary[j];
}


void DecimalToHexadecimal(int number)
{

	char hexadecimal[100];


	int i = 0;
	while (number != 0) {

		int temp = 0;


		temp = number % 16;


		if (temp < 10) {
			hexadecimal[i] = temp + 48;
			i++;
		}
		else {
			hexadecimal[i] = temp + 55;
			i++;
		}

		number = number / 16;
	}


	for (int j = i - 1; j >= 0; j--)
		cout << hexadecimal[j];
}


int main()
{


	int start;
	int end;
	const char separator = ' ';
	const int nameWidth = 24;
	const int numWidth = 24;
	cout << " What range of value do you want to convert:";
	cout << endl;
	cout << "Enter start: ";
	cin >> start;
	cout << "Enter end: ";
	cin >> end;

	cout << left << setw(nameWidth) << setfill(separator) << "Decimal";
	cout << left << setw(nameWidth) << setfill(separator) << "Binary";
	cout << left << setw(numWidth) << setfill(separator) << "Hexadecimal";
	cout << endl;


	for (int i = start; i <= end; i++)
	{
		//int number=1 + (rand() % 200);
		cout << i;
		cout << "			";
		decimalToBinary(i);
		cout << "			";
		DecimalToHexadecimal(i);
		cout << endl;

	}



	system("pause");


}