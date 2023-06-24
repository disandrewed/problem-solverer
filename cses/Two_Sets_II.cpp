//#include <bits/stdc++.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
 
using namespace std;
 
#define LL long long
#define MAXLL 9223372036854775806
#define MAXN 505
#define MOD 1000000007
 
// const LL INF = 2000000000;
 
#define TESTCASE 0
#if TESTCASE == 1
    #define TAKE_INPUT LL t; cin >> t; while (t--) { solve(); }
#else 
    #define TAKE_INPUT solve();
#endif

void solve();
int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    TAKE_INPUT;
}
 
// CODE :D


LL dp[MAXN][62627] = {};
LL a[MAXN] = {};

void solve() {
    LL n;
    cin >> n;

    LL total  = n * (n+1) / 2;
    if (total % 2 != 0) {
        cout << 0 << endl;
        return;
    }
    total /= 2;

    dp[0][0] = 1;
    for (LL i = 1; i < n; i++) {
        for (LL j = 0; j <= total; j++) {
            dp[i][j] = dp[i-1][j];
            LL k = j - i;
            if (k >= 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
            }
        }
    }

    cout << dp[n-1][total] << endl;

}
/*

 
*/