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
LL component[MAXN] = {};
vector<LL> parents;

void DFS(LL n) {
    if (component[n] == 0) {
        component[n] = n;
        parents.push_back(n);
    }

    for (auto next : adj[n]) {
        if (component[next] == 0) {
            component[next] = component[n];
            DFS(next);
        }
    }
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

    for (LL i = 1; i <= n; i++) {
        DFS(i);
    }

    cout << parents.size() - 1 << endl;

    for (LL i = 1; i < parents.size(); i++) {
        cout << parents[i-1] << " " << parents[i] << endl;
    } 

}
/*


*/
