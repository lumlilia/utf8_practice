#include <iostream>
#include <string>
#include <string.h>

using namespace std;


void output(const char* str, int len){
  char outstr[len + 1];
  memset(&outstr[0], 0, len + 1);
  memcpy(&outstr[0], str, len);

  cout << outstr << endl;
}


int main(void){
  string instr;  // 入力文字列

  cin >> instr;

  const char* strptr = instr.c_str();  // 入力文字列のポインタ(char)
  int strsize = instr.size();

  while((strptr[0] != '\0') && (strsize > 0)){
    int bytesize = 0;
    // 上位0bitが0なら1byte文字
    if(!(strptr[0] & 128)){
      bytesize = 1;
    }

    else{
      // 上位から連続している1の数を数える (これが文字のbyte数になる)
      // ※上位1bitは分岐で1が確定しているので確認する必要はないのですが、「これは仕組みを知るためのお勉強用コードである」＆「意味合い的には必要」と考えたので、あえてそこも含めて確認しています。
      while(strptr[0] & (128 >> bytesize)){
        bytesize++;

        // 念の為
        if(bytesize > 4){
          cout << "Error!!" << endl;
          return 0;
        }
      }
    }

    output(strptr, bytesize);
    strptr += bytesize;
    strsize--;
  }


  return 0;
}
