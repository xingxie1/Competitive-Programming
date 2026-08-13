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


class Unionfind
{
    vector<int> fa; 
public:
    int cc;
    Unionfind (int n) 
    {
        fa.resize(n);
        ranges::iota(fa,0);
        cc = n;
    }
    int find(int x)
    {
        if (x != fa[x]) fa[x] = find(fa[x]);
        return fa[x];
    }
    bool merge(int from,int to)
    {
        int x = find(from),y = find(to);
        if (x == y)
        {
            return false;
        }
        fa[x] = y;
        cc--;
        return true;
    }
};
void solve()
{
    int n;
    cin >> n;
    vt a(n);
    Unionfind uf(n);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0;i < n;i++)
    {
        uf.merge(i,a[i]);
    }
    string s;
    cin >> s;
    map<int,int> sum;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '0')
        {
            int x = uf.find(i);
            sum[x]++;
        }
    }
    for (int i = 0;i < n;i++)
    {
        int x = uf.find(i);
        cout << sum[x] << " ";
    }
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