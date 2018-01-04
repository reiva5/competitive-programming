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
#define mp make_pair
#define eb emplace_back

/* MACROS FOR ATTRIBUTE */
#define fi first
#define se second


ll data[1000000];
ll N;
void prnt(){
	for (ll i = 0; i < N; ++i) printf("%lld ", data[i]);
	nl;
}

int main(){
	scanf("%lld", &N);
	for (ll i = 0; i < N; ++i){
		scanf("%lld", &data[i]);
	}
	ll jawab = 0;
	ll i = 0;
	ll j = N-1;
	while (i < j){
		while (i < N-1 && data[i+1] - data[i] > 0) ++i;
		while (j > 0 && data[j-1] - data[j] > 0) --j;
		if (i < j){
			if (data[j] < data[i]){
				jawab += (data[j]+1-data[j-1]);
				data[j-1] = data[j]+1;
				--j;
			} else {
				jawab += (data[i]+1-data[i+1]);
				data[i+1] = data[i]+1;
				++i;
			}
		}
	}
	printf("%lld\n", jawab);
	return 0;
}