#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
// #define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    int x = 1,y = 1;
    int d1;
    cout << "? " << x << " " << y << endl;
    cin >> d1;
    if (d1 + x <= n) {
        cout << "? " << x + d1 << " " << y << endl;
        int d2;
        cin >> d2;
        if (d2 != d1) 
        {
            cout << "! " << d1 + x << " " << d2 + y << endl; 
        }
        else 
        {
            int d3;
            cout << "? " << x + d1 << " " << y + d2 << endl;
            cin >> d3;
            cout << "! " << d1 - d3 + x << " " << d1 + y << endl;
        }
    } 
    else {
        cout << "? " << x << " " << y + d1 << endl;
        int d2;
        cin >> d2;
        if (d2 != d1) 
        {
            cout << "! " << d2 + x << " " << d1 + y << endl; 
        }
        else 
        {
            int d3;
            cout << "? " << x + d1 << " " << y + d2 << endl;
            cin >> d3;
            cout << "! " << d1 + x << " " << d1 - d3 + y << endl;
        }
    }
    


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}