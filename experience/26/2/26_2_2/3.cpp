#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt d(n);
    vpii a(n);
    int mx = 0,h = 0,sum = 0,mxi = 0;
    for (int i = 0;i < n;i++) 
    {
        cin >> d[i];
    }
    for (int i = 0;i < n;i++) 
    {
        sum += abs(d[i]);
        cin >> a[i].fi >> a[i].se;
        if (mx > a[i].se) 
        {
            cout << -1 << endl;
            return ;
        }
        if (a[i].fi > mx) 
        {
            mxi = i;
            mx = a[i].fi;
        }
        if (sum < mx) 
        {
            cout << -1 << endl;
            return ;
        }
    }
    h = mx;
    for (int i = mxi;i >= 0;i--)
    {
        if (d[i] == -1 && h) 
        {
            d[i] = 1;
            h--;
        }
        else if (d[i] == -1 && h == 0) d[i] = 0;
    }
    for (int i = mxi + 1;i < n;i++) 
    {
        if (d[i] == -1) d[i] = 0;
    }
    for (int x : d) cout << x << " ";
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