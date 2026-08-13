#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;  cin >> n;
    map<int,int> mp;
    int maxn = 0;
    for(int i = 1;i<=n;i++){
        int t; cin >> t;
        mp[t]++;
        maxn = max(maxn , t);
    }
    if(mp[maxn]>maxn) cout << "purple" << endl;
    else cout << "red" << endl;
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