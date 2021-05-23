#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int n;
string s;

int memo[101][101][2];

int dfs(int i,int dep,bool ch){ // ch : i 文字目を変更したかどうか
	if(dep<0) return INF;

	int& res=memo[i][dep][ch];
	if(res!=-1) return res;

	if(i==n) return res=(dep==0?0:INF);

	bool ok=true;
	{
		if(ch) s[i]=(s[i]=='('?')':'(');

		int cnt=dep;
		for(int j=i;j<n;j++){
			if(s[j]=='('){
				cnt++;
			}
			else{
				cnt--;
				if(cnt<0) ok=false;
			}
		}
		if(cnt!=0) ok=false;

		if(ch) s[i]=(s[i]=='('?')':'(');
	}
	if(ok) return res=0;

	int dep2=dep;
	if((s[i]=='(')!=ch) dep2++;
	else                dep2--;
	res=dfs(i+1,dep2,false)+1; // i 文字目を変更しない
	if(!ch){
		res=min(res,dfs(i,dep,true)+1); // i 文字目を変更する
	}
	return res;
}

int main(){
	cin>>s;
	n=s.length();

	memset(memo,-1,sizeof memo);
	cout<<dfs(0,0,false)<<'\n';

	return 0;
}
