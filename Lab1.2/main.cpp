#include <stdio.h>

void GetSet( int ** , int * ) ;

int main() {
    int *data, num ;
    GetSet( &data, &num ) ;

    for ( int i = 0 ; i < num ; i++ ) {
        printf("%d",data[i]);
    }// end for loop

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
        if ( scanf( "%d" , &arr[ i ] ) != 1 ) {
            arr[ i ] = 0 ;
        }// end if
    }// end for loop

    *data = arr ;
    delete [] arr ;
}// end GetsSet function