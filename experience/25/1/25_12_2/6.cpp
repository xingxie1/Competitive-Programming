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
    int n,jj,kk;
    cin >> n >> jj >> kk;
    vt a;
    if (n == 12)
    {
        a.push_back(12);
        a.push_back(21);
    }
    else if (n == 123)
    {
        for (int i = 1;i <= 3;i++)
        {
            for (int j = 1;j <= 3;j++)
            {
                for (int k = 1;k <= 3;k++)
                {
                    if (i != j && j != k && i != k) a.push_back(i * 100 + j * 10 + k);
                }
            }
        }
    }
    else 
    {
        for (int i = 1;i <= 4;i++)
        {
            for (int j = 1;j <= 4;j++)
            {
                for (int k = 1;k <= 4;k++)
                {
                    for (int l = 1;l <= 4;l++)
                    {
                        if (i != j && i != k && i != l && j != k && j != l && k != l)
                        {
                            int t = 1000 * i + 100 * j + 10 * k + l;
                            a.push_back(t);
                        }
                    }
                }
            }
        }
    }
    sort(a.begin(),a.end());
    jj--;
    kk--;
    string s = to_string(a[jj]);
    string t = to_string(a[kk]);

    int A = 0,B = s.size();
    for (int i = 0;i < s.size();i++)
    {
        if (s[i] == t[i]) 
        {
            A++;
            B--;
        }
    }
    cout << A << "A" << B << "B" << endl;
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