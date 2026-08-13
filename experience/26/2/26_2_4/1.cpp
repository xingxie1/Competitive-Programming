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
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector a(n,vector<ll>(m));
    vll r(n),c(m);
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++) 
        {
            cin >> a[i][j];
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    }
    int i = 0,j = 0;
    for (char ch : s)
    {
        if (ch == 'R')
        {
            a[i][j] = -c[j];
            r[i] += a[i][j];
            j++;
        }
        else 
        {
            a[i][j] = -r[i];
            c[j] += a[i][j];
            i++;
        }
    }
    a[i][j] = -r[i];
    for (int i = 0;i < n;i++)
    {
        for (ll x : a[i]) cout << x << " ";
        cout << endl;
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