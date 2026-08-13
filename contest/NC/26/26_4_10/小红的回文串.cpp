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
    string s;
    int n;
    cin >> n;
    cin >> s;
    if (n % 2 == 1) 
    {
        int ans = 1;
        char t = s[n / 2];
        int l = n / 2 - 1,r = n / 2 + 1;
        while (l >= 0 && r < n && s[l] == s[r] && s[l] == t) 
        {
            ans += 2;
            l--;
            r++;
        }
        cout << ans << endl;
    }
    else 
    {   
        int l = n / 2 - 1,r = n / 2;
        char t = s[l];
        int ans = 0;
        while (l >= 0 && r < n && s[l] == t && s[r] == t) 
        {
            ans+=2;
            l--;
            r++;
        }
        cout << ans << endl;
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