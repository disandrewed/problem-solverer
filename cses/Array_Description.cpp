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
#define MAXN 100005
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
LL dp[100001][101];

void solve() {
    LL n, m;
    cin >> n >> m;
    LL a[MAXN];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    

    if (a[0] == 0) {
        for (LL i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][a[0]] = 1;
    }


    for (LL i = 1; i < n; i++) {
        if (a[i] == 0) {
            for (LL j = 1; j <= m; j++) {
                if (j-1 >= 1) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                }
                if (j+1 <= m) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
                }
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
        } else {
            if (a[i]-1 >= 1) {
                dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]-1]) % MOD;
            }
            if (a[i]+1 <= m) {
                dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]+1]) % MOD;
            }
            dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]]) % MOD;
        }
    }
    LL ans = 0;

    for (LL i = 1; i <= m; i++) {
        ans = (ans + dp[n-1][i]) % MOD;
    }

    cout << ans << endl;
}

/*

 
*/