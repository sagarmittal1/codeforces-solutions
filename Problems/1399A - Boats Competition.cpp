// https://codeforces.com/contest/1399/problem/C

#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define endl "\n"

typedef long long ll;
typedef vector<int> vi;

int main()
{
    fast;

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vi v(n);

        for (int i = 0; i < n; i++) cin >> v[i];
        sort(all(v));

        int ans = 0;
        for (int k = 2; k <= 100; k++) {
            int cnt = 0;
            int i = 0, j = n - 1;
            while (i < j) {
                if (v[i] + v[j] == k)  {
                    cnt++;
                    i++;
                    j--;
                } else if (v[i] + v[j] < k) {
                    i++;;
                } else {
                    j--;
                }
            }
            ans = max(ans, cnt);
        }
        cout << ans << endl;

    }

    return 0;
}