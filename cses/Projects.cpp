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
#define MAXN 200005
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


//LL dp[MAXN]= {};
LL s[MAXN] = {};
LL e[MAXN] = {};
LL r[MAXN] = {};


void solve() {
    LL n;
    cin >> n;

    map<LL,LL> c;
    for (LL i = 0; i < n; i++) {
        cin >> s[i] >> e[i] >> r[i];
        e[i]++;
        c[s[i]] = 0;
        c[e[i]] = 0;
    }

    LL coords = 0;

    for (auto &p : c) {
        p.second = coords++;
    }

    vector<vector<pair<LL,LL>>> project(coords);
    for (LL i = 0; i < n; i++) {
        project[c[e[i]]].emplace_back(c[s[i]], r[i]);
    }

    vector<LL> dp(coords, 0);

    for (LL i = 0; i < coords; i++) {
        if (i > 0) {
            dp[i] = dp[i-1];
        }
        for (auto p : project[i]) {
            dp[i] = max(dp[i], dp[p.first] + p.second);
        }
    }

    cout << dp[coords - 1] << endl;

}
/*

 
*/