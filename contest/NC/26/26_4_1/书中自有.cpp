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
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    string s;
    cin >> s;
    ll g = 0,gi = 0,gir = 0,girl = 0;
    ll cnt = 0;
    for (int i = 0;i < s.size();i++)
    {
        char c = s[i];
        if (c == 'g') g++;
        if (c == 'i') gi += g;
        if (c == 'r') gir += gi;
        if (c == 'l') girl += gir;
        g %= MOD;
        gi %= MOD;
        gir %= MOD;
        girl %= MOD;
        if (c == 'g')
        {
            string tmp(s.begin() + i,min(s.begin() + i + 4,s.end()));
            if (tmp == "gold") cnt++;
        }
    }
    if (cnt && girl) 
    {
        cout << 4 * (cnt + girl) % MOD << endl;
    }
    else cout << 0 << endl;
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