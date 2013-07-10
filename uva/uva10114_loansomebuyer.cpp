#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std; 

int main() {
    int tenure;
    int n;
    double downPayment;
    double loan;

    while (cin >> tenure >> downPayment >> loan >> n, (tenure >= 0)) {

        double deps[101] = {0.0};
        for (int i = 0; i < n; ++i) {
            int id;
            double val;
            cin >> id >> val;
            for (int j = id; j < 101; ++j)
                deps[j] = val;
        }

        double carValue = (downPayment + loan)*(1 - deps[0]);
        double amtRemaining = loan;
        double emi = (loan/tenure);

        int i = 0;
        while(carValue < amtRemaining) {
            ++i;
            amtRemaining -= emi;
            carValue *= (1 - deps[i]);

        }

        cout << i << " month";
        if (i != 1)
            cout << "s";
        cout << endl;
    }

}
