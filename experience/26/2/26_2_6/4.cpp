#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vll a(n);
    vector<pair<ll,ll>> b;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        ll x = a[i];
        int cnt = 0;
        while (x % 3 == 0) 
        {
            x /= 3;
            cnt++;
        }
        b.push_back({cnt,a[i]});
    }
    sort(b.begin(),b.end(),[](auto& f,auto& g){
        if (f.fi == g.fi) return f.se < g.se;
        return f.fi > g.fi;
    });
    for (auto& [x,y] : b) cout << y << " ";
    cout << endl;
    
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