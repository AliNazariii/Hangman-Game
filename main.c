#include <stdio.h>
#include <stdlib.h>

FILE * AVAILABLE_TOPICS;
FILE * selected_topic;

struct node
{
    char word[30];
    struct node *next;
};

int menu()
{
    printf("Enter [1] to play a new game\nAnd also enter [2] to resume your previous game:");
    int char_input;
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
    AVAILABLE_TOPICS = fopen("AVAILABLE_TOPICS.txt","r");
    char c[500];
    int i=1;
    while(fgets(c,500,AVAILABLE_TOPICS)!= NULL)
    {
        printf("Enter [%d] for:  ",i);
        printf("%s\n",c);
        i++;
    }
    int topic_input;
    printf("So: ");
    scanf("%d",&topic_input);
    open_topic(topic_input);
}

int open_topic(int a)
{
    switch(a)
    {
    case 1:
        selected_topic = fopen("fruits.txt","r");
    case 2:
        selected_topic = fopen("soccer_players.txt","r");
    case 3:
        selected_topic = fopen("programming_languages.txt","r");
    case 4:
        selected_topic = fopen("computer_networks.txt","r");
    case 5:
        selected_topic = fopen("video_games.txt","r");
    }
    init_link(selected_topic);
}

int init_link(FILE *b)
{
    struct node *current = head;
    char c_word;
    while(feof(b)==0)
    {
        fscanf(b,"%s",current->word);

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

    return 0;
}
