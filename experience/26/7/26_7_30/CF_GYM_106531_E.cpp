#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    ll ax,ay,bx,by;
    cin >> ax >> ay >> bx >> by;
    int m;
    cin >> m;
    ll ans = abs(ax - bx) + abs(ay - by);
    for (int i = 0;i < m;i++) 
    {
        ll d,k;
        cin >> k >> d;
        ll y1 = d * ax + k;
        ll y2 = d * bx + k;
        ll x1 = (ay - k) / d;
        ll x2 = (by - k) / d;
        ans = min(ans,abs(ax - x1) + abs(bx - x2) + abs(x2 - x1));
        ans = min(ans,abs(ax - x1) + abs(y2 - by) + abs(bx - x1));
        ans = min(ans,abs(y1 - ay) + abs(bx - x2) + abs(ax - x2));
        ans = min(ans,abs(y1 - ay) + abs(y2 - by) + abs(ax - bx));
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}