#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        unordered_map<ll, ll> mp;
        ll s=0,c=0,d=0;
        for(ll i=0;i<n;i++)
        {
            ll m;
            cin>>m;
            ll p;
            c=0,d=0;
            for(int j=0;j<m;j++)
            {
                cin>>p;
                if(mp[abs(p)]<=i+1)
                {
                    cout<<mp[abs(p)]<<endl;
                    mp[abs(p)]++;
                }
                if(p<0)
                    c++;
                else
                    d++;
            }
            s=s+c*d;
        }
        cout<<s<<endl;
        for(auto x:mp)
        {
            if(x.second>1)
                s++;
        }
        cout<<s<<endl;
    }
}

/* 1
2
3 -3 2 3
2 4 2
*/
