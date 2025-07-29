#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7; // Nếu đề yêu cầu lấy modulo
const int N = 1e6 + 5;

ll derange[N];

int main() {
    int n;
    cin >> n;

    derange[0] = 1;
    derange[1] = 0;
    for (int i = 2; i <= n; ++i) {
        derange[i] = (1LL * (i - 1) * (derange[i - 1] + derange[i - 2])) % MOD;
    }

    cout << derange[n] << '\n';
}
