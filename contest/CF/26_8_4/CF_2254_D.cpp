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
    int n;
    cin >> n;
    vpll b(n);
    for (int i = 0;i < n;i++) cin >> b[i].fi,b[i].se = i;
    ranges::sort(b);
    vll a(n);
    ll sum = 0;
    ll mx = 0;
    if (b[0].fi != 0) 
    {
        cout << -1 << endl;
        return ;
    }
    for (int i = 0;i < n;i++)
    {
        int j = i;
        int cnt = 0;
        while (j < n && b[j].fi == b[i].fi)
        {
            j++;
            cnt++;
        }
        if (j == n) 
        {
            if (sum != b[i].fi) 
            {
                cout << -1 << endl;
                return ;
            }
            for (int jj = i;jj < n;jj++)
            {
                a[b[jj].se] = mx + 1;
            }
            break;
        }
        auto [x,id] = b[j];
        if (x < sum || (x - sum) % cnt) 
        {
            // cout << x << " " << sum << " " << cnt << endl;
            cout << -1 << endl;
            return ;
        }
        ll t = (x - sum) / cnt;
        if (t <= mx) 
        {
            cout << -1 << endl;
            return ;
        }
        mx = t;
        for (int ii = i;ii < j;ii++)
        {
            int id = b[ii].se;
            a[id] = t;
            sum += t;
        }
        i = j - 1;
    }
    for (ll x : a) cout << x << " ";
    cout << endl;
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