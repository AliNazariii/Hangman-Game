#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

FILE * AVAILABLE_TOPICS ;
FILE * selected_topic ;
FILE * players ;


//define the structure of nodes
struct node
{
    char word [ 30 ] ;
    struct node * next ;
} ;
struct node * head = NULL ;
//

//define the structure of saving information of players
typedef struct
{
    char name [ 30 ] ;
    int high_score ;
    int sum_score ;
} player ;
//

int menu() //this is my main menu
{
    //show the description of menu and get what player wants
    printf ( "Enter [1] to play a new game\nAnd also enter [2] to resume your previous game:" ) ;
    int char_input ;
    scanf ( "%d", & char_input ) ;
    //

    // if player choose 1, we will start new game with all of the topics and words
    if ( char_input == 1 )
    {
        new_game () ;
        return 1 ;
    }
    //

    //if player choose 2, we will continue his previous game
    if ( char_input == 2 )
    {

    }
    else //yeah, this is nothing ha ha
    {
        printf ( "Wrong input!\n" ) ;
        menu () ;
    }
}

int new_game () //show topics and select one of them //when the player press 1 we will come here
{
    AVAILABLE_TOPICS = fopen ( "AVAILABLE_TOPICS.txt" , "r" ) ; //open file of topics

    //put each line in a string and print each topic
    char c [ 500 ] ;
    int i = 1 ;
    while ( fgets ( c , 500 , AVAILABLE_TOPICS ) != NULL )
    {
        printf ( "Enter [%d] for:  " , i ) ;
        printf ( "%s\n" , c ) ;
        i++ ;
    }
    //

    // here we ask player to choose a topic
    int topic_input ;
    printf ( "So: " ) ;
    scanf ( "%d" , & topic_input ) ;
    //

    open_topic ( topic_input ) ;
}

int open_topic ( int a ) //here we open the selected topic
{
    //open the selected file of words
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
    case 6 :
        selected_topic = fopen ( "name_of_teacher_assistants.txt" , "r" ) ;
        break ;
    case 7 :
        selected_topic = fopen ( "adobe_products.txt" , "r" ) ;
        break ;
    case 8 :
        selected_topic = fopen ( "animals.txt" , "r" ) ;
        break ;
    case 9 :
        selected_topic = fopen ( "colors.txt" , "r" ) ;
        break ;
    }
    //

    init_link ( selected_topic ) ;
}

int init_link ( FILE * b )  //put each word into a node of linked list
{
    head = ( struct node* )malloc( sizeof ( struct node ) ) ;
    head -> next = NULL;
    struct node * current = head ;
    char c_word ;
    while ( 1 )
    {
        //put each word in a node and create the next node
        fscanf( b , "%s" , current -> word ) ;
        add_link_node ( current ) ;
        current = current -> next ;
        current -> next = NULL ;
        if( feof ( b ) )
        {
            break ;
        }
    }

    // delete the last two node because they are extra
    struct node * to_delete = head ;
    struct node * tmp = head ;
    while ( to_delete -> next != NULL )
    {
        tmp = to_delete ;
        to_delete = to_delete -> next ;
    }
    tmp -> next = NULL ;
    free ( to_delete ) ;
    to_delete = head ;
    tmp = head ;
    while ( to_delete -> next != NULL )
    {
        tmp = to_delete ;
        to_delete = to_delete -> next ;
    }
    tmp -> next = NULL ;
    free ( to_delete ) ;
    //until here


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

    process_topic () ;
}

void add_link_node ( struct node * current ) //add a new node at the end of the linked list
{
    current -> next = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
}

void process_topic()
{
    int random;
    char random_word [ 30 ] ;
    while ( 1 )
    {
        random = find_random_word ( length_link ( head ) ) ;         //find a word randomly to start process
        init_word ( random , random_word ) ; //put the word in an array
        process_word_begin ( random_word ) ; //process that word to play

        //check if the nodes are finished or not
        if ( length_link ( head ) == 1 )
        {
            free ( head ) ; //delete the last remaining node
            break ;
        }
        //

        delete_node ( random ) ; //delete that node of word
    }
}

