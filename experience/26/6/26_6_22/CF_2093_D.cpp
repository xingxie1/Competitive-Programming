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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n, q;
    cin >> n >> q;
    while (q--) 
    {
        string op;
        cin >> op;
        if (op == "->") 
        {
            int x,y;
            cin >> x >> y;
            auto dfs = [&](auto&& self,ll x,ll y,ll N,ll mx,ll d) -> ll
            {
                if (N == 2) 
                {
                    if (x == 1 && y == 1) return d;
                    else if (x == 2 && y == 2) return d + 1;
                    else if (x == 2 && y == 1) return d + 2;
                    return d + 3;
                }
                ll res = 0;
                N /= 2;
                if (x <= N && y <= N) res = self(self,x,y,N,mx / 4,d);
                else if (x <= N && y > N) res = self(self,x,y - N,N,mx / 4,d + mx / 4 * 3);
                else if (x > N && y <= N) res = self(self,x - N,y,N,mx / 4,d + mx / 2);
                else res = self(self,x - N,y - N,N,mx / 4,d + mx / 4);
                return res;
            };
            ll N = 1 << n;
            ll mx = N * N;
            cout << dfs(dfs,x,y,N,mx,1) << endl;
        }
        else 
        {
            ll d;
            cin >> d;
            auto dfs = [&](auto&& self,ll x,ll y,ll N,ll mx,ll d) -> pii
            {
                if (N == 2) 
                {
                    if (d % 4 == 0) return {x,y + 1};
                    if (d % 4 == 3) return {x + 1,y};
                    if (d % 4 == 2) return {x + 1,y + 1};
                    return {x,y};
                }
                pll res = {1,1};
                N /= 2;
                if (d <= mx / 4) res = self(self,x,y,N,mx / 4,d);
                else if (d <= mx / 2) res = self(self,x + N,y + N,N,mx / 4,d - mx / 4);
                else if (d <= mx / 4 * 3) res = self(self,x + N,y,N,mx / 4,d - mx / 2);
                else res = self(self,x,y + N,N,mx / 4,d - mx / 4 * 3);
                return res;
            };
            ll N = 1 << n;
            ll mx = N * N;
            auto [x,y] = dfs(dfs,1,1,N,mx,d);
            cout << x << " " << y << endl;
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