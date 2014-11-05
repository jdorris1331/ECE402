#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> operations;

//need recursive function
int order_ops(string eq1) {
  cout << eq1 << endl;
  int i=0;
  int p_start=0;
  int p_end=0;
  int initial=1;
  int balance = 0;
  while(i<eq1.size()) {
    if(eq1.at(i) == '(' ) {
      balance++;
      if(initial) {
        p_start = i;
        initial = 0;
      }
    }
    if(eq1.at(i) == ')' ) {
      if (initial) return 1;
      balance--;
      if(balance==0) {
        p_end=i;
        break;
      }
    }
    i++;
  }
  
  if(initial==1) return 0;
  return order_ops(eq1.substr(p_start+1,p_end-p_start-1)); 
} 

int main() {
string eq1 = "dvar1=)var1*3+1/((2/3))-3)";
int i=0;
while(eq1.at(i)!='=') {
  cout << eq1.at(i) << endl; 
  i++;
}
while(eq1.at(i) == '=' && eq1.at(i) == ' ') {i++;}

int start = i;
/*
//while(1) {
  i=start;
  while(eq1.at(i) != '(' ) {i++;}
  int start_paren = i;
  while(eq1.at(i) != ')' ) {i++;}
  int end_paren = i;
  cout << start_paren << " " << end_paren << endl;
  cout << eq1.at(start_paren) << " " << eq1.at(end_paren) << endl;
//}
*/
if(order_ops(eq1)) cerr << "Equation has error\n";

}
