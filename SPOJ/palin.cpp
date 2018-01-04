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

int main(){
	ll T;
	scll(T);
	while (T--){
		string s;
		cin >> s;
		if (s.size()%2 == 0){
			string tmp[2];
			for (ll i = 0; i < s.size()/2; ++i){
				tmp[0].pb(s[i]);
				tmp[1].pb(s[s.size()/2+i]);
			}
			string junk = tmp[0];
			reverse(junk.begin(),junk.end());
			if (tmp[1] < junk){
				cout << tmp[0]+junk << endl;
			} else {
				ll carry = 1;
				string res;
				for (ll i = tmp[0].size()-1; i >= 0; --i){
					if (tmp[0][i] + carry > '9'){
						res.pb('0');
						carry = 1;
					} else {
						res.pb(tmp[0][i] + carry);
						carry = 0;
					}
				}
				if (carry){
					res.pb('1');
				}
				reverse(res.begin(),res.end());
				if (res.size() > tmp[0].size()){
					for (ll i = 0; i < res.size()-1; ++i){
						cout << res[i];
					}
					cout << res.back();
					for (ll i = res.size()-2; i >= 0; --i){
						cout << res[i];
					}
					cout << endl;
				} else {
					junk = res;
					reverse(junk.begin(), junk.end());
					cout << res+junk << endl;
				}
			}
		} else {
			string tmp[2];
			for (ll i = 0; i < s.size()/2; ++i){
				tmp[0].pb(s[i]);
				tmp[1].pb(s[s.size()/2+i+1]);
			}
			string junk = tmp[0];
			reverse(junk.begin(),junk.end());
			if (tmp[1] < junk){
				cout << tmp[0]+s[s.size()/2]+junk << endl;
			} else {
				tmp[0].pb(s[s.size()/2]);
				ll carry = 1;
				string res;
				for (ll i = tmp[0].size()-1; i >= 0; --i){
					if (tmp[0][i] + carry > '9'){
						res.pb('0');
						carry = 1;
					} else {
						res.pb(tmp[0][i] + carry);
						carry = 0;
					}
				}
				if (carry){
					res.pb('1');
				}
				reverse(res.begin(),res.end());
				if (res.size() > tmp[0].size()){
					for (ll i = 0; i < res.size()-1; ++i){
						cout << res[i];
					}
					for (ll i = res.size()-2; i >= 0; --i){
						cout << res[i];
					}
					cout << endl;
				} else {
					for (ll i = 0; i < res.size()-1; ++i){
						cout << res[i];
					}
					cout << res[res.size()-1];
					for (ll i = res.size()-2; i >= 0; --i){
						cout << res[i];
					}
					cout << endl;
				}
			}
		}
	}
	return 0;
}