#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;


int board [9][9];
int boardshade [9][9];


// initiate arrays
void initboard(){
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            board [i][j] = 0;
        }
    }
}

void initboardshade(){
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            boardshade [i][j] = 0;
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            if (board[i][j] == 0){
                boardshade [i][j] = 1;
            }
        }
    }
}

// print to screen
void showboard () {
    
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            cout << board [i][j] << "  ";
            if (j == 8) {
                cout << "\n";
            }
            if (j == 2) {
                cout << "   ";
            }
            if (j == 5) {
                cout << "   ";
            }
        }
        
        if (i == 2) {
            cout << "\n";
        }
        if (i == 5) {
            cout << "\n";
        }
    }
}

void showboardshade () {
    
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            cout << boardshade [i][j] << "  ";
            if (j == 8) {
                cout << "\n";
            }
            if (j == 2) {
                cout << "   ";
            }
            if (j == 5) {
                cout << "   ";
            }
        }
        
        if (i == 2) {
            cout << "\n";
        }
        if (i == 5) {
            cout << "\n";
        }
    }
}

// take board input
void fillboard () {
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            cout << "Enter value for: " << "board [" << i << "] [" << j << "]";
            cin >> board [i][j];
            cout << "\n";
        }
    }
}

// identifies which box the point is in
int box=0;
void whichbox(int x, int y){
    
    if (x < 3){
        if (y < 3){
            box = 1;
        }
        if (y < 6 && y >= 3){
            box = 2;
        }
        if (y < 9 && y >= 6){
            box = 3;
        }
    }
    if (x < 6 && x >= 3){
        if (y < 3){
            box = 4;
        }
        if (y < 6 && y >= 3){
            box = 5;
        }
        if (y < 9 && y >= 6){
            box = 6;
        }

    }
    if (x < 9 && x >= 6){
        if (y < 3){
            box = 7;
        }
        if (y < 6 && y >= 3){
            box = 8;
        }
        if (y < 9 && y >= 6){
            box = 9;
        }
    }
}

// shade possible solutions in boardshade
void shadebox(int x){
    if (x == 1){
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                boardshade[i][j] = 0;
            }
        }
    }
    if (x == 2){
        for (int i=0;i<3;i++) {
            for (int j=3;j<6;j++) {
                boardshade[i][j] = 0;
            }
        }
    }
    if (x == 3){
        for (int i=0;i<3;i++) {
            for (int j=6;j<9;j++) {
                boardshade[i][j] = 0;
            }
        }
    }
    if (x == 4){
        for (int i=3;i<6;i++) {
            for (int j=0;j<3;j++) {
                boardshade[i][j] = 0;
            }
        }
    }
    if (x == 5){
        for (int i=3;i<6;i++) {
            for (int j=3;j<6;j++) {
                boardshade[i][j] = 0;
            }
        }
    }
    if (x == 6){
        for (int i=3;i<6;i++) {
            for (int j=6;j<9;j++) {
                boardshade[i][j] = 0;
            }
        }
    }
    if (x == 7){
        for (int i=6;i<9;i++) {
            for (int j=0;j<3;j++) {
                boardshade[i][j] = 0;
            }
        }
    }
    if (x == 8){
        for (int i=6;i<9;i++) {
            for (int j=3;j<6;j++) {
                boardshade[i][j] = 0;
            }
        }
    }
    if (x == 9){
        for (int i=6;i<9;i++) {
            for (int j=6;j<9;j++) {
                boardshade[i][j] = 0;
            }
        }
    }
}

// shade possible solution locations from boardshade
void shade(int x, int y){
    for (int i=0 ; i <9 ; i++) {
        boardshade [x][i] = 0;
    }
    for (int i=0 ; i <9 ; i++) {
        boardshade [i][y] = 0;
    }
    whichbox(x,y);
    shadebox(box);
}

// update boardshade
void updateboardshade(int x){
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            if (board [i][j] == x){
                shade(i,j);
            }
        }
    }
}

