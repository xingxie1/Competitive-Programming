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
    for (int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    
    auto check = [&](int t)
    {
        int l = 0,r = n - 1;
        while (r >= 0 && a[r] == t) r--;
        while (l < r)
        {
            if (a[l] + a[r] != t)
            {
                return 0;
            }
            l++;
            r--;
        }
        if (l == r) return 0;
        return 1;
    };
    vt ans;
    if (check(a[n - 1])) ans.push_back(a[n - 1]);
    if (check(a[0] + a[n - 1])) ans.push_back(a[0] + a[n - 1]);
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