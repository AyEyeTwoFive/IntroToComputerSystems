/* C Program to run tic tac toe game 
  by Asef Islam
  COMP 2131 
  TRU Summer 2019 */

#include<stdio.h>


void print_board(char board[]) {
  printf(" %c | %c | %c \n", board[0], board[1], board[2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", board[3], board[4], board[5]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

void initialize(char board[]) {
  for (int i = 0; i < 9; i++) {
    board[i] = ' ';
  }
  printf("*********************************************\n"); 
  printf("Tic Tac Toe Game by Asef Islam\n");
  printf("COMP 2131, TRU, Summer 2019\n");
  printf("You will be playing against the computer\n");
  printf("*********************************************\n");
  printf("\n\nWhat is your name?\n");
  char name[999]; 
  scanf("%s", name);
  printf("Hello %s ... Let's have fun!!!  You = X | Computer = O\n", name);
  print_board(board);
}

int game_done(char board[]) {
  if ((board[0] == 'X' && board[1] == 'X' && board[2] == 'X') || 
      (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') || 
      (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') ||
      (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') ||
      (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') ||
      (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') ||
      (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') ||
      (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')) {
      printf("*******\n");
      printf("You won!\n");
      printf("*******\n"); 
      return 1;
  }
  else if ((board[0] == 'O' && board[1] == 'O' && board[2] == 'O') ||
      (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') ||
      (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') ||
      (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') ||
      (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') ||
      (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') ||
      (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') ||
      (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')) {
      printf("*******\n");
      printf("Sorry, you lost!\n");
      printf("*******\n");
      return 1;
  }
  else {
    for (int i = 0; i < 9; i++) {
      if (board[i] == ' ') {
        return 0;
      }
    }
    printf("*******\n");
    printf("Stalemate!\n");
    printf("*******\n");
    return 1;
  }
}

void computer_turn(char board[]) {
    for (int i = 0; i < 9; i++) {
      if (board[i] == ' ') {
        board[i] = 'O';
        return;
      }
    }
}


int main() {
  char board[9];
  initialize(board);
  int x;
  int y; 
  while(1) {
    if (game_done(board)) {
      break;
    }
    printf("Enter X coordinate for your move:\n");
    scanf("%d", &x);
    if (x < 1 || x > 3) {
      printf("Error: out of range. Try again\n");
      continue;
    }
    printf("Enter Y coordinate for your move:\n");
    scanf("%d", &y);
    if (y < 1 || y > 3) {
      printf("Error: out of range. Try again\n");
      continue;
    }
    if (x == 1) {
      if (board[x + y - 2] != ' ') {
        printf("Error: space already occupied. Try again\n");
        continue;
      }
      board[x + y - 2] = 'X';
    } 
    else if (x == 2) {
      if (board[x + y] != ' ') {
        printf("Error: space already occupied. Try again\n");
        continue;
      }
      board[x + y] = 'X'; 
    }
    else if (x == 3) {
      if (board[x + y + 2] != ' ') {
        printf("Error: space already occupied. Try again\n");
        continue;
      }
      board[x + y + 2] = 'X';
    }
    if (game_done(board)) {
      break;
    }
    computer_turn(board);
    if (game_done(board)) {
      break;
    }
    print_board(board);
  }
  print_board(board);
  return 0;
}



