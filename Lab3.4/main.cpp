#include <stdio.h>
#include <string.h>

struct student {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
} ;

void GetStudent ( struct student child[ 20 ][ 10 ] , int *room ) ;

int main() {
    struct student children[ 20 ][ 10 ] ;
    int group ;
    int i = 0 ;
    int j = 0 ;
    char sex ;

    GetStudent( children , &group ) ;

    printf( "ROOM\tNAME\tAGE\tSEX\tGPA\n" ) ;
    for( i = 0 ; i < group ; i++ ) {
        for( j= 0 ; j < 10 ; j++ ) {
            printf( "%d\t%s\t%d\t%c\t%.2f\n" , i + 1 , children[ i ][ j ].name , children[ i ][ j ].age , children[ i ][ j ].sex , children[ i ][ j ].gpa ) ;
        }
    }

    return 0 ;
}

void GetStudent ( struct student child[ 20 ][ 10 ] , int *room ) {

    if ( scanf( "%d" , room ) != 1 ) {
        return ;
    }

    if ( *room < 0 ) {
        return ;
    }

    int i = 0 ;
    int j = 0 ;

    char name[ 20 ] ;

    for( i = 0 ; i < *room ; i++ ) {

        printf( "--- Room %d ---\n" , i + 1 ) ;

        for( j = 0 ; j < 10 ; j++ ) {
            char name[ 20 ] ;
            char sex ;

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
        }
    }
}