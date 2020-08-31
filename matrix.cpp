#include<bits/stdc++.h>
using namespace std;

class matrix{
	public:
		vector < vector < int > > mat;                    // stores the matrix

		matrix(int r,int c){
			mat.assign(r, vector < int > (c, 0));
		}

		void init(vector < vector < int > > &M){
			int r=M.size(),c=M[0].size();
			for(int i=0;i<r;++i){
				for(int j=0;j<c;++j)
					mat[i][j]=M[i][j];
			}
			return ;
		}

		matrix operator +(matrix const &M){
			int r=mat.size(), c=mat[0].size();
			assert(r == M.mat.size() && c == M.mat[0].size());
			matrix A(r,c);
			for(int i=0;i<r;++i){
				for(int j=0;j<c;++j)
					A.mat[i][j] = M.mat[i][j] + mat[i][j];
			} 
			return A;
		} 

		matrix operator *(matrix const &M){
			int r=mat.size(), c=M.mat[0].size();
			assert(mat[0].size() == M.mat.size());
			matrix A(r,c);
			for(int i=0;i<r;++i){
				for(int j=0;j<c;++j){
					for(int z=0;z<(int)mat[0].size();++z)
					    A.mat[i][j]+= mat[i][z]*M.mat[z][j];
				}
			} 
			return A;
		}

		void print(){
			int r=mat.size(),c=mat[0].size();
			for(int i=0;i<r;++i){
				for(int j=0;j<c;++j)
					cout<<mat[i][j]<<" ";
				cout<<"\n";
			}
		}

		matrix exp(matrix &M, int n){                // redundant as independent of class based implementation.
			if(n==1)
				return M;
			matrix M1= exp(M,n/2);
			M1 = M1*M1;
			if(n&1)
				M1 = M1*M;
			return M1;
		}
};


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	return 0;
}
