#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vvt = vector<vt>;
using pii = pair<int,int>;
using vll = vector<ll>;
using vpii = vector<pii>;

void solve()
{
    int n = 7;
    int k = 2;
    for (int n = 12;n <= 12;n++) 
    {
        for (int k = 7;k <= 7;k++)
        {
            vt a(n);
            ranges::iota(a,1);
            vvt ans;
            int mn = INT_MAX / 2;
            for (int mask = 0;mask < 1 << n;mask++)
            {
                if (popcount(1u * mask) != k) continue;
                vt b,c;
                for (int i = 0;i < n;i++)
                {
                    if (mask >> i & 1) 
                    {
                        c.push_back(a[i]);
                        continue;
                    }
                    b.push_back(a[i]);
                }
                int sum = 0;
                for (int i = 0;i < b.size();i++)
                {
                    for (int j = i + 1;j < b.size();j++)
                    {   
                        sum += gcd(abs(b[i] - b[j]),n);
                    }
                }
                if (sum == mn) ans.push_back(c);
                else if (sum < mn) 
                {
                    mn = sum;
                    ans.clear();
                    ans.push_back(c);
                }
            }
            cout << "n : " << n << " k : " << k << endl;
            for (int i = 0;i < ans.size();i++)
            {
                for (int x : ans[i]) cout << x << " ";
                cout << endl;
            }

        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}