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
#define MAXN 5001
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


LL dp[MAXN][MAXN] = {};
LL a[MAXN] = {};

void solve() {
    LL n;
    cin >> n;
    LL total = 0;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    for (int l = n - 1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if (l == r) {
                dp[l][r] = a[l];
            } else {
                dp[l][r] = max(a[l] - dp[l+1][r],
                a[r]-dp[l][r-1]);
            }
        }
    }
    cout << (total + dp[0][n-1]) / 2 << endl;

}
/*

 
*/