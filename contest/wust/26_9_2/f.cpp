#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

using i128 = __int128_t;
i128 cin_128() 
{
    string s;
    cin >> s;
    i128 x = 0;
    for (char c : s)
    {
        x = x * 10 + (c - '0');
    }
    return x;
}
void print_128(i128 x)
{
    string s;
    while (x)
    {
        s.push_back('0' + x % 10);
        x /= 10;
    }
    ranges::reverse(s);
    cout << s << endl;
}
void solve()
{
    int n;
    cin >> n;
    vector<i128> a(n);
    priority_queue<i128,vector<i128>,greater<>> pq;
    for (int i = 0;i < n;i++) 
    {
        i128 x = cin_128();
        pq.push(x);
    }
    while (pq.size() > 1)
    {
        auto x1 = pq.top();
        pq.pop();
        auto x2 = pq.top();
        pq.pop();
        if (x1 == x2)
        {
            pq.push(x1 + x2);
        }
        else pq.push(x2);
    }
    print_128(pq.top());
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}