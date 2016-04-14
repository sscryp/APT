#include "game.h"

void initialiseGame()
{
    Cell board[BOARD_HEIGHT][BOARD_WIDTH];

    while(TRUE) {

        char str1[] = {"load 1"};
        char str2[] = {"load 2"};
        char str3[] = {"quit"};
        char *tok;
        int numx;
        int numy;
        char *end;
        char *choice;
        Direction direction;
        Position position;
        Player *player;
        Player player2;
        player = &player2;

        do {

            choice = validateString();

            if (strcmp(choice, str1) == 0) {

                printf("\n");
                loadBoard(board, BOARD_1);
                displayBoard(board, NULL);
                printf("load <g>\n");
                printf("init <x>,<y>,<direction>\n");
                printf("quit\n\n");


            }

            else if (strcmp(choice, str2) == 0) {

                printf("\n");
                loadBoard(board, BOARD_2);
                displayBoard(board, NULL);
                printf("load <g>\n");
                printf("init <x>,<y>,<direction>\n");
                printf("quit\n\n");

            }

            else if (strcmp(choice, str3) == 0) {

                printf("\n");
                printf("Welcome to Car Board \n");
                printf("-------------------- \n");
                printf("1. Play game \n");
                printf("2. Show student's information \n");
                printf("3. Quit \n\n");
                return;

            }

            /*START OF THE INITIALISATION MENU*/
            /*It checks the initialisation input*/

            else if((tok = strtok(choice, " ")) != NULL && strcmp(tok, "init") == 0){

                tok = NULL;

                if ((tok = strtok(tok, ",")) != NULL) {

                    numx = (int) strtol(tok, &end, 10);

                    if (numx >= 0 && numx <= 9) {

                        tok = NULL;

                        position.x = numx;

                        if((tok = strtok(tok, ",")) != NULL){

                            numy = (int) strtol(tok, &end, 10);

                            if(numy >= 0 && numy <= 9){

                                tok = NULL;

                                position.y = numy;

                                if((tok = strtok(tok, ",")) != NULL){

                                    /*NUMX and NUMY are stored at THIS POINT*/

                                    /*if input is NORTH*/

                                    if(strcmp(tok, DIRECTION_NORTH) == 0 && placePlayer(board, position) == TRUE){

                                        direction = NORTH;
                                        placePlayer(board, position);
                                        initialisePlayer(player, position, direction);
                                        printf("\n");
                                        displayBoard(board, player);
                                        showigCommands();
                                        playGame(player, board);

                                    }

                                    /*if input is SOUTH*/

                                    else if(strcmp(tok, DIRECTION_SOUTH) == 0 && placePlayer(board, position) == TRUE){

                                        direction = SOUTH;
                                        placePlayer(board, position);
                                        initialisePlayer(player, position, direction);
                                        printf("\n");
                                        displayBoard(board, player);
                                        showigCommands();
                                        playGame(player, board);


                                    }

                                    /*if input is WEST*/

                                    else if(strcmp(tok, DIRECTION_WEST) == 0 && placePlayer(board, position) == TRUE){

                                        direction = WEST;
                                        placePlayer(board, position);
                                        initialisePlayer(player, position, direction);
                                        printf("\n");
                                        displayBoard(board, player);
                                        showigCommands();
                                        playGame(player, board);

                                    }

                                    /*if input is EAST*/

                                    else if(strcmp(tok, DIRECTION_EAST) == 0 && placePlayer(board, position) == TRUE){

                                        direction = EAST;
                                        placePlayer(board, position);
                                        initialisePlayer(player, position, direction);
                                        printf("\n");
                                        displayBoard(board, player);
                                        showigCommands();
                                        playGame(player, board);

                                    }


                                    else if(strcmp(tok, DIRECTION_EAST) == 0 || strcmp(tok, DIRECTION_WEST) == 0 || strcmp(tok, DIRECTION_NORTH) == 0 || strcmp(tok, DIRECTION_SOUTH) == 0 && placePlayer(board, position) == FALSE){

                                        printf("\n");
                                        printf("The cell is blocked\n\n");

                                    }

                                    else if(strcmp(tok, DIRECTION_EAST) != 0 || strcmp(tok, DIRECTION_WEST) != 0 || strcmp(tok, DIRECTION_NORTH) != 0 || strcmp(tok, DIRECTION_SOUTH) != 0) {

                                        printf("\n");
                                        printf("Invalid input\n\n");

                                    }



                                }

                                else {

                                    printf("\n");
                                    printf("Invalid input\n\n");

                                }


                                }

                            else {

                                printf("\n");
                                printf("Invalid input\n\n");

                            }

                            }

                        else {

                            printf("\n");
                            printf("Invalid input\n\n");

                        }

                        }

                    else {

                        printf("\n");
                        printf("Invalid input\n\n");

                    }

                    }

                else {

                    printf("\n");
                    printf("Invalid input\n\n");

                }

                }

            /*END OF THE INITIALISATION MENU*/

            else {

                printf("\n");
                printf("Invalid input\n\n");

            }

        }

        while (strcmp(choice, str1) != 0 && strcmp(choice, str2) != 0 && strcmp(choice, str3) != 0);
    }

}





void  playGame(Player *player, Cell board[BOARD_HEIGHT][BOARD_WIDTH]) {

    while (TRUE) {

        char *choice;
        char quit[] = "quit";


        do {

            choice = validateString();

            if (strcmp(choice, COMMAND_TURN_LEFT_SHORTCUT) == 0 || strcmp(choice, COMMAND_TURN_LEFT) == 0) {

                turnDirection(player, TURN_LEFT);
                printf("\n");
                displayBoard(board, player);
                showigCommands();

            }

            else if (strcmp(choice, COMMAND_TURN_RIGHT_SHORTCUT) == 0 || strcmp(choice, COMMAND_TURN_RIGHT) == 0) {

                turnDirection(player, TURN_RIGHT);
                printf("\n");
                displayBoard(board, player);
                showigCommands();

            }

            else if (strcmp(choice, COMMAND_FORWARD) == 0 || strcmp(choice, COMMAND_FORWARD_SHORTCUT) == 0){

                movePlayerForward(board, player);
                printf("\n");
                displayBoard(board, player);
                showigCommands();

            }

            else if (strcmp(choice, quit) == 0) {

                return;

            }

            else {

                printf("\n");
                printf("Invalid input\n\n");
            }

        } while (choice != NULL);


    }
}

void showigCommands(){

    printf("forward\n");
    printf("turn_left (or l)\n");
    printf("turn_right (or l)\n");
    printf("quit\n\n");
}