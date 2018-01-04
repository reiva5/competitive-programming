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
typedef pair<ld,ld> pld;

/* MACROS FOR PRINT */
#define nl printf("\n");
#define sp printf(" ");

/* MACROS FOR FUNCTION */
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define eb emplace_back
#define SQR(x) (x)*(x)
#define CUBE(x) SQR(x)*(x)
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

const ld g = 9.81;
const ld PI = acos(-1);

ld theta(ld x){
	return x/180.00*PI;
}

bool isSafe(ld v0, ld sudut, ld x1, ld h1, ld h2){
	ld t = x1/(v0*cos(theta(sudut)));
	ld y = v0*t*sin(theta(sudut)) - 0.5*g*SQR(t);
	return h1+1 <= y && y <= h2-1;
}

int main(){
	ll N;
	scll(N);
	while (N--){
		ld v0, sudut, x1, h1, h2;
		cin >> v0 >> sudut >> x1 >> h1 >> h2;
		cout << (isSafe(v0, sudut, x1, h1, h2) ? "Safe" : "Not Safe") << endl;
	}
	return 0;
}