// #include<bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define endl '\n'
// #define YES cout << "YES\n"
// #define NO cout << "NO\n"
// using ll = long long;
// using vt = vector<int>;
// using vvt = vector<vector<int>>;
// using vpii = vector<pair<int,int>>;
// using vll = vector<long long>;
// using vvll = vector<vector<long long>>;
// using vpll = vector<pair<long long,long long>>;
// using pii = pair<int,int>;
// using pll = pair<ll,ll>;
// int _ = 1;
// const int INF = 0x3f3f3f3f;
// const long long LINF = 0x3f3f3f3f3f3f3f3fLL;


// void solve() {
//     int n, m;
//     cin >> n >> m;
//     ll ans = 0;
//     vll v(n);
//     for(int i = 0; i < n; i++) {
//         int a, b;
//         cin >> a >> b;

//         ans += a;
//         v[i] = b - a;
//     }
    
//     sort(v.begin(), v.end());

//     int x = m - n;// 最多有多少独栋
//     if(x == 0) {
//         cout << ans << endl;
//         return;
//     }
    
//     for(int i = n - 1; i >= 0; i--) {
//         if(i == 0) {
//             cout << max(ans + v[0], ans - v[1]);
//             return;
//         }
//         if(x == 0) break;
//         if(v[i] <= 0) break;

//         ans += v[i];
//         x--;
//     }

//     cout << ans << endl;
//     return;
// }

// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0),cout.tie(0);

//     cin >> _;

// /*
//     (__)
//     (..)_____
//     (oo)    /|\
//       | |--/ | *
//       w w w  w
//       20260810
// */

//     while(_--) solve();
//     return 0;
// }
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
    int n,m;
    cin >> n >> m;
    vpll a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    if (n == 1) 
    {
        cout << a[0].se << endl;
        return ;
    }
    ll ans = 0;
    for (int i = 0;i < n;i++) 
    {
        ans += a[i].fi;
    }
    ranges::sort(a,{},[&](auto& b){
        return -(b.se - b.fi);
    });
    int all = n;
    for (int i = 0;i < n;i++)
    {
        ll d = a[i].se - a[i].fi;
        if (d <= 0) break;
        all--;
        if (all == 1 && (m - all) / 2 >= n - all) 
        {
            ans = max(ans + d + a[i + 1].se - a[i + 1].fi,ans);
            break;
        }
        if ((m - all) / 2 >= n - all) 
        {
            ans += d;
        }
        else break;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}