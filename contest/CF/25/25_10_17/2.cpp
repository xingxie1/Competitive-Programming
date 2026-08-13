#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    string s;
    vt ans;
    cin >> s;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '0') ans.push_back(i+1);
    }
    if (ans.empty()) cout << 0 << endl << endl;
    else 
    {
        cout << ans.size() << endl;
        for (int i = 0;i < ans.size();i++) cout << ans[i] << " ";
        cout << endl;
    }
    
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