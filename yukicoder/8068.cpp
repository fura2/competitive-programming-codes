/*
解説をデコードすると次のようになる

base64でデコードする
fileコマンドで形式を確認する
鍵が掛かっているが、エスパーしてyukiと入力する。
あるいは、全探索ツールを使って破る。fcrackzipなど。
問題文のmarkdownが得られる
連続する9文字が独立かどうか調べる。
ところが、厳しい提出コード制限がある
親切にテストケースのファイル名が書かれている
厳しい制限を掛ける入出力ファイル名は、evulから始まっている
evilから始まるテストケースは、WAになっても全体ではAC判定となる
よって、コード制限に関しては、ifを取り除くだけで十分である。論理演算子・三項演算子を駆使してがんばる。
ちなみにevilケースはwhitespace,C等でAC出来る。

:wq
*/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	bool ok=false;
	rep(i,n-8) ok|=set<char>(s.begin()+i,s.begin()+i+9).size()==9;
	puts(ok?"Yes":"No");

	return 0;
}
