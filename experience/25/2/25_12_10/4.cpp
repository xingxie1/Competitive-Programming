// https://codeforces.com/problemset/problem/1428/C
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
    stack<char> st;
    for (char c : s)
    {
        if (st.empty()) st.push(c);
        else 
        {
            if (c == 'B') st.pop();
            else st.push(c);
        }
    }
    cout << st.size() <<endl;
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