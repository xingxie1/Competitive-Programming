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
    int n;
    cin >> n;
    vpii ans;
    if (n == 1) 
    {
        cout << 1 << " " << 1 << endl;
        return ;
    }
    ans.push_back({1,1});
    ans.push_back({n,n});
    if (n == 2)
    {
        for (auto& [l,r] : ans) cout << l << " " << r << endl;
        return ;
    }
    if (n == 3)
    {
        cout << "1 1" << endl;
        cout << "1 2" << endl;
        cout << "3 2" << endl;
        return ;
    }
    ans.push_back({1,2});
    for (int i = 4;i <= n;i++)
    {
        if (i % 4 == 0)
        {
            int k = i / 4;
            ans.push_back({i - k,1});
            i++;
            if (i > n) break;
            ans.push_back({i - k,1});
        }
        else 
        {
            int k = i / 4 + 1;
            ans.push_back({1,i - k});
            i++;
            if (i > n) break;
            ans.push_back({1,i - k});
        }
    }
    for (auto& [l,r] : ans) cout << l << " " << r << endl;
    
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