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
#define MAXN 100005
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

vector<LL> adj[MAXN];
LL visited[MAXN];
LL colour[MAXN];

LL dfs(LL node, LL col, LL parent) {
    visited[node] = 1;
    colour[node] = col;
    for (auto i : adj[node]) {
        if (i != parent) {
            if (colour[i] == 0) {
                LL c = 1;
                if (col == 1) {
                    c = 2;
                }
                if (dfs(i, c, node) == 0) {
                    return 0;
                }
            }
            if (colour[i] == colour[node]) {
                return 0;
            }
        }
    }
    return 1;
}

void solve() {
    LL n, m;
    cin >> n >> m;
    
    LL a, b;
    for (LL i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    LL success = 1;
    for (LL i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, 1, -1) == 0) {
                success = 0;
            }
        }
    }

    if (success == 1) {
        for (LL i = 1; i <= n; i++) {
            cout << colour[i] << " ";
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    } 
}
/*


*/
