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
    s += '#';
    t += '#';
    int ans = 1;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '#' && t[i] == '#') continue;
        if (s[i] == '.' && t[i] == '#')
        {
            if (s[i + 1] == '.')
            {
                s[i] = '#';
                s[i + 1] = '#';
            }
            else 
            {
                cout << "None" << endl;
                return ;
            }
        }
        else if (s[i] == '#' && t[i] == '.')
        {
            if (t[i + 1] == '.')
            {
                t[i] = '#';
                t[i + 1] = '#';
            }
            else 
            {
                cout << "None" << endl;
                return ;
            }
        }
        else 
        {
            s[i] = '#';
            t[i] = '#';
            if (s[i + 1] == '.' && t[i + 1] == '.')
            {
                s[i + 1] = '#';
                t[i + 1] = '#';
                ans = 2;
            }
        }
    }
    // cout << s << endl << t << endl;
    if (ans == 1) cout << "Unique" << endl;
    else cout << "Multiple" << endl;
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