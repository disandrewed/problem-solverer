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
#define MAXIN 2000000000
#define MAXN 1003
 
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
 
LL recurse(vector<LL> a, LL total, LL curr, LL sum) {
    if (curr == a.size()) {
        return sum; 
    }
    LL first = recurse(a, total, curr + 1, sum + a[curr]);
    LL second = recurse(a, total, curr + 1, sum);
 
    LL half = total/2;
    LL firstdiff = abs(half - first);
    LL seconddiff = abs(half - second);
 
    if (firstdiff < seconddiff) {
        return first;
    }
    return second;
}
 
 
void solve() {
    LL n;
    cin >> n;
    LL total = 0;
    LL ans = 0;
    vector<LL> a;
    for (LL i = 0; i < n; i++) {
        LL x;
        cin >> x;
        a.push_back(x);
        total += x;
    }
 
    LL res = recurse(a, total, 0, 0);
 
    //cout << res << endl;
 
    ans = abs((total - res) - res);
 
 
    cout << ans << endl;
 
 
}
 
 
/*
 
5
3 2 7 4 1
 
1 2 3 4 7
 
*/