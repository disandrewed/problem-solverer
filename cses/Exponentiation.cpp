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
#define MAXN 1000000
#define MOD 1000000007
 
// const LL INF = 2000000000;
 
#define TESTCASE 1
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


void solve() {
    LL n, p;
    cin >> n >> p;
    
    LL result = 1;
    while (p > 0) {
        
        if (p % 2 == 1) {
            result = (result * n) % MOD;
        }
        n = (n * n) % MOD;
        p = p / 2;
    }
    cout << result << endl;

}

/*

 
*/