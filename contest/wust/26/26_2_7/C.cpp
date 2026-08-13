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
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto f = [&](string& s,char c)
    {
        string ttt;
        if (c == '1')
        {
            while (ttt.size() < s.size())
            {
                ttt += '1';
                if (ttt.size() == s.size()) break;
                ttt += '0';
            }
        }
        else 
        {
            while (ttt.size() < s.size())
            {
                ttt += '0';
                if (ttt.size() == s.size()) break;
                ttt += '1';
            }
        }
        string t;
        for (int i = 0;i < n;i++) 
        {
            if (s[i] == ttt[i]) t += s[i];
        }
        int mx = INT_MIN,sum = 0,mn = INT_MAX;
        for (int i = 0;i < t.size();i++)
        {
            if (t[i] == '1') sum++;
            else sum--;
            if (sum > 0) sum = 0;
            mn = min(mn,sum);
        }
        sum = 0;
        for (int i = 0;i < t.size();i++)
        {
            if (t[i] == '1') sum++;
            else sum--;
            if (sum < 0) sum = 0;
            mx = max(mx,sum);
        }
        return max(abs(mn),mx);
    };
    cout << min(f(s,'1'),f(s,'0')) << endl;
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