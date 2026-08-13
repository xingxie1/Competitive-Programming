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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    map<int,int> dp;
    int mx = 0,end = -1;
    for (int x : a)
    {
        dp[x] = dp[x - 1] + 1;
        if (dp[x] > mx)
        {
            mx = dp[x];
            end = x;
        }
    }
    int s = end - mx + 1;
    vt ans;
    for (int i = 0;i < n;i++)
    {
        if (a[i] == s)
        {
            ans.push_back(i + 1);
            s++;
        }
        if (s > end) break;
    }
    cout << mx << endl;
    for (int x : ans) cout << x << " ";
    
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