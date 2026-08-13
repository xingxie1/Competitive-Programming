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
    vt b(n),p(n),dist(n);
    for (int i = 0;i < n;i++) 
    {
        cin >> b[i];
        b[i]--;
    }
    for (int i = 0;i < n;i++) 
    {
        cin >> p[i];
        p[i]--;
        dist[p[i]] = i;
    }
    vt w(n);
    for (int i = 0;i < n;i++) 
    {
        w[i] = dist[i] - dist[b[i]];
    }
    for (int x : w) 
    {
        if (x < 0) 
        {
            cout << -1 << endl;
            return ;
        }
    }
    for (int x : w) cout << x << " ";
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