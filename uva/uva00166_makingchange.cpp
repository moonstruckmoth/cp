#include <iostream>
#include <vector>
#include <iomanip>

using namespace std; 

int main(int argc, char const *argv[]) {
    const int N = 6;
    const int denom[] = {5, 10, 20, 50, 100, 200};
    const int INF = 200000000;

    int coins[N];
    double transaction;

    while (cin >> coins[0] >> coins[1] >> coins[2] >> coins[3] >> coins[4] >> coins[5] >> transaction, (coins[0] || coins[1] || coins[2] || coins[3] || coins[4] || coins[5])) {

        int tr = (100 * transaction + 0.5);

        int total = 0;
        for (size_t i = 0; i < N; ++i) {
            total += denom[i] * coins[i];
        }

        // classical coin change
        vector<int> change(total + 1);
        change[0] = 0;

        for (size_t i = 1; i < total + 1; ++i) {
            change[i] = INF;
            for (size_t j = 0; j < N; ++j) {
                if (denom[j] && denom[j] <= i && change[i - denom[j]] + 1 < change[i])
                    change[i] = change[i - denom[j]] + 1;
            }
        }

        // limited coin change
        vector< vector<int> > coinsState(N, vector<int>(total + 1));
        for (size_t i = 0; i < N; ++i) {
            coinsState[i][0] = coins[i];
        }

        vector<int> minCoins(total + 1);
        minCoins[0] = 0;

        for (size_t i = 1; i < total + 1; ++i) {
            minCoins[i] = INF;
            for (size_t j = 0; j < N; ++j) {
                if (denom[j] > i || coinsState[j][i - denom[j]] <= 0 || minCoins[i - denom[j]] == INF) {
                    coinsState[j][i] = coinsState[j][0];
                } else {
                    minCoins[i] = minCoins[i - denom[j]] + 1;
                    for (size_t k = 0; k < N; ++k) {
                        coinsState[k][i] = coinsState[k][i - denom[j]];
                        if (k == j)
                            (coinsState[k][i])--;
                    }
                }
            }
        }

        int min = minCoins[tr];
        for (size_t i = tr + 1; i < total + 1; ++i) {
            if (minCoins[i] + change[i - tr] < min)
                min = minCoins[i] + change[i - tr];
        }

        cout << setw(3) << min << endl;
    }


    return 0;
}
