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
#define pcl pair<char,ll>

deque< pair<char,ll> > data;
deque< pair<char,ll> > temp;
int main(){
	ll N;
	scll(N);
	for (ll i = 0; i < N; ++i){
		ll A, B, K;
		scll(A); scll(B); scll(K);
		ll a, b;
		a = A;
		b = B;
		while (B > 0 && A >= 0){
			if (B > 0){
				data.pb(mp('P',min(B,K)));
				B -= K;
			}
			if (A){
				data.pb(mp('L',1));
				--A;
			} else {
				--A;
			}
		}
		if (A > 0){
			data.push_front(mp('L',1));
			--A;
		}
		while (A > 0 && !data.empty()){
			if (!data.empty() && data.front().fi != 'L'){
				ll cnt = data.front().se;
				ll hit = 0;
				for (ll i = 0; i < cnt-1 && A > 0; ++i){
					temp.pb(mp('P',1));
					temp.pb(mp('L',min(A, (ll) 2)));
					A -= min(A, (ll) 2);
					++hit;
				}
				temp.pb(mp('P',cnt-hit));
				data.pop_front();
			} else {
				temp.pb(mp('L',2));
				--A;
				data.pop_front();
			}
		}
		if (A > 0 || B > 0){
			cout << "mustahil" << endl; 
		} else {
			while (!data.empty()){
				temp.pb(data.front());
				data.pop_front();
			}
			bool salah = false;
			deque<pcl>::iterator iit;
			ll hehe[256];
			hehe['P'] = hehe['L'] = 0;
			for (iit = temp.begin(); iit != temp.end() && !salah; ++iit){
				if (iit->fi == 'L' && iit->se > 2){
					salah = true;
				} else if (iit->fi == 'P' && iit->se > K){
					cerr << "disini" << endl;
					salah = true;
				} else {
					hehe[iit->fi] += iit->se;
				}
			}
			if (!salah && hehe['L'] == a && hehe['P'] == b){
				for (auto it : temp){
					for (ll i = 0; i < it.se; ++i){
						cout << it.fi;
					}
				}
			} else {
				cout << "mustahil";
			}
			cout << endl;
		}
		data.clear();
		temp.clear();
	}
	return 0;
}