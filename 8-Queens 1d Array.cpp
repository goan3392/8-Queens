#include <iostream>
#include <cmath>
using namespace std;

int q[8] = {0}, c = 0, count = 1;

//functions
bool passTests(){
  for (int i = 0; i < c; i++){
    //horzontal test
    if(q[c] == q[i]) return false;
    //diagonal test
    else if(abs(q[c]-q[i]) == c-i) return false;
  }
  return true;
}

void toPrint(int q[]){
  cout << '#' << count++ << ": \n";
  for (int i = 0; i < 8; i++){
    cout << q[i];
  }
  cout << endl;
}

int main(){
  while (true){
    c++;
    if(c>= 8){
      toPrint(q);
      //backtrack
      c--;
    } else{
      // r = -1
      q[c] = -1;
    }

    while (true){
      //row++
      q[c]++;
      if(q[c]>= 8){
        //r=8 so backtrack and check
        c--;
        if (c== -1) return 0;
      }else if(passTests() == true) break;
        //goto NC
    
    }

}

  return 0;
}

