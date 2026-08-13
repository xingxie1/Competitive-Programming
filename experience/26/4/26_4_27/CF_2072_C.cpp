#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,x;
    cin >> n >> x;
    vt a;
    for (int i = 0;i < n;i++)
    {
        int f = 1;
        for (int j = 0;j < 30;j++)
        {
            if (!(x >> j & 1) && (i >> j & 1)) 
            {
                f = 0;
                break;
            }
        }
        if (f && a.size() < n) a.push_back(i);
        else break;
    }
    while (a.size() < n - 1) a.push_back(0);
    if (a.size() == n)
    {
        int s = 0;
        for (int y : a) s |= y;
        if (s != x) a[n - 1] = x;
    }
    else a.push_back(x);
    for (int x : a ) cout << x << " ";
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