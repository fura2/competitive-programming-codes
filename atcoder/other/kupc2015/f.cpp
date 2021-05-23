#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

struct node{
	node* l;
	node* r;
	node* par;
	char c;
	node():l(nullptr),r(nullptr),par(nullptr){}
};

string ans[100];

void dfs(node* v,int dep){
	ans[dep]+=v->c;
	if(isdigit(v->c)) return;
	dfs(v->l,dep+1);
	dfs(v->r,dep+1);
}

int main(){
	string s; cin>>s;

	stack<node*> S;
	for(char c:s){
		if(isdigit(c)){
			node* u=new node;
			u->c=c;
			S.push(u);
		}
		else{
			node* r=S.top(); S.pop();
			node* l=S.top(); S.pop();
			node* u=new node;
			u->c=c;
			u->l=l;
			u->r=r;
			S.push(u);
		}
	}
	node* root=S.top();

	dfs(root,0);

	for(int dep=99;dep>=0;dep--){
		reverse(ans[dep].begin(),ans[dep].end());
		cout<<ans[dep];
	}
	cout<<'\n';

	return 0;
}
