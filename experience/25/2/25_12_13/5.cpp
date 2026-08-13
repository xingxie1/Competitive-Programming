#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    set<int> s(a.begin(),a.end());
    int flag;
    if (a.back() > n) 
    {
        flag = 0;
    }
    else 
    {   
        vt vis(a.back() + 1);
        for (int i = 0;i < n;i++) vis[a[i]]++;
        flag = 1;
        for (int i = 1;i <= a.back();i++) 
        {
            if (!vis[i]) flag = 0;
        }
    }

    if (flag == 1) cout <<  "MingshenMingshen" << endl;
    else 
    {
        cout << "MingbianMingbian" << endl;
        int j = 1;
        ll ans = 0;
        for (int i = 0;i < n;i++)
        {
            if (a[i] > j) ans += a[i] - j;
            else 
            {
                while (i + 1 < n && a[i + 1] == a[i]) i++;
            }
            j++;
        }
        cout << ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}