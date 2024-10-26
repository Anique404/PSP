#include <iostream>
using namespace std;

int main() {
    int count = 0;
    float sum = 0, num;
    float avg;

    do {
        cout << "Enter a number (negative to exit): ";
        cin >> num;

        if (num >= 0) {
            count++;
            sum += num;
        }

    } while (num >= 0);

    if (count > 0) {
        avg = sum / count;
        cout << "Count of numbers: " << count << endl;
        cout << "Sum is: " << sum << endl;
        cout << "Average is: " << avg << endl;
    } else {
        cout << "No positive numbers were entered." << endl;
    }

    return 0;
}

