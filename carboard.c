#include "carboard.h"

int main() {

    printf("\n");
    printf("Welcome to Car Board \n");
    printf("-------------------- \n");
    printf("1. Play game \n");
    printf("2. Show student's information \n");
    printf("3. Quit \n\n");

    showMenu();
    return 0;

}


void showMenu() {
    Cell board[BOARD_HEIGHT][BOARD_WIDTH];
    while (TRUE) {
        int choice = validateNumber();
        if (choice == 1) {

            showCommands();
            initialiseBoard(board);
            displayBoard(board, NULL);

            printf("load <g>\n");
            printf("quit\n\n");

            initialiseGame();

        }

        if (choice == 2) {

            showStudentInformation();

        }

        if (choice == 3) {

            printf("\n");
            printf("Good Bye!\n\n");

            return;

        }
    }
}

void showCommands(){

    printf("\n");
    printf("You can use the following commands to play the game: \n");
    printf("load <g> \n");
    printf("\t g: number of the game board to load \n");
    printf("init <x>,<y>,<direction> \n");
    printf("\t x: horizontal position of the car on the board (between 0 & 9) \n");
    printf("\t y: vertical position of the car on the board (between 0 & 9) \n");
    printf("\t direction: direction of the car's movement (north, east, south, west) \n");
    printf("forward (or f) \n");
    printf("turn_left (or 1) \n");
    printf("turn_right (or r) \n");
    printf("quit \n\n");
}

void showStudentInformation()
{
    printf("\n");
    printf("Name: %s \n",STUDENT_NAME);
    printf("No: %s \n",STUDENT_ID);
    printf("Email: %s \n\n",STUDENT_EMAIL);
}

