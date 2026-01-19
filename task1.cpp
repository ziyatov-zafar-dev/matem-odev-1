#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    double diskriminant, x1, x2;

    cout << "a katsayisini giriniz: ";
    cin >> a;

    cout << "b katsayisini giriniz: ";
    cin >> b;

    cout << "c katsayisini giriniz: ";
    cin >> c;

    diskriminant = b * b - 4 * a * c;

    cout << "\nDiskriminant = " << diskriminant << endl;

    if (diskriminant < 0) {
        cout << "Bu denklemin gercek kokleri yoktur." << endl;
    } 
    else if (diskriminant == 0) {
        x1 = -b / (2 * a);
        cout << "Bu denklemin bir tane gercek koku vardir." << endl;
        cout << "Kok: x = " << x1 << endl;
    } 
    else {
        x1 = (-b + sqrt(diskriminant)) / (2 * a);
        x2 = (-b - sqrt(diskriminant)) / (2 * a);
        cout << "Bu denklemin iki farkli gercek koku vardir." << endl;
        cout << "1. Kok: x1 = " << x1 << endl;
        cout << "2. Kok: x2 = " << x2 << endl;
    }

    return 0;
}
