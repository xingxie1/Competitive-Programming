#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
using ll = long long;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
void solve()
{
    int n,m;
    cin >> n >> m;
    vt last(m + 1,-1);
    vvt a(n);
    for (int i = 0;i < n;i++)
    {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0;j < k;j++)
        {
            cin >> a[i][j];
            last[a[i][j]] = i;
        }
    }
    if (n == 1) 
    {
        cout << "No" << endl;
        return ;
    }
    vt ans;
    for (int i = 0;i < n - 1;i++)
    {
        set<int> s1,s2,st;
        for (int j = 0;j < a[i].size();j++)
        {
            s1.insert(a[i][j]);
            // cout << a[i][j] << " ";
        }
        // cout << endl;
        for (int j = 0;j < a[i + 1].size();j++)
        {
            s2.insert(a[i + 1][j]);
            // cout << a[i + 1][j] << " ";
        }
        // cout << endl;
        for (int x : s1) 
        {
            if (s2.contains(x)) st.insert(x);
        }
        int f = 1;
        for (int x : st) 
        {
            if (last[x] <= i + 1) 
            {
                f = 0;
                break;
            }
        }
        if (f)
        {
            for (int j = 0;j < i;j++) ans.push_back(j);
            ans.push_back(i + 1);
            ans.push_back(i);
            for (int j = i + 2;j < n;j++) ans.push_back(j);
            cout << "Yes" << endl;
            // cout << ans.size() << endl;
            for (int i = 0;i < n;i++) 
            {
                if (i) cout << " ";
                cout << ans[i] + 1;
            }
            cout << endl;
            return ;
        }
    }
    cout << "No" << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();
}