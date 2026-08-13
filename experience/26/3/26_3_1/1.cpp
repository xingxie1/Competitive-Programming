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
    int c0 = 0,c1 = 0;
    for (char c : s)
    {
        c0 += c == '0';
        c1 += c == '1';
    }
    if (c0 != c1) 
    {
        cout << -1 << endl;
        return ;
    }
    int l = 0,r = n - 1;
    vt ans;
    while (!s.empty())
    {
        if (s.front() != s.back())
        {
            s = s.substr(1,s.size() - 2);
            r--;
        }
        else if (s.front() == '0')
        {
            s = s.substr(1) + "0";
            r++;
            ans.push_back(r);
        }
        else if (s.front() == '1')
        {
            s = "1" + s.substr(0,s.size() - 1);
            r++;
            ans.push_back(l);
        }
        l++;
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;
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