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

int mex(vt& a)
{
    int n = a.size();
    sort(a.begin(),a.end());
    int ret = 0;
    for (int i = 0;i < n;i++)
    {
        if (ret < a[i]) return ret;
        else ret++;
    }
    return ret;
}
void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) a[i] = i;
    int mx = 0,ans = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            vector<int> tmp(a.begin() + j,a.end());
            int x = mex(tmp);
            if (x > mx)
            {
                ans = 1;
            }
            else if (x == mx) ans++;
        }
    }
    cout << n << " : " << ans << endl;
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