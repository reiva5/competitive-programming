// Bismillaahirrahmaanirrahiim
/* Author   : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define jehian using
#define mau namespace
#define libur std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(0);}

jehian mau libur;
/* MACROS FOR TYPE */
typedef long l;
typedef long double ld;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

/* MACROS FOR PRINT */
#define nl printf("\n");
#define sp printf(" ");

/* MACROS FOR FUNCTION AND METHOD */
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) memset((x), (y), sizeof(x))

/* MACROS FOR ATTRIBUTE */
#define fi first
#define se second

/* MACROS FOR SCAN */
#define scc(x) scanf("%c", &x)
#define scd(x) scanf("%Lf", &x)
#define scf(x) scanf("%f", &x)
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scld(x) scanf("%Lf", &x)
#define scui(x) sci(x)
#define scul(x) scl(x)
#define scull(x) scll(x) 

int prime[78498];
bool isPrime[1000001];
ll dp[100001];
ll data[100001];
int size_prime = 0;

int _b, _p;
ll _ret;
ll tmp;
ll res = 0;
ll wehe = 1;
ll i, j;
int T;
ll A, B;
ll awal;
ll cnt;
ll it;

ll pangkat(ll &b, int &p){
    _b = b;
    _p = p;
    _ret = 1;
    for (; _p; _p >>= 1, _b = (_b * _b)){
        if (_p & 1) _ret = (_ret * _b);
    }
    return _ret;
}


int main(){
    /* SIEVE */
    memset(isPrime, true, sizeof isPrime);
    isPrime[0] = isPrime[1] = false;
    for (i = 2; i <= 1000000; ++i){
        if (isPrime[i]){
            prime[size_prime++] = i;
            for (j = 2; i*j <= 1000000; ++j){
                isPrime[i*j] = false;
            }
        }
    }

    sci(T);
    scll(A); scll(B);

    while (T--){
        scll(tmp);

        for (i = 0; i <= 100000; ++i){
            dp[i] = 1;
        }

        res = 0;
        for (i = A; i <= B; ++i){
            data[i-A] = i;
        }

        for (it = 0; it < size_prime; ++it){
            awal = A + ((prime[it]-A%prime[it]))%prime[it];
            for (i = awal; i <= B; i += prime[it]){
                cnt = 0;
                while (!(data[i-A]%prime[it])){
                    data[i-A] /= prime[it];
                    ++cnt;
                }
                if (prime[it] != tmp){
                    dp[i-A] *= (cnt+1);
                }
            }
        }

        for (i = A; i <= B; ++i){
            if (data[i-A] > 1 && data[i-A] != tmp){
                dp[i-A] *= 2;
            }
        }

        for (ll i = A; i <= B; ++i){
            res += dp[i-A];
        }
        cout << res << endl;
    }
    return 0;
} 