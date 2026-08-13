#include<bits/stdc++.h>
using namespace std;
int _;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>_;
    while(_--){
        int n,k;
        cin>>n>>k;
        vector<int>num(n);
        for(int i=0;i<n;i++)cin>>num[i];
        int ans=0;
        sort(num.begin(),num.end(),[](int x,int y){
            return x>y;
        });
        int kd=0;
        int l=0;
        int flag;
        for(int i=0;i<n;i++){
            ans+=num[i];
            // int thisl=num[i]-1;
            l+=num[i]-1;
            // int thiskd=l/k;
            kd+=(l/k);
            l%=k;
            if(i+1+kd>=n){
                ans-=l;
                ans-=(kd+1+i-n)*k;
                flag=kd+1+i-n;
                break;
            }
            if(i+1+kd==n-1){
                ans++;
                break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}