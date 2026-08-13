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
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '0') 
        {
            int p = i + 1;
            if (p > n / 2)
            {
                cout << 1 << " " << p << " " << 1 << " " << p - 1 << endl;
            }
            else 
            {
                cout << p << " " << n << " " << p + 1 << " " << n << endl;
            }
            return ;
        }
    }

    cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
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