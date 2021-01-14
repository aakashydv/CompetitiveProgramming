#include<bits/stdc++.h>
using namespace std;

// handles range updates and range queries using lazy propagation
// 1 based indexing

class segmentTree{
	public:
		int n;
		vector < int > t,lazy;

		segmentTree(int sz, vector < int > &a){
			n = sz;
			t.assign(4*sz,0);                                // can be problematic (Initialized with 0 each NODE ) 
			lazy.assign(4*sz,0);
			build(a,1,1,n);
			return;
		}

		void build(vector < int > &a, int v, int tl, int tr) {
			if (tl == tr) {
			    t[v] = a[tl];
			} else {
			    int tm = (tl + tr) / 2;
			    build(a, v*2, tl, tm);
			    build(a, v*2+1, tm+1, tr);
			    t[v] = t[v*2] + t[v*2+1];
			}
		}

		int sum(int v, int tl, int tr, int l, int r) {
			if (l > r) 
			    return 0;
			if (l == tl && r == tr) {
			    return t[v];
			}
			int tm = (tl + tr) / 2;
			return sum(v*2, tl, tm, l, min(r, tm))
			       + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
			}

		void push(int v) {
			t[v*2] += lazy[v];
			lazy[v*2] += lazy[v];
			t[v*2+1] += lazy[v];
			lazy[v*2+1] += lazy[v];
			lazy[v] = 0;
		}

		void update(int v, int tl, int tr, int l, int r, int addend) {
			if (l > r) 
			    return;
			if (l == tl && tr == r) {
			    t[v] += addend;
			    lazy[v] += addend;
			} else {
			    push(v);
			    int tm = (tl + tr) / 2;
			    update(v*2, tl, tm, l, min(r, tm), addend);
			    update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
			    t[v] = t[v*2] + t[v*2+1];
			}
		}

		int query(int v, int tl, int tr, int l, int r) {
			if (l > r)
			    return 0;
			if (l <= tl && tr <= r)
			    return t[v];
			push(v);
			int tm = (tl + tr) / 2;
			return query(v*2, tl, tm, l, min(r, tm)) + query(v*2+1, tm+1, tr, max(l, tm+1), r);
			}

};

int main(){
	return 0;
}
