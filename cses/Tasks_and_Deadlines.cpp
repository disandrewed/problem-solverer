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
vector<pair<LL, LL>> a;

void solve() {
    LL n;
    cin >> n;

    LL duration, deadline;
    for (LL i = 0; i < n; i++) {
        cin >> duration >> deadline;
        a.push_back({duration, deadline});
    }

    sort(a.begin(), a.end());

    LL total = 0;
    LL start = 0;
    for (LL i = 0; i < n; i++) {
        start += a[i].first;
        total += a[i].second - start;
    }

    cout << total << endl;
}
/*


*/