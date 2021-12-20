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
const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
vector<int> dist(N, INT64_MAX);
vector<int> parent(N, -1);
vector<int> processed(N, false);
vector<int> restore_path(int src, int dest)
{
	vector<int> path;
	for (int v = dest; v != src; v = parent[v])
		path.push_back(v);
	path.push_back(src);
	reverse(path.begin(), path.end());
	return path;
}

vector<int> dijkstra(int src, int V) {
	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
	pq.push({0, src});
	dist[src] = 0;
	parent[src] = src;
	while (!pq.empty()) {
		pair<int, int> f = pq.top();
		pq.pop();
		int u = f.second;
		int d = f.first;
		if (processed[u]) {
			continue;
		}
		processed[u] = true;
		for (auto it : adj[u]) {
			if (d != INT64_MAX && dist[u] + it.second < dist[it.first]) {
				dist[it.first] = dist[u] + it.second;
				parent[it.first] = u;
				pq.push({dist[it.first], it.first});
			}
		}
	}
	return dist;
}
signed main() {
	rootdada;
	int V, m;
	cin >> V >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u].pb({v, w});
		// adj[v].pb({u, w});
	}
	int src = 0;
	vector<int> distance = dijkstra(src, V);
	rep(i, 0, V)
	cout << i << " " << distance[i] << " " << parent[i] << endl;
	rep(i, 0, V)
	{
		cout << "0 - " << i << " => ";
		vector<int> printpath = restore_path(0, i);
		rep(i, 0, printpath.size())
		cout
		    << printpath[i] << " ";
		cout << endl;

		printpath.clear();
	}

}