void fillrow(int i){
    
    // find location of empty box
    int jx;
    
    for (int j=0 ; j < 9 ; j++){
        if (board[i][j] == 0){
            jx = j;
        }
    }
    
    // check which number should go in there
    bool numused[10];
    int x=0;
    
    for (int j=0; j<10 ; j++)
        numused[j] = false;
    
    for (int j=0; j<9; j++){
        if (board[i][j] == 1){
            numused[1] = true;
        }
        if (board[i][j] == 2){
            numused[2] = true;
        }
        if (board[i][j] == 3){
            numused[3] = true;
        }
        if (board[i][j] == 4){
            numused[4] = true;
        }
        if (board[i][j] == 5){
            numused[5] = true;
        }
        if (board[i][j] == 6){
            numused[6] = true;
        }
        if (board[i][j] == 7){
            numused[7] = true;
        }
        if (board[i][j] == 8){
            numused[8] = true;
        }
        if (board[i][j] == 9){
            numused[9] = true;
        }

    }
    
    for (int j=1; j<10; j++){
        if (numused[j] == false){
            x = j;
        }
    }
    
    // put the number you found
    for (int j=0; j<9; j++){
        if (board[i][j] == 0){
            board [i][j] = x;
        }
    }
}

void fillcol(int j){
    // find location of empty box
    int ix;
    
    for (int i=0 ; i < 9 ; i++){
        if (board[i][j] == 0){
            ix = i;
        }
    }
    
    // check which number should go in there
    bool numused[10];
    int x=0;
    
    for (int i=0; i<10 ; i++)
        numused[i] = false;
    
    for (int i=0; i<9; i++){
        if (board[i][j] == 1){
            numused[1] = true;
        }
        if (board[i][j] == 2){
            numused[2] = true;
        }
        if (board[i][j] == 3){
            numused[3] = true;
        }
        if (board[i][j] == 4){
            numused[4] = true;
        }
        if (board[i][j] == 5){
            numused[5] = true;
        }
        if (board[i][j] == 6){
            numused[6] = true;
        }
        if (board[i][j] == 7){
            numused[7] = true;
        }
        if (board[i][j] == 8){
            numused[8] = true;
        }
        if (board[i][j] == 9){
            numused[9] = true;
        }
        
    }
    
    for (int i=1; i<10;i++){
        if (numused[i] == false){
            x = i;
        }
    }
    
    // put the number you found
    for (int i=0; i<9; i++){
        if (board[i][j] == 0){
            board [i][j] = x;
        }
    }

}

