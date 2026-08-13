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
    vt a(n + 1);
    if (n == 6)
    {
        cout << "1 4 6 2 5 3" << endl;
        return ;
    }
    a[1] = 1;
    vt vis(n + 1);
    vt b;
    for (int j = 2;j <= n;j *= 2)
    {
        vis[j] = 1;
        b.push_back(j);
    }
    for (int j = 0;j < b.size() - 1;j++) 
    {
        a[b[j]] = b[j + 1];
    }
    a[b.back()] = b[0];
    b.clear();
    for (int i = 3;i <= n;i++)
    {
        if (vis[i]) continue;
        vt b;
        for (int j = i;j <= n;j += i)
        {
            if (vis[j]) continue;
            vis[j] = 1;
            b.push_back(j);
        }
        if (b.size() == 1) 
        {
            a[b[0]] = b[0];
            continue;
        }
        for (int j = 0;j + 1 < b.size();j++)
        {
            a[b[j]] = b[j + 1];
        }
        a[b.back()] = b[0];
    }
    for (int i = 1;i <= n;i++) cout << a[i] << " ";
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