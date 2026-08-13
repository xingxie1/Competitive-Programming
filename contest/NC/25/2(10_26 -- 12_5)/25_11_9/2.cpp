#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    unordered_map<int,int> cnt;
    for (int i = 0;i < n;i++) 
    {
        int x,y;
        cin >> x >> y;
        cnt[x]++;
        cnt[y]++;
    }
    auto it = cnt.begin();
    while (it != cnt.end())
    {
        if (it->second == n)
        {
            cout << it->first;
            return ;
        }
        it++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}