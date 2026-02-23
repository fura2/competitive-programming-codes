#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

double memo[40][40];

double dfs(int m,int n){
	if(n==0) return 0;

	if(memo[m][n]!=-1) return memo[m][n];

	double& res=memo[m][n];
	res=1.0/m*(dfs(m-1,n-1)+1);              // 次にめくるべきカードをめくる
	res+=(n-1.0)/m*(dfs(m-1,n-1)+3);         // それ以外の数が書かれたカードをめくる
	if(m>n) res+=1.0*(m-n)/m*(dfs(m-1,n)+2); // 白紙のカードをめくる
	return res;
}

int main(){
	string s,t; cin>>s>>t;
	int len=s.length();
	{
		string tmp;
		bool used[128]={};
		for(char c:s){
			if(t.find(c)==string::npos && !used[c]){
				tmp+=c;
				used[c]=true;
			}
		}
		s=tmp;
	}
	int n=s.length(),m=36-t.length();

	// 裏側で並べられた m 枚のカードがある
	// そのうち n 枚には 1, 2, ..., n の番号が書かれていて, それ以外は白紙
	// 裏側のカードを 1 枚選んでめくる操作を繰り返す
	// ・1 または「すでに表になっている数の最大値 + 1」がめくれた場合, そのカードは表のままにする
	// ・それ以外の場合, カードの位置を覚えて裏に戻す
	// 1, 2, ..., n が全部めくれたら終了
	// カードをめくる回数を最小化する戦略をとったときのその期待値を求める

	rep(i,40) rep(j,40) memo[i][j]=-1;
	printf("%.9f\n",len-n+dfs(m,n));

	return 0;
}
