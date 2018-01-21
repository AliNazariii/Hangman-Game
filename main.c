#include <stdio.h>
#include <stdlib.h>

int char_input;

int menu()
{
    printf("Enter [1] to play a new game\nAnd also enter [2] to resume your previous game:");
    scanf("%d",char_input);
    if(char_input==1)
    {

    }
    if(char_input==2)
    {

    }
    else
    {
        printf("Wrong input!\n");
        menu();
    }
}
int main()
{
    printf("Hello Friend...Hello Friend!\n");
    printf("This is a Hangman game.\nLet's play.\n\n");
    printf("Enter your name:");
    char char_name[20];
    scanf("%s",char_name);
    printf("\nWelcome %s!\n\n",char_name);
    menu();


    //hey i learnt how to use git hahahaha
    return 0;
}
