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
    ll n, m;
    cin >> n >> m;
    vt a;
    if (1LL * n * (n + 1) / 2 < m || m < n)
    {
        cout << -1 << endl;
        return ;
    }
    ll sum = 0,mx = n;
    vt used(n + 1);
    for (int i = 0;i < n;i++)
    {
        if (m - sum - n + i + 1 >= mx)
        {
            sum += mx;
            a.push_back(mx);
            used[mx] = 1;
            mx--;
        }
        else 
        {
            a.push_back(m - sum - n + i + 1);
            used[m - sum - n + i + 1] = 1;
            break;
        }
    }
    for (int i = 1;i <= n;i++)
    {
        if (!used[i]) a.push_back(i);
    }
    cout << a[0] << endl;
    for (int i = 0;i < n - 1;i++) cout << a[i] << " " << a[i + 1] << endl;
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