#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,k;
    cin >> n >> k;
    vt a(n);
    vt pre(n + 1);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    double ans = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = i + k - 1;j < n;j++)
        {
            int cnt = j - i + 1;
            double ave = 1.0 * (pre[j + 1] - pre[i]) / cnt;
            ans = max(ans,ave);
        }
    }
    printf("%.10lf\n",ans);
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