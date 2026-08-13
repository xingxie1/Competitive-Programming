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
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
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
    string s;
    cin >> s;
    int n = s.size();
    auto f = [&](int j)
    {
        for (int i = j;i < n;i++)
        {
            if ((i - j) % 3 == 0 && s[i] != 'o') 
            {
                return 0;
            }
            else if ((i - j) % 3 == 1 || (i - j) % 3 == 2) 
            {
                if (s[i] != 'x') 
                {
                    return 0;
                }
            }
        }
        return 1;
    };
    if ((s[0] == 'o' && f(0)) || (s[0] == 'x' && f(1)) || (s[0] == 'x' && s[1] == 'x' && f(2))) YES;
    else NO;
    
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