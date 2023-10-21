#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

char grid[3][3];
char player = 'X', comp = 'O', winner = ' ';
int row, col;

void reset_board();  void print_board(); void turn_decider(); void winner_check();
void player_turn();  void comp_turn();   bool end_checker();  void end();

void main()
{
    printf(" Tic Tac Toe!! \n");
    printf("    Start \n");

    reset_board(); 
    print_board();
    turn_decider();
}

void reset_board()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            grid[i][j] = ' ';
}

void print_board()
{
    printf("\n %c | %c | %c ", grid[0][0], grid[0][1], grid[0][2]);
    printf("\n---|---|---   ");
    printf("\n %c | %c | %c ", grid[1][0], grid[1][1], grid[1][2]);
    printf("\n---|---|---   ");
    printf("\n %c | %c | %c \n", grid[2][0], grid[2][1], grid[2][2]);
}

void turn_decider()
{
    srand(time(0));
    int turn = rand() % 2;

    if (turn) 
        player_turn();
    else 
        comp_turn();
}

bool end_checker()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == ' ')
                return false;
        }
    return true;
}

void winner_check()
{
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2])
            {
                if(grid[i][0]=='X')
                    winner = player;
                if(grid[i][0]=='O')
                    winner = comp;
                break;
            }
        if (grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i])
            {
                if(grid[0][i]=='X')
                    winner = player;
                if(grid[0][i]=='O')
                    winner = comp;
                break;
            }      
    }

    if (grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2])
    {
        if(grid[1][1]=='X')
            winner = player;
        if(grid[1][1]=='O')
            winner = comp;
    }
    if (grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0])
    {
        if(grid[1][1]=='X')
            winner = player;
        if(grid[1][1]=='O')
            winner = comp;
    }   
}

void player_turn()
{
    printf("\nYour Turn\n");

    while (1)
    {
        printf("\nEnter row num(1-3): ");
        scanf("%d", &row);
        printf("Enter column num(1-3): ");
        scanf("%d", &col);
        row--;
        col--;

        if (grid[row][col] != ' ')
            printf("\nInvalid Entry!\n");
        else
        {
            grid[row][col] = player;
            print_board(); 
            winner_check();

            if (winner != ' ' || end_checker()) 
                end();
            else 
                comp_turn();
        }
    }
}

void comp_turn()
{
    printf("\nComputer's turn\n");

    while (1)
    {
        row = rand() % 3;
        col = rand() % 3;

        if (grid[row][col] == ' ')
        {
            grid[row][col] = comp;
            print_board(); 
            winner_check();

            if (winner != ' ' || end_checker()) 
                end();
            else 
                player_turn();               
        }
    } 
}

void end()
{
    if (winner == 'X')
        printf("\nYayyyy! You won!");
    else if (winner == 'O')     
        printf("\nOh no! You lost!");    
    else
        printf("It's a tie!");
    exit(0);
}