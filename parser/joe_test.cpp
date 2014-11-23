#include <iostream>
#include "parser.h"
#include "variable.h"
#include "functions.h"

using namespace std;

int main() {
  VAR * A = new VAR;
  VAR * B = new VAR;
  VAR * C = new VAR;
  A->type = 0;
  A->val = 2.1;
  B->type = 0;
  B->val = 3.2;
  
  bool ans = add(A,B,C);
  cout << C->val << endl;
  //Parser prs;
  //char* ans = prs.parse("2+3");
  //cout << ans << endl;
	
}
