/* Author	: Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define jehian using
#define mau namespace
#define libur std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(NULL);}

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
typedef pair<double,double> pd;
typedef pair<ld,ld> pld;

/* MACROS FOR PRINT */
#define nl printf("\n");
#define sp printf(" ");

/* MACROS FOR FUNCTION */
#define pb push_back
#define mp make_pair
#define eb emplace_back

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
#define scld(x) cin >> x;
#define scui(x) sci(x)
#define scul(x) scl(x)
#define scull(x) scll(x)

ll n;
ld t;
pld data[1000];
ll cnt = 0;

ld DIV(ld a, ld b){
	a *= 1.00;
	b *= 1.00;
	if (b != 0){
		return (ld) a / (ld) b;
	} else {
		return t + (ld) 1.00;
	}
}

ld sum(ld c){
	ld res = 0;
	for (ll i = 0; i < n; ++i){
		res += DIV(data[i].fi,(data[i].se+c));
	}
	return res;
}

ld bef = 1e6;
ld binary_seacrh(ld a, ld b){
	++cnt;
	ld mid = (ld) ( a + b ) / (ld) 2.00;
	ld res = sum(mid);
	if (res-t > 0.00000000000001 && cnt <= 100){
		return binary_seacrh(mid,b);
	} else if (abs(res-t) <= 0.00000000000001 || cnt > 100){
		return mid;
	} else {
		return binary_seacrh(a,mid);
	}
}

int main(){
	scll(n); scld(t);
	ld MIN = -1e12;
	for (ll i = 0; i < n; ++i){
		scld(data[i].fi); scld(data[i].se);
		MIN = max(MIN,-data[i].se);
	}
	ld tmp = binary_seacrh(MIN,1000000000000000.123);
	cout << setprecision(9) << fixed << tmp << endl;
	cerr << setprecision(6) << fixed << sum(tmp) << endl;
	return 0;
}