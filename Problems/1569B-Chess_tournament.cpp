#include<bits/stdc++.h>

using namespace std;
#define int long long


signed  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int o = 0, t = 0, jj = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                o++;
            }
            else {t++; jj = i;}
        }
        if (t <= 2 && t != 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        std::vector<std::vector<char> > v(n, std::vector<char> (n));
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == '-') {
                    continue;
                }
                if (i == j) {
                    v[i][j] = 'X';
                }
                else {
                    if (s[i] == '1') {
                        v[i][j] = '=';
                    }
                    else {
                        if (i != jj && j > i && s[j] == '2' && c == 0) {
                            v[i][j] = '+';
                            v[j][i] = '-';
                            c = 1;
                        }
                        else if (i == jj && j < i && s[j] == '2' && c == 0) {
                            v[i][j] = '+';
                            v[j][i] = '-';
                            c = 1;
                        }
                        else v[i][j] = '=';
                    }
                }
            }
            c = 0;
        }
        for (auto i : v) {
            for (auto j : i) {
                cout << j;
            }
            cout << endl;
        }

    }


    return 0;

}