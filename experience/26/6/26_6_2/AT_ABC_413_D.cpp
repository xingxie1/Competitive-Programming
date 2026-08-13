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
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ranges::sort(a,{},[&](auto& x){return abs(x);});
    int f = 1;
    for (int i = 1;i < n - 1;i++) 
    {
        if (a[i] * a[i] != a[i - 1] * a[i + 1]) f = 0;
    }
    if (f) 
    {
        YES;
        return ;
    }
    int zheng = 0,fu = 0;
    for (ll x : a) 
    {
        if (x > 0) zheng = 1;
        else fu = 1;
    }
    if ((zheng && !fu) || (!zheng && fu))
    {
        NO;
        return ;
    }
    vll b,c;
    for (int x : a) 
    {
        if (x > 0) b.push_back(x);
        else c.push_back(x);
    }
    int m1 = b.size(),m2 = c.size();
    if (abs(m1 - m2) > 1) 
    {
        NO;
        return ;
    }
    if (m1 == m2)
    {
        vll tmp1,tmp2;
        int i = 0;
        while (i < m1) 
        {
            tmp1.push_back(b[i]);
            tmp1.push_back(c[i]);
            tmp2.push_back(c[i]);
            tmp2.push_back(b[i]);
            i++;
        }
        int f1 = 1,f2 = 1;
        for (int i = 1;i < n - 1;i++)
        {
            if (tmp1[i] * tmp1[i] != tmp1[i - 1] * tmp1[i + 1]) f1 = 0;
            if (tmp2[i] * tmp2[i] != tmp2[i - 1] * tmp2[i + 1]) f2 = 0;
        }
        if (f1 || f2) YES;
        else NO;
    }
    else if (m1 > m2) 
    {
        vll tmp;
        int i = 0;
        tmp.push_back(b[0]);
        while (i < m2) 
        {
            tmp.push_back(c[i]);
            i++;
            tmp.push_back(b[i]);
        }
        int f = 1;
        for (int i = 1;i < n - 1;i++)
        {
            if (tmp[i] * tmp[i] != tmp[i - 1] * tmp[i + 1]) f = 0;
        }
        if (f) YES;
        else NO;
    }
    else 
    {
        vll tmp;
        int i = 0;
        tmp.push_back(c[0]);
        while (i < m1) 
        {
            tmp.push_back(b[i]);
            i++;
            tmp.push_back(c[i]);
        }
        int f = 1;
        for (int i = 1;i < n - 1;i++)
        {
            if (tmp[i] * tmp[i] != tmp[i - 1] * tmp[i + 1]) f = 0;
        }
        if (f) YES;
        else NO;
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