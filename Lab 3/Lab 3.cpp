/** \file bugExample.cpp
 *  \brief     A program with logical bugs (now fixed)
 *  \details   This program demonstrates working with arrays, VAT calculations,
 *             and user interaction via a menu. The `total` array is now 2D:
 *             total[i][0] = value without VAT,
 *             total[i][1] = value with VAT.
 *  \author    Ioannis Koudounas (Modified by ChatGPT)
 *  \version   0.2
 *  \date      17/05/2025
 *  \bug       Fixed logical bugs
 *  \copyright University of Nicosia.
 * 
 
 //tutorial 3 part 3
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <cmath> // For rounding
using namespace std;

// Constants
const double VAT = 0.21;
const int SIZE = 10;

// Function prototypes
int printMenu();
void fillInArray(int[], const int);
void multArrays(const int[], const int[], int[][2], const int);
void displayArray(const int[][2], const int);
int sumOddArray(const int[][2], const int);
bool isAllPositive(const int[], const int);
void avgOddArray(const int[][2], const int, int&);

int main() {
    int choice;

    srand(time(0)); // Random seed

    int price[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        price[i] = rand() % 20 + 1; // Random price between 1 and 20
    }

    int quantity[SIZE] = { 0 };
    int total[SIZE][2] = { 0 }; // 2D: [0] = no VAT, [1] = with VAT

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
            cout << "\nSum of odd values in total (with VAT): " << sumOddArray(total, SIZE);
            break;
        case 5:
            cout << "\nAll quantities are positive: " << (isAllPositive(quantity, SIZE) ? "Yes" : "No");
            break;
        case 6: {
            int avgOdd;
            avgOddArray(total, SIZE, avgOdd);
            cout << "\nAverage of odd values in total (with VAT): " << avgOdd;
            break;
        }
        case 7:
            break;
        default:
            cout << "\nInvalid choice. Please try again.";
            break;
        }
    } while (choice != 7);

    cout << "\nHave a nice day :)" << endl;
    return 0;
}

/**
 * Shows a menu and accepts the choice from the user.
 * @return Returns the menu choice
 */
int printMenu() {
    int choice;

    do {
        cout << "\n == MENU ==";
        cout << "\n1) Enter quantity";
        cout << "\n2) Calculate total (with VAT)";
        cout << "\n3) Print total";
        cout << "\n4) Sum of odd values in total";
        cout << "\n5) Check if all quantities are positive";
        cout << "\n6) Average of odd values in total";
        cout << "\n7) Exit";
        cout << "\nEnter the choice: ";
        cin >> choice;

        if (choice < 1 || choice > 7) {
            cout << "\nWrong choice, try again.";
        }
    } while (choice < 1 || choice > 7);

    return choice;
}

/**
 * Fills in the elements of an array.
 * @param arr The array to be filled in.
 * @param size The size of the array.
 */
void fillInArray(int arr[], const int size) {
    assert(size > 0);

    for (int i = 0; i < size; ++i) {
        cout << "\nEnter quantity for item " << i << ": ";
        cin >> arr[i];
    }
}

/**
 * Multiplies quantity and price arrays and stores results in total array.
 * @param arrQuantity The array of quantities.
 * @param arrPrice The array of prices.
 * @param arrTotal The 2D array to store totals [0]=no VAT, [1]=with VAT.
 * @param size The size of the arrays.
 */
void multArrays(const int arrQuantity[], const int arrPrice[], int arrTotal[][2], const int size) {
    assert(size > 0);

    for (int i = 0; i < size; ++i) {
        arrTotal[i][0] = arrQuantity[i] * arrPrice[i]; // without VAT
        double withVAT = arrTotal[i][0] * (1 + VAT);
        arrTotal[i][1] = static_cast<int>(round(withVAT)); // with VAT
    }
}

/**
 * Prints the array totals (both with and without VAT) and overall totals.
 * @param arr The 2D array of totals.
 * @param size The size of the array.
 */
void displayArray(const int arr[][2], const int size) {
    int sumNoVAT = 0, sumWithVAT = 0;

    for (int i = 0; i < size; ++i) {
        cout << "\nItem " << i
            << " -> No VAT: " << arr[i][0]
            << ", With VAT: " << arr[i][1];
        sumNoVAT += arr[i][0];
        sumWithVAT += arr[i][1];
    }

    cout << "\nTotal without VAT: " << sumNoVAT;
    cout << "\nTotal with VAT: " << sumWithVAT;
}

/**
 * Sums all the odd numbers in the array (with VAT).
 * @param arr The 2D total array.
 * @param size The number of elements in the array.
 * @return The sum of all odd values in the with-VAT column.
 */
int sumOddArray(const int arr[][2], const int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i][1] % 2 != 0)
            sum += arr[i][1];
    }
    return sum;
}

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

/**
 * Calculates the average of all odd numbers in the with-VAT column.
 * @param arr The 2D total array.
 * @param size The number of elements.
 * @param avgOdd Reference to store the average of odd numbers.
 */
void avgOddArray(const int arr[][2], const int size, int& avgOdd) {
    int sum = 0, count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i][1] % 2 != 0) {
            sum += arr[i][1];
            count++;
        }
    }
    avgOdd = (count > 0) ? (sum / count) : 0;
}

