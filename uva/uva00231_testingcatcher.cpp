#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    vector<int> v;
    int n;
    int count = 0;

    while (true) {

        while (cin >> n, (n != -1))
            v.push_back(n);

        vector<int> lis(v.size(), 1);

        int ans = 1;
        for (size_t i = 1; i < v.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if ((v[i] < v[j]) && (lis[i] < lis[j] + 1)) {
                    lis[i] = lis[j] + 1;
                    ans = max(ans, lis[i]);
                }
            }
        }

        cout << "Test #" << ++count << ":" << endl;
        cout << "  maximum possible interceptions: " << ans << endl;

        v.clear();

        cin >> n;
        if (n == -1)
            break;
        else
            v.push_back(n);
    }
}