void fillbox(int s){
    // find location of empty box
    int ix;
    int jx;
    int adj = 0;
    
    if (s < 4){
        
        if (s==1)
            adj=0;
        if (s==2)
            adj=3;
        if (s==3)
            adj=6;
        
        for (int i=0; i<3 ; i++){
            for (int j=0+adj; j<3+adj ; j++){
                if (board[i][j] == 0){
                    ix = i;
                    jx = j;
                }
            }
        }
    }
    
    if (s < 7 && s > 4){
        
        if (s==4)
            adj=0;
        if (s==5)
            adj=3;
        if (s==6)
            adj=6;
        
        for (int i=3; i<6 ; i++){
            for (int j=0+adj; j<3+adj ; j++){
                if (board[i][j] == 0){
                    ix = i;
                    jx = j;
                }
            }
        }
    }
    
    if (s < 10 && s > 7){
        
        if (s==7)
            adj=0;
        if (s==8)
            adj=3;
        if (s==9)
            adj=6;
        
        for (int i=6; i<9 ; i++){
            for (int j=0+adj; j<3+adj ; j++){
                if (board[i][j] == 0){
                    ix = i;
                    jx = j;
                }
            }
        }
    }
    
    // check which number should go in there
    bool numused[10];
    int x=0;
    
    for (int i=0; i<10 ; i++)
        numused[i] = false;
    
    if (s < 4){
        
        if (s==1)
            adj=0;
        if (s==2)
            adj=3;
        if (s==3)
            adj=6;
        
        for (int i=0; i<3 ; i++){
            for (int j=0+adj; j<3+adj ; j++){
                if (board[i][j] == 1){
                    numused[1] = true;
                }
                if (board[i][j] == 2){
                    numused[2] = true;
                }
                if (board[i][j] == 3){
                    numused[3] = true;
                }
                if (board[i][j] == 4){
                    numused[4] = true;
                }
                if (board[i][j] == 5){
                    numused[5] = true;
                }
                if (board[i][j] == 6){
                    numused[6] = true;
                }
                if (board[i][j] == 7){
                    numused[7] = true;
                }
                if (board[i][j] == 8){
                    numused[8] = true;
                }
                if (board[i][j] == 9){
                    numused[9] = true;
                }
            }
        }
    }
    
    if (s < 7 && s > 4){
        
        if (s==4)
            adj=0;
        if (s==5)
            adj=3;
        if (s==6)
            adj=6;
        
        for (int i=3; i<6 ; i++){
            for (int j=0+adj; j<3+adj ; j++){
                if (board[i][j] == 1){
                    numused[1] = true;
                }
                if (board[i][j] == 2){
                    numused[2] = true;
                }
                if (board[i][j] == 3){
                    numused[3] = true;
                }
                if (board[i][j] == 4){
                    numused[4] = true;
                }
                if (board[i][j] == 5){
                    numused[5] = true;
                }
                if (board[i][j] == 6){
                    numused[6] = true;
                }
                if (board[i][j] == 7){
                    numused[7] = true;
                }
                if (board[i][j] == 8){
                    numused[8] = true;
                }
                if (board[i][j] == 9){
                    numused[9] = true;
                }
            }
        }
    }
    
    if (s < 10 && s > 7){
        
        if (s==7)
            adj=0;
        if (s==8)
            adj=3;
        if (s==9)
            adj=6;
        
        for (int i=6; i<9 ; i++){
            for (int j=0+adj; j<3+adj ; j++){
                if (board[i][j] == 1){
                    numused[1] = true;
                }
                if (board[i][j] == 2){
                    numused[2] = true;
                }
                if (board[i][j] == 3){
                    numused[3] = true;
                }
                if (board[i][j] == 4){
                    numused[4] = true;
                }
                if (board[i][j] == 5){
                    numused[5] = true;
                }
                if (board[i][j] == 6){
                    numused[6] = true;
                }
                if (board[i][j] == 7){
                    numused[7] = true;
                }
                if (board[i][j] == 8){
                    numused[8] = true;
                }
                if (board[i][j] == 9){
                    numused[9] = true;
                }
            }
        }
    }
    
    for (int i=1; i<10;i++){
        if (numused[i] == false){
            x = i;
        }
    }
    
    // put the number you found
    if (s < 4){
        
        if (s==1)
            adj=0;
        if (s==2)
            adj=3;
        if (s==3)
            adj=6;
        
        for (int i=0; i<3 ; i++){
            for (int j=0+adj; j<3+adj ; j++){
                if (board[i][j] == 0){
                    board[i][j] = x;
                }
            }
        }
    }
    
    if (s < 7 && s > 4){
        
        if (s==4)
            adj=0;
        if (s==5)
            adj=3;
        if (s==6)
            adj=6;
        
        for (int i=3; i<6 ; i++){
            for (int j=0+adj; j<3+adj ; j++){
                if (board[i][j] == 0){
                    board[i][j] = x;
                }
            }
        }
    }
    
    if (s < 10 && s > 7){
        
        if (s==7)
            adj=0;
        if (s==8)
            adj=3;
        if (s==9)
            adj=6;
        
        for (int i=6; i<9 ; i++){
            for (int j=0+adj; j<3+adj ; j++){
                if (board[i][j] == 0){
                    board[i][j] = x;
                }
            }
        }
    }

}

