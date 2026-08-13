#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
using ll = long long;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vpii = vector<pair<int,int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vpll = vector<pair<long long,long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
int _ = 1;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;


void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vvt g(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vll ans(n + 1, -1);
    ans[1] = 0;

    queue<int> gi, ou;
    ou.push(1);

if(k % 2 == 1) {
    ll num = 0;
    while(!gi.empty() || !ou.empty()) {

        num++;
        for(int i = 1; i <= k; i++) {


            if(gi.empty() && ou.empty()) break;

            if(i % 2 == 1) { // 此时该从ou点走到gi点
                while(!ou.empty()) {
                    int x = ou.front();

                    // cout << "x: " << x << endl;
                    
                    ou.pop();
                    for(auto it : g[x]) {
                        if(ans[it] != -1) continue;

                        ans[it] = num;
                        gi.push(it);
                    }
                }
            }
            else {
                 while(!gi.empty()) {
                    int x = gi.front();

                    // cout << "x: " << x << endl;

                    gi.pop();
                    for(auto it : g[x]) {
                        // if(ans[it] != -1) continue;
                        ou.push(it);
                    }
                }
            }
        }

        swap(gi, ou);

    }
}
else {
    ll num = 0;

    while(!gi.empty() || !ou.empty()) {

        num++;

        for(int i = 1; i <= k; i++) {

            if(gi.empty() && ou.empty()) break;

            if(i % 2 == 1) { // 此时该从ou点走到gi点
                while(!ou.empty()) {
                    int x = ou.front();

                    ou.pop();
                    for(auto it : g[x]) {

                        gi.push(it);
                    }
                }
            }
            else {
                 while(!gi.empty()) {
                    int x = gi.front();

                    // cout << "x: " << x << endl;

                    gi.pop();
                    for(auto it : g[x]) {
                        if(ans[it] != -1) continue;

                        ans[it] = num;
                        ou.push(it);
                    }
                }
            }
        }
    }
}

for(int i = 1; i <= n; i++) {
    if(ans[i] == -1) {
        cout << -1 << ' ';
        continue;
    }
    cout << 1LL * ans[i] * k << ' ';
}

cout << endl;
return;

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> _;

/*
    (__)
    (..)_____
    (oo)    /|\
      | |--/ | *
      w w w  w
      20260805
*/

    while(_--) solve();
    return 0;
}