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
    string s1,s2;
    cin >> s1 >> s2;
    int flag = 1;
    set<char> ok1,ok2;
    ok1 = {'O','0'};
    ok2 = {'I','l','1'};
    for (int i = 0;i < n;i++)
    {
        char c1 = s1[i],c2 = s2[i];
        if (s1[i] != s2[i])
        {
            if ((ok1.contains(c1) && ok1.contains(c2)) || (ok2.contains(c1) && ok2.contains(c2))) {}
            else 
            {
                flag = 0;
                break;
            } 
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

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