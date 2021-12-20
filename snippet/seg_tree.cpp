#include <bits/stdc++.h>
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

struct segment_tree {
	vector<int> tree;
	vector<int> a;
	
	void init(int n) {
		int sz = 1;
		while (sz < n)
			sz *= 2;
		// edit the initialisation for tree
		tree.assign(2 * sz, INT64_MAX);
		a.resize(n + 1);
	}

	void build(string type, int node, int st, int ed) {
		if (st == ed) {
			tree[node] = min(a[st], tree[node]);
			return;
		}
		int mid = (st + ed) / 2;
		build(type, 2 * node, st, mid);
		build(type, 2 * node + 1, mid + 1, ed);
		// edit the logic for building tree
		if (type == "add")
			tree[node] = tree[2 * node] + tree[2 * node + 1];
		if (type == "min")
			tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
		if (type == "xor")
			tree[node] = tree[2*node]^tree[2*node+1];
		return;
	}

	void update(string type, int node, int st, int ed, int idx, int val) {
		if (st == ed) {
			tree[node] = val;
			a[idx] = val;
			return;
		}
		int mid = (st + ed) / 2;
		if (idx <= mid) {
			update(type, 2 * node, st, mid, idx, val);
		}
		else {
			update(type, 2 * node + 1, mid + 1, ed, idx, val);
		}
		// update logic
		if (type == "add")
			tree[node] = tree[2 * node] + tree[2 * node + 1];
		if (type == "min")
			tree[node] = min(tree[2 * node], tree[2 * node + 1]);
		if (type == "xor")
			tree[node] = tree[2*node]^tree[2*node+1];
		return;
	}

	int get_query(string type, int node, int st, int ed, int l, int r) {
		if (l <= st && ed <= r) {
			return tree[node];
		}
		if (st > r || ed < l) {
			// logic for when it lies outside the range.
			if (type == "add")
				return 0;
			if (type == "min")
				return INT64_MAX;
			if (type == "xor")
				return 0;
		}
		int mid = (st + ed) / 2;
		int s1 = get_query(type, 2 * node, st, mid, l, r);
		int s2 = get_query(type, 2 * node + 1, mid + 1, ed, l, r);
		// edit the method for the query.
		if (type == "add")
			return s1 + s2;
		if (type == "min")
			return min(s1, s2);
		if (type == "xor")
			return s1^s2;
		return 0;
	}
} st;


signed main() {
	rootdada;
	int n, q;
	cin >> n >> q;
	st.init(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> st.a[i];
	}
	string type = "xor";
	st.build(type, 1, 1, n);
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << st.get_query(type, 1, 1, n, l, r) << endl;
	}
}

