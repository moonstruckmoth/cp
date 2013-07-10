#include <iostream> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
using namespace std; 

bool cmp(const pair<double, double>& lhs, const pair<double, double>& rhs) {
    return lhs.first < rhs.first;
}

int main(int argc, char const *argv[])
{
    int n;
    int l;
    int w;

    while (cin >> n >> l >> w) {
        vector< pair<double, double> > v;

        double w2 = 0.25 * w * w;
        for (size_t i = 0; i < n; ++i) {
            double c, r;
            cin >> c >> r;

            double d = r * r - w2;
            if (d <= 0)
                continue;
            d = sqrt(d);

            v.push_back(make_pair(c - d, c + d));
        }

        sort(v.begin(), v.end(), cmp);
        // for (size_t i = 0; i < v.size(); ++i) {
        //     cout << "l: " << v[i].first << ", r: " << v[i].second << endl;
        // }

        double left = 0;
        double right = 0;
        double count = 1;
        for (size_t i = 0; i < v.size(); ++i) {
            if (v[i].first <= left) {
                right = max(right, v[i].second);
            } else {
                if (v[i].first > right)
                    break;
                
                count++;
                left = right;
                right = max(right, v[i].second);
            }
            
        }

        if (right >= l)
            cout << count << endl;
        else
            cout << "-1" << endl;

    }

    return 0;
}
