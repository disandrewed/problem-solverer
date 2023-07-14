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
vector<LL> parents;
int visited[MAXN];
int back[MAXN];

void solve() {
    LL n, m;
    cin >> n >> m;
    
    LL a, b;
    for (LL i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<LL> q;
 
    q.push(1);
    int success = 0;
    while (!q.empty()) {
        LL temp = q.front();
        q.pop();
 
        if (temp == n) {
            success = 1;
            break;
        }

        for (auto i : adj[temp]) {
            if (visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
                back[i] = temp;
            }
        }
    }
 
    if (success == 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<LL> res = {};
    auto temp = n;
    res.push_back(n);
    while (temp != 1) {
        res.push_back(back[temp]);
        temp = back[temp];
    }
    cout << res.size() << endl;
    for (int i = res.size()-1; i >= 0; i--) {
        cout << res[i] << " ";
    }
}
/*


*/
