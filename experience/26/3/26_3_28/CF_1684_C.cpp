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
    int n,m;
    cin >> n >> m;
    vvt a(n,vt(m));
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++) cin >> a[i][j];
    }
    int c1 = -1,c2 = -1,find = 0;
    for (int i = 0;i < n;i++)
    {
        vt tmp = a[i];
        ranges::sort(tmp);
        int cnt = 0;
        if (!find) c1 = c2 = -1;
        for (int j = 0;j < m;j++)
        {
            if (tmp[j] != a[i][j]) 
            {
                cnt++;
                if (cnt == 1 && !find) c1 = j;
                else if (cnt == 2 && !find) c2 = j;
            }
        }
        if (cnt > 2) 
        {
            cout << -1 << endl;
            return ;
        }
        if (cnt == 2) 
        {
            find = 1;
        }
    }
    // cout << c1 << " " << c2 << endl;
    if (!find) 
    {
        cout << 1 << " " << 1 << endl;
        return ;
    }
    for (int i = 0;i < n;i++)
    {
        swap(a[i][c1],a[i][c2]);
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 1;j < m;j++)
        {
            if (a[i][j] < a[i][j - 1])
            {
                cout << -1 << endl;
                return ;
            }
        }
    }
    cout << c1 + 1 << " " << c2 + 1 << endl;
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