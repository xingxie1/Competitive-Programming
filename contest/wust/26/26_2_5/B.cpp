#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    umap<int,int> cnt;
    for (int x : a) cnt[x]++;
    
    vt b,d;
    int mxo = 0,mxe = 0;
    for (auto&[x,c] : cnt)
    {
        if (c % 2 == 0) 
        {
            b.push_back(x);
            mxe = max(mxe,x);
        }
        else 
        {
            mxo = max(mxo,x);
            d.push_back(x);
        }
    }
    sort(b.begin(),b.end());
    sort(d.begin(),d.end());

    string s;
    for (int i = 0;i < n;i++) s += '0';
    
    for (int i = 0;i < n;i++)
    {
        int x = a[i];
        if (cnt[x] % 2 == 1)
        {
            if (a[i] == mxo) s[i] = '1';
            else 
            {
                if (mxo < mxe) s[i] = '1';
                else s[i] = '0';
            }
        }
        else 
        {
            if (a[i] == mxe)
            {
                s[i] = '0';
            }
            else 
            {
                if (mxe > mxo) s[i] = '1';
                else s[i] = '0';
            }
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