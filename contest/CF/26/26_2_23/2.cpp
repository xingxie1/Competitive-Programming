#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    string s(2,'a'),X;
    if (n % 2 == 0) s[1] = 'b';
    cin >> X;
    for (int i = 0;i < n;i++)
    {
        if (X[i] == 'a')
        {
            if (s[0] == 'a') s[0] = 'b';
            else if (s[1] == 'a') s[1] = 'b';
            else 
            {
                cout << "NO" << endl;
                return ;
            }
        }
        else if (X[i] == 'b') 
        {
            if (s[0] == 'b') s[0] = 'a';
            else if (s[1] == 'b') s[1] = 'a';
            else 
            {
                cout << "NO" << endl;
                return ;
            }
        }
        else 
        {
            if (s[0] == s[1]) 
            {
                if (s[0] == 'a') s[0] = 'b';
                else s[0] = 'a';
            }
            else 
            {
                if (i < n - 1)
                {
                    if (X[i + 1] == 'b') 
                    {
                        if (s[0] == 'a') s[0] = 'b';
                        else if (s[1] == 'a') s[1] = 'b';
                        else 
                        {
                            cout << "NO" << endl;
                            return ;
                        }
                    }
                    else if (X[i + 1] == 'a')
                    {
                        if (s[0] == 'b') s[0] = 'a';
                        else if (s[1] == 'b') s[1] = 'a';
                        else 
                        {
                            cout << "NO" << endl;
                            return ;
                        }
                    }
                    else 
                    {
                        if (s[0] == 'b') s[0] = 'a';
                        else s[0] = 'b';
                    }
                }
            }
        }
    }
    cout << "YES" << endl;


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