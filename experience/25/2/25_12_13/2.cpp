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

int isprime(string s)
{
    int n = stoi(s);
    if (n == 1 || n == 0) return 0;
    for (int i = 2;i <= sqrt(n);i++)
    {
        if (n % i == 0) return 0;
    }
    return 1;
}
void solve()
{
    int n;
    cin >> n;
    queue<pair<string,int>> q;
    q.emplace(to_string(n),0);
    umap<string,int> vis;
    while (!q.empty())
    {
        auto [s,d] = q.front();
        if (s == "") break;
        if (isprime(s))break;
        vis[s]++;
        q.pop();
        for (int i = 0;i < s.size();i++)
        {
            string tmp;
            for (int j = 0;j < s.size();j++)
            {
                if (j != i) tmp += s[j];
            }
            if (!vis.count(tmp)) q.emplace(tmp,d + 1);
            vis[tmp]++;
        }
    }
    if (q.front().fi == "") 
    {
        cout << -1 << endl;
        return ;
    }
    int ans = q.front().se;
    cout << ans << endl;
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