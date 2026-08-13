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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int hasp = 0,hass = 0,lasts = -1;
    for (int i = 0;i < n;i++)
    {
        if (s[i] != '.') 
        {
            if (s[i] == 'p')
            {
                if (hass && i != n - 1 && lasts != 0)
                {
                    cout << "NO" << endl;
                    return ;
                }
                hasp = 1;
            }
            else if (s[i] == 's')
            {
                if (hasp)
                {
                    cout << "NO" << endl;
                    return ;
                }
                hass = 1;
                lasts = i;
            }
        }
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