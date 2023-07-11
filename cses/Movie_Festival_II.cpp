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

vector<pair<LL, LL>> a;
multiset<pair<LL, LL>> s;

void solve() {
    LL n, k;
    cin >> n >> k;
    LL x, y;
    for (LL i = 0; i < n; i++) {
        cin >> x >> y;
        a.push_back({y, x});
    }

    sort(a.begin(), a.end());

    LL ans = 0;
    for (LL i = 0; i < n; i++) {
        auto it = s.upper_bound({a[i].second, MAXLL});
        if (*it != *s.begin()) {
            it--;
            if ((*it).first <= a[i].second) {
                s.erase(it);
            }
        }
        if (s.size() < k) {
            s.insert(a[i]);
            ans++;
        }
    } 

    cout << ans << endl;
}
/*
5 2
1 5
2 5
3 6
6 9
8 10


10 5
57 69
35 72
53 78
77 79
49 87
80 90
75 94
46 95
64 95
22 99
*/
