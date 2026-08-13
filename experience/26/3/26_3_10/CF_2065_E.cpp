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
    int n,m,k;
    cin >> n >> m >> k;
    if (k > max(n,m) || k < abs(m - n) || (abs(n / k - m / k) > 1)) 
    {
        cout << -1 << endl;
        return ;
    } 
    string s;
    if (n > m)
    {
        if ((n / k + m / k) % 2)
        {
            s.insert(s.end(),k,'0');
            n -= k;
            while (n >= k && m >= k)
            {
                s.insert(s.end(),k,'1');
                s.insert(s.end(),k,'0');
                n -= k;
                m -= k;
            }
            s.insert(s.end(),m,'1');
            s.insert(s.end(),n,'0');
        }
        else 
        {
            while (n >= k && m >= k)
            {
                s.insert(s.end(),k,'0');
                s.insert(s.end(),k,'1');
                n -= k;
                m -= k;
            }
            s.insert(s.end(),n,'0');
            s.insert(s.end(),m,'1');
        }
    }
    else 
    {
        if ((m / k + n / k) % 2)
        {
            s.insert(s.end(),k,'1');
            m -= k;
            while (n >= k && m >= k)
            {
                s.insert(s.end(),k,'0');
                s.insert(s.end(),k,'1');
                n -= k;
                m -= k;
            }
            s.insert(s.end(),n,'0');
            s.insert(s.end(),m,'1');
        }
        else 
        {
            while (n >= k && m >= k)
            {
                s.insert(s.end(),k,'1');
                s.insert(s.end(),k,'0');
                n -= k;
                m -= k;
            }
            s.insert(s.end(),m,'1');
            s.insert(s.end(),n,'0');
        }
    }
    cout << s << endl;
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