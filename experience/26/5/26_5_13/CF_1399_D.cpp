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
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
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
    string s;
    cin >> s;
    set<int> p0,p1;
    for (int i = 0;i < n;i++) 
    {
        if (s[i] == '0') p0.insert(i);
        else p1.insert(i);
    }
    vt vis(n);
    vvt ans;
    for (int i = 0;i < n;i++) 
    {
        if (vis[i]) continue;
        vis[i] = 1;
        int t = s[i] - '0';
        int pos = i;
        vt tmp = {i};
        while (1)
        {
            if (t == 0) 
            {
                auto it = p1.lower_bound(pos);
                if (it == p1.end()) break;
                int j = *it;
                vis[j] = 1;
                pos = j;
                tmp.push_back(j);
                p1.erase(it);
            }
            else 
            {
                auto it = p0.lower_bound(pos);
                if (it == p0.end()) break;
                int j = *it;
                vis[j] = 1;
                pos = j;
                tmp.push_back(j);
                p0.erase(it);
            }
            t ^= 1;
        }
        ans.push_back(tmp);
    }
    cout << ans.size() << endl;
    vt pos(n);
    for (int i = 0;i < ans.size();i++) 
    {
        for (int x : ans[i]) pos[x] = i + 1;
    }
    for (int x : pos) cout << x << " ";
    cout << endl;
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