#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std; 

int main() {
    int n = 0;
    int id = 0;

    while(scanf("%d", &n) && n > 0) {
        if (n < 0)
            break;

        int l = ceil(log(n)/log(2));
        printf("Case %d: %d\n", ++id, l);
    }

    return 0;
}
