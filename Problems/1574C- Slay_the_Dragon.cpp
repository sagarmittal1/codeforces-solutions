//LINK : https://codeforces.com/problemset/problem/1574/C

#include<bits/stdc++.h>

using namespace std;

#define int long long

signed  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n;

    int sum = 0;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    cin >> m;

    sort(a.begin(), a.end());

    while (m--) {

        int x, y;
        cin >> x >> y;

        int low = 0;
        int high = n - 1;

        while (high - low > 1) {
            int mid = (high + low) / 2;
            if (a[mid] > x) {
                high = mid - 1;
            }
            else low = mid;
        }

        int k;

        if (a[high] <= x) {
            k = a[high];
        }
        else k = a[low];

        int ans = 0, sum1 = sum - k;

        if (k < x) {
            ans += (x - k);
        }
        if (sum1 < y) {
            ans += y - sum1;
        }
        low = 0;
        high = n - 1;

        while (high - low > 1) {
            int mid = (high + low) / 2;
            if (a[mid] <= x) {
                low = mid + 1;
            }
            else high = mid;
        }

        int k1;
        if (a[low] > x) {
            k1 = a[low];
        }
        else k1 = a[high];

        int ans1 = 0, sum2 = sum - k1;

        if (k1 < x) {
            ans1 += (x - k1);
        }

        if (sum2 < y) {
            ans1 += y - sum2;
        }

        ans = min(ans, ans1);
        cout << ans << endl;;

    }
    return 0;

}