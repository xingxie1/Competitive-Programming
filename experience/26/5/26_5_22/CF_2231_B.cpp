#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define fi first
#define se second
#define umap unordered_map
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
    vt b;
    int mx = 0;
    for (int i = 1;i < n;i++) 
    {
        if (a[i] < a[i - 1]) 
        {
            b.push_back(i);
            mx = max(mx,a[i - 1] - a[i]);
        }
    }
    if (b.empty()) 
    {
        YES;
        return ;
    }
    for (int i = 0;i + 1 < b.size();i++)
    {
        int j1 = b[i],j2 = b[i + 1];
        int f = 0;
        for (int j = j1;j <= j2;j++) 
        {
            if (a[j] - a[j - 1] >= mx) f = 1;
        }
        if (!f) 
        {
            NO;
            return ;
        }
    }
    YES;
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