int true_or_false ( char c , char guessed_char ) //to check whether this character is in this word or not
{
    if ( guessed_char == c )
    {
        return 1 ;
    }
    return 0 ;
}

int process_word_begin ( char random_word [] )
{
    int word_length = strlen( random_word ) ;
    int p , o , l ;

    char print_word [ word_length ] ;
    for ( p = 0 ; p < word_length ; p++ )
    {
        print_word [ p ] = '_' ;
    }

    printf( "\nSo the word is like this: " ) ;
    print_words( print_word , word_length ) ;
    printf( "\n\n" ) ;

    char guessed_char;
    int error ;
    int guessed ;
    guessed = 0 ;
    for ( l = 0 ; l < 5 ; )
    {
        printf ( "Enter your guess: " ) ;
        getchar () ;
        scanf ( "%c", & guessed_char ) ;
        printf ( "So: " ) ;
        error = 0 ;
        for ( o = 0 ; o < word_length ; o++ )
        {
            if ( true_or_false ( random_word [ o ] , guessed_char ) == 1 )
            {
                print_word [ o ] = guessed_char ;
                guessed++ ;
            }
            else
            {
                error++ ;
            }
        }
        print_words( print_word , word_length ) ;
        printf( "\n\n" ) ;

        if ( error == word_length )
        {
            l++ ;
            if ( l == 5 )
            {
                printf( "Oh! You could not guess the word! " ) ;
                printf( "\nThe word was: %s " , random_word ) ;
                break ;
            }
        }

        if ( guessed == word_length )
        {
            printf( "Wow you guessed the word correctly! \n_________________________________________\n" ) ;
            break ;
        }
    }
}

void print_words ( char print_word [] , int word_length ) //print the word , character by character
{
    int q ;
    for ( q = 0 ; q < word_length ; q++ )
    {
        printf( " %c" , print_word [ q ] ) ;
    }
}

void init_word ( int random , char random_word [] ) //go to the node and copy the word to an array to process
{
    int y ;
    struct node * selected_node = head ;
    //go to a loop to reach the selected node
    for ( y = 1 ; y < random ; y++ )
    {
        selected_node = selected_node -> next ;
    }
    //

    strcpy( random_word , selected_node -> word ) ; //copy the word to the array
}

void delete_node ( int random )  // delete the node that we have played with it
{
    struct node * deleted_node = head ;
    struct node * last = head ;
    int k ;
    //if it is the first node we should do this
    if ( random == 1 )
    {
        head = head -> next ;
        free ( deleted_node ) ;
        return ;
    }
    //

    //if it is the last node, we should do this
    else if ( random == length_link ( head ) )
    {
        while ( deleted_node -> next != NULL )
        {
            last = deleted_node ;
            deleted_node = deleted_node -> next ;
        }
        last -> next = NULL ;
        free ( deleted_node ) ;
        return ;
    }
    //

    else
    {
        for ( k = 1 ; k < random ; k++ )
        {
            last = deleted_node ;
            deleted_node = deleted_node -> next ;
        }
        last -> next = deleted_node -> next ;
        free( deleted_node ) ;
        return ;
    }
}

int find_random_word ( int length_link ) //find a random number to select that node of words
{
    return ( ( ( rand () ) % length_link ) + 1 ) ;
}

int length_link ( struct node * head ) //find the length of the linked list
{
    struct node * temp = head ;
    int j = 1 ;
    while ( temp -> next != NULL )
    {
        temp = temp -> next ;
        j++ ;
    }
    return j ;
}

void init_players ()
{
    players = fopen ( "players.txt" , "a+" ) ;

    //get player's name and welcoming
    printf ( "Enter your name:" ) ;
    player now ;
    scanf ( "%s" , now . name ) ;
    fprintf ( players , "\n%s" , now . name ) ;
    printf ( "\nWelcome %s!\n\n" , now . name ) ;
    //

    while ( 1 )
    {
        menu () ;
    }


}
int main ()
{

    time_t t = time( NULL ) ;
    srand ( t ) ;

    //greeting
    printf ( "Hello Friend...Hello Friend!\n" ) ;
    printf ( "This is a Hangman game.\nLet's play.\n\n" ) ;
    //

    init_players () ;

    return 0 ;
}
