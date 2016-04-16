#ifndef CARBOARD_H
#define CARBOARD_H

#include "helpers.h"
#include "game.h"

#define STUDENT_NAME "Mert Atakan"
#define STUDENT_ID "s3457702"
#define STUDENT_EMAIL "s3457702@student.rmit.edu.au"


typedef struct choice
{
    char choice;

} Choice;

/**
 * Main menu option 2 - show your student information as per the specification.
 *
 * You should change the defines above related to student information and use
 * them when printing.
 */

void showStudentInformation();
void showCommands();
void showMenu();


#endif