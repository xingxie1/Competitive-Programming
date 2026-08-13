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
    int n,a,b;
    cin >> n >> a >> b;
    if (a > b) swap(a,b);
    if (popcount(1u * a) % 2 != popcount(1u * b) % 2) 
    {
        NO;
        return;
    }
    YES;
    auto get_id = [&](int x) 
    {
        return min(x,x ^ 3);
    };
    set<int> ban;
    ban.insert(get_id(a));
    ban.insert(get_id(b));
    vpii add;
    if ((a ^ b) != 3)
    {
        vt bits;
        for (int i = 2;i < n;i++) 
        {
            if (((a ^ b) >> i) & 1) bits.push_back(i);
        }
        int cur = a ^ 3;
        for (int j = 0;j + 1 < bits.size();j++)
        {
            int bit = bits[j];
            int v = cur ^ (1 << bit) ^ 1;
            add.push_back({cur,v});
            ban.insert(get_id(v));
            cur = v ^ 3;
        }
        add.push_back({cur,b ^ 3});
    }
    for (int i = 0;i < 1 << n;i+=4)
    {
        if (!ban.contains(i)) cout << i << " " << i + 3 << endl;
        if (!ban.contains(i + 1)) cout << i + 1 << " " << i + 2 << endl;
    }
    for (auto& [x,y] : add) cout << x << " " << y << endl;
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