#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n,k,mxb = 0;
    cin >> n >> k;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) 
    {
        cin >> b[i];
        mxb = max(mxb,b[i]);
    }
    vector<vector<int>> g(n + 1,vector<int>(2));
    int mx = INT_MIN / 2;

    if (k & 1)
    {   
        int flag = 0;
        for (int i = 0;i < n;i++)
        {
            if (a[i] < 0)
            {
                g[i + 1][0] = max(max(g[i][0],0), max(g[i][1]+ b[i],0)) + a[i];
                g[i + 1][1] = max(g[i][1],0) + a[i];
                flag = 1;
            }
            else 
            {
                g[i + 1][1] = max(g[i][1],0) + a[i];
                g[i + 1][0] = max(g[i][0],0) + a[i];
            }
            mx = max(mx,g[i + 1][0]);
            mx = max(mx,g[i + 1][1]);
        }
        if (flag == 0) mx += mxb;
    }
    else 
    {
        int flag = 0;
        for (int i = 0;i < n;i++)
        {
            if (a[i] > 0)
            {
                g[i + 1][0] = max(max(g[i][0],0), max(g[i][1] - b[i],0)) + a[i];
                g[i + 1][1] = max(g[i][1],0) + a[i];
                flag = 1;
            }
            else 
            {
                g[i + 1][1] = max(g[i][1],0) + a[i];
                g[i + 1][0] = max(g[i][0],0) + a[i];
            }
            mx = max(mx,g[i + 1][0]);
            mx = max(mx,g[i + 1][1]);
        }
        if (flag == 0) mx -= mxb;
    }

    
    cout << mx << endl;
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