// https://codeforces.com/problemset/problem/1342/B
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
    string t;
    cin >> t;
    string s;
    int n = t.size();
    if (t.size() <= 2) 
    {
        cout << t << endl;
    }
    else 
    {
        int flag = 1;
        for (int i = 0;i < n - 1;i++)
        {
            if (t[i] != t[i + 1]) flag = 0;
        }
        if (flag)
        {
            cout << t << endl;
            return ;
        }
        if (t[0] == '1')
        {
            for (int i = 0;i < n;i++)
            {
                s += '1';
                s += '0';
            }
        }
        else 
        {
            for (int i = 0;i < n;i++)
            {
                s += '0';
                s += '1';
            }
        }
        cout << s << endl;
    }

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