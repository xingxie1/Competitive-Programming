#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    map<char,int> a,b;
    for (int i = 0;i < n;i++)
    {
        a[s[i]]++;
        b[t[i]]++;
    }
    auto it1 = a.begin(),it2 = b.begin();
    while (it1 != a.end())
    {
        if (it1->first != it2->first || it1->second != it2->second)
        {
            cout << "No" << endl;
            return ;
        }
        it1++;
        it2++;
    }
    cout << "Yes" << endl;
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