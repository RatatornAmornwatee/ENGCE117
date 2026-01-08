#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

void ShowAll( struct studentNode *walk ) ;
struct studentNode *AddNode( struct studentNode** , const char[ 20 ] , int , char , float ) ;
void InsNode( struct studentNode* , const char[ 20 ] , int  , char, float ) ;
void DelNode( struct studentNode* ) ;

int main() {
    struct studentNode *start ;
    struct studentNode *now ;
    start = NULL ;

    now = AddNode( &start , "one" , 6 , 'M' , 3.11 ) ;
    ShowAll( start ) ;
    now = AddNode( &start , "two" , 8 , 'F' , 3.22 ) ;
    ShowAll( start ) ;
    InsNode( now , "three" , 10 , 'M' , 3.33 ) ;
    ShowAll( start ) ;
    InsNode( now , "four" , 12 , 'F' , 3.44 ) ;
    ShowAll( start ) ;
    DelNode( now ) ;
    ShowAll( start ) ;

    delete start , now ;

    return 0 ;
}// end main function

void ShowAll(struct studentNode *walk) {
    while ( walk != NULL ) {
        printf("%s " , walk->name ) ;
        walk = walk->next ;
    }// end wile loop

    printf( "\n" ) ;
}// end ShowAll function

struct studentNode *AddNode( struct studentNode **walk , const char name[ 20 ] , int age , char sex , float gpa ) {
    struct studentNode *temp = NULL ;
    
    while( *walk != NULL ) {
        temp = *walk ;
        walk = &(*walk)->next ;
    }// end while loop

    *walk = new struct studentNode ;
    strcpy( (*walk)->name , name ) ;
    (*walk)->age = age ;
    (*walk)->sex = sex ;
    (*walk)->gpa = gpa ;
    (*walk)->next = NULL ;

    return *walk ;
}// end AddNode function

void InsNode( struct studentNode *walk , const char name[ 20 ] , int age , char sex , float gpa ) {
    struct studentNode *temp =  walk->next ;

    walk->next = new struct studentNode ;
    strcpy( walk->next->name , name ) ;
    walk->next->age = age ;
    walk->next->sex = sex ;
    walk->next->gpa = gpa ;
    walk->next->next = temp ;
}// end InsNode function

void DelNode( struct studentNode *walk ) {
    struct studentNode *temp =  walk->next->next ;
    
    delete walk->next  ;

    walk->next = temp ;
}// end DelNode function
