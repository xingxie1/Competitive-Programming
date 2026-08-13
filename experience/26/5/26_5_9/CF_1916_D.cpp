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

void solve()
{
    int n;
    cin >> n;

    if(n == 1)
    {
        cout << 1 << endl;
        return;
    }

    vector<string> ans = {"169", "196", "961"};

    for(int len = 5; len <= n; len += 2)
    {
        for(auto &s : ans)
        {
            s += "00";
        }

        int cnt = (len - 3) / 2;

        string a = "1";
        a += string(cnt, '0');
        a += "6";
        a += string(cnt, '0');
        a += "9";

        string b = "9";
        b += string(cnt, '0');
        b += "6";
        b += string(cnt, '0');
        b += "1";

        ans.push_back(a);
        ans.push_back(b);
    }

    for(auto s : ans)
    {
        cout << s << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }

    return 0;
}