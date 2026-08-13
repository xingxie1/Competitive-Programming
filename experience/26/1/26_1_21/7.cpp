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
    ll ans = a.back();
    vt b,c;
    ll s1 = 0,s2 = 0;
    for (int i = 0;i < n - 1;i++)
    {
        if (a[i] % 2) 
        {
            b.push_back(a[i]);
            s1 += a[i];
        }
        else 
        {
            c.push_back(a[i]);
            s2 += a[i];
        }
    }
    if (ans % 2)
    {
        if (!c.empty())
        {
            ans += s2;
            ans--;
            ans += s1;
            ans -= b.size();
            ans++;
        }
    }
    else 
    {
        if (!b.empty())
        {
            ans ++;
            int x = b.back();
            s1 -= x;
            b.pop_back();
            c.push_back(x - 1);
            s2 += x - 1;
            ans += s2;
            ans--;
            ans += s1;
            ans -= b.size();
            ans++;
        }
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