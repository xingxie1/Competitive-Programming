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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
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
    string s,t;
    cin >> s >> t;
    string ss = s,tt = t;
    ranges::sort(ss);
    ranges::sort(tt);
    if (ss != tt) 
    {
        cout << -1 << endl;
        return ;
    }
    vt ans;
    for (int i = n - 1;i >= 0;i--)
    {
        if (s[i] == t[i]) continue;
        char tmp = t[i];
        int in;
        for (int j = i;j >= 0;j--)
        {
            if (s[j] == t[i]) 
            {
                in = j;
                break;
            }
        }
        for (int j = in;j < i;j++)
        {
            s[j] = s[j + 1];
            ans.push_back(j + 1);
        }
        s[i] = t[i];
    }
    cout << ans.size() << endl;
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