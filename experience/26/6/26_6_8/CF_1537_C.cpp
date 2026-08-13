#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    map<int,int> cnt;
    for (int x : a) cnt[x]++;
    vt ans;
    int t = -1;
    for (auto& [x,c] : cnt)
    {
        if (c >= 2)
        {
            t = x;
            break;
        }
    }
    if (t != -1) 
    {
        ans.push_back(t);
        for (auto& [x,c] : cnt)
        {
            if (x < t) continue;
            if (x == t) c -= 2;
            while (c--) 
            {
                ans.push_back(x);
            }
        }
        for (auto& [x,c] : cnt)
        {
            if (x >= t) continue;
            while (c--) 
            {
                ans.push_back(x);
            }
        }
        ans.push_back(t);
        for (int x : ans) cout << x << " ";
        cout << endl;
        return ;
    }
    int t1 = -1,t2 = -1,mn = INT_MAX;
    for (auto it = cnt.begin();it != cnt.end();it++)
    {
        auto nit = it;
        nit++;
        if (nit == cnt.end()) break;
        int x1 = it->fi,x2 = nit->fi;
        if (x2 - x1 < mn) 
        {
            mn = x2 - x1;
            t1 = x1;
            t2 = x2;
        }
    }
    ans.push_back(t1);
    for (auto& [x,c] : cnt)
    {
        if (x < t1) continue;
        if (x == t1 || x == t2) c--;
        while (c--) ans.push_back(x);
    }
    for (auto& [x,c] : cnt)
    {
        if (x >= t1) continue;
        if (x == t1 || x == t2) c--;
        while (c--) ans.push_back(x);
    }
    ans.push_back(t2);
    for (int x : ans) cout << x << " ";
    cout << endl;
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