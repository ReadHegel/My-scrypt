#include<bits/stdc++.h>

using namespace std;



struct monoque{
	queue <int> q; //typ danych nale¿y ustawiæ w tym miejscu 
	deque <int> dq;
	
	void insert(int value){
    		q.push(value);
    		while(!dq.empty() && dq.back()>value)	dq.pop_back(); //kolejka daje minimum ">", aby dawa³a maximum nale¿y zmieniæ znak na "<"
   		dq.push_back(value);
	}
	
	void pop(){
		if(q.empty())return;
    		auto x = q.front(); q.pop(); 
    		if(dq.front() == x)dq.pop_front(); 
	}
	
	void clear(){
    		dq.clear();
    		while(!q.empty()) q.pop();  
	}
		
	int minn(){
		if(q.empty())return -1;
    		return dq.front();
	}
	
	bool empty(){
		if(q.empty()) return true;
		else return false;
	}
	
};

monoque Q;

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}

