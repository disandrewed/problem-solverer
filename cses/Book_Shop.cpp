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
#define MAXN 1005
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
    int n, x;
    cin >> n >> x;

    int price[1000];
    int pages[1000];

    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    // int dp[1001][10000];
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - price[i-1] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j - price[i-1]] + pages[i-1]);

            }
            
        }
    }
    cout << dp[n][x] << endl;

}

/*

 
*/