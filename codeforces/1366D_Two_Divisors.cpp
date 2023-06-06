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
#define MAXN 500000
#define MOD 1000000007
 
const int N = 1e7+5;
const int INF = 2000000000;
 
#define TESTCASE 0
#if TESTCASE == 1
    #define TAKE_INPUT int t; cin >> t; while (t--) { solve(); }
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
 
int pf[N+1];
 
 
vector<int> pd (int g) {
    vector<int> ret;
    while (g != 1) {
        if (ret.size() == 0 || ret[ret.size()-1] != pf[g]) {
            ret.push_back(pf[g]);
        }
        g /= pf[g];
    }
    return ret;
}
 
 
void solve() {
    
    pf[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (pf[i] == 0) {
            pf[i] = i;
            for (int j = i; j <= N; j += i) {
                if (j > N) break;
                if (pf[j] == 0) {
                    pf[j] = i;
                }
            }
        }
    }
    
 
    int n;
    cin >> n;
 
    int a[MAXN];
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans1[MAXN], ans2[MAXN];
    
    for (int i = 0; i < n; i++) {
        vector<int> v = pd(a[i]);
        if (v.size() < 2) {
            ans1[i] = -1;
            ans2[i] = -1;
        } else {
            ans1[i] = v[0];
            int total = 1;
            int sz = v.size();
            for (int j = 1; j < sz; j++) {
                total *= v[j];
            }
            ans2[i] = total;
        }
    }
 
    for (int i = 0; i < n;i++) {
        cout << ans1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n;i++) {
        cout << ans2[i] << " ";
    }
    cout << endl;
    
}
/*
 
 
 
*/