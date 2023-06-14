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
#define MAXN 1006
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
    LL n;
    cin >> n;
    int a[MAXN][MAXN];
    int dp[MAXN][MAXN];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char x;
            cin >> x;
            if (x == '.') {
                a[i][j] = 1;
            } else if (x == '*') {
                a[i][j] = 0;
            }
        }
    }
    
    dp[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 0) {
                dp[i][j] = 0;
            } else if (i == 1 && j == 1) {

            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
            
            
        }
    }


    cout << dp[n][n] << endl;



}

/*

 
*/