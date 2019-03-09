#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int q[8] = {}, c = 0, count = 1;
    q[c] = 0;
    
    NC: //next column
        c++;
        if(c >= 8)
            goto print;
        q[c] = -1; 
        //r = -1;   
        
    NR: // next row   
        q[c]++;
        if(q[c] >= 8 )
            goto backtrack;
            
        //horizontal line test
        for(int i = 0; i < c; i++){
            if(q[i] == q[c])
                goto NR;
        }
    
        //up diagonal line test
        for(int i = 0; i < c; i++){
            if(q[i] - q[c] == c-i)
                goto NR;
        }
    
        //down diagonal line test
        for(int i = 0; i < c; i++){
            if(abs(q[c] - q[i]) == c- i)
                goto NR;
        }
        
        goto NC;
        
    backtrack: 
        c--;
        if(c == -1)
            return 0;
        goto NR;    
        
    print:
        cout << '#' << count << ": ";
        count++;
        for(int i = 0; i < 8; i++){
            cout << q[i];
        }
        cout << endl;
        goto backtrack;
        
}

