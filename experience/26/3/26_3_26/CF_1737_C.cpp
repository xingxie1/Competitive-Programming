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
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    int x1,x2,x3,y1,y2,y3,x,y;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x >> y;
    int X = 0,Y = 0;
    X = (x1 == x2 || x1 == x3) ? x1 : x2;
    Y = (y1 == y2 || y1 == y3) ? y1 : y2;  
    // cout << X << " " << Y << endl;
    // cout << x << " " << y << endl;
    if ((X == 1 || X == n) && (Y == 1 || Y == n))
    {
        if (X == x || y == Y) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else if (X % 2 != x % 2 && y % 2 != Y % 2) cout << "NO" << endl;
    else cout << "YES" << endl;
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