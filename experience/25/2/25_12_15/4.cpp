// https://codeforces.com/problemset/problem/1616/B
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    for (int i = 1;i < n;i++)
    {
        if (s[i] > s[i - 1]) 
        {
            string tmp(s.begin(),s.begin() + i);
            ans = tmp;
            break;
        }
        else if (s[i] == s[i - 1]) 
        {
            if (i == 1) continue;
            else break;
        }
    }
    if (ans.empty()) ans = s;
    string tmp = ans;
    reverse(tmp.begin(),tmp.end());
    ans += tmp;
    cout << ans << endl;
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