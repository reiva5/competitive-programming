/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define Lost using
#define In namespace
#define Colour std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(0);}

Lost In Colour;

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

string prob;
int main(){
	ll TC;
	scll(TC);
	char it;
	scc(it);
	while (TC--){
		char x;
		scc(x);
		if (x == 'e'){
			scc(x);
			int bef = 0;
			int junk = 0;
			for (; scc(x), x != '\n'; ){
				it = x;
				if (it != ' '){
					junk = it-'a'+1;
				} else {
					junk = 0;
				}
				junk += bef;
				junk %= 27;
				if (junk){
					printf("%c", junk+'a'-1);
				} else {
					printf(" ");
				}
				bef = junk;
			}
		} else {
			scc(x);
			int bef = 0;
			int junk = 0;
			for (; scc(x), x != '\n'; ){
				it = x;
				if (it != ' '){
					junk = it-'a'+1;
				} else {
					junk = 0;
				}
				junk -= bef;
				while (junk < 0){
					junk += 27;
				}
				junk %= 27;
				if (junk){
					printf("%c", junk-1+'a');
				} else {
					printf(" ");
				}
				if (it != ' '){
					bef = it-'a'+1;
				} else {
					bef = 0;
				}
			}
		}
		nl;
	}
	return 0;
}