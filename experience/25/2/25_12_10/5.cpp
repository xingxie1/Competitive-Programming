// https://codeforces.com/problemset/problem/1304/B
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
    vector<string> a(n);
    map<string,int> cnt;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<string> left,right;
    string mid;
    for (int i = 0;i < n;i++)
    {
        string s = a[i];
        if (!cnt.count(s)) continue;
        string tmp = s;
        reverse(tmp.begin(),tmp.end());
        if (s == tmp) 
        {
            if (s.size() > mid.size()) mid = s;
        }
        else if (cnt.count(tmp))
        {
            left.push_back(s);
            right.push_back(tmp);
            cnt[s]--;
            if (cnt[s] == 0) cnt.erase(s);
            cnt[tmp]--;
            if (cnt[tmp] == 0) cnt.erase(tmp);
        }
    }
    cout << left.size() * 2 * m + mid.size() << endl;
    for (string& s : left) cout << s;
    cout << mid;
    reverse(right.begin(),right.end());
    for (string& s : right) cout << s;
    cout << endl;
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