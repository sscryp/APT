#include "board.h"

Cell BOARD_1[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

Cell BOARD_2[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

void initialiseBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
    int x, y;
    for (x=0; x < BOARD_WIDTH; x++){
        for (y=0; y < BOARD_HEIGHT; y++){
            board[x][y] = EMPTY;
        }
    }
}

void loadBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
               Cell boardToLoad[BOARD_HEIGHT][BOARD_WIDTH])
{
    int x, y;
    for (x=0; x < BOARD_WIDTH; x++){
        for (y=0; y < BOARD_HEIGHT; y++){
            board[x][y] = boardToLoad[x][y];
        }
    }
}

Boolean placePlayer(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Position position)
{
    if(board[position.x][position.y] == BLOCKED) {

        printf("\n");
        printf("The cell is blocked\n\n");
        return FALSE;

    }

    else

        board[position.x][position.y] = PLAYER;
        return TRUE;
}

PlayerMove movePlayerForward(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
                             Player * player)
{
    /* TODO*/

    return PLAYER_MOVED;
}

void displayBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player)
{
    int x,y;
    printf("| |0|1|2|3|4|5|6|7|8|9|\n");

    for (x=0; x < BOARD_WIDTH; x++){
        printf("|%i|", x);
        for (y=0; y < BOARD_HEIGHT; y++){
            if (board[x][y] == EMPTY){

                printf("%s|", EMPTY_OUTPUT);
            }
            if (board[x][y] == BLOCKED){

                printf("%s|", BLOCKED_OUTPUT);
            }
            if (board[x][y] == PLAYER){

                displayDirection(player->direction);

            }
        }

        printf("\n");
    }

    printf("\n");
}