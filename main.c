#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//helper functions;
int is_empty(char** board, int n);
char is_win(char** board, int n);
void player1(char** board, int n);
void player2(char** board, int n);
void show_board(char** b, int n);
void create_board(char show,int n);

// check if the board has empty space
int is_empty(char** board, int n){
  int i,j;
  for(i=0; i<n; i++) {
      for(j=0; j<n;j++) {
         if (board[i][j]== ' '){
           return 1;
         }
         }
      }
      return 0;
   }


//check if there is winner
char is_win(char** board,int n){
 int i,j,x,o;
  //horizontal
  for (i=0; i<n; i++){
    x = 0,o=0;
    for(j=0; j<n; j++)
    {
    if (board[i][j]=='X')
    x++;
    else if(board[i][j]=='O'){
    o++;
    }
    }
  if (x==n){
    return 'X';
  }
  else if (o==n){
    return 'O';
  }
  }
  //vertical
   for (i=0; i<n; i++){
    x = 0,o = 0;
    for(j=0; j<n; j++)
    {
    if (board[j][i]=='X')
    x++;
    else if(board[j][i]=='O'){
    o++;
    }
    }
  if (x==n){
    return 'X';
  }
  else if (o==n){
    return 'O';
  }
   }
  //diagonal
   x = 0, o =0;
  for (i=0; i<n; i++){

    if (board[i][i] == 'X')
    x++;
    else if (board[i][i] == 'O')
    o++;
    if (x==n){
    return 'X';
  }
  else if (o==n){
    return 'O';
  }
  }
//diagonal
x = 0, o = 0;
for (i=n-1; i>=0; i--){
 
    
    if (board[n-i-1][i]=='X')
    x++;
    else if(board[n-i-1][i]=='O'){
    o++;
    } 
  if (x==n){
    return 'X';
  }
  else if (o==n){
    return 'O';
  }
}
return ' ';
}
//player 1 interation
void player1(char** board, int n){
  int x,y;
  printf("Player 1:\n");
  scanf("%d%d", &x,&y);
  if (x == -1||y == -1){
    exit(0);
  }
  if (x>n-1||y>n-1){
    printf("Incorrect value, try again.\n");
    player1(board,n);
  }
  else if (board[x][y] != ' '){
    printf("Incorrect value, try again.\n");
    player1(board,n);
  }
  else {board[x][y] = 'O';
  printf("Player 1 entered %d %d.\n",x,y);}
}

//player 2 interation
void player2(char** board, int n){
   int x,y;

  printf("Player 2:\n");
  scanf("%d%d", &x,&y);
   if (x == -1||y == -1){
    exit(0);
  }
  if (x>n-1||y>n-1){
    printf("Incorrect value, try again.\n");
    player2(board,n);
  }
  else if (board[x][y] != ' '){
    printf("Incorrect value, try again.\n");
    player2(board,n);
  }
  else {board[x][y] = 'X';
  printf("Player 2 entered %d %d.\n",x,y);
  }

}

//display the board
void show_board(char** b, int n){
  int i,j,k;
  for (i=0; i<4*n+1; i++){
printf("-");
  }
  //for i = 0 till size:
    //strcat(line, "----")
  //print("%s-\n", line)
  printf("\n");
  for (j=0; j < n; j++){
    for (k=0; k<n; k++){
      printf("| %c ",b[j][k]);
    }
    printf("|\n");
    for (i=0; i<4*n+1; i++){
printf("-");
//printf("\n%s-\n", line)
  }
  printf("\n");
  }
}

//create the board and the game procedure
void create_board(char show, int n){
  char game_over;
  int i;
  char** board= (char**)malloc(n*sizeof(char*));
  for (i=0;i<n; i++){
    board[i]=(char*)malloc(n*sizeof(char));
  }
  int a,b;
  for (a = 0;a < n; a++){
    for (b =0; b< n; b++){
      board[a][b] =  ' ';
    }
  }

  if (show == 'y'){
    do {
    //printf("%c",is_win(board,n));
    player1(board,n);
    game_over = is_win(board,n);
    //printf("%c",is_win(board,n));
    show_board(board,n);
    if (game_over != ' ')break;
    if (is_empty(board,n)==0){ 
      printf("Who wins?? Nobody!\n");
      show_board(board,n);
      exit(0);}
    player2(board,n);
    game_over = is_win(board,n);
    show_board(board,n);
    if (game_over != ' ')break;
    if (is_empty(board,n)==0){
      printf("Who wins?? Nobody!\n");
      show_board(board,n);
      exit(0);}
  }while (game_over == ' ');
  }

  if (show =='n'){
    do {
    player1(board,n);
    game_over = is_win(board,n);
    if (game_over != ' ')break;
    if (is_empty(board,n)==0){
      printf("Who wins?? Nobody!\n");
      show_board(board,n);
      exit(0);}
    player2(board,n);
    game_over = is_win(board,n);
    if (game_over != ' ')break;
    if (is_empty(board,n)==0){
      printf("Who wins?? Nobody!\n");
      show_board(board,n);
      exit(0);}
  }while (game_over == ' ');
  }
   
  if (game_over == 'X'){
    printf("Player 2 is the winner.\n");
    show_board(board,n);

  }
  if (game_over == 'O'){
    printf("Player 1 is the winner.\n");
    show_board(board,n);
  }

free(board);
  
}


int main(){
  int num;
  char show;
  printf("Board Size (3..N):\n");
  scanf("%d", &num);
   if(num<3){
    printf("Inappropriate value. Goodbye.\n");
    exit(0);
  }
  printf("Output Play (y/n):\n");
  scanf(" %c", &show);
  if(show !='y'&& show !='n'){
    printf("Inappropriate value. Goodbye.\n");
    exit(0);
  }
  printf("You entered %d %c.\n", num, show);
printf("Starting game with %d x %d board.\n",num,num);
printf("Each player should enter\na row and col num (eg: 2 0).\n");
  create_board(show,num);
  return 0;
}    