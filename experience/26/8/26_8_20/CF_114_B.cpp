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
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    map<pair<string,string>,int> p;
    for (int i = 0;i < m;i++) 
    {
        string s,t;
        cin >> s >> t;
        p[{s,t}] = 1;
        p[{t,s}] = 1;
    }
    vector<string> ans;
    for (int mask = 0;mask < 1 << n;mask++)
    {
        vector<string> tmp;
        for (int i = 0;i < n;i++)
        {
            if (mask >> i & 1) 
            {
                tmp.push_back(a[i]);
            }
        }
        int f = 1;
        for (int i = 0;i < tmp.size();i++)
        {
            for (int j = i + 1;j < tmp.size();j++)
            {
                if (p.count({tmp[i],tmp[j]})) f = 0;
            }
        }
        if (f) 
        {
            if (tmp.size() > ans.size()) ans = tmp;
        }
    }
    cout << ans.size() << endl;
    ranges::sort(ans);
    for (string& s : ans)
    {
        cout << s << endl;
    }
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