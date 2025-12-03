#include <stdio.h>

int *GetMatrix( int *row , int *col ) ;

int main() {
    int *data ;
    int m ;
    int n ;
    data = GetMatrix( &m , &n ) ;

    for( int i = 0 ; i < m ; i++ ) {
        for( int j = 0 ; j < n ; j++ ) {
            printf("%d %d : %d \n" , i , j , data[ i * m + j ] ) ;
        }// end j for loop
    }// end i for loop 
        
    delete [] data ;
    return 0 ;
}// end main function

int *GetMatrix(int *row , int *col ) {
    printf( "Row: " ) ;
    if ( scanf( "%d" , row ) != 1 ) {
        printf( "Error" ) ;
        return NULL;
    }// end if

    printf( "Column: " ) ;
    if ( scanf( "%d" , col ) != 1 ) {
        printf( "Error" ) ;
        return NULL;
    }// end if

    if ( *row * *col <= 0 ) {
        printf( "Error" ) ;
        return NULL;
    }// end if

    int size = *row * *col ;
    int *value ;
    value = new int[ size ] ;
    int i = 0 ;
    int j = 0 ;

    for( i = 0 ; i < *row ; i++ ) {
        for( j = 0 ; j < *col ; j++ ) {
            scanf( "%d" , &value[ i * *row + j ] ) ;
        }// end j for loop
    }//end i for loop

    return value ;
}//end GetMatrix function