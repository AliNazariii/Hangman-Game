#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

FILE * AVAILABLE_TOPICS ;
FILE * selected_topic ;

struct node
{
    char word [ 30 ] ;
    struct node * next ;
};
struct node * head = NULL ;

typedef struct
{
    char name[30];
    int high_score;
    int sum_score;
}player;

int menu () ; //this is my main menu
int new_game () ; //show topics and select one of them
int open_topic ( int a ) ; //yeah open topic
extern int init_link ( FILE * b ) ; //put each word int a node of link list
int length_link ( struct node * head ) ; //find the length of the linked list
int add_link_node ( struct node * current ) ; //add a new node at the end of the linked list
void delete_node () ; // delete the node that we have played with it
int find_random_word ( int a ) ;  //find a random number to select that node of words

int main ()
{
    printf ( "Hello Friend...Hello Friend!\n" ) ;
    printf ( "This is a Hangman game.\nLet's play.\n\n" ) ;
    printf ( "Ente r your name:" ) ;
    char char_name [ 20 ] ;
    scanf ( "%s" , char_name ) ;
    printf ( "\nWelcome %s!\n\n" , char_name ) ;
    time_t t = time( NULL ) ;
    srand ( t ) ;
    menu () ;

    return 0 ;
}

int menu()
{
    printf ( "Enter [1] to play a new game\nAnd also enter [2] to resume your previous game:" ) ;
    int char_input ;
    scanf ( "%d", & char_input ) ;
    if ( char_input == 1 )
    {
        new_game () ;
        return 1;
    }
    if ( char_input == 2 )
    {

    }
    else
    {
        printf ( "Wrong input!\n" ) ;
        menu () ;
    }
}

int new_game ()
{
    AVAILABLE_TOPICS = fopen ( "AVAILABLE_TOPICS.txt" , "r" ) ;
    char c [ 500 ] ;
    int i = 1 ;
    while ( fgets ( c , 500 , AVAILABLE_TOPICS ) != NULL )
    {
        printf ( "Enter [%d] for:  " , i ) ;
        printf ( "%s\n" , c ) ;
        i++ ;
    }
    int topic_input ;
    printf ( "So: " ) ;
    scanf ( "%d" , & topic_input ) ;
    open_topic ( topic_input ) ;
}

int open_topic ( int a )
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

int init_link ( FILE * b )
{
    head = ( struct node* )malloc( sizeof ( struct node ) ) ;
    head -> next = NULL;
    struct node * current = head ;
    char c_word ;
    while ( 1 )
    {
        fscanf( b , "%s" , current -> word ) ;
        if( feof ( b ) )
        {
            current->next = NULL ;
            break ;
        }
        add_link_node( current ) ;
        current = current -> next ;
        current -> next = NULL ;
    }

    /*
    // delete the last node because it is extra
    struct node * tmp ;
    tmp = head ;
    while ( tmp -> next != NULL )
    {
        tmp = tmp -> next ;
    }
    free ( tmp ) ;
    tmp -> next = NULL ;
    //until here
    printf("\n%d\n",length_link(head));

    current = head ;
    while (1)
    {
        printf("%s\n",current->word);
        if ( current -> next == NULL)
        {
            break;
        }
        current = current -> next ;
    }
    printf("\n%d\n",length_link(head));
    */
    process_topic () ;
}

void process_topic()
{
    int random;
    char random_word [ 30 ] ;
    while ( 1 )
    {
        random = find_random_word ( length_link ( head ) ) ;
        init_word ( random , random_word ) ;
        delete_node ( random ) ;
    }
}

int process_word ()
{
    int number_length;

}

void init_word ( int a , char b [] )
{
    int y ;
    struct node * selected_node = head ;
    for ( y = 1 ; y < a ; y++)
    {
        selected_node = selected_node -> next ;
    }
    strcpy(b,selected_node -> word);
}

void delete_node ( int a )
{
    struct node * deleted_node = head ;
    int k ;
    if ( a == 1 )
    {
        free ( deleted_node ) ;
        return ;
    }
    else if ( a == length_link ( head ) )
    {
        for ( k = 1 ; k < ( a - 1 ) ; k++)
        {
            deleted_node = deleted_node -> next ;
        }
        deleted_node -> next = NULL ;
        deleted_node = deleted_node -> next ;
        free ( deleted_node ) ;
        return ;
    }
    else
    {
        for ( k = 1 ; k < ( a - 1 ) ; k++)
        {
            deleted_node = deleted_node -> next ;
        }
        deleted_node -> next = deleted_node -> next -> next ;
        return ;
    }
}

int find_random_word ( int a )
{
    return ( ( ( rand () ) % a ) + 1 ) ;
}

int length_link ( struct node * head )
{
    struct node * temp = head ;
    int j = 0 ;
    while ( temp -> next != NULL )
    {
        temp = temp -> next ;
        j++ ;
    }
    return j ;
}

int add_link_node ( struct node * current )
{
    current -> next = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
}

