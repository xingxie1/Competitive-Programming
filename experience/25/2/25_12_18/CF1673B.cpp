// https://codeforces.com/problemset/problem/1673/B
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
    string s;
    cin >> s;
    map<char,int> seen;
    string order;
    for (char c : s)
    {
        if (!seen.count(c))
        {
            seen[c] = 1;
            order += c;
        }
    }
    int k = order.size();
    for (int i = 0;i < s.size();i++)
    {
        if (s[i] != order[i % k])
        {
            cout << "NO" << endl;
            return ;
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