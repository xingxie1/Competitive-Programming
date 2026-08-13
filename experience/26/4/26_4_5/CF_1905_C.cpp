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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int f = 1;
    for (int i = 1;i < n;i++)
    {
        if (s[i] < s[i - 1]) f = 0;
    }
    if (f) 
    {
        cout << 0 << endl;
        return ;
    }
    vector<char> suf(n + 1,'a' - 1);
    for (int i = n - 1;i >= 0;i--) suf[i] = max(suf[i + 1],s[i]);
    string st;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == suf[i]) st.push_back(s[i]);
    }
    int ans = st.size();
    int j = 0,cnt = 0;
    while (j < st.size() && st[j] == st[0])
    {
        j++;
        cnt++;
    }
    j = 0;
    ranges::reverse(st);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == suf[i]) 
        {
            s[i] = st[j++];
        }
    }
    for (int i = 1;i < n;i++)
    {
        if (s[i] < s[i - 1]) 
        {
            cout << -1 << endl;
            return ;
        }
    }
    cout << ans - cnt << endl;
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