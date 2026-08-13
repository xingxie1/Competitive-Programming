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
    int n,a,b;
    cin >> n >> a >> b;
    vt ans(n);
    if (abs(a - b) > 1 || a > (n - 1) / 2 || b > (n - 1) / 2)
    {
        cout << -1 << endl;
        return ;
    }
    if (a == b && a == n / 2) 
    {
        cout << -1 << endl;
        return ;
    }
    if (a > b) 
    {
        int x = n;
        for (int i = 1;i < n;i+=2) 
        {
            if (a == 0) break;
            ans[i] = x--;
            a--;
        }
        for (int& y : ans) 
        {
            if (y == 0) y = x--;
        }
    }
    else if (a < b)
    {
        int x = 1;
        for (int i = 1;i < n;i += 2) 
        {
            if (b == 0) break;
            ans[i] = x++;
            b--;
        }
        x = n;
        for (int i = n - 1;i >= 0;i--) 
        {
            if (ans[i] == 0) ans[i] = x--;
        }
    }
    else 
    {
        int x = 2;
        ans[0] = 1;
        for (int i = 2;i < n;i += 2) 
        {
            if (a == 0) break;
            ans[i] = x++;
            a--;
        }
        for (int& y : ans) 
        {
            if (y == 0) y = x++;
        }
    }
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