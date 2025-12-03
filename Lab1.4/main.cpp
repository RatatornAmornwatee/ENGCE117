#include <stdio.h>

int GetSet( int [] ) ;

int main() {
    int *data ; 
    int num ;
    int i = 0 ;
    num = GetSet( data ) ;

    for( i = 0 ; i < num ; i++ ) {
        printf( "\n%d" , data[i] ) ;
    }

    delete [] data ;

    return 0 ;
}// end main function

int GetSet( int data[] ) {
    int num ;

    if ( scanf( "%d" , &num ) != 1 ) {
        printf( "Error" ) ;
        return 0 ;
    }// end if

    if ( num <= 0 ) {
        printf( "Error" ) ;
        return 0 ;
    }// end if

    int i =  0 ;

    for( i = 0 ; i < num ; i++ ) {
        scanf( "%d" , &data[i] ) ;
    }//end for loop

    return num ;
}// end GetSet function