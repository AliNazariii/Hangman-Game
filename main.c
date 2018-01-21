#include <stdio.h>
#include <stdlib.h>

int char_input;
FILE * file_topic;

int menu()
{
    printf("Enter [1] to play a new game\nAnd also enter [2] to resume your previous game:");
    scanf("%d",&char_input);
    if(char_input==1)
    {
        new_game();
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

int new_game()
{
    file_topic = fopen("AVAILABLE_TOPICS.txt","r+");
    char c[500];
    int i=1;
    while(fgets(c,500,file_topic)!= NULL)
    {
        printf("Enter [%d] for:  ",i);
        printf("%s\n",c);
        i++;
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
