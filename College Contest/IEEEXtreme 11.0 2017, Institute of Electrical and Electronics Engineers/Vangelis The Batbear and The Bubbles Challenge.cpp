// Bismillaahirrahmaanirrahiim
/* Author   : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define jehian using
#define mau namespace
#define libur std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(0);}

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

/* MACROS FOR FUNCTION AND METHOD */
#define pb push_back
#define mp make_pair
#define eb emplace_back
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
 
class Graph{
    private:
        int V;
        list<int> *adj;
        bool cekLooping(int v, bool visited[], int parent);
    public:
        Graph(int V);
        void addEdge(int v, int w);
        bool adaLoop();
};
 
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w){
    adj[v].pb(w);
    adj[w].pb(v);
}
 
bool Graph::cekLooping(int v, bool visited[], int parent){
    visited[v] = true; 
    list<int>::iterator i;
    for (auto i : adj[v]){
        if (!visited[i]){
           if (cekLooping(i, visited, v)){
              return true;
           }
        } else if (i != parent){
           return true;
        }
    }
    return false;
}
 
bool Graph::adaLoop(){
    bool visited[V];
    RESET(visited);
    for (int u = 0; u < V; u++){
        if (!visited[u]){
            if (cekLooping(u, visited, -1)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ll T;
    scll(T);
    while (T--){
        ll N, M;
        ll A, B;
        scll(N); scll(M);
        Graph G(N);
        while (M--){
            scll(A); scll(B);
            G.addEdge(A,B);
        }
        cout << G.adaLoop() << endl;
    }
    return 0;
}