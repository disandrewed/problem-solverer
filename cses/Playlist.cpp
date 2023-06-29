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


// LL dp[MAXN]= {};
LL a[MAXN] = {};



void solve() {
    LL n;
    cin >> n;

    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }

    LL ans = 0;
    LL start = 0;
    
    unordered_map<LL,LL> m;
    m.reserve(32768);
    m.max_load_factor(0.25);

    for (LL i = 0; i < n; i++) {
        start = max(m[a[i]], start);
        ans = max(ans, i - start + 1);
        m[a[i]] = i + 1;
    }

    cout << ans << endl;
}
/*

 
*/