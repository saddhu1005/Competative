#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1000000007

ll f[1000001];

ll pow(ll a, ll b, ll MOD)
{
    ll x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x * y);
            if (x > MOD)
                x %= MOD;
        }
        y = (y * y);
        if (y > MOD)
            y %= MOD;
        b /= 2;
    }
    return x;
}

/* Modular Multiplicative Inverse
     Using Euler's Theorem
     a^(phi(m)) = 1 (mod m)
     a^(-1) = a^(m-2) (mod m) */
ll InverseEuler(ll n, ll MOD)
{
    return pow(n, MOD - 2, MOD);
}

ll nCr(ll n, ll r, ll MOD)
{

    return (f[n] * ((InverseEuler(f[r], MOD) * InverseEuler(f[n - r], MOD)) % MOD)) % MOD;
}

ll dpncr(ll n, ll r, ll MOD)
{
    if (r == 0)
        return 1;
    ll C[r + 1];

    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = min(i, (int)r); j > 0; --j)
        {
            C[j] = (C[j] + C[j - 1]) % MOD;
        }
    }

    return C[r];
}
int main()
{
    f[0] = 1;
    for (int i = 1; i <= 100000; i++)
        f[i] = (f[i - 1] * i) % INF;
    int n = 99999;
    int r = 100;
    cout << nCr(n, r, INF) << " " << dpncr(n, r, INF) << endl;
}
