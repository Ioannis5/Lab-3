/** \file bugExample.cpp
 *  \brief     A little with logical bugs in it
 *  \details   This program is littered with logical bugs. Your task is the
 *              following:
 *                1) Compile and run the program.
 *                2) For each bug you find you must fix the bug then Check In
 *                   the code with a comment on the fix you did
 *                3) There are a three functions that are not completed, you need to
 *                   complete them and also update the menu and the main function
 *  \author    Ioannis Koudounas
 *  \version   0.1
 *  \date      17/05/2025
 *  \bug       Many logical bugs
 *  \copyright University of Nicosia.
 */

#include <iostream>
#include <cassert>
using namespace std;

// Function prototypes
int printMenu();
void fillInArray(int[], const int);
void multArrays(const int[], const int[], int[], const int);
void displayArray(const int[], const int);
int sumOddArray(const int[], const int);
bool isAllPositive(const int[], const int);
void avgOddArray(const int[], const int, int&);

/**
 * <code>main</code> is the main function of this program.
 * <BR>
 * @return Returns 0 if success, any other value otherwise.
 */
#include <cstdlib>
#include <ctime>

//task 1
int main() {
	int choice;
	const int SIZE = 10;

	srand(time(0));

	int price[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		price[i] = rand() % 20 + 1;
	}

	int quantity[SIZE] = { 0 }, total[SIZE] = { 0 };

	do {
		choice = printMenu();

		switch (choice) {
		case 1:
			fillInArray(quantity, SIZE);
			break;
		case 2:
			multArrays(quantity, price, total, SIZE);
			break;
		case 3:
			displayArray(total, SIZE);
			break;
		case 4:
			cout << "\nSum of odd values in total: " << sumOddArray(total, SIZE);
			break;
		case 5:
			cout << "\nAll quantities are positive: " << (isAllPositive(quantity, SIZE) ? "Yes" : "No");
			break;
		case 6:
			int avgOdd;
			avgOddArray(total, SIZE, avgOdd);
			cout << "\nAverage of odd values in total: " << avgOdd;
			break;
		case 7:
			break;
		default:
			cout << "\nInvalid choice. Please try again.";
			break;
		}
	} while (choice != 7);

	cout << "\nHave a nice day:)" << endl;
	return 0;
}


/**
 * <code>printMenu</code> shows a menu and accepts the choice
 * from the user which is returned.
 * <BR>
 * @return Returns the menu choice
 */
int printMenu() {
	int choice;

	do {
		cout << "\n == MENU ==";
		cout << "\n1) Enter quantity";
		cout << "\n2) Calculate total";
		cout << "\n3) Print total";
		cout << "\n4) Exit";

		cout << "\nEnter the choice: ";
		cin >> choice;

		if (choice < 1 || choice > 4) {
			cout << "\nWrong choice, try again.";
		}
		//bug 6
	} while (choice < 1 || choice > 4);
	return choice;
}

/**
 * <code>fillInArray</code> is a function that will
 * fill in the elements of an array.
 * <BR>
 * @param arr The array to be filled in.
 * @param size The size of the array.
 */
void fillInArray(int arr[], const int size) {
	assert(size > 1);

	for (int i = 0; i < size; ++i) {
		cout << "\nEnter an element for the array at " << i << ": ";
		cin >> arr[i];
	}
}

/**
 * <code>multArrays</code> multiplies the value of elements of the source array
 * to the corresponding value at the destination array. NOTE: precondition
 * is that the arrays have the same size.
 * <BR>
 * @param arrSource The array containing the destination elements.
 * @param arrDest The array containing the source elements.
 * @param size The size of the arrays.
 */
//task 2
void multArrays(const int arrQuantity[], const int arrPrice[], int arrTotal[], const int size) {
	assert(size > 0);

	for (int i = 0; i < size; ++i) {
		double priceWithVAT = arrPrice[i] * (1 + VAT);
		arrTotal[i] = static_cast<int>(arrQuantity[i] * priceWithVAT);
	}
}


/**
 * <code>displayArray</code> prints the value of each of the elements of the
 * array. In addition the function sums up the value of all the elements and
 * print the total.
 * <BR>
 * @param ar The array containing the values
 * @param size The size of the array.
 */
void displayArray(const int arr[], const int size) {
	int sum = 0;

	//bug 4
	for (int i = 0; i < size; ++i) {
		cout << "\nValue at " << i << ": " << arr[i];
		sum += arr[i];
	}

	cout << "\nThe total is: " << sum;
}

//function 1
/**
 * Sums all the odd numbers in the array.
 * @param arr The array of integers.
 * @param size The number of elements in the array.
 * @return The sum of all odd elements.
 */
int sumOddArray(const int arr[], const int size) {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2 != 0)
			sum += arr[i];
	}
	return sum;
}

//function 2
/**
 * Checks if all values in the array are positive.
 * @param arr The array to check.
 * @param size The number of elements in the array.
 * @return True if all elements are positive, false otherwise.
 */
bool isAllPositive(const int arr[], const int size) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] <= 0)
			return false;
	}
	return true;
}

//function 3
/**
 * Calculates the average of all odd numbers in the array.
 * @param arr The array to process.
 * @param size The number of elements in the array.
 * @param avgOdd Reference to store the average of odd numbers.
 */
void avgOddArray(const int arr[], const int size, int& avgOdd) {
	int sum = 0, count = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2 != 0) {
			sum += arr[i];
			count++;
		}
	}
	avgOdd = (count > 0) ? (sum / count) : 0;
}
