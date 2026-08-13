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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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
    ll n,k,s;
    cin >> n >> k >> s;
    if (k * (n - 1) < s || k > s) 
    {
        NO;
        return ;
    }
    int cnt = 0,cur = 1;
    ll sum = 0;
    vt ans;
    while (cnt < k)
    {
        if (sum + n - 1 + k - (cnt + 1) <= s) 
        {
            sum += n - 1;
            cnt++;
            if (cur == 1) 
            {
                ans.push_back(n);
                cur = n;
            }
            else 
            {
                ans.push_back(1);  
                cur = 1;
            }
        }
        else 
        {
            int res = s - (sum + k - cnt - 1);
            sum += res;
            cnt++;
            if (cur - res >= 1) 
            {
                cur -= res;
                ans.push_back(cur);
            }
            else 
            {
                cur += res;
                ans.push_back(cur);
            }
        }
    }
    YES;
    for (int x : ans) cout << x << " ";
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