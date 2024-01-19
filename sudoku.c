/* This code solves any user input sudokus
Replace the 0s given in grid array with the corresponding numbers and leave the blank
boxes of sudoku as 0 */
#include<stdio.h>
int grid[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
int safe(int x, int y,int num){
    for(int i=0;i<9;i++){
        if(grid[x][i]==num){
            return 0;
        }
        if(grid[i][y]==num){
            return 0;
    }}
    for(int i=(x/3)*3;i<((x/3)*3)+3;i++){
         for(int j=(y/3)*3;j<((y/3)*3)+3;j++){
            
            if(grid[i][j]==num){
            return 0;
        }}
    }
    return 1;
}
int sudoku(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(grid[i][j]==0){
                for(int k=1;k<=9;k++){
                    if(safe(i,j,k)==1){
                        grid[i][j]=k;
                        if(sudoku()){
                            return 1;
                        }
                        grid[i][j]=0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}
int main(){
   
    if(sudoku()==1){
        for(int j=0;j<9;j++){
            for(int i=0;i<9;i++){
                printf("%d ",grid[j][i]);
            }
            printf("\n");
    }}
    
    return 0;
}
