// https://codeforces.com/problemset/problem/1547/C
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
    int k,n,m;
    cin >> k >> n >> m;
    vt a(n),b(m);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < m;i++) cin >> b[i];
    vector<int> ans;
    int l = 0,r = 0,cnt = 0;
    while (l < n && r < m)
    {
        if (a[l] == 0) 
        {
            ans.push_back(a[l]);
            l++;
            cnt++;
        }
        else if (b[r] == 0)
        {
            ans.push_back(b[r]);
            r++;
            cnt++;
        }
        else if (a[l] <= k + cnt) 
        {
            ans.push_back(a[l]);
            l++;
        }
        else if (b[r] <= cnt + k)
        {
            ans.push_back(b[r]);
            r++;
        }
        else 
        {
            cout << -1 <<endl;
            return ;
        }
    }
    while (l < n)
    {
        if (a[l] == 0)
        {
            ans.push_back(0);
            cnt++;
        }
        else 
        {
            if (a[l] <= cnt + k) ans.push_back(a[l]);
            else 
            {
                cout << -1 << endl;
                return ;
            }
        }
        l++;
    }
    while (r < m)
    {
        if (b[r] == 0)
        {
            ans.push_back(0);
            cnt++;
        }
        else 
        {
            if (b[r] <= cnt + k) ans.push_back(b[r]);
            else 
            {
                cout << -1 << endl;
                return ;
            }
        }
        r++;
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