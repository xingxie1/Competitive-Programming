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
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    if (a[0] == a[n - 1])
    {
        cout << -1 << endl;
        return ;
    }
    ll g = 0;
    for (int i = 1;i < n;i++) g = gcd(g,llabs(a[i] - a[0]));
    cout << g << endl;
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