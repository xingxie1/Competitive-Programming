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
    int n,m;
    cin >> n >> m;
    queue<pair<int,int>> q; 
    ll sum = 0;
    for (int i = 0;i < n;i++)
    {
        while (!q.empty() && i - q.front().fi >= m) 
        {
            sum -= q.front().se;
            q.pop();
        }
        string s;
        cin >> s;
        if (s == "eat")
        {
            int x;
            cin >> x;
            if (x <= sum)
            {
                ll cnt = 0;
                while (cnt < x)
                {
                    if (cnt + q.front().se < x)
                    {
                        cnt += q.front().se;
                        q.pop();
                    }
                    else 
                    {
                        
                        q.front().se -= (x - cnt);
                        cnt = x;
                        if (q.front().se == 0) q.pop();
                    }
                }
                sum -= x;
                cout << "xie xie ni" << endl;
            }
            else cout << "wu wu wu" << endl;
        }
        else 
        {
            int x;
            cin >> x;
            q.emplace(i,x);
            sum += x;
        }
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