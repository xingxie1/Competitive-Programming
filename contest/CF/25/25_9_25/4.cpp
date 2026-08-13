#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

long long solve_one(string s,char c)
{
    int n = s.size();
    vt pos;
    for (int i = 0;i < n;i++) 
    {
        if (s[i] == c) pos.push_back(i);
    }
    int k = pos.size();
    if (k <= 1) return 0;
    vt v(k);
    for (int i = 0;i < k;i++)
    {
        v[i] = pos[i] - i;
    }
    int medium = v[(k-1)/2];
    long long cnt = 0;
    for (int i = 0;i < k;i++)
    {
        cnt += abs(v[i] - medium);
    }
    return cnt;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string tmp(s.begin(),s.end());
    long long ans = min(solve_one(s,'a'),solve_one(s,'b'));
    cout << ans << endl;
    
}

int main()
{
    int t = 1;
    cin >> t;
    while (t --) solve();
    return 0;
}