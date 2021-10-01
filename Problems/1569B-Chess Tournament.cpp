// Problem: https://codeforces.com/problemset/problem/1569/B

#include<bits/stdc++.h>
#define ll long long
#define db double
#define rep(i,t) for(ll i=0;i<t;i++)
using namespace std;
long long prime(int n)
{
    if (n == 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
       return 0;

    for (ll i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return 0;
        }
    }
    return 1;
}
template <typename T>
void print_vector(vector <T> &vec)
{
    for(auto elem:vec)
    cout<<elem;

    cout<<endl;
}
template <typename T>
void print_vector_rev(vector <T> &vec)
{
    for(auto it=vec.rbegin;it!=vec.rend;it++)
    cout<<*it<<endl;

    cout<<endl;
}
template <typename T>
void sort_inc(vector <T> &vec)
{
    sort(vec.begin(),vec.end());
}
template <typename T>
void sort_dec(vector <T> &vec)
{
    sort(vec.rbegin(),vec.rend());
}
template <typename T>
void inp(T &a)
{
    cin>>a;
}
template <typename T>
void inp(T &a,T &b)
{
    cin>>a>>b;
}
template <typename T>
void inp(T &a,T &b,T &c)
{
    cin>>a>>b>>c;
}
template <typename T>
void inp(T &a,T &b,T &c,T &d)
{
    cin>>a>>b>>c>>d;
}
template <typename T>
void inp(T &a,T &b,T &c,T &d,T &e)
{
    cin>>a>>b>>c>>d>>e;
}
template <typename T>
void inp(vector <T> &vec)
{
    for(int i=0;i<vec.size();i++)
    cin>>vec[i];
}
void solve1(){
    ll n;
    inp(n);
    string s;
    cin>>s;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]=='a'&&s[i+1]=='b')
        {
            cout<<i+1<<" "<<i+2<<endl;
            return ;
        }
        if(s[i]=='b'&&s[i+1]=='a')
        {
            cout<<i+1<<" "<<i+2<<endl;
            return ;
        }
    }
    cout<<-1<<" "<<-1<<endl;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    ll t;
    cin>>t;
    rep(i,t){
        solve1();
    }
    return 0;
}
