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
    vt p(n),q(n);
    int pos = -1;
    for (int i = 0;i < n;i++) 
    {
        cin >> p[i];
        if (p[i] == n) pos = i;
    }
    vt p1,p2;
    for (int i = 0;i < n;i++) 
    {
        if (i % 2 == pos % 2) p1.push_back(i);
        else p2.push_back(i);
    }
    ranges::sort(p1,{},[&](int x){return p[x];});
    ranges::sort(p2,{},[&](int x){return -p[x];});
    int x = n;
    for (int i : p1) q[i] = x--;
    x = 1;
    for (int i : p2) q[i] = x ++; 
    for (int x : q) cout << x << " ";
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