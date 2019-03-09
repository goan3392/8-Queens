#include <iostream>
using namespace std;
int main(){
    int board[8][8] = {0}; 
    int r = 0, c = 0, num = 1;    
    board[r][c] = 1;
    

NC: //next coloumn
    c++;
    if(c >= 8) 
	goto print;
    else
    	r = -1;
    


NR: //next row
    r++;
    
    //check if you went pass the final row
    if(r >= 8) goto backtrack; 
    
    //check if other queens are on the same row
    for(int i = 0; i < 8; i++){
        if(board[r][i] == 1) 
		goto NR;
    }    
   
    //check for  queens upper left diagonally
    for(int i = 0; i < 8; i++){
	if(r-i < 0 || c - i <0) break; 
	//to check if it goes out of bounds
        if(board[r-i][c-i] == 1) 
		goto NR;
    }   
    

    //check for queens lower left digonally   
    for(int i = 0; i < 8; i++){
	if(r+i > 7 || c-i <0) break;
        if(board[r+i][c-i] == 1)
                goto NR;
    }
    
    board[r][c] = 1;
    goto NC;
    


backtrack:
    c--;
    if(c < 0) 
        return 0;
    
    r = 0;	
    for(int i = 0; i < 8; i++){
	if(board[i][c]!=1)
		r++;
        else if(board[i][c] == 1) 
		break;
    }
    
    board[r][c] = 0;
    goto NR;
    


print:
    cout << "Number " << num++ << endl;
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            cout << board[r][c];
            
        }
        cout << endl;
    }
    
    goto backtrack;
    
}
