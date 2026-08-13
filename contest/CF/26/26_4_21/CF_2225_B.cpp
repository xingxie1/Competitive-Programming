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
    string s;
    cin >> s;
    int n = s.size();
    auto f = [&](char t)
    {
        int flag = 0;
        for (int i = 0;i < n;i++)
        {
            if (s[i] != t)
            {
                // cout << i << " " << t << endl;
                int j = i;
                if (flag) return 0;
                flag = 1;
                while (j < n && s[j] != t) 
                {
                    j++;
                    t = ((t - 'a') ^ 1) + 'a';
                }
                i = j - 1;
                continue;
            }
            t = ((t - 'a') ^ 1) + 'a';
        }
        return 1;
    };
    if (f('a') || f('b')) YES;
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