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
    int n,m;
    cin >> n >> m;
    vt cnt(m + 1);
    for (int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int flag = 1,flag2 = 1;
    for (int i = 1;i <= m;i++) 
    {
        if (cnt[i] > 1) flag = 0;
        if (!cnt[i]) flag2 = 0;
    }
    if (flag) YES;
    else NO;
    if (flag2) YES;
    else NO;

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