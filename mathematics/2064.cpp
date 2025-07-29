#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 2e6 + 5; // đủ cho n <= 1e6

ll fact[MAX], inv_fact[MAX];

// Hàm mũ lũy thừa nhanh
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

// Tiền xử lý giai thừa và nghịch đảo giai thừa
void preprocess() {
    fact[0] = 1;
    for (int i = 1; i < MAX; ++i)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

ll catalan_mod(int n) {
    if (n % 2 != 0) return 0; // độ dài lẻ thì không có dãy ngoặc đúng
    int k = n / 2;
    ll res = fact[2 * k];
    res = res * inv_fact[k] % MOD;
    res = res * inv_fact[k + 1] % MOD;
    return res;
}

int main() {
    preprocess();
    int n;
    cin >> n;
    cout << catalan_mod(n) << '\n';
}
