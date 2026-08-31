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
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

using i128 = __int128_t;
void solve()
{
    int n,k;
    cin >> n >> k;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    if (k == 1)
    {
        ll sum = 0;
        for (ll x : a) 
        {
            sum = (sum + x) % MOD;
        }
        cout << sum << endl;
        return ;
    }
    // if (k == 2) 
    // {
    //     cout << 0 << endl;
    //     return ;
    // }
    i128 cnt = 0;
    pqueue<ll> pq;
    for (ll x : a) 
    {
        cnt += x / k;
        if (x % k) pq.push(x % k);
    }
    // cout << (ll)cnt << endl;
    while (cnt && !pq.empty())
    {
        ll x = pq.top();
        pq.pop();
        ll res = k - x;
        // cout << x << " " << (ll)cnt << endl;
        if (cnt >= res)
        {
            cnt -= res;
            cnt++;
            x = 0;
        }
        else
        {
            x += cnt;
            cnt = 0;
            pq.push(x);
            break;
        }
    }
    cnt %= (k - 1);
    ll ans = cnt % MOD;
    while (!pq.empty())
    {
        ll x = pq.top();
        if (x == k - 1)
        {
            x = 0;
        }
        ans = (ans + x) % MOD;
        pq.pop();
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