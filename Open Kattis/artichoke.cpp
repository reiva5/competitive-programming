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

ld func(ld p, ld a, ld b, ld c, ld d, ld k){
	return p*(sin(a*k+b)+cos(c*k+d)+2.00);
}

vector<ld> data;
int main(){
	ld p, a, b, c, d, n;
	cin >> p >> a >> b >> c >> d >> n;
	for (ld i = 1; i <= n; ++i){
		data.pb(func(p,a,b,c,d,i));
	}
	ld now = data[0];
	ld selisih_min = 0;
	for (ld i = 1; i < data.size(); ++i){
		if (now < data[i]){
			now = data[i];
		} else {
			selisih_min = max(selisih_min, now-data[i]);
		}
	}
	cout << setprecision(9) << fixed << selisih_min << endl;
	return 0;
}