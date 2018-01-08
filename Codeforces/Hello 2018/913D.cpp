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

int main(){
	ll N, T;
	scll(N);
	scll(T);
	ll kembali = T;
	pair<pll,ll> data[N];
	for (ll i = 0; i < N; ++i){
		scll(data[i].fi.fi);
		scll(data[i].fi.se);
		data[i].se = i+1;
	}
	sort(ALLSIZE(data,N));
	reverse(ALLSIZE(data,N));
	ll max_soal = 0;
	priority_queue< pair<pll,ll>, vector< pair<pll,ll> >, less< pair<pll,ll> > > pq, x;

	if (T >= data[0].fi.se){
		pq.push(mp(mp(data[0].fi.se,data[0].fi.fi),data[0].se));
		T -= data[0].fi.se;
		++max_soal;
	}
	ll soal_valid = max_soal;
	for (ll i = 1; i < N; ++i){
		if (max_soal < data[i].fi.fi){
			if (T >= data[i].fi.se){
				pq.push(mp(mp(data[i].fi.se,data[i].fi.fi),data[i].se));
				T -= data[i].fi.se;
				soal_valid += (data[i].fi.fi >= pq.size());
			} else if (!pq.empty() && data[i].fi.se < pq.top().fi.fi && data[i].fi.fi >= pq.size()){
				T -= data[i].fi.se;
				pq.push(mp(mp(data[i].fi.se,data[i].fi.fi),data[i].se));
				T += pq.top().fi.fi;
				pq.pop();
			}
			max_soal = max(max_soal, soal_valid);
		} else {
			break;
		}
	}
	cout << max_soal << endl;
	while (!pq.empty()){
		pq.pop();
	}
	T = kembali;
	ll cnt = 0, cnt_valid;
	if (T >= data[0].fi.se){
		pq.push(mp(mp(data[0].fi.se,data[0].fi.fi),data[0].se));
		T -= data[0].fi.se;
		++cnt;
	}
	cnt_valid = cnt;
	for (ll i = 1; i < N; ++i){
		if (cnt == max_soal) {
			cout << pq.size() << endl;
			string spasi = "";
			while (!pq.empty()){
				cout << spasi << pq.top().se;
				pq.pop();
				spasi = " ";
			}
			cout << endl;
			return 0;
		} else if (cnt < data[i].fi.fi) {
			if (T >= data[i].fi.se){
				pq.push(mp(mp(data[i].fi.se,data[i].fi.fi),data[i].se));
				T -= data[i].fi.se;
				cnt_valid += (data[i].fi.fi >= pq.size());
			} else if (!pq.empty() && data[i].fi.se < pq.top().fi.fi && data[i].fi.fi >= pq.size()){
				T -= data[i].fi.se;
				pq.push(mp(mp(data[i].fi.se,data[i].fi.fi),data[i].se));
				T += pq.top().fi.fi;
				pq.pop();
			}
			cnt = max(cnt, cnt_valid);
		}
	}
	cout << pq.size() << endl;
	string spasi = "";
	while (!pq.empty()){
		cout << spasi << pq.top().se;
		pq.pop();
		spasi = " ";
	}
	cout << endl;
	return 0;
}