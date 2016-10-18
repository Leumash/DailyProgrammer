#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        int divisor = gcd(a,b);

        cout << a / divisor << ' ' << b / divisor << endl;
    }

}

