#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;

// struct custom_hash
// {
//     static uint64_t splitmix64(uint64_t x) 
//     {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
//     static uint64_t fixed_random()
//     {
//         static const uint64_t seed = chrono::steady_clock::now().time_since_epoch().count();
//         return seed;
//     }
//     size_t operator() (uint64_t x) const
//     {
//         return splitmix64(x + fixed_random());
//     }
// };
void solve()
{
    int n;
    cin >> n;
    vt a(n);
    vt vis(n + 2);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
        if (a[i] <= n) vis[a[i]] = 1;
    }
    int mex = 0;
    while (vis[mex]) mex++;
    sort(a.begin(),a.end());
    vt tmp,tmp2;
    for (int i = 0;i < n;i++) 
    {
        tmp.push_back(a[i]);
        tmp2.push_back(a[i]);
        tmp2.push_back(a[i] + mex);
    }
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    sort(tmp2.begin(),tmp2.end());
    tmp2.erase(unique(tmp2.begin(),tmp2.end()),tmp2.end());
    int m1 = tmp.size(),m2 = tmp2.size();
    vt cnt(m1 + 10),p(m2 + 10,-1);

    for (int x : a) 
    {
        auto it = lower_bound(tmp.begin(),tmp.end(),x) - tmp.begin();
        cnt[it]++;
    }
    for (int i = 0; i < mex;i++)
    {
        auto it = lower_bound(tmp.begin(),tmp.end(),i) - tmp.begin();
        cnt[it]--;
    }
    for (int i = 0;i < n;i++)
    {
        int k = a[i] + mex;
        auto it1 = lower_bound(tmp2.begin(),tmp2.end(),k) - tmp2.begin();
        if (p[it1] != -1) continue;
        int nmex = mex;
        vt vis(m1);
        while (1)
        {
            auto id1 = lower_bound(tmp.begin(),tmp.end(),nmex) - tmp.begin();
            auto id2 = lower_bound(tmp.begin(),tmp.end(),k - nmex) - tmp.begin();
            if (!((id1 < m1 && tmp[id1] == nmex) || (id2 < m1 && tmp[id2] == k - nmex))) break;
            if ((id1 < m1 && tmp[id1] == nmex && cnt[id1] > 1) || ((id2 < m1 && tmp[id2] == k - nmex) && cnt[id2] > 1)) 
            {
                nmex++;
                continue;
            }
            if (id1 < m1 && tmp[id1] == nmex && cnt[id1])
            {
                cnt[id1]--;
                vis[id1] = 1;
            }
            else if (id2 < m1 && tmp[id2] == k - nmex && cnt[id2]) 
            {
                cnt[id2]--;
                vis[id2] = 1;
            }
            else break;
            nmex++;
        }
        // cout << k << " " << nmex << endl;
        p[it1] = nmex;
        for (int i = 0;i < m1;i++) 
        {
            if (vis[i]) cnt[i]++;
        }
    }
    int q;
    cin >> q;
    int ans = 0;
    while (q--)
    {
        int k;
        cin >> k;
        auto it = lower_bound(tmp2.begin(),tmp2.end(),k) - tmp2.begin();
        int res = mex;
        if (it < m2 && tmp2[it] == k && p[it] != -1) res = max(res,p[it]);
        ans ^= res; 
        // cout << res << endl;
    }
    cout << ans << '\n';
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();

}