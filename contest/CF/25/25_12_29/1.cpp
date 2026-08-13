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
    string s;
    cin >> s;
    int ans = INT_MAX;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '2')
        {
            if (i < n - 1&&s[i + 1] == '0') 
            {
                if (i < n - 2 && s[i + 2] == '2')
                {
                    if (i < n - 1 && s[i + 3] == '6') ans = 0;
                    else ans = min(ans,1);
                }
                else ans = min(ans,2);
            }
            else ans = min(ans,3);
        }
    }
    int flag = 0;
    for (int i = 0;i < n - 3;i++)
    {
        if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2' && s[i + 3] == '5')
        {
            ans = min(ans,1);
            flag = 1;
        }
    }
    if (!flag) ans = 0;
    cout << ans << endl;

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