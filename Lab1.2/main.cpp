#include <stdio.h>

void GetSet( int ** , int * ) ;

int main() {
    int *data, num;
    GetSet( &data, &num ) ;

    return 0 ;
}// end main function

void GetSet( int **data , int *num ) {
    if ( scanf( "%d" , num ) != 1 ) {
        printf( "Error" ) ;
        return ;
    }// end if

    if ( *num <= 0 ) {
        printf( "Error" ) ;
        return ;
    }// end if

    int i = 0 ;
    int *arr ;
    arr = new int[ *num ] ;

    for ( i = 0 ; i < *num ; i++ ) {
        scanf( "%d" , &arr[ i ] ) ;
    }// end for loop

    *data = arr ;
}// end GetsSet function