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
    int n,k;
    cin >> n >> k;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    if (k >= 3)
    {
        cout << 0 << endl;
        return ;
    }
    else if (k == 1) 
    {
        ll mn = LLONG_MAX;
        for (int i = 0;i < n;i++)
        {
            mn = min(mn,a[i]);
            for (int j = 0;j < i;j++) mn = min(mn,llabs(a[i] - a[j]));
        }
        cout << mn << endl;
    }
    else 
    {
        ll mn = LLONG_MAX;
        sort(a.begin(),a.end());
        for (int i = 1;i < n;i++)
        {
            if (a[i] == a[i - 1]) 
            {
                cout << 0 << endl;
                return ;
            }
        }
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < i;j++) 
            {
                ll x = llabs(a[i] - a[j]);
                mn = min(mn,x);
                auto it = ranges::lower_bound(a,x) - a.begin();
                if (it != n) mn = min(mn,llabs(a[it] - x));
                it--;
                if (it != -1) mn = min(mn,llabs(a[it] - x)); 
            }
        }
        cout << mn << endl;
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