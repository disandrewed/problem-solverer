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
    LL n, x;
    cin >> n >> x;
    LL input;
    for (LL i = 0; i < n; i++) {
        cin >> input;
        a.push_back(input);
    }
    //sort(a.begin(), a.end());
    

    unordered_map<LL, LL> m;

    LL ans = 0;
    LL front = 0;
    LL total = 0;

    for (LL back = 0; back < n; back++) {
        while (front < n && total + (m[a[front]] == 0) <= x) {
            m[a[front]]++;
            if (m[a[front]] == 1) {
                total++;
            }
            front++;
        }

        ans += front - back;
        if (m[a[back]] == 1) {
            total--;
        }
        m[a[back]]--;
    }
 
    cout << ans << endl;
}
/*
 
 
*/
/*


*/