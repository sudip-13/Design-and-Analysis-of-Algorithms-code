#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int ch_board[4],sol;
void print_board(int n) {
  int i, j;
  printf("\n\nSolution %d:\n\n", ++sol);

  for (i = 1; i <= n; i++)
    printf("\t%d", i);

  for (i = 1; i <= n; i++) {
    printf("\n\n%d", i);
    for (j = 1; j <= n; ++j) {
      if (ch_board[i] == j)
        printf("\tQ");
      else
        printf("\t0");
    }
  }
}
int isplace(int row,int col){
    for(int i=1;i<=row-1;i++)
    {
        if(ch_board[i]==col){
            return 0;
        }
        else if((abs(ch_board[i]-col)) == (abs(i-row))){
            return 0;
        }
    }
    return 1;
}
void N_queen(int row,int n){
    for(int col=1;col<=n;col++){
        if(isplace(row,col)){
            ch_board[row]=col;
            if(row==n){
                print_board(n);
            }
            else{
                N_queen(row+1,n);
            }
        }
    }
}
void main(){
    N_queen(1,4);
}