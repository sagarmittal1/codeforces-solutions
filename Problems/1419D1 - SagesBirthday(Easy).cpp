
//Problem : https://codeforces.com/contest/1419/problem/D1

#include<bits/stdc++.h>
#define ll long long
#define rep(i,t) for(ll i=0;i<t;i++)
using namespace std;
void solve1(){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    rep(j,n)
    cin>>arr[j];
    sort(arr.begin(),arr.end());
    if(n%2)
    {
        cout<<n/2<<endl;
        int a=1;
        int b=(n/2)+1;
        for(int i=1;i<=n;i++)
        {
            if(i%2)
            {
                cout<<arr[b-1]<<" ";
                b++;
            }
            else
            {
                cout<<arr[a-1]<<" ";
                a++;
            }
        }
        cout<<endl;
    }
    else
    {
        cout<<n/2-1<<endl;
        int a=1;
        int b=(n/2)+1;
        for(int i=1;i<=n;i++)
        {
            if(i%2)
            {
                cout<<arr[b-1]<<" ";
                b++;
            }
            else
            {
                cout<<arr[a-1]<<" ";
                a++;
            }
        }
        cout<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    // ll t;
    // cin>>t;
    ll t=1;
    rep(i,t){
        solve1();
    }
    return 0;
}
