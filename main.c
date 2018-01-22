#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE * AVAILABLE_TOPICS ;
FILE * selected_topic ;

struct node
{
    char word[30] ;
    struct node *next ;
};
struct node * head = NULL ;

int menu() //this is my main menu
{
    printf ( "Enter [1] to play a new game\nAnd also enter [2] to resume your previous game:" ) ;
    int char_input ;
    scanf ( "%d", &char_input ) ;
    if ( char_input == 1 )
    {
        new_game();
    }
    if ( char_input == 2 )
    {

    }
    else
    {
        printf ( "Wrong input!\n" ) ;
        menu() ;
    }
}

int new_game() //show topics and select one of them
{
    AVAILABLE_TOPICS = fopen ( "AVAILABLE_TOPICS.txt" , "r" ) ;
    char c[500] ;
    int i = 1 ;
    while ( fgets( c , 500 , AVAILABLE_TOPICS ) != NULL )
    {
        printf ( "Enter [%d] for:  " , i ) ;
        printf ( "%s\n" , c ) ;
        i++ ;
    }
    int topic_input ;
    printf ( "So: " ) ;
    scanf ( "%d" , &topic_input ) ;
    open_topic ( topic_input ) ;
}

int open_topic ( int a ) //yeah open topic
{
    switch ( a )
    {
    case 1 :
        selected_topic = fopen ( "fruits.txt" , "r" ) ;
        break;
    case 2 :
        selected_topic = fopen ( "soccer_players.txt" , "r" ) ;
        break;
    case 3 :
        selected_topic = fopen ( "programming_languages.txt" , "r" ) ;
        break;
    case 4 :
        selected_topic = fopen ( "computer_networks.txt" , "r" ) ;
        break;
    case 5 :
        selected_topic = fopen ( "video_games.txt" , "r" ) ;
        break;
    }
    init_link ( selected_topic ) ;
}

extern int init_link ( FILE * b ) //put each word int a node of link list
{
    head = ( struct node* )malloc( sizeof ( struct node ) ) ;
    head->next = NULL;
    struct node *current = head;
    char c_word ;
    while(1)
    {
        fscanf( b , "%s" , current->word ) ;
        if( feof ( b ) )
        {
            current->next = NULL ;
            break;
        }
        add_link_node( current ) ;
        current = current->next ;
        current->next = NULL ;
    }

    // delete the last node because it is extra
    struct node *tmp ;
    tmp = head ;
    while (tmp->next != NULL)
    {
        tmp = tmp -> next ;
    }
    free(tmp);
    tmp->next=NULL ;
    //until here
    find_random_word(length_link(head));
}

int length_link (struct node * head) //find the length of the linked list
{
    struct node * temp = head;
    int j = 0 ;
    while(temp->next != NULL )
    {
        temp = temp -> next ;
        j++;
    }
    return j;
}

int add_link_node ( struct node *current ) //add a new node at the end of the linked list
{
    current->next = ( struct node* )malloc( sizeof ( struct node ) ) ;
}

void delete_node()
{

}
int main()
{
    printf ( "Hello Friend...Hello Friend!\n" ) ;
    printf ( "This is a Hangman game.\nLet's play.\n\n" ) ;
    printf ( "Enter your name:" ) ;
    char char_name[20] ;
    scanf ( "%s" , char_name ) ;
    printf ( "\nWelcome %s!\n\n" , char_name ) ;
    menu() ;

    return 0 ;
}
