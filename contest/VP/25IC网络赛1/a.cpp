#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vvt = vector<vt>;
using pii = pair<int,int>;
using vll = vector<ll>;
using vpii = vector<pii>;

struct node
{
    string s;
    char c;
    int t;
    string m;
};

void solve()
{
    int n;
    cin >> n;
    map<string,pii> p;
    map<pair<string,char>,int> vis,cnt;
    map<string,int> unc,unt;
    vector<node> a(n);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i].s >> a[i].c >> a[i].t >> a[i].m;
    }
    ranges::sort(a,{},[&](auto& b) {
        return b.t;
    });
    for (int i = 0;i < n;i++)
    {
        string s = a[i].s;
        char c = a[i].c;
        int t = a[i].t;
        string m = a[i].m;
        // cout << s << " " << c << " " << t << " " << m << endl;
        if (m == "Accepted")
        {
            if (!vis.count({s,c})) 
            {
                p[s].fi++;
                p[s].se += cnt[{s,c}] * 20 + t;
                vis[{s,c}] = 1;
            }
        }
        else if (m == "Rejected")
        {
            cnt[{s,c}]++;
        }
        else if (m == "Unknown" && !vis.count({s,c}))
        {
            vis[{s,c}] = 1;
            unc[s]++;
            unt[s] += t + cnt[{s,c}] * 20;
            // cout << s << " " << c << endl;
        }
    }
    for (int i = 0;i < n;i++) 
    {
        string s = a[i].s;
        if (!p.count(s)) p[s] = {0,0};
    }
    int mxc = 0,mnt = INT_MAX / 2;
    for (auto&[s,pp] : p)
    {
        auto [c,t] = pp;
        if (c > mxc) 
        {
            mxc = c;
            mnt = t;
        }
        else if (c == mxc)
        {
            if (t < mnt)
            {
                mnt = t;
            }
        }
    }
    vector<string> ans;
    // cout << mxc << " " << mnt << endl;
    for (auto& [s,pp] : p)
    {
        auto [c,t] = pp;
        // cout << s << " " << unc[s] << " " << unt[s] << endl;
        if (c == mxc && t == mnt) 
        {
            ans.push_back(s);
            continue;
        }
        if (c + unc[s] > mxc) ans.push_back(s);
        else if (c + unc[s] == mxc && t + unt[s] <= mnt) ans.push_back(s);
    }
    ranges::sort(ans);
    for (auto& s : ans) cout << s << " ";
    cout << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();
}