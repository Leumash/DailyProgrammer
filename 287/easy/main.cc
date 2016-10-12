#include <iostream>
#include <algorithm>

using namespace std;

int maxDigit(int);
int descending(int);
string toFourDigitString(int);
int kaprekar(int);
bool hasTwoDifferentDigits(int);
int ascending(int);
int kaprekarIter(int,int);
bool isKaprekarsConstant(int);
int maxKaprekarIterations();

int main() {
    int n;

    cin >> n;

    cout << "Input:      " << n << endl;
    cout << "Max digit:  " << maxDigit(n) << endl;
    cout << "Descending: " << descending(n) << endl;
    cout << "Kaprekar:   " << kaprekar(n) << endl;
    cout << "Max Iters:  " << maxKaprekarIterations() << endl;

    return 0;
}

int maxKaprekarIterations() {
    int maxIters = 0;
    for (int i=0; i<10000; ++i) {
        int iters = kaprekar(i);
        maxIters = max(maxIters, iters);
    }
    return maxIters;
}

int maxDigit(int n) {
    string number = to_string(n);
    return *max_element(number.begin(), number.end()) - '0';
}

string toFourDigitString(int n) {
    string number = to_string(n);
    while (number.size() < 4) {
        number = '0' + number;
    }
    return number;
}

int kaprekar(int n) {
    if (!hasTwoDifferentDigits(n)) {
        return 0;
    }
    return kaprekarIter(n, 0);
}

int kaprekarIter(int n, int count) {
    if (isKaprekarsConstant(n)) {
        return count;
    }
    int iteration = descending(n) - ascending(n);
    return kaprekarIter(iteration, count + 1);
}

int descending(int n) {
    string number = toFourDigitString(n);
    sort(number.rbegin(), number.rend());
    return stoi(number);
}

int ascending(int n) {
    string number = toFourDigitString(n);
    sort(number.begin(), number.end());
    return stoi(number);
}

bool hasTwoDifferentDigits(int n) {
    return descending(n) != ascending(n);
}

bool isKaprekarsConstant(int n) {
    return n == 6174;
}

