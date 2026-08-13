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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    auto lm = [](string& t)
    {
        reverse(t.begin() + 1,t.end());
        reverse(t.begin(),t.end());
    };
    for (int k = 1;k <= n;k++)
    {
        int cnt = 0;
        for (int i = 0;i < n;i++)
        {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            i = j - 1;
            cnt++;
        }
        lm(s);
        ans = max(ans,cnt);
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