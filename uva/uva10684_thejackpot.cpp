#include <iostream> 
using namespace std; 

int main(int argc, char const *argv[]) {
    int n;

    while (cin >> n, (n != 0)) {
        int maxSoFar = 0;
        int maxEndingHere = 0;
        int a;
        for (size_t i = 0; i < n; ++i) {
            cin >> a;

            maxEndingHere += a;
            if (maxEndingHere < 0)
                maxEndingHere = 0;

            if (maxSoFar < maxEndingHere)
                maxSoFar = maxEndingHere;
        }

        if (maxSoFar > 0)
            cout << "The maximum winning streak is " << maxSoFar << "." << endl;
        else
            cout << "Losing streak." << endl;
    }

    return 0;
}
