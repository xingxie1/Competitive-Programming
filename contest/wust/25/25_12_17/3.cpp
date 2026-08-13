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
    int n,q;
    cin >> n >> q;
    string a,b;
    cin >> a >> b;
    vector<vector<int>> cnt1(n + 1,vector<int>(26)),cnt2(n + 1,vector<int>(26));
    for (int i = 0;i < n;i++)
    {
        cnt1[i + 1] = cnt1[i];
        cnt1[i + 1][a[i] - 'a']++;
        cnt2[i + 1] = cnt2[i];
        cnt2[i + 1][b[i] - 'a']++;
    }

    while (q--)
    {
        int l,r;
        cin >> l >> r;
        ll cnta = 0,cntb = 0,ans = 0;
        for (int j = 0;j < 26;j++)
        {
            cnta = cnt1[r][j] - cnt1[l - 1][j];
            cntb = cnt2[r][j] - cnt2[l - 1][j];
            ans += abs(cnta - cntb);
        }
        cout << ans / 2<< endl;
    }
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