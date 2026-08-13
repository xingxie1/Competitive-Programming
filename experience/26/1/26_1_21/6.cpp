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
    ll ans = 0;    
    ll need = 0;

    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        ll f = j - i;
        ll x = a[i];

        if (i == 0 || x != a[i - 1] + 1) 
        {
            ans += f;
            need = f;
        } 
        else 
        {
            if (f >= need) 
            {
                ans += f - need;
                need = f;
            } 
            else need = f;
        }
        i = j;
    }
    cout << ans << endl;
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