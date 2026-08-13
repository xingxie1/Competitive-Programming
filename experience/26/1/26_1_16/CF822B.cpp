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
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    int ans = INT_MAX;
    vt a;
    for (int i = 0;i <= m - n;i++)
    {
        int cnt = 0;
        vt tmp;
        for (int j = 0;j < n;j++)
        {
            if (s[j] == '?' || s[j] == t[i + j]) {}
            else 
            {
                cnt++;
                tmp.push_back(j + 1);
            }
        }
        if (cnt < ans)
        {
            ans = cnt;
            a = tmp;
        }
    }
    cout << ans << endl;
    for (int x : a) cout << x << " ";
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