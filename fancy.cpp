#include <iostream>
using namespace std;

int oddPerfectSquare(){
     int num = 5;
     while(true){
	int square = num * num;
	if(square%2==1 && square/10%2==1){
	     return square;
     	}
	num++;
     } 
}



int main(){
     cout << oddPerfectSquare();
     
}     
