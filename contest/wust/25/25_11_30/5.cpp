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
    int a,b;
    cin >> a >> b;
    queue<pair<string,int>> q;

    string t1 = to_string(b);
    while (t1.size() < 4) t1.insert(0,"0");
    string t2 = to_string(a);
    while (t2.size() < 4) t2.insert(0,"0");
    q.emplace(t2,0);

    int ans = -1;
    unordered_map<string,int> cnt;
    cnt[t2]++;

    int n = 10000;
    vector<int> primes; 
    vector<bool> isPrime(n + 1, true); 
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= n; ++i) 
    {
        if (isPrime[i]) primes.push_back(i);
        for (int p : primes) 
        {
            if (1LL * i * p > n) break;
            isPrime[i * p] = false;
            if (i % p == 0) break; 
        }
    }

    while (!q.empty())
    {
        auto [tmp,d] = q.front();
        q.pop();
        while (tmp.size() < 4) tmp.insert(0,"0");
        cnt[tmp]++;
        if (tmp == t1)
        {
            ans = d;
            break;
        }
        for (int i = 0;i < 4;i++)
        {
            string s = tmp;
            for (int j = 0;j < 10;j++)
            {
                s[i] = '0' + j;
                if (cnt.count(s)) continue;
                cnt[s]++;
                int x = stoi(s);
                if (isPrime[x])
                {
                    q.emplace(s,d + 1);
                    cout << s << endl;
                }
            }
        }
    }
    cout << ans << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
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