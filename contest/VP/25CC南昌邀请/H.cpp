#include<bits/stdc++.h>
using namespace std;
#define int long long
int _;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>_;
    while(_--){
        int n;
        cin>>n;
        vector<int>num(n+1);
        vector<int>mn(n+2);
        mn[n+1]=1e17;
        for(int i=1;i<=n;i++) cin>>num[i];
        for(int i=n;i>=1;i--) mn[i]=min(num[i]-i,mn[i+1]);

        if(mn[1]<0){
            cout<<"-1\n";
            continue;
        }
        int flag=0;
        int ans=0;
        int p=0;
        for(int i=1;i<=n;i++){
            if(flag<mn[i]){
                if(p>=mn[i]-flag){
                    ans+=mn[i]-flag;
                    p-=mn[i]-flag;
                    flag=mn[i];

                }
                else{
                    flag+=p;
                    ans+=p;
                    p=0;
                }
            }
            ans++;
            p+=num[i]-i-flag;
        }
        cout<<ans+p<<'\n';
    }
    return 0;
}