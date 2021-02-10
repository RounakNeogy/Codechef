#include<iostream>
using namespace std;
int arr[5];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int l[n];
        for(int i=0;i<n;i++)
            cin>>l[i];
        if(n==2){
            if(arr[0]==1)
                cout<<0<<endl;
            else if(arr[0]==2){
                if(l[0]==1)
                    cout<<2<<endl;
                else
                    cout<<1<<endl;
            }
        }
        else if(n==3){
            int ans=0;
            int aj,bj,cj;
            int a1,b1,c1;
            for(int i=0;i<n;i++){
                if(arr[i]==1){
                    aj=i;
                    a1=i;
                }
                else if(arr[i]==2){
                    bj=i;
                    b1=i;
                }
                else if(arr[i]==3){
                    cj=i;
                    c1=i;
                }
            }
            while(cj<bj||bj<aj||cj<aj){
                while(bj<=aj){
                    bj+=l[b1];
                    ans++;
                }
                while(cj<=bj||cj<=aj){
                    cj+=l[c1];
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
        else if(n==4){
            int ans=0;
            int aw,bw,cw,dw;
            int a1,b1,c1,d1;
            for(int i=0;i<n;i++){
                if(arr[i]==1){
                    aw=i;
                    a1=i;
                }
                else if(arr[i]==2){
                    bw=i;
                    b1=i;
                }
                else if(arr[i]==3){
                    cw=i;
                    c1=i;
                }
                else{
                    dw=i;
                    d1=i;
                }
            }
            while(cw<bw||bw<aw||cw<aw||dw<aw||dw<bw||dw<cw){
                while(bw<=aw){
                    bw+=l[b1];
                    ans++;
                }
                while(cw<=bw||cw<=aw){
                    cw+=l[c1];
                    ans++;
                }
                while(dw<=aw||dw<=bw||dw<=cw){
                    dw+=l[d1];
                    ans++;
                }
            }
            cout<<ans<<endl;
        }

    }
}
