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
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;


void solve()
{
    int n,k;
    cin >> n >> k;
    string s,t;
    cin >> s >> t;
    if (n >= 6)
    {
        ranges::sort(s);
        ranges::sort(t);
        if (s == t) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else if (n <= 3)
    {
        if (s == t) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else if (n == 4)
    {
        if (s[1] == t[1] && s[2] == t[2] && (s[0] == t[0] || s[0] == t[3]) && (s[3] == t[0] || s[3] == t[3])) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else if (n == 5)
    {
        set<char> s1,s2;
        for (int i = 0;i < n;i++)
        {
            if (i == 2) continue;
            s1.insert(s[i]);
            s2.insert(t[i]);
        }
        if (s[2] == t[2] && s1 == s2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

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