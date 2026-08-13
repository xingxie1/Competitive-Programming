#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
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
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt cnt(n + 1);
    for (int x : a) cnt[x]++;
    int f = 0;
    for (int i = 1;i <= n;i++) 
    {
        if (cnt[i] >= 3) 
        {
            cout << -1 << endl;
            return ;
        }
    }
    vt b(n),c(n);
    set<int> st1,st2;
    for (int i = 1;i <= n;i++) 
    {
        st1.insert(i);
        st2.insert(i);
    }
    vt vis(n + 1);
    for (int i = 0;i < n;i++)
    {
        if (cnt[a[i]] == 2) 
        {
            if (vis[a[i]]) 
            {
                c[i] = a[i];
                st2.erase(a[i]);
            }
            else 
            {
                b[i] = a[i];
                st1.erase(a[i]);
                vis[a[i]] = 1;
            }
        } 
    }
    for (int i = 0;i < n;i++) 
    {
        if (cnt[a[i]] == 1) 
        {
            if (st1.contains(a[i])) 
            {
                b[i] = a[i];
                st1.erase(a[i]);
            }
            if (st2.contains(a[i]))
            {
                c[i] = a[i];
                st2.erase(a[i]);
            }
        }
    }
    for (int i = 0;i < n;i++)
    {
        if (cnt[a[i]] == 2) 
        {
            if (!b[i])
            {
                b[i] = *st1.begin();
                st1.erase(st1.begin());
            } 
            if (!c[i])
            {
                c[i] = *st2.begin();
                st2.erase(st2.begin());
            } 
        } 
    }
    int c0 = 0,c1 = 0;
    for (int i = 0;i < n;i++) 
    {
        if (a[i] == b[i]) c0++;
        if (a[i] == c[i]) c1++;
        if (a[i] != b[i] && a[i] != c[i]) 
        {
            cout << -1 << endl;
            return ;
        }
    }
    if (c0 < n / 2 || c1 < n / 2) 
    {
        cout << -1 << endl;
        return ;
    }
    for (int x : b) cout << x << " ";
    cout << endl;
    for (int x : c) cout << x << " ";

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