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
    int n;
    cin >> n;
    vt x(n);
    for (int i = 0;i < n;i++) cin >> x[i];
    int ans = x[n - 1] - x[0];
    priority_queue<int> pq;
    for (int i = 0;i < n - 1;i++) 
    {
        pq.push(x[i + 1] - x[i]);
    }
    cout << ans << " ";
    for (int i = 0;i < n - 1;i++)
    {
        ans -= pq.top();
        pq.pop();
        cout << ans << " ";
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