#include<bits/stdc++.h>
using namespace std;

// handles point updates and range queries 
// 0 based indexing

class fenwick{             
	public:
		int n;
		vector < int > ft; 
		fenwick(int sz){              // can include an initial array here 
			n=sz; 
			ft.assign(sz,0);
		}

		int sum(int r){
			int ans=0;
			while(r >= 0){
				ans+=ft[r];
				r=(r&(r+1)) - 1;
			}
			return ans;
		}

		int getsum(int l,int r){
		    return sum(r)-sum(l-1);
		}

		void add(int r,int v){
			while(r < n){
				ft[r]+=v;
				r=r|(r+1);
			}	
			return ;
		}
};



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	return 0;
}
