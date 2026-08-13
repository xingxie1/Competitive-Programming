#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char,int> hash;
    for (int i = 0;i < n;i++)
    {
        hash[s[i]]++;
    }
    if (hash['K'] < 1 || hash['a'] < 1 || hash['t'] < 1 || hash['o'] < 3 ||
       hash['_'] < 1 || hash['S'] < 1 || hash['h'] < 1 || hash['k'] < 1)
    {
        cout << "NO" << endl;
    }
    else 
    {
        cout << "YES " << n - 10 << endl;
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}