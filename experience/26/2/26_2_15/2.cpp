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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    string s;
    cin >> s;
    cout << "#";
    int t = 0;
    auto f = [&](char c1,char c2) 
    {
        int ret = 0;
        if (c1 >= 'a' && c1 <= 'f') ret += (c1 - 'a' + 10) * 16;
        else ret += (c1 - '0') * 16;
        if (c2 >= 'a' && c2 <= 'f') ret += (c2 - 'a') + 10;
        else ret += (c2 - '0');
        ret = 255 - ret;
        int k = ret / 16;
        int r = ret - k * 16;
        char ac1,ac2;
        if (k >= 10) ac1 = k - 10 + 'a';
        else ac1 = '0' + k;
        if (r >= 10) ac2 = r - 10 + 'a';
        else ac2 = r + '0';
        string s;
        s += ac1;
        s += ac2;
        return s;
    };
    cout << f(s[1],s[2]) << f(s[3],s[4]) << f(s[5],s[6]) << endl;
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