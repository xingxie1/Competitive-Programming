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
    string s;
    cin >> s;
    int n = s.size();
    map<char,vt> p;
    for (int i = 0;i < n;i++)
    {
        p[s[i]].push_back(i);
    }
    for (auto& [c,g] : p)
    {
        ranges::reverse(g);
    }
    int ans = 0;
    for (int i = 0;i < n;i++)
    {   
        if (s[i] == 'B')
        {
            while (!p['C'].empty() && p['C'].back() < i) p['C'].pop_back();
            if (!p['A'].empty() && p['A'].back() < i && !p['C'].empty()) 
            {
                ans++;
                p['A'].pop_back();
                p['C'].pop_back();
            }
        }
    }
    cout << ans << endl;
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