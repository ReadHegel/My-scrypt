#include <bits/stdc++.h>

using namespace std;

const int Size = 1000005;
struct FandU{
	
	int oj[Size];
	int roz[Size];
	
	void initiation(){
		for(int i=0; i<Size; i++){
			roz[i]++;	
			oj[i]=i;
		}
	}
	
	int F(int v){
		if(oj[v]!=v){
			int wynik=F(oj[v]);
			oj[v]=wynik;
			return wynik;
		}
		else return v;	
	}

	void U(int a, int b){
		a = F(a); b = F(b);
		if(roz[a] < roz[b]){
			roz[b]+=roz[a];
			oj[a]=b;
		}
		else{
			roz[a]+=roz[b];
			oj[b]=a;
		}
	}
};

FandU x;

int main(){
	std::ios_base::sync_with_stdio(0);
	return 0;
}
