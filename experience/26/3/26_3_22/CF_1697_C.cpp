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
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    int c1 = 0,c2 = 0;
    for (char c: s) 
    {
        if (c == 'b') c1++;
    }
    for (char c: t) 
    {
        if (c == 'b') c2++;
    }
    if (c1 != c2)
    {
        cout << "NO" << endl;
        return ;
    }
    int j = 0;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == 'b') continue;
        while (t[j] == 'b') j++;
        if (s[i] != t[j] || (s[i] == 'a' && i > j) || (s[i] == 'c' && i < j))
        {
            cout << "NO" << endl;
            return ;
        }
        j++;
    }
    cout << "YES" << endl; 
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