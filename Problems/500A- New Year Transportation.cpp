#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define pb(x)           push_back(x)
#define mkp(x,y)        make_pair(x,y)
#define L               length()
#define bs              binary_search
#define mod             1000000007
#define IOS             ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(v)          v.begin(),v.end()
#define mem0(a)         memset(a,0,sizeof(a))
#define mem1(a)         memset(a,-1,sizeof(a))
#define F               first
#define S               second
#define pii             pair<int,int>
#define vi              vector<int>
#define vs              size()
#define gcd(a,b)        __ gcd(a,b)
#define endl            '\n'
#define atoi            stoi
#define elasped_time    1.0 * clock() / CLOCKS_PER_SEC
#define si              set <int>
#define vpii            vector < pair <int,int> >

int power(int b,int e)
{
	if(e==0)
	return 1;
	if(e%2)
	return b*power(b*b,(e-1)/2);
	else
	return power(b*b,e/2);
}
/*int ncr(int n,int r)
{
    int f1=1;
    for(int i=1;i<=n;i++)
    {
        f1=(f1%mod*(i)%mod)%mod;
    }
    int f2=1;
    for(int i=1;i<=r;i++)
    {
        f2=(f2%mod*(i)%mod)%mod;
    }
    int f3=1;
    for(int i=1;i<=n-r;i++)
    {
        f3=(f3%mod*i%mod)%mod;
    }
    int k=(f1%mod*power(f2,mod-2,mod)%mod*power(f3,mod-2,mod)%mod)%mod;
    return k;
}*/
void dpv(vi v)
{
    for(int i=0;i<v.vs;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void dpv(vpii v)
{
    for(int i=0;i<v.vs;i++)
    {
        cout<<v[i].F<<" "<<v[i].S<<endl;
    }
}
void dpv(set <int> v)
{
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
int Logn(int n,int k) 
{ 
    return (n > k-1) ? 1 + Logn(n / k,k) : 0; 
} 
bool prime[10000];
void Seive()
{
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(int p=2;p*p<10000;p++)
    {
        if(prime[p]==true)
        {
            for(int i=2*p;i<10000;i+=p)
            {
                prime[i]=false;
            }
        }
    }
}
int sumofd(int z)
{
    int s=0;
    while(z!=0)
    {
        s+=z%10;
        z=z/10;
    }
    return s;
}
bool isvowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
vector <int> graph[100000];
void dfs(int u,bool vis[])
{
    vis[u]=1;
    for(auto i:graph[u])
    {
        if(vis[i])
        {
            continue;
        }
        dfs(i,vis);
    }
}
void oblivious()
{
    int n,k;
    cin>>n>>k;
    bool vis[n+1];
    memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        graph[i+1].pb(x+i+1);
    }
    dfs(1,vis);
    if(vis[k])
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
signed main()
{
    IOS;
    int t=1;
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    //cin>>t;
    int k=0;
    while(k<t)
    {
        k++;
        oblivious();
    }
    return 0;
}