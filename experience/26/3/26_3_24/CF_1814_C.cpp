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
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,s1,s2;
    cin >> n >> s1 >> s2;
    vt a,b;
    vpii r(n);
    for (int i = 0;i < n;i++) 
    {
        cin >> r[i].fi;
        r[i].se = i + 1;
    }
    ranges::sort(r,{},[&](auto& a){
        return -a.fi;
    });
    ll c1 = 1,c2 = 1;
    for (auto&[x,i] : r)
    {
        if (c1 * s1 < c2 * s2)
        {
            a.push_back(i);
            c1++;
        }
        else 
        {
            b.push_back(i);
            c2++;
        }
    }
    cout << a.size() << " ";
    for (int x : a) cout << x << " ";
    cout << endl << b.size() << " ";
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