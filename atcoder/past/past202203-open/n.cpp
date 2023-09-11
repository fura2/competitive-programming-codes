#include "template.hpp"

const double PI = acos(-1);
const complex<double> I = complex<double>(0, 1);

const int m = 19;
complex<double> omega; // exp(2πi/(2^m))
vector<complex<double>> omegas; // 1, ω, ω^2, ..., ω^{2^m-1}

vector<complex<double>> fft_rec(int n, vector<complex<double>> A, int sgn) {
    if (n == 0) {
        return {A[0]};
    }

    vector<complex<double>> A_even(1 << (n - 1)), A_odd(1 << (n - 1));
    rep (j, 1 << (n - 1)) {
        A_even[j] = A[2 * j];
        A_odd[j] = A[2 * j + 1];
    }
    vector<complex<double>> A_hat_even = fft_rec(n - 1, A_even, sgn);
    vector<complex<double>> A_hat_odd = fft_rec(n - 1, A_odd, sgn);

    vector<complex<double>> A_hat(1 << n);
    rep (k, 1 << n) {
        int idx = (sgn * k) % (1 << n);
        if (idx < 0) idx += 1 << n;
        A_hat[k]
            = A_hat_even[k % (1 << (n - 1))] + omegas[idx << (m - n)] * A_hat_odd[k % (1 << (n - 1))];
    }
    return A_hat;
}

// assume |A| = 2^n
vector<complex<double>> fft(int n, vector<complex<double>> A) {
    return fft_rec(n, A, -1);
}

// assume |A| = 2^n
vector<complex<double>> ifft(int n, vector<complex<double>> A) {
    auto res = fft_rec(n, A, 1);
    rep (i, 1 << n) res[i] /= 1 << n;
    return res;
}

int main() {
    omega = exp(2 * PI * I / double(1 << m));
    omegas.resize(1 << m);
    omegas[0] = 1;
    rep (i, (1 << m) - 1) {
        omegas[i + 1] = omegas[i] * omega;
    }

    int n;
    cin >> n;
    vector<int> A(n);
    rep (i, n) cin >> A[i];

    vector<complex<double>> f(1 << m), g(1 << m);
    rep (i, n) {
        f[A[i]] += 1;
        g[(1 << (m - 1)) - A[i]] += 1;
    }
    f = fft(m, f);
    g = fft(m, g);
    rep (i, 1 << m) f[i] *= g[i];
    f = ifft(m, f);

    int ans = 0;
    rep (i, 1 << m) {
        if (real(f[i]) > 1e-3) ans++;
    }
    cout << ans << endl;

    return 0;
}
