#include "closest_pair.h"
#include <cmath>

using namespace std;

pair<int,int> closest_pair_tonum(int upper_limit) {
    int best_m = -1, best_n = -1;
    
    int max_k = sqrt(2 * upper_limit); 

    for (int k = max_k; k >= 1; --k) {
        int k2 = k * k;
        for (int l = k - 1; l >= 1; --l) {
            int l2 = l * l;

            // m = (k² + l²)/2, n = (k² - l²)/2
            if (((k2 + l2) % 2 != 0) || ((k2 - l2) % 2 != 0)) continue;

            int m = (k2 + l2) / 2;
            int n = (k2 - l2) / 2;

            if (m >= upper_limit || n <= 0) continue;

            if (m > best_m || (m == best_m && n > best_n)) {
                best_m = m;
                best_n = n;
            }
        }
    }
    return {best_m, best_n};
}