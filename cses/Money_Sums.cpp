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
#define MAXN 501
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


LL dp[MAXN][100001] = {};

void solve() {
    LL n;
    cin >> n;
    LL a[MAXN];

    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0][0] = 1;

    for (LL i = 1; i <= n; i++) {
		for (LL j = 0; j <= 100000; j++) {
			dp[i][j] = dp[i - 1][j];
			LL prev_sum = j - a[i - 1];
			if (prev_sum >= 0 && dp[i - 1][prev_sum] == 1) {
				dp[i][j] = 1;
			}
		}
	}

    vector<LL> res = {};
    for (LL i = 1; i <= 100000; i++) {
		if (dp[n][i]) { 
            res.push_back(i); 
        }
	}

    cout << res.size() << endl;
    for (auto e : res) {
        cout << e << " ";
    }
    cout << endl;

}
/*

 
*/