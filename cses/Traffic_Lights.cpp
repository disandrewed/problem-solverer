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
set<LL> s; // lights
multiset<LL> ms; // gaps

void solve() {
    LL x, n;
    cin >> x >> n;

    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    s.insert(x);
    s.insert(0);
    ms.insert(x);

    for (LL i = 0; i < n; i++) {
        auto it = s.upper_bound(a[i]);
        LL above = *it;
        it--;
        LL below = *it;
        LL gap = above - below;

        ms.erase(ms.lower_bound(gap));

        ms.insert(above - a[i]);
        ms.insert(a[i] - below);
        s.insert(a[i]);
    
        cout << *ms.rbegin() << " ";
    }
}
/*

 
*/