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
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,k;
    cin >> n >> k;
    vt a(n),cnt(n + 1);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vt b;
    ll sum = 0;
    for (int x : cnt) 
    {
        if (x) 
        {
            b.push_back(x);
            sum += x;
        }
    }
    ranges::sort(b,{},[&](int x) {return -x;});
    int ans = 0;
    // cout << sum << endl;
    while (b.size())
    {
        int mn = b.back();
        for (int i = 0;i < mn;i++)
        {
            ll ns = sum - 1LL * i * b.size();
            if (k >= ns && (k - ns) % b.size() == 0)
            {
                ans ++;
                break;
            }
        }
        for (int& x : b) x -= mn;
        sum -= 1LL * b.size() * mn;
        while (b.size() && b.back() == 0) b.pop_back(); 
    }
    cout << ans << endl;
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