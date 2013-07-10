#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(int argc, char const *argv[]) {
    int n, k, a;
    cin >> n >> k;

    vector<int> v1(n), v2(n), v3(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> a; 
        v1[i] = a; 
    }

    sort(v1.begin(), v1.end());

    for (size_t i = 0; i < n; ++i) {
        v2[i] = v1[i] + k; 
    }

    vector<int>::iterator it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    v3.resize(it - v3.begin());

    cout << v3.size() << endl;

    return 0;
}

