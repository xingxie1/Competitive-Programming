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
    int r,g,b;
    cin >> r >> g >> b;
    vector<pii> a = {{r, 'R'}, {g, 'G'}, {b, 'B'}};
    ranges::sort(a,{},[](auto& b){
        return -b.fi;
    });
    int A = a[0].fi;
    int B = a[1].fi;
    int C = a[2].fi;

    A = min(A,B + C + 1);
    int L = A + B + C;
    int odd = (L + 1) / 2,even = L / 2;
    int c1 = odd - A,c2 = C - c1;
    string s1,s2;
    s1.insert(s1.end(),c1,a[2].se);
    s1.insert(s1.end(),A,a[0].se);
    s2.insert(s2.end(),B,a[1].se);
    s2.insert(s2.end(),c2,a[2].se);

    string s;
    for (int i = 0;i < even;i++)
    {
        s += s1[i];
        s += s2[i];
    }
    if (odd > even)
    {
        s += s1.back();
    }
    
    cout << s << endl;
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