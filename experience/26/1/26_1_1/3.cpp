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
    int n,x;
    cin >> n >> x;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    int cnt0 = 0,cnt1 = 0;
    for (int y : a)
    {
        if (y <= x - 1) cnt0++;
        else if (y >= x + 1) cnt1++;
    }
    if (cnt0 > cnt1) cout << x - 1 << endl;
    else cout << x + 1 << endl;
    
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