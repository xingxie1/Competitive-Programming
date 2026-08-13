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
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    vector<int> cnt(2);
    for (int i = 0;i < n;i++) 
    {
        a[i].resize(m);
        for (int j = 0;j < m;j++)
        {
            cin >> a[i][j];
            cnt[a[i][j] - '0']++;
        }
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++) 
        {
            if (cnt[a[i][j] - '0'] > 1) cout << "Y";
            else cout << "N";
        }
        cout << "\n";
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