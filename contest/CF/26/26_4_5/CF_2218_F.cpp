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
    int x,y;
    cin >> x >> y;
    int n = x + y;
    vvt g(n,vt());
    if (x > y || (n % 2 == 0 && y == n)) 
    {
        cout << "NO" << endl;
        return ;
    }
    if (n == 1)
    {
        if (x == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
        return ;
    }
    if (n == 2)
    {
        if (x == 1 && y == 1) 
        {
            cout << "YES" << endl;
            cout << "1 2" << endl;
        }
        else cout << "NO" << endl;
        return ;
    }
    if (x == 0)
    {
        cout << "YES" << endl;
        for (int i = 2;i <= n;i++) 
        {
            cout << 1 << " " << i << endl;
        }
        return ;
    }
    if (x == 1 && n % 2 == 0)
    {
        cout << "YES" << endl;
        for (int i = 2;i <= n;i++) cout << 1 << " " << i << endl;
        return ;
    }
    if (n % 2 == 0) x--;
    else y--;
    cout << "YES" << endl;
    int mx = 0;
    for (int i = 1;;i+=2)
    {
        if (x == 0) break;
        x--;
        y--;
        g[i].push_back(i + 1);
        g[0].push_back(i);
        mx = i + 1; 
    }
    while (y--)
    {
        g[2].push_back(++mx);
    }
    for (int i = 0;i < n;i++)
    {
        for (int x : g[i]) cout << i + 1 << " " << x + 1 << endl;
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