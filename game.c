#include "game.h"

/*INITIALISATION MENU
 * User chooses which board to play on and initialises the game*/

void initialiseGame()
{
    while(TRUE){
        
        Cell board[BOARD_HEIGHT][BOARD_WIDTH];
        char str1[] = {"load 1"};
        char str2[] = {"load 2"};
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
                showinitMenu();


            }

            else if (strcmp(choice, str2) == 0) {

                printf("\n");
                loadBoard(board, BOARD_2);
                displayBoard(board, NULL);
                showinitMenu();

            }

            else if (strcmp(choice, COMMAND_QUIT) == 0) {

                return;

            }

            /*START OF THE INITIALISATION MENU*/
            /*It checks the initialisation input*/

            else if((tok = strtok(choice, " ")) && strcmp(tok, COMMAND_INIT) == 0){ /*Splits input and checks if the first input is "init"*/

                tok = NULL;

                if ((tok = strtok(tok, ",")) != NULL) {

                    numy = (int) strtol(tok, &end, 10);

                    if (numy>= 0 && numy <= 9) {

                        tok = NULL;

                        position.y = numy; /*Players initial y coord on the board*/

                        if((tok = strtok(tok, ",")) != NULL){

                            numx = (int) strtol(tok, &end, 10);

                            if(numx >= 0 && numx <= 9){

                                tok = NULL;

                                position.x = numx; /*Players initial x coord on the board*/

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
                                        break;
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
                                        break;

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
                                        break;
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
                                        break;
                                    }



                                    /*Checks if cell initial player position is blocked returns an error*/

                                    else if((strcmp(tok, DIRECTION_EAST) == 0 || strcmp(tok, DIRECTION_WEST) == 0 || strcmp(tok, DIRECTION_NORTH) == 0 || strcmp(tok, DIRECTION_SOUTH) == 0) && placePlayer(board, position) == FALSE){

                                        printf("\n");
                                        printf("The cell is blocked\n\n");

                                    }

                                    /*Checks the direction bit and returns an error if not entered correctly*/

                                    else if(strcmp(tok, DIRECTION_EAST) != 0 || strcmp(tok, DIRECTION_WEST) != 0 || strcmp(tok, DIRECTION_NORTH) != 0 || strcmp(tok, DIRECTION_SOUTH) != 0) {

                                        printf("\n");
                                        printf("Invalid input\n\n");

                                    }
                                        
                                }
                                /*Checks X and returns an error if not entered correctly*/

                                else {

                                    printf("\n");
                                    printf("Invalid input\n\n");

                                }


                                }

                            /*Checks Y and returns an error if not entered correctly*/

                            else {

                                printf("\n");
                                printf("Invalid input\n\n");

                            }

                            }

                        /*Checks "init" string and returns an error if not entered correctly*/

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

        }while (strcmp(choice, COMMAND_QUIT) != 0);
        break;
    }
}



/*IN GAME MENU
 * User can input three in game commands and play the game on desired board*/

void  playGame(Player *player, Cell board[BOARD_HEIGHT][BOARD_WIDTH]) {

    while (TRUE) {

        char *choice;


        do {

            choice = validateString();

            if (strcmp(choice, COMMAND_TURN_LEFT_SHORTCUT) == 0 || strcmp(choice, COMMAND_TURN_LEFT) == 0) {

                turnDirection(player, TURN_LEFT);
                printf("\n");
                displayBoard(board, player);
                showigCommands();
                player->moves ++;

            }

            else if (strcmp(choice, COMMAND_TURN_RIGHT_SHORTCUT) == 0 || strcmp(choice, COMMAND_TURN_RIGHT) == 0) {

                turnDirection(player, TURN_RIGHT);
                printf("\n");
                displayBoard(board, player);
                showigCommands();
                player->moves ++;

            }

            else if (strcmp(choice, COMMAND_FORWARD) == 0 || strcmp(choice, COMMAND_FORWARD_SHORTCUT) == 0){

                movePlayerForward(board, player);
                printf("\n");
                displayBoard(board, player);
                showigCommands();
                player->moves ++;

            }

            else if (strcmp(choice, COMMAND_QUIT) == 0) {

                printf("\n");
                printf("Total player moves: ");
                printf("%i\n\n", player->moves);
                return;

            }

            else {

                printf("\n");
                printf("Invalid input\n\n");
            }

        } while (strcmp(choice, COMMAND_QUIT) != 0);


    }
}


/*GENERAL MENU INSTRUCTIONS*/

void showigCommands(){
    printf("forward\n");
    printf("turn_left (or l)\n");
    printf("turn_right (or l)\n");
    printf("quit\n\n");
}

void showinitMenu(){
    printf("load <g>\n");
    printf("init <x>,<y>,<direction>\n");
    printf("quit\n\n");
}