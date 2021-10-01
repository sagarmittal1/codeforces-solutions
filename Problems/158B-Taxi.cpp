//LINK : https://codeforces.com/problemset/problem/158/B

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE


    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    std::vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    int ans = 0;
    int c = 4;
    while (i <= j) {
        c -= v[j];
        j--;
        while (c != 0) {
            if (v[i] > c) {
                break;
            }
            c -= v[i];
            i++;
        }
        c = 4;
        ans++;
    }
    cout << ans << endl;

    return 0;
}