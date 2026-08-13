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
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvt cnt(m,vt(2));
    for (int j = 0;j < m;j++)
    {
        for (int i = 0;i < n;i++)
        {
            if (a[i][j] == '0') cnt[j][0]++;
            else cnt[j][1]++;
        }
    }
    vt ans(n);
    for (int i = 0;i < n;i++)
    {
        vll d(m);
        ll sum = 0,s = 0,mn = INT_MAX;
        for (int j = 0;j < m;j++)
        {
            int c0 = cnt[j][0];
            int c1 = cnt[j][1];
            if (a[i][j] == '1') 
            {
                sum += c0;
                d[j] = c1 - c0 - 1;
            }
            else 
            {
                sum += c1;
                d[j] = c0 - c1 - 1;
                s = min(s,0LL) + d[j];
            }
            mn = min(mn,s);
        }
        ans[i] = sum + min(mn,0LL);
    }
    for (int x : ans) cout << x << endl;
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