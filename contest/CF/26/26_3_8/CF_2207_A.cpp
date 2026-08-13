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
    int c1 = 0;
    string t = s;
    for (int i = 1;i < n - 1;i++)
    {
        if (s[i - 1] == '1' && s[i + 1] == '1') 
        {
            s[i] = '1';
        }
    }
    for (char c : s) c1 += (c == '1');
    int mx = c1;
    c1 = 0;
    for (int i = 1;i < n - 1;i++)
    {
        if (s[i - 1] == '1' && s[i + 1] == '1') 
        {
            s[i] = '0';
        }
    }
    for (char c : s) c1 += (c == '1');
    int mn = c1;
    cout << mn << " " << mx << endl;
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