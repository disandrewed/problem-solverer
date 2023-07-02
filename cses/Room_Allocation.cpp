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

// LL a[MAXN] = {};
set<vector<LL>> s;
LL a[MAXN];

void solve() {
    LL n;
    cin >> n;

    int arr, dep;
    for (LL i = 0; i < n; i++) {
        cin >> arr >> dep;
        vector<LL> ins = {arr, dep, i};
        s.insert(ins);
    }

    LL endrooms = 0;
    LL numrooms = 0;

    auto it = s.begin();
    priority_queue<pair<LL, LL>> rooms;

    while (it != s.end()) {
        if (rooms.empty()) {
            endrooms++;
            rooms.push({-(*it)[1], endrooms});
            a[(*it)[2]] = endrooms;
        } else {
            auto min = rooms.top();
            if (-min.first < (*it)[0]) {
                rooms.pop();
                rooms.push({-(*it)[1], min.second});
                a[(*it)[2]] = min.second;
            } else {
                endrooms++;
                rooms.push({-(*it)[1], endrooms});
                a[(*it)[2]] = endrooms;

            }
        }
        numrooms = max(endrooms, static_cast<LL>(rooms.size()));
        it++;
    }

    cout << numrooms << endl;
    for (LL i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
/*



*/