// attempt to check in boardshade for right locations
void attempt(int x){
    int sol = 0;
    
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (boardshade[i][j] == 1)
                sol++;
            
            if (i==2 && j== 2 && sol==1){
                for (int i=0; i<3; i++){
                    for (int j=0; j<3; j++){
                        if (boardshade[i][j] == 1)
                            board[i][j] = x;
                    }
                }

            }
        }
    }
    sol = 0;
    
    for (int i=0; i<3; i++){
        for (int j=3; j<6; j++){
            if (boardshade[i][j] == 1)
                sol++;
            
            if (i==2 && j== 5 && sol==1){
                for (int i=0; i<3; i++){
                    for (int j=3; j<6; j++){
                        if (boardshade[i][j] == 1)
                            board[i][j] = x;
                    }
                }
                
            }

        }
    }
    sol = 0;

    for (int i=0; i<3; i++){
        for (int j=6; j<9; j++){
            if (boardshade[i][j] == 1)
                sol++;
            
            if (i==2 && j== 8 && sol==1){
                for (int i=0; i<3; i++){
                    for (int j=6; j<9; j++){
                        if (boardshade[i][j] == 1)
                            board[i][j] = x;
                    }
                }
                
            }

        }
    }
    sol = 0;

    
    
    for (int i=3; i<6; i++){
        for (int j=0; j<3; j++){
            if (boardshade[i][j] == 1)
                sol++;
            
            if (i==5 && j== 2 && sol==1){
                for (int i=3; i<6; i++){
                    for (int j=0; j<3; j++){
                        if (boardshade[i][j] == 1)
                            board[i][j] = x;
                    }
                }
                
            }

        }
    }
    sol = 0;

    for (int i=3; i<6; i++){
        for (int j=3; j<6; j++){
            if (boardshade[i][j] == 1)
                sol++;
            
            if (i==5 && j== 5 && sol==1){
                for (int i=3; i<6; i++){
                    for (int j=3; j<6; j++){
                        if (boardshade[i][j] == 1)
                            board[i][j] = x;
                    }
                }
                
            }

        }
    }
    sol = 0;

    for (int i=3; i<6; i++){
        for (int j=6; j<9; j++){
            if (boardshade[i][j] == 1)
                sol++;
            
            if (i==5 && j== 8 && sol==1){
                for (int i=3; i<6; i++){
                    for (int j=6; j<9; j++){
                        if (boardshade[i][j] == 1)
                            board[i][j] = x;
                    }
                }
                
            }

        }
    }
    sol = 0;

    
    
    for (int i=6; i<9; i++){
        for (int j=0; j<3; j++){
            if (boardshade[i][j] == 1)
                sol++;
            
            if (i==8 && j== 2 && sol==1){
                for (int i=6; i<9; i++){
                    for (int j=0; j<3; j++){
                        if (boardshade[i][j] == 1)
                            board[i][j] = x;
                    }
                }
                
            }

        }
    }
    sol = 0;

    for (int i=6; i<9; i++){
        for (int j=3; j<6; j++){
            if (boardshade[i][j] == 1)
                sol++;
            
            if (i==8 && j== 5 && sol==1){
                for (int i=6; i<9; i++){
                    for (int j=3; j<6; j++){
                        if (boardshade[i][j] == 1)
                            board[i][j] = x;
                    }
                }
                
            }

        }
    }
    sol = 0;

    for (int i=6; i<9; i++){
        for (int j=6; j<9; j++){
            if (boardshade[i][j] == 1)
                sol++;
            
            if (i==8 && j== 8 && sol==1){
                for (int i=6; i<9; i++){
                    for (int j=6; j<9; j++){
                        if (boardshade[i][j] == 1)
                            board[i][j] = x;
                    }
                }
                
            }

        }
    }
    sol = 0;

}

