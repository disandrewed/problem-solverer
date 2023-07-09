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

vector<LL> a;
 
void solve() {
    LL n, k;
    cin >> n >> k;
    LL input;
    LL total = 0;
    for (LL i = 0; i < n; i++) {
        cin >> input;
        a.push_back(input);
        total += input;
    }
    
    LL hi = total;
    LL lo = 0;
    LL ans = 0;
    while (lo <= hi) {
        LL lim = (hi + lo) / 2;
        LL res = 1;
        LL sum = 0;
        LL groups = 0;
        for (LL i = 0; i < n; i++) {
            if (a[i] > lim) {
                res = 0;
                break;
            } else if (sum + a[i] > lim) {
                sum = 0;
                groups++;
            }
            sum += a[i];
        }
        if (sum > 0) {
            groups++;
        }
        if (res == 1) {
            if (groups > k) {
                res = 0;
            }
        }
        if (res) {
            hi = lim - 1;
            ans = lim;
        } else {
            lo = lim + 1;
        }
        
    }
    cout << ans << endl;

}
/*
 
 
*/
/*
5 5 6 9 10

*/