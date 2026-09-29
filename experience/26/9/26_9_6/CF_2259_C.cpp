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
    vt a(n);
    vt p;
    int fi = -1,last = -1;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        if (a[i] == 1) p.push_back(i);
        if (a[i] == -1) 
        {
            if (fi == -1) fi = i;
            last = i;
        }
    }
    if (p.empty() && fi != -1)
    {
        p.push_back(fi);
        p.push_back(last);
    }
    else if (fi != -1)
    {
        if (fi < p[0]) p.insert(p.begin(),fi);
        if (last > p.back()) p.insert(p.end(),last);
    }
    int mxl = -1,mxr = -1;
    if (!p.empty())
    {
        mxl = mxr = p[0];
    }
    for (int i = 1;i < p.size();i++)
    {
        if (p[i] - p[i - 1] > mxr - mxl)
        {
            mxr = p[i];
            mxl = p[i - 1];
        }
    }
    for (int i = 0;i < n;i++)
    {
        if (a[i] != -1) cout << a[i] << " ";
        else 
        {
            if (i == mxl || i == mxr) cout << 1 << " ";
            else cout << 0 << " ";
        }
    }
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