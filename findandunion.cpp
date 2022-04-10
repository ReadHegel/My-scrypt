#include <bits/stdc++.h>

using namespace std;

struct FandU{
	
	vector<int> ojciec;
	vector<int> roz;
	
	FandU(int n){
		ojciec.resize(n+1); roz.resize(n+1);
		for(int i=0; i<n+1; i++){roz[i]++; ojciec[i]=i;}
	}
	
	int F(int v){
		return v == ojciec[v] ? v : ojciec[v] = F(ojciec[v]);
	}

	void U(int a, int b){
		a = F(a); b = F(b);
		if(roz[a] < roz[b])swap(a , b);
		roz[a]+=roz[b];
		ojciec[b]=a;
	}
};

FandU FU(5);

int main(){
	std::ios_base::sync_with_stdio(0);
	return 0;
}
