
//Problem : https://codeforces.com/contest/1419/problem/D2

#include <bits/stdc++.h>
#define ll long long
#define db double
#define rep(i, t) for (ll i = 0; i < t; i++)
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
void print_vector(vector<T> &vec)
{
    for (auto elem : vec)
        cout << elem<<" ";

    cout << endl;
}
template <typename T>
void print_vector_rev(vector<T> &vec)
{
    for (auto it = vec.rbegin; it != vec.rend; it++)
        cout << *it << endl;

    cout << endl;
}
template <typename T>
void sort_inc(vector<T> &vec)
{
    sort(vec.begin(), vec.end());
}
template <typename T>
void sort_dec(vector<T> &vec)
{
    sort(vec.rbegin(), vec.rend());
}
template <typename T>
void inp(T &a)
{
    cin >> a;
}
template <typename T>
void inp(T &a, T &b)
{
    cin >> a >> b;
}
template <typename T>
void inp(T &a, T &b, T &c)
{
    cin >> a >> b >> c;
}
template <typename T>
void inp(T &a, T &b, T &c, T &d)
{
    cin >> a >> b >> c >> d;
}
template <typename T>
void inp(T &a, T &b, T &c, T &d, T &e)
{
    cin >> a >> b >> c >> d >> e;
}
template <typename T>
void inp(vector<T> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cin >> vec[i];
}
void solve1()
{
    ll n;
    inp(n);
    vector<ll> a(n);
    inp(a);
    if (n == 1 || n == 2)
    {
        cout << 0 << endl;
        print_vector(a);
    }
    else
    {
        sort(a.begin(), a.end());
        if (n % 2 == 0)
        {
            vector<ll> ans(n);
            int k = n / 2 - 1;
            ans[0]=a[k];k++;
            for (int i = 1; i < n; i += 2)
            {
                ans[i] = a[k];
                k++;
            }
            k = 0;
            ll ans_val = 0;
            for (int i = 2; i < n; i+=2)
            {
                ans[i] = a[k];
                if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])
                {
                    ans_val++;
                }
                k++;
            }
            cout << ans_val << endl;
            print_vector(ans);
        }
        else
        {
            vector<ll> ans(n);
            int k = n / 2;
            for (int i = 0; i < n; i += 2)
            {
                ans[i] = a[k];
                k++;
            }
            k = 0;
            ll ans_val = 0;
            for (int i = 1; i < n; i += 2)
            {
                ans[i] = a[k];
                if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])
                {
                    ans_val++;
                }
                k++;
            }
            cout << ans_val << endl;
            print_vector(ans);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll t;
    // cin>>t;
    t = 1;
    rep(i, t)
    {
        solve1();
    }
    return 0;
}
