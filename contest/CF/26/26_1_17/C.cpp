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
    vt pre(n + 1),suf(n + 1);
    for (int i = 0;i < n;i++)
    {
        pre[i + 1] = pre[i] + (s[i] == '1');
    }
    for (int i = n - 1;i >= 0;i--)
    {
        suf[i] = suf[i + 1] + (s[i] == '0');
    }

    for (int i = 0;i < n;i++)
    {
        if (pre[i] == suf[i] && pre[i] != 0) 
        {
            cout << "Alice" << endl;
            vt a;
            for (int j = 0;j < i;j++)
            {
                if (s[j] == '1') a.push_back(j + 1);
            }
            for (int j = i;j < n;j++)
            {
                if (s[j] == '0') a.push_back(j + 1);
            }
            cout << a.size()  << endl;
            for (int x : a) cout << x << " ";
            cout << endl;
            return ;
        }
    }
    cout << "Bob" << endl;
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