#include<bits/stdc++.h>
using namespace std;

int N = 5000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n,m;
    cin >> n;
    vector<int> a(n),s(n+1);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        int l,r;
        cin >> l >> r;
        cout << s[r] - s[l-1] << endl;
    }

    

    return 0;
}