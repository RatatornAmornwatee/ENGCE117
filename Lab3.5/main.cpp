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

    int showi ;
    int showj ;

    printf( "ROOM\tNAME\tAGE\tSEX\tGPA\n" ) ;
    for( showi = 0 ; showi < group ; showi++ ) {
        for( showj = 0 ; showj < 10 ; showj++ ) {
            printf( "%d\t%s\t%d\t%c\t%.2f\n" , showi + 1 , children[ showi ][ showj ].name , children[ showi ][ showj ].age , children[ showi ][ showj ].sex , children[ showi ][ showj ].gpa ) ;
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
            if ( scanf( "%s" , name ) != 1 ) {
                return nullptr ;
            }
            strcpy( child[ i ][ j ].name , name ) ;

            printf( "Age: " ) ;
            if ( scanf( "%d" , &child[ i ][ j ].age ) != 1 ) {
                return nullptr ;
            }

            printf( "Sex: " ) ;
            if ( scanf(" %c", &child[ i ][ j ].sex ) != 1 ) {
                return nullptr ;
            }

            printf("GPA: ") ;
            if ( scanf("%f", &child[ i ][ j ].gpa ) != 1 ) {
                return nullptr ;
            }

            printf( "\n" ) ;
        }// end for loop
    }// end for loop

    return child ;
}// end GetStudent function