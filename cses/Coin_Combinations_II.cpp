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
#define MAXN 1000
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


void solve() {
    LL n, x;
    LL a[MAXN];
    cin >> n >> x;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }

    LL dp[1000001] = {};
    dp[0] = 1;

    for (LL j = 0; j < n; j++) {
        for (LL i = 0; i <= x; i++) {
            if (i - a[j] >= 0) {
                dp[i] += dp[i - a[j]];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[x] << endl;


}

/*
 
 3 9
2 3 5
 
*/