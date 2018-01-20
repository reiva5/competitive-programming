/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define Jehian using
#define Norman namespace
#define Saviero std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(0);}

Jehian Norman Saviero;

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
#define nl printf("\n")
#define sp printf(" ")

/* MACROS FOR FUNCTION AND METHOD */
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define eb emplace_back
#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) for(int _je = sizeof(x)/sizeof(x[0]); _je--;) x[_je] = y
#define SQR(x) (x)*(x)
#define CUBE(x) SQR(x)*(x)
#define ALL(x) (x).begin(), (x).end()
#define ALLSIZE(x,n) (x), (x)+(n)

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

const ll MD = 1e9+7;
string A;
ll pindah[1005];
ll fact[5005];
ll rfact[5005];
vll anggota[1005];
ll K;
ll res = 0;
bool stop = false;

ll powMod(ll a, ll b){
	ll res = 1;
	for (; b; b >>= 1, a = SQR(a)%MD) {
		if (b & 1) res = (res*a)%MD;
	}
	return res%MD;
}

ll C(ll N, ll K) {
	if (N >= K && K >= 0) {
		return (((fact[N] * rfact[N-K]) % MD) * rfact[K]) % MD;
	}
	return 0;
}

void preCompute() {
	fact[0] = 1;
	for (ll i = 1; i <= 5000; ++i) {
		fact[i] = fact[i-1]*i;
		fact[i] %= MD;
	}
	for (ll i = 0; i <= 5000; ++i) {
		rfact[i] = powMod(fact[i], MD-2);
	}
}

bool isAllOne(ll idx) {
	for (ll i = idx; i < A.size(); ++i) {
		if (!(A[i]-48)) {
			return false;
		}
	}
	return true;
}

ll rec(ll idx) {
	if (pindah[idx]) {
		return pindah[idx];
	} else {
		ll tmp = idx;
		ll cnt = 0;
		while (idx) {
			cnt += (idx%2);
			idx /= 2;
		}
		if (pindah[cnt] || cnt == 1) {
			return 1 + pindah[cnt];
		} else {
			pindah[cnt] = 1 + rec(cnt);
			return pindah[cnt];
		}
	}
}

void nextPreCompute(){
	RESET(pindah);
	pindah[1] = 0;
	for (ll i = 2; i <= 1000; i *= 2){
		pindah[i] = 1;
	}
	for (ll i = 2; i <= 1000; ++i) {
		if (!pindah[i]) {
			pindah[i] = rec(i);
		}
	}
}

string toBiner(ll i) {
	string hehe;
	while (i) {
		hehe.pb(i%2+48);
		i /= 2;
	}
	reverse(ALL(hehe));
	return hehe;
}

void bacaInput(){
	A.clear();
	cin >> A;
	scll(K);
}

void debungging_1();
void ADA_MANTAN();
ll MAXI = -1;

int main(){
	preCompute();
	nextPreCompute();
	for (ll i = 2; i <= 1000; ++i) {
		MAXI = max(MAXI,pindah[i]);
		anggota[pindah[i]].pb(i);
	}
	bacaInput();
	if (K == 0) {
		cout << 1 << endl;
		return 0;
	} else if (K == 1) {
		cout << A.size()-1 << endl;
		return 0;
	}
	--K;
	if (!anggota[K].empty()){
		if (!isAllOne(0)){
			ll cnt = 0;
			ll sz = A.size();
			for (ll i = 0; i < sz && !stop; ++i) {
				if (A[i] - 48){
					stop = isAllOne(i);
					if (!stop) {
						for (auto it : anggota[K]) {
							res += C(sz-i-1, it-cnt);
							// if (C(sz-i-1, it-cnt)) {
							// 	cerr << "C(" << sz-i-1 << "," << it-cnt << ") = " << C(sz-i-1, it-cnt) << endl; 
							// }
							res %= MD;
						}
					} else {
						cerr << res << endl;
						for (auto it : anggota[K]) {
							res += C(sz-i, it-cnt);
							// if (C(sz-i, it-cnt)) {
							// 	cerr << "C(" << sz-i << "," << it-cnt << ") = " << C(sz-i, it-cnt) << endl; 
							// }
							res %= MD;
						}
					}
					++cnt;
				}
			}
			if (!stop){
				for (auto it : anggota[K]) {
					res += (cnt == it);
				}
			}
			cout << res << endl;
		} else {
			for (auto& it : anggota[K]) {
				res += C(A.size(), it);
				res %= MD;
			}
			cout << res << endl;
			return 0;
		}
	} else {
		cout << 0 << endl;
	}
	return 0;
}