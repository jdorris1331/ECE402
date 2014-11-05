#include <iostream>
#include "parser.h"


using namespace std;

int main() {
  
  Parser prs;
  char* ans = prs.parse("2+3");
  cout << ans << endl;
	
}
