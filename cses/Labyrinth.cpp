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
#define MAXN 10000
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

int a[MAXN][MAXN];
int visited[MAXN][MAXN];
char back[MAXN][MAXN];
void solve() {
    LL n, m;
    pair<LL, LL> start;
    pair<LL, LL> end;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            if (x == '.') {
                a[i][j] = 0;
            } else if (x == 'A') {
                a[i][j] = 2;
                start = {i, j};
            } else if (x == 'B') {
                a[i][j] = 3;
                end = {i, j};
            } else {
                a[i][j] = 1;
                visited[i][j] = 1;
            }
        }
    }
    for (int i = 0; i <= m+1; i++) {
        visited[0][i] = 1;
        visited[n+1][i] = 1;
    }
    for (int i = 0; i <= n+1; i++) {
        visited[i][0] = 1;
        visited[i][m+1] = 1;
    }
    queue<pair<LL, LL>> q;

    q.push(start);
    int success = 0;
    while (!q.empty()) {
        pair<LL, LL> temp = q.front();
        q.pop();

        if (a[temp.first][temp.second] == 3) {
            success = 1;
            break;
        }
        
        if (visited[temp.first + 1][temp.second] == 0) {
            q.push({temp.first + 1, temp.second});
            back[temp.first + 1][temp.second] = 'D';
            visited[temp.first + 1][temp.second] = 1;
        }
        if (visited[temp.first][temp.second + 1] == 0) {
            q.push({temp.first, temp.second + 1});
            back[temp.first][temp.second + 1] = 'R';
            visited[temp.first][temp.second + 1] = 1;
        }
        if (visited[temp.first - 1][temp.second] == 0) {
            q.push({temp.first - 1, temp.second});
            back[temp.first - 1][temp.second] = 'U';
            visited[temp.first - 1][temp.second] = 1;
        }
        if (visited[temp.first][temp.second - 1] == 0) {
            q.push({temp.first, temp.second - 1});
            back[temp.first][temp.second - 1] = 'L';
            visited[temp.first][temp.second - 1] = 1;
        }
    }

    if (success == 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

    vector<char> res = {};
    auto temp = end;
    while (temp != start) {
        res.push_back(back[temp.first][temp.second]);
        if (back[temp.first][temp.second] == 'U') {
            temp.first++;
        } else if (back[temp.first][temp.second] == 'D') {
            temp.first--;
        } else if (back[temp.first][temp.second] == 'R') {
            temp.second--;
        } else if (back[temp.first][temp.second] == 'L') {
            temp.second++;
        }
    }
    cout << res.size() << endl;

    for (int i = res.size()-1; i >= 0; i--) {
        cout << res[i];
    }
}
/*


*/
