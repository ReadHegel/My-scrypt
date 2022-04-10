#include <bits/stdc++.h>

using namespace std;

const int inf = 2147483646;

struct SegTree{
	
	int leafcount = 1;
	vector<int> t;
	vector<int> lazy;
	
	SegTree(int n){
		while(leafcount<n)leafcount*=2;
		t.resize(2*leafcount);	
		lazy.resize(2*leafcount);
	}
	
	void Propagate(int v){
		t[v]+=lazy[v];
		if(v<leafcount){
			lazy[2*v]+=lazy[v];
			lazy[2*v+1]+=lazy[v];
		}
		lazy[v]=0;
	}
	
	void Add1(int a, int b, int lo, int hi, int v, int value){
		Propagate(v);
		if(b<a)return;
		if(a==lo && b==hi){
			lazy[v]+=value;
			Propagate(v);
			return;
		}
		int mid = (lo+hi)/2;
		Add1(a, min(mid, b), lo, mid, 2*v, value);
		Add1(max(a, mid+1), b, mid+1, hi, 2*v+1, value);
		t[v]=max( t[2*v] , t[2*v+1] );
	}
	
	void Add(int a, int b, int value){
		Add1(a, b, 0, leafcount-1, 1, value);
	}
	
	int maxx1(int a, int b, int lo, int hi, int v){
		if(b<a)return -inf;
		if(a==lo && b==hi)return t[v];
		int mid = (lo+hi)/2;
		int L = maxx1(a, min(b, mid), lo, mid, 2*v);
		int R = maxx1(max(a, mid+1), b, mid+1, hi, 2*v+1);
		return max(L, R);
	}
	
	int maxx(int a, int b){
		return maxx1(a, b, 0, leafcount-1, 1);
	}
	
};

SegTree t(10);

int main(){
	std::ios_base::sync_with_stdio(0);
	return 0;
}
