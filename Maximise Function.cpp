#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long a[n];
        for(long long i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        cout<<(a[n-1]-a[0])*2<<endl;
    }
}
