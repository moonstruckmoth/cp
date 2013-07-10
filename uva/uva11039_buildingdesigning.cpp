#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;

    while (N--) {
        vector<int> red;
        vector<int> blue;

        int n;
        int a;

        cin >> n;

        for (size_t i = 0; i < n; ++i) {
            cin >> a;

            if (a > 0)
                blue.push_back(a);
            else
                red.push_back(a);
        }

        sort(blue.rbegin(), blue.rend());
        sort(red.begin(), red.end());

        int last = 0;
        int count = 0;
        int j = 0;
        int k = 0;

        for (size_t i = 0; i < n; ++i) {
            if (count == 0) {
                if (j < blue.size() && i < red.size()) {
                    if (blue[j] > -red[k]) {
                        last = blue[j++];
                        count++;
                    } else {
                        last = red[k++];
                        count++;
                    }
                }
            } else if (last < 0) {
                if (j < blue.size()) {
                    if (blue[j] < -last) {
                        last = blue[j];
                        count++;
                    }
                    j++;
                }
            } else {
                if (k < red.size()) {
                    if (-red[k] < last) {
                        last = red[k];
                        count++;
                    }
                    k++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
