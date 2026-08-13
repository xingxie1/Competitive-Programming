#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    unordered_map<int,int> cnt;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vt ans1,ans2;
    auto it = cnt.begin();
    int flag = 1;
    while (it!= cnt.end())
    {
        if (it->second > 2)
        {
            flag = 0;
            break;
        }
        ans1.push_back(it->fi);
        it->se--;
        if (it->se) ans2.push_back(it->fi);

        it++;
    }
    sort(ans1.begin(),ans1.end());
    sort(ans2.begin(),ans2.end(),greater<int>());
    if (flag == 0) cout << "NO" << endl;
    else 
    {
        cout << "YES" << endl;
        cout << ans1.size() << endl;
        for (int i = 0;i < ans1.size();i++) cout << ans1[i] << " ";
        cout << endl;
        cout << ans2.size() << endl;
        for (int i = 0;i < ans2.size();i++) cout << ans2[i] << " ";
        cout << endl;
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