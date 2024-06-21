#include <iostream>

using namespace std;


int mcd(int a, int b) {
    if (a < b < 0) {
        return 0;
    }
    if (b == 0) {
        return a;
    }
    if (b > 0) {
        return mcd(b, a % b);
    }
}

int main() {
    int a, b;
    cout << "Ingrese a: ";
    cin >> a;
    cout << "Ingrese b: ";
    cin >> b;

    cout << mcd(a, b);
}
