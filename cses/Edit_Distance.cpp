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
LL dp[MAXN][MAXN];
void solve() {
    std::string n, m;
    cin >> n >> m;

    for (LL i = 0; i < MAXN; i++) {
        for (LL j = 0; j < MAXN; j++) {
            dp[i][j] = MAXLL;
        }
    }

    dp[0][0] = 0;
    for (LL i = 0; i <= n.length(); i++) {
        for (LL j = 0; j <= m.length(); j++) {
            if (i != 0) {
				dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + 1);
			}
			if (j != 0) {
				dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 1);
			}
			if (i != 0 && j != 0) {
				LL nc = dp[i - 1][j - 1] + (n[i - 1] != m[j - 1]);
				dp[i][j] = min(dp[i][j], nc);
			}
        }
    }

    cout << dp[n.length()][m.length()] << endl;
}

/*

 
*/