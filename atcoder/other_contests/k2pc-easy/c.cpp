#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

pair<int,int> f(int i){
	int x;
	for(x=1;x*(x+1)/2<i;x++);
	int y=i-x*(x-1)/2;
	return {x-y+1,y};
}

int g(int a,int b){
	return (a+b-2)*(a+b-1)/2+b;
}

int main(){
	int i,j; cin>>i>>j;

	auto p=f(i),q=f(j);
	cout<<g(p.first+q.first,p.second+q.second)<<'\n';

	return 0;
}
