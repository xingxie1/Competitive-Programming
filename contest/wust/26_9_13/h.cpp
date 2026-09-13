#include<bits/stdc++.h>
using namespace std;

using vt = vector<int>;
using pii = pair<int,int>;
void solve()
{
    int n;
    cin >> n;
    int N = 2 * n;
    vt a(N);
    vt cnt(N + 1);
    for (int i = 0;i < N;i++) 
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    set<pii> st;
    for (int i = 1;i <= N;i++) 
    {
        if (cnt[i] == 0) continue;
        st.insert({cnt[i],i});
    }
    // if (st.empty())
    // {
    //     cout << "Kevin" << endl;
    //     return ;
    // }
    while (!st.empty())
    {

        auto [c,x] = *(--st.end());
        if (st.size() == 1 && c == 1) 
        {
            cout << "Kevin" << endl;
            return ;
        }
        else if (st.size() == 1)
        {
            cout << "Qingyu" << endl;
            return ;
        }
        // cout << "c,x " << c << " " << x << endl; 
        st.erase(--st.end());
        c--;
        if (c) st.insert({c,x});
        auto [c2,x2] = *st.begin();
        if (st.size() == 1 && c2 == 1) 
        {
            cout << "Kevin" << endl;
            return ;
        }
        st.erase(st.begin());
        // cout << "c2,x2 " << c2 << " " << x2 << endl; 
        c2--;
        if (c2) st.insert({c2,x2});

    }

}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();

    return 0;
}