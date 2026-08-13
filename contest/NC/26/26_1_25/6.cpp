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
    string s;
    cin >> s;
    int n = s.size();
    stack<int> st;
    int j = n - 1;
    string ans;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '1') 
        {
            st.push(i);
        }
        else if (s[i] == '0')
        {
            while (!st.empty() && j > i)
            {
                if (s[j] == '1') 
                {
                    s[j] = '2';
                    st.pop();
                }
                j--;
            }
            while (!st.empty())
            {
                st.pop();
                ans += '1';
            }
            ans += '0';
        }
        else 
        {
            while (!st.empty()) 
            {
                ans += '1';
                st.pop(); 
            }
            ans += s[i];
        }
    }
    while (!st.empty()) 
    {
        ans += '1';
        st.pop();
    }
    cout << ans << endl;
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