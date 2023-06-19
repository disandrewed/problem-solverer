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
#define MAXN 1000005
#define MOD 1000000007
 
// const LL INF = 2000000000;
 
#define TESTCASE 1
#if TESTCASE == 1
    #define TAKE_INPUT LL t; cin >> t; while (t--) { solve(); }
#else 
    #define TAKE_INPUT solve();
#endif


LL dp[MAXN][4];


void solve();
int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    dp[3][0] = 8;
    dp[3][1] = 5;
    dp[3][2] = 3;
    dp[3][3] = 34;
    for (int i = 4; i <= 1000000; i++) {
        dp[i][0] = (dp[i-1][3]) % MOD;
        dp[i][1] = ((dp[i-1][1] * 3) + dp[i-1][0]) % MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][2]) % MOD;
        dp[i][3] = ((dp[i][0] * 2) + (dp[i][1] * 3) + dp[i][2]) % MOD;
    }

    TAKE_INPUT;
}
 
// CODE :D

void solve() {
    LL n;
    cin >> n;

    if (n == 1) {
        cout << "2" << endl;
        return;
    } else if (n == 2) {
        cout << "8" << endl;
        return;
    } else if (n == 3) {
        cout << "34" << endl;
        return;
    }

    cout << dp[n][3] << endl;

}

/*

 
*/