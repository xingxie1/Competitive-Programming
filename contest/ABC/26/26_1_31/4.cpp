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
    ll ans = 0,cnt = 0,sum = 0;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0;i < n - 1;i++)
    {
        a[i + 1] = min(a[i + 1],a[i] + 1);
    }
    for (int i = n - 2;i >= 0;i--)
    {
        a[i] = min(a[i],a[i + 1] + 1);
    }
    for (int x : a) cnt += x;
    cout << sum - cnt << endl; 
    
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