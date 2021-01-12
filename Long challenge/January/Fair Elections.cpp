#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m,s=0,s1=0;
        cin>>n>>m;
        int a[n],b[m];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s+=a[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>b[i];
            s1+=b[i];
        }
        sort(a,a+n);
        sort(b,b+m);
        int c=0,i=0,j=m-1,flag=0;
        while(s<=s1 && i<n && j>=0)
        {
            s=s-a[i]+b[j];
            s1=s1-b[j]+a[i];
            i++;
            j--;
            c++;
        }
        if(s<=s1)
            cout<<"-1"<<endl;
        else
            cout<<c<<endl;
    }
}
