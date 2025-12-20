#include <stdio.h>
#include <string.h>

struct student {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
} ;

struct student ( *GetStudent( int *room ) )[ 10 ] ;

int main() {
    struct student ( *children )[ 10 ] ;
    int group ;

    children = GetStudent( &group ) ;

    if ( *children == nullptr ) {
        return 1 ;
    }// end if

    int i ;
    int j ;

    printf( "ROOM\tNAME\tAGE\tSEX\tGPA\n" ) ;
    for( i = 0 ; i < group ; i++ ) {
        for( j= 0 ; j < 10 ; j++ ) {
            printf( "%d\t%s\t%d\t%c\t%.2f\n" , i + 1 , children[ i ][ j ].name , children[ i ][ j ].age , children[ i ][ j ].sex , children[ i ][ j ].gpa ) ;
        }// end for loop
    }// end for loop

    delete [] children ;
    
    return 0 ;
}// end main function

struct student ( *GetStudent( int *room ) )[ 10 ] {
    if ( scanf( "%d" , room ) != 1 ) {
        return nullptr ;
    }// end if

    if ( *room < 0 ) {
        return nullptr ;
    }// end if

    struct student ( *child )[ 10 ] = new student[ *room ][ 10 ] ;

    int i = 0 ;
    int j = 0 ;

    for( i = 0 ; i < *room ; i++ ) {

        printf( "--- Room %d ---\n" , i + 1 ) ;

        for( j = 0 ; j < 10 ; j++ ) {
            char name[ 20 ] ;

            printf( "Name: " ) ;
            scanf( "%s" , name ) ;
            strcpy( child[ i ][ j ].name , name ) ;

            printf( "Age: " ) ;
            scanf( "%d" , &child[ i ][ j ].age ) ;

            printf( "Sex: " ) ;
            scanf(" %c", &child[i][j].sex ) ;

            printf("GPA: ");
            scanf("%f", &child[i][j].gpa ) ;

            printf( "\n" ) ;
        }// end for loop
    }// end for loop

    return child ;
}// end GetStudent function