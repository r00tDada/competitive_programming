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


// Bellam Ford Algorithm
// Time Complexity = O(V*E)
// Space Complexity = O(V)

const int N = 1e5 + 5;
const int INF = INT64_MAX;
vector<int> adj[N];
int dist[N];
vector<int> parent(N, -1);

signed main() {
	rootdada;
	int vertices, edges;
	cin >> vertices >> edges;
	rep(i, 0, edges)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[i].push_back(x);
		adj[i].push_back(y);
		adj[i].push_back(w);
	}
	rep(i, 0, vertices)
	{
		dist[i] = INF;
	}


	int src = 0;
	dist[src] = 0;
	int x;
	for (int i = 0; i < vertices ; i++)
	{
		int flg = 0;
		int j = 0;
		x = -1;
		while (adj[j].size() != 0)
		{
			if (dist[adj[j][0]] != INF && (dist[adj[j][0]] + adj[j][2] < dist[adj[j][1]]))
			{
				dist[adj[j][1]] = dist[adj[j][0]] + adj[j][2];
				parent[adj[j][1]] = adj[j][0];
				flg = 1;
				x = adj[j][1];
			}
			j++;
			// rep(i, 0, vertices)
			//         cout
			//     << dist[i] << " ";
			// cout << endl;
		}

		if (flg == 0)
			break;
	}
	if (x == -1)
	{
		rep(i, 0, vertices) {
			cout << i << " " << dist[i] << " " << parent[i] << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "Negative cycle\n";
	}
}