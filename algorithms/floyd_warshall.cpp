#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  // Common file
#include <ext/pb_ds/tree_policy.hpp>  // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define rep(i, a, b) for (__typeof((b)) i = (a); i < (b); i++)
#define nrep(i, a, b) for (__typeof((b)) i = (a); i > (b); i--)
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define ppi pair<int, int>
#define pppi pair<ppi, int>
#define vi vector<int>
#define vii vector<ppi>
#define viii vector<pppi>
#define vs vector<string>
#define pb push_back
#define bitcount __builtin_popcountll  // count no's of ones in a set bit
#define mem(x, val) memset((x), (val), sizeof(x));
#define sz(x) (int)x.size()
#define M_PI 3.14159265358979323846
#define int long long
#define rootdada                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define test \
  int T;     \
  cin >> T;  \
  while (T--)
#define MOD 1000000007
#define ordered_set                            \
  tree<int, null_type, less<int>, rb_tree_tag, \
       tree_order_statistics_node_update>

void __print(int x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T1, typename T2, typename T3>
void __print(const tuple<T1, T2, T3> &x) {cerr << '{'; __print(get<0>(x)); cerr << ','; __print(get<1>(x)); cerr << ','; __print(get<2>(x)); cerr << '}';}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


struct hash_pair
{
// use pair as key in unordered_map<pair<int,int>,int,hash_pair>;
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2> &p) const
	{
		auto hash1 = hash<T1> {}(p.first);
		auto hash2 = hash<T2> {}(p.second);
		return hash1 ^ hash2;
	}
};

int ceil_div(int a, int b) {
	return (a + b - 1) / b;
}


const int N = 1e3 + 5;
#define inf 1e15

int adj[N][N];
int dist[N][N];
int parent[N][N];


void printsolution(int vertices)
{
	rep(i, 0, vertices)
	{
		rep(j, 0, vertices)
		{
			if (dist[i][j] == inf)
				cout << "INF"
				     << " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

void printparent(int vertices)
{
	rep(i, 0, vertices)
	{
		rep(j, 0, vertices)
		{
			if (parent[i][j] == -1)
				cout << "NIL"
				     << " ";
			else
				cout << parent[i][j] << " ";
		}
		cout << "\n";
	}
}

void floydwarshall(int vertices) {

	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			if (i == j) {
				dist[i][j] = 0;
				parent[i][j] = -1;
			}
			else {
				dist[i][j] = adj[i][j];
				parent[i][j] = i;
			}
		}
	}
	for (int k = 0; k < vertices; k++) {
		for (int i = 0; i < vertices; i++) {
			for (int j = 0; j < vertices; j++) {
				if (dist[i][k] != inf && dist[k][j] != inf) {
					if (dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
						parent[i][j] = k;
					}
				}
			}
		}
		// If distance of any verex from itself
		// becomes negative, then there is a negative
		// weight cycle.
		rep(i, 0, vertices)
		{
			if (dist[i][i] < 0)
			{
				cout << "Contains negative cycle\n";
				return;
			}
		}
		// cout << k << "-----" << endl;
		// printsolution(vertices);
		// cout << endl;
		// printparent(vertices);
		// cout << endl;

	}
}



signed main() {
	rootdada;
	int V, m, q;
	cin >> V >> m >> q;
	for (int i = 0 ; i < V ; i++ )
		for (int j = 0; j < V ; j++ )
			adj[i][j] = inf;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u][v] = min(adj[u][v], w);
		adj[v][u] = min(adj[v][u], w);
	}

	floydwarshall(V);

	while (q--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		int ans = dist[u][v] >= inf ? -1 : dist[u][v];
		cout << ans << endl;
	}
}