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
    int n;
    cin >> n;
    vector<pair<int,int>> ans;
    map<int,vector<pair<int,char>>> a;
    for (int i = 0;i < n;i++)
    {
        int x;
        char c;
        cin >> x >> c;
        int flag = 1;
        if (a.count(x))
        {
            for (auto [x1,c1] : a[x])
            {
                if (c == c1) flag = 0;
            }
        }
        if (flag)
            a[x].push_back({i + 1,c});
    }
    // for (auto it = a.begin();it != a.end();it++)
    // {
    //     int x = it->fi;
    //     cout << x << " :";
    //     for (auto [a,b] : a[x]) cout << a << " " << b << " ";
    //     cout << endl;
    // }
    for (auto it = a.begin();it != a.end();it++)
    {
        int x = it->fi;
        while (a[x].size() >= 2)
        {
            int aa = a[x].back().fi;
            a[x].pop_back();
            int bb = a[x].back().fi;
            a[x].pop_back();
            ans.push_back({aa,bb});
        }
    }
    cout << ans.size() * 2 << endl;
    for (auto [a,b] : ans) cout << a << " " << b << endl;
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