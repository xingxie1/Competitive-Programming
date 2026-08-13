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
    int n;
    cin >> n;
    n = n * 2 + 2;

    int flag = 1;
    char choose[2] = {'a', 'b'};
    for(int i = 0; i < n; i++) {
        int in;
        cin >> in;

        if(i % 2 == 1 && i != n - 1) {
            if(in == 1) {
                flag ^= 1;
            }
            cout << choose[flag];
        }
    }
    cout << endl;
    return;

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

//     cin >> _;

/*
    (__)
    (..)_____
    (oo)    /|\
      | |--/ | *
      w w w  w
      20260803
*/

    while(_--) solve();
    return 0;
}