void attempt2(){
    //check rows
    
    int emptyboxes=0;
    
    for (int i=0 ; i<9 ; i++){
        for (int j=0; j<9; j++){
            if (board[i][j] == 0){
                emptyboxes++;
            }
            
            if (j == 8 && emptyboxes == 1){
                // find the empty box and fill it
                fillrow(i);
            }
        }
    }
    
    
    //check coloumns
    
    emptyboxes=0;
    
    for (int j=0 ; j<9 ; j++){
        for (int i=0; i<9; i++){
            if (board[i][j] == 0){
                emptyboxes++;
            }
            
            if (i == 8 && emptyboxes == 1){
                // find the empty box and fill it
                fillcol(j);
            }
        }
    }
    
    //check boxes
    
    emptyboxes=0;
    
    for (int s=1; s<10; s++){
        if (s == 1){
            emptyboxes=0;
            for (int i=0;i<3;i++) {
                for (int j=0;j<3;j++) {
                    if (board[i][j] == 0)
                        emptyboxes++;
                    if (i == 2 && j == 2 && emptyboxes == 1)
                        fillbox(s);
                }
            }
        }
        
        if (s == 2){
            emptyboxes=0;
            for (int i=0;i<3;i++) {
                for (int j=3;j<6;j++) {
                    if (board[i][j] == 0)
                        emptyboxes++;
                    if (i == 2 && j == 5 && emptyboxes == 1)
                        fillbox(s);
                }
            }
        }
        if (s == 3){
            emptyboxes=0;
            for (int i=0;i<3;i++) {
                for (int j=6;j<9;j++) {
                    if (board[i][j] == 0)
                        emptyboxes++;
                    if (i == 2 && j == 8 && emptyboxes == 1)
                        fillbox(s);
                }
            }
        }
        if (s == 4){
            emptyboxes=0;
            for (int i=3;i<6;i++) {
                for (int j=0;j<3;j++) {
                    if (board[i][j] == 0)
                        emptyboxes++;
                    if (i == 5 && j == 2 && emptyboxes == 1)
                        fillbox(s);
                }
            }
        }
        if (s == 5){
            emptyboxes=0;
            for (int i=3;i<6;i++) {
                for (int j=3;j<6;j++) {
                    if (board[i][j] == 0)
                        emptyboxes++;
                    if (i == 5 && j == 5 && emptyboxes == 1)
                        fillbox(s);
                }
            }
        }
        if (s == 6){
            emptyboxes=0;
            for (int i=3;i<6;i++) {
                for (int j=6;j<9;j++) {
                    if (board[i][j] == 0)
                        emptyboxes++;
                    if (i == 5 && j == 8 && emptyboxes == 1)
                        fillbox(s);
                }
            }
        }
        if (s == 7){
            emptyboxes=0;
            for (int i=6;i<9;i++) {
                for (int j=0;j<3;j++) {
                    if (board[i][j] == 0)
                        emptyboxes++;
                    if (i == 8 && j == 2 && emptyboxes == 1)
                        fillbox(s);
                }
            }
            
        }
        if (s == 8){
            emptyboxes=0;
            for (int i=6;i<9;i++) {
                for (int j=3;j<6;j++) {
                    if (board[i][j] == 0)
                        emptyboxes++;
                    if (i == 8 && j == 5 && emptyboxes == 1)
                        fillbox(s);
                }
            }
        }
        if (s == 9){
            emptyboxes=0;
            for (int i=6;i<9;i++) {
                for (int j=6;j<9;j++) {
                    if (board[i][j] == 0)
                        emptyboxes++;
                    if (i == 8 && j == 8 && emptyboxes == 1)
                        fillbox(s);
                }
            }
        }
    }
}

// solve the game
void solve () {
    for (int f = 0; f < 40 ; f++){
        for (int i=1;i<10;i++){
            initboardshade();
            updateboardshade(i);
            attempt(i);
            attempt2();
        }
        
    }
}

// starts program
int main () {
    initboard();
    fillboard();
    showboard();
    cout << "\n \n";
   
    solve();
    
    cout << "\n";
    cout << "Solution: " <<"\n \n";
    showboard();
}


