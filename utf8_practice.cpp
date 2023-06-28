#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(void){
  string instr;  // 入力文字列
  stringstream outstr;  //出力文字列

  cin >> instr;

  const char* strptr = instr.c_str();  // 入力文字列のポインタ(char)
  int strsize = instr.size() - 1;  // 入力文字列のサイズ
  int ptrpos = 0;  // ポインタの現在位置

  while(ptrpos <= strsize){
    // 上位1bit目が0なら1byteの文字
    if((strptr[0] & 128) == 0){
      outstr << instr.substr((ptrpos), 1);
      ptrpos++;
    }

    // 上位1bit目が1の場合はbyte数を計算する
    else{
      int bytesize = 1;  // 文字のサイズ
      bool errorflag = true;

      // 上位2bit目から0がある位置を探す
      for(int i = 64; i > 0; i = i >> 1){
        bytesize++;

        // 検索箇所が0ならエラーフラグを偽にしてループを抜ける
        if((strptr[0] & i) == 0){
          errorflag = false;
          break;
        }
      }

      if(errorflag){
        cout << "Error!!" << endl;
        return 0;
      }

      outstr << instr.substr((ptrpos), bytesize);
      strptr++;
      ptrpos += bytesize;
    }
  }

  cout << outstr.str() << endl;

  return 0;
}
