// thanks http://garnacha.techblog.jp/archives/45767709.html
/*
	たとえば, 辞書が {0, 1, 01} の場合,
		dp[0][][1] = 1
		dp[1][0][11] = 1
		dp[1][0][10] = 0
		dp[1][01][111] = 1
		dp[2][01][101] = 0
	となって, 起こりうる区切り位置を全て含む状態にのみ遷移するので重複カウントしない!!
*/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=1e9+7;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }
	mint &operator+=(const mint &m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	friend ostream &operator<<(ostream &os,const mint &m){ return os<<m.x; }
};

int main(){
	int n,L; cin>>n>>L;
	vector<int> w(n),len(n);
	rep(i,n){
		string s; cin>>s;
		len[i]=s.length();
		rep(j,len[i]) w[i]=2*w[i]+(s[j]-'0');
	}

	// end[S][T][b]  := ( 状態 [S][T] の次に bit b を立てた直後の位置が区切り位置になりうるかどうか )
	bool end[1<<7][1<<8][2]={};
	rep(S,1<<7) rep(T,1<<8) {
		rep(j,n){
			int k=len[j]-1;
			if(k>7 || (T>>k&1)==0) continue;

			int S_mask=S&((1<<k)-1); // S の下位 k bit
			int w_mask=w[j]>>1;      // w[j] の上位 k bit
			end[S][T][w[j]&1]|=(S_mask==w_mask);
		}
	}

	// dp[i][S][T] := ( i 文字目まで見たときに, 直前 7 文字が S で,
	//                  今使っている単語の開始位置としてありうる場所の集合が T であるような文字列の個数 )
	static mint dp[101][1<<7][1<<8];
	dp[0][0][1]=1;
	rep(i,L) rep(S,1<<7) rep(T,1<<8) {
		rep(b,2){ // add b
			int S2=((S<<1)&127)+b;
			int T2=((T<<1)&255)+(end[S][T][b]?1:0);
			dp[i+1][S2][T2]+=dp[i][S][T];
		}
	}

	mint ans=0;
	rep(S,1<<7) rep(T,1<<8) if(T&1) ans+=dp[L][S][T];
	cout<<ans<<endl;

	return 0;
}
