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
const LL INF = 1e18;
 
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

vector<LL> pref;
multiset<LL> s;

void solve() {
    LL n, a, b;
    cin >> n >> a >> b;
    LL x;
    LL p = 0;
    pref.push_back(0);
    for (LL i = 0; i < n; i++) {
        cin >> x;
        p += x;
        pref.push_back(p);
    }

    LL ans = -MAXLL;
    for (LL i = a; i <= n; i++) {
        if (i > b) {
            s.erase(s.find(pref[i - b - 1]));
        }
        s.insert(pref[i - a]);
        ans = max(ans, pref[i] - *s.begin());
    }

    cout << ans << endl;
}
/*


*/
