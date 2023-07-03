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

// LL a[MAXN];
vector<LL> a;


void solve() {
    LL n, t;
    cin >> n >> t;
    for (LL i = 0; i < n; i++) {
        LL x;
        cin >> x;
        a.push_back(x);
    }

    LL hi = 1000000000000000000, lo = 0;
    while (lo <= hi) {
        LL mid = (hi + lo) / 2;
        LL created = 0;
        for (int i = 0; i < n; i++) {
            created += mid / a[i];
            if (created >= t) break;
        }

        if (created >= t) {
            hi = mid - 1;
        } else if (created <= t) {
            lo = mid + 1;
        }
    }
    cout << hi + 1 << endl;
}
/*
43478261000000000
1000000000000000000
*/