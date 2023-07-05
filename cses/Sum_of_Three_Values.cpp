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
    LL n, x;
    cin >> n >> x;
    LL in;
    for (int i = 0; i < n; i++) {
        cin >> in;
        a.push_back({in, i+1});
    }
    sort(a.begin(), a.end());

    for (int top = 2; top < n; top++) {
        int left = 0;
        int right = top-1;
        while (left != right) {
            if (a[left].first + a[right].first + a[top].first == x) {
                cout << a[left].second << " " << a[right].second << " " << a[top].second << endl;
                return;
            } else if (a[left].first + a[right].first + a[top].first > x) {
                right--;
            } else {
                left++;
            }
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
}
/*

//cout << "top: " << top << " middle: " << middle << " bottom: " << bottom << endl;
*/