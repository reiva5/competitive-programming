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

ll in[100100];
ll _max[100100];
ll _min[100100];
ll max_atas[100100];
ll max_bawah[100100];
ll min_atas[100100];
ll min_bawah[100100];

int main(){
	ll n;
	ll data[3];
	scll(n);
	ll toMax, toMin;
	toMax = toMin = 0;
	for (ll i = 0; i < 3; ++i) scll(data[i]);
	for (ll i = 0; i < 3; ++i){
		if (data[i] >= 0){
			toMax += data[i];
		} else {
			toMin += data[i];
		}
	}
	for (ll i = 0; i < n; ++i){
		scll(in[i]);
	}
	if (toMax == 0){
		ll tmp = *min_element(in,in+n);
		cout << toMin*tmp << endl;
	} else if (toMin == 0){
		ll tmp = *max_element(in,in+n);
		cout << toMax*tmp << endl;
	} else {
		max_atas[0] = in[0];
		min_atas[0] = in[0];
		for (ll i = 1; i < n; ++i){
			max_atas[i] = max(max_atas[i-1],in[i]);
			min_atas[i] = min(min_atas[i-1],in[i]);
		}
		max_bawah[n-1] = in[n-1];
		min_bawah[n-1] = in[n-1];
		for (ll i = n-1; i > 0; --i){
			max_bawah[i-1] = max(max_bawah[i],in[i-1]);
			min_bawah[i-1] = min(min_bawah[i],in[i-1]);
			cerr << min_bawah[i-1] << endl;
		}
		if (data[0] >= 0){
			if (data[2] >= 0){
				ll res = max_atas[0]*data[0] + in[0]*data[1] + max_bawah[0]*data[2];
				for (ll i = 0; i < n; ++i){
					res = max(res, max_atas[i]*data[0] + in[i]*data[1] + max_bawah[i]*data[2]);
				}
				cout << res << endl;
			} else {
				if (data[1] >= 0){
					ll res = max_atas[0]*(data[0]+data[1]) + min_bawah[0]*data[2];
					for (ll i = 0; i < n; ++i){
						res = max(res, max_atas[i]*(data[0]+data[1]) + min_bawah[i]*data[2]);
					}
					cout << res << endl;
				} else {
					ll res = max_atas[0]*(data[0]) + min_bawah[0]*(data[1]+data[2]);
					for (ll i = 0; i < n; ++i){
						res = max(res, max_atas[i]*(data[0]) + min_bawah[i]*(data[1]+data[2]));
					}
					cout << res << endl;					
				}
			}
		} else {
			if (data[2] < 0){
				ll res = min_atas[0]*data[0] + in[0]*data[1] + min_bawah[0]*data[2];
				for (ll i = 0; i < n; ++i){
					res = max(res, min_atas[i]*data[0] + in[i]*data[1] + min_bawah[i]*data[2]);
				}
				cout << res << endl;
			} else {
				if (data[1] < 0){
					ll res = min_atas[0]*(data[0]+data[1]) + max_bawah[0]*data[2];
					for (ll i = 0; i < n; ++i){
						res = max(res, min_atas[i]*(data[0]+data[1]) + max_bawah[i]*data[2]);
					}
					cout << res << endl;
				} else {
					ll res = min_atas[0]*(data[0]) + max_bawah[0]*(data[1]+data[2]);
					for (ll i = 0; i < n; ++i){
						res = max(res, min_atas[i]*(data[0]) + max_bawah[i]*(data[1]+data[2]));
					}
					cout << res << endl;
				}
			}
		}
	}
	return 0;
}