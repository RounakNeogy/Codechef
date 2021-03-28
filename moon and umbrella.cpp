#include<bits/stdc++.h>
using namespace std;
int count_mincost(string s,int x,int y){
    int n=s.size(),ans=0;
    for(int i=0;i<n-1;i++){
        if(s[i]=='C' and s[i+1]=='J')
            ans=ans+x;
        if(s[i]=='J' and s[i+1]=='C')
            ans=ans+y;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    for(int k=1;k<=t;k++){
        int x,y;
        cin>>x>>y;
        string s;
        cin>>s;
        int n=s.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='?')
                c++;
        }
        if(c==n or c==n-1)
            cout<<"Case #"<<k<<": 0"<<endl;
        else{
            int pos=0;
            char a,b;
            for(int i=0;i<n;i++){
                if(s[i]!='?')
                {
                    pos=i;
                    a=s[i];
                    b=s[i];
                    break;
                }
            }
            for(int i=pos+1;i<n;i++){
                if(s[i]=='?')
                    s[i]=a;
                else
                    a=s[i];
            }
            for(int i=pos-1;i>=0;i--){
                if(s[i]=='?')
                    s[i]=b;
                else
                    b=s[i];
            }
            cout<<s<<endl;
            int ans=count_mincost(s,x,y);
            cout<<"Case #"<<k<<": "<<ans<<endl;
        }
    }
}

