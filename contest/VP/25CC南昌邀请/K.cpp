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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int& x : a) x %= 4;
    vvt p(4,vt());
    int c1 = 0,c2 = 0,c3 = 0;
    for (int i = 0;i < n;i++)
    {
        p[a[i]].push_back(i + 1);
        c1 += a[i] == 1;
        c2 += a[i] == 2;
        c3 += a[i] == 3;
    }
    vt ans;
    while (!p[0].empty())
    {
        ans.push_back(p[0].back());
        p[0].pop_back();
    }
    if (c3 <= c1)
    {
        while (!p[3].empty())
        {
            ans.push_back(p[3].back());
            ans.push_back(p[1].back());
            p[1].pop_back();
            p[3].pop_back();
        }
        c1 -= c3;
        c3 = 0;
    }
    else 
    {
        c3 -= c1;
        while (c1--)
        {
            ans.push_back(p[3].back());
            ans.push_back(p[1].back());
            p[1].pop_back();
            p[3].pop_back();
        }
    }
    if (c2 * 2 <= c1)
    {
        while (!p[2].empty())
        {
            ans.push_back(p[2].back());
            ans.push_back(p[1].back());
            p[1].pop_back();
            p[2].pop_back();
            ans.push_back(p[1].back());
            p[1].pop_back();
        }
        c1 -= 2 * c2;
        c2 = 0;
    }
    else 
    {
        int k = c1 / 2;
        int res = c1 % 2;
        c2 -= k;
        c1 = res;
        while (k--)
        {
            ans.push_back(p[2].back());
            ans.push_back(p[1].back());
            p[1].pop_back();
            p[2].pop_back();
            ans.push_back(p[1].back());
            p[1].pop_back();
        }
    }
    
    if (c1 > 0) 
    {
        cout << -1 << endl;
        return ;
    }

    if (c2 * 2 >= c3)
    {
        int k = c3 / 2;
        int res = c3 % 2;
        c3 = res;
        c2 -= k;
        if (res == 0) 
        {
            while (k--)
            {
                ans.push_back(p[3].back());
                p[3].pop_back();
                ans.push_back(p[3].back());
                ans.push_back(p[2].back());
                p[3].pop_back();
                p[2].pop_back();
            }
            while (c2--) 
            {
                ans.push_back(p[2].back());
                p[2].pop_back();
            }
        }
        else 
        {
            if (c2 % 2)
            {
                cout << -1 << endl;
                return ;
            }
            while (k--)
            {
                ans.push_back(p[3].back());
                p[3].pop_back();
                ans.push_back(p[3].back());
                ans.push_back(p[2].back());
                p[3].pop_back();
                p[2].pop_back();
            }
            while (c2--) 
            {
                ans.push_back(p[2].back());
                p[2].pop_back();
            }
            ans.push_back(p[3].back());
        }
    }
    else 
    {
        if (c3 - c2 >= 3) 
        {
            cout << -1 << endl;
            return ;
        }
        c3 -= c2;
        while (c2--)
        {
            ans.push_back(p[3].back());
            p[3].pop_back();
            ans.push_back(p[3].back());
            ans.push_back(p[2].back());
            p[3].pop_back();
            p[2].pop_back();
        }
        while (c3--) 
        {
            ans.push_back(p[3].back());
            p[3].pop_back();
        }
    }
    for (int x : ans) cout << x << " ";
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