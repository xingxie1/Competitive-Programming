#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    string s;
    cin >> s;
    int ans = INT_MAX;
    int n = s.size();
    for (char c = 'a';c <= 'z';c++)
    {
        int cnt = 0,mx = 0;
        for (int i = 0;i < n;i++)
        {
            int j = i;
            if (s[i] == c) continue;
            while (j < n && s[j] != c) j++;
            mx = max(mx,j - i);
            i = j - 1;
        }
        if (mx == 0)
        {
            cout << 0 << endl;
            return ;
        }
        ans = min(ans,bit_width(1u * mx));
    }
    cout << ans << endl;
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