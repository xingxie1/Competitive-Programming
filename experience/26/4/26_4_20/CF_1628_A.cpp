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
    vt a(n),b;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
    }
    int mex = 0;
    vt suf(n),vis(n + 2);
    for (int i = n - 1;i >= 0;i--)
    {
        vis[a[i]] = 1;
        while (vis[mex]) mex++;
        suf[i] = mex;
    }
    int i = 0;
    vt seen(n + 1);
    while (i < n)
    {
        int t = suf[i];
        b.push_back(t);
        if (t == 0) 
        {
            i++;
            continue;
        }
        int j = i,cnt = 0;
        while (j < n && cnt < t)
        {
            if(!seen[a[j]] && a[j] < t) 
            {
                seen[a[j]] = 1;
                cnt++;
            }
            j++;
        }
        for (int k = i;k < j;k++) seen[a[k]] = 0;
        i = j;
    }
    cout << b.size() << endl;
    for (int x : b) cout << x << " ";
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