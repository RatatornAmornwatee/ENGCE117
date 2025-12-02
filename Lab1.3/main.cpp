#include <stdio.h>

int *GetSet( int* ) ;

int main() {
    int *data , num ;

    data = GetSet( &num ) ;

    return 0 ;
}//end main function

int *GetSet( int *num ) {
    // Input Text Varidation
    if ( scanf( "%d" , num ) != 1 ) {
        printf( "Array size input error" ) ;
        return NULL ;
    } // enf if

     // Input Size Varidation
    if ( *num <= 0 ) {
        printf( "Array size must be positive number" ) ;
        return NULL ;
    }

    int *arr = new int[10] ;
    int i = 0 ;

     // Storage data to array
    for( i = 0 ; i < *num ; i++ ) {
        scanf( "%d" , &arr[ i ] ) ;
    }// end for loop

    return arr ;
}// end GetSet function