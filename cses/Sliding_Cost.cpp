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

multiset<LL> l;
multiset<LL> r;

LL lsum = 0;
LL rsum = 0;

void rem(LL y) {
    if (r.size() == 0) {
        l.erase(l.find(y));
        lsum -= y;
    } else if (*l.rbegin() >= y) {
        l.erase(l.find(y));
        lsum -= y;
        lsum += *r.begin();
        l.insert(*r.begin());
        rsum -= *r.begin();
        r.erase(r.begin());
        
    } else {
        r.erase(r.find(y));
        rsum -= y;
    }
}

void ins(LL x) {
    if ((r.size() != 0 && x > *l.rbegin()) && !l.empty()) {
        r.insert(x);
        rsum += x;
        LL p = *(r.begin());
        rsum -= p;
        r.erase(r.begin());
        l.insert(p);
        lsum += p;
    } else {
        l.insert(x);
        lsum += x;
    }
    
    while (l.size() != r.size() && l.size() != r.size() + 1) {
        auto it = l.end();
        if (l.size() != 0) {
            it--;
            r.insert(*it);
            rsum += *it;
            lsum -= *it;
            l.erase(it++);
        }
    }
}

void solve() {
    LL n, k;
    cin >> n >> k;
    LL input;
    for (LL i = 0; i < n; i++) {
        cin >> input;
        a.push_back(input);
    }

    for (LL i = 0; i < k; i++) {
        ins(a[i]);
    }

    LL mult = k/2;
    LL med = 0;
    for (LL i = k; i < n; i++) {
        med = *(l.rbegin());
        LL leftsum = lsum - med;
        LL rightsum = rsum;
        LL ans = ((med * mult) - leftsum) + (rightsum - (med * mult));
        if (k % 2 == 0) {
            ans = ((med * (mult - 1)) - leftsum) + (rightsum - (med * mult));
        }

        cout << ans << " ";

        rem(a[i-k]);
        ins(a[i]);
        
    }
    med = *(l.rbegin());   
    LL leftsum = lsum - med;
    LL rightsum = rsum;
    LL ans = ((med * mult) - leftsum) + (rightsum - (med * mult));
    if (k % 2 == 0) {
        ans = ((med * (mult - 1)) - leftsum) + (rightsum - (med * mult));
    }
    cout << ans << " ";
}
/*


*/
