#include <stdio.h>

void GetMatrix( int **value , int *row , int *col ) ;

int main() {
    int *data ;
    int m ;
    int n ;
    GetMatrix( &data , &m , &n ) ;

    for( int i = 0 ; i < m ; i++ ) {
        for( int j = 0 ; j < n ; j++ ) {
            printf("%d %d : %d \n" , i , j , data[ i * m + j ] ) ;
        }// end j for loop
    }// end i for loop 
        
    delete [] data ;
    return 0 ;
}// end main function

void GetMatrix( int **value , int *row , int *col ) {
    printf( "Row: " ) ;
    if ( scanf( "%d" , row ) != 1 ) {
        printf( "Error" ) ;
        return ;
    }// end if

    printf( "Column: " ) ;
    if ( scanf( "%d" , col ) != 1 ) {
        printf( "Error" ) ;
        return ;
    }// end if

    if ( *row * *col <= 0 ) {
        printf( "Error" ) ;
        return ;
    }// end if

    int size = *row * *col ;
    *value = new int[ size ] ;
    int i = 0 ;
    int j = 0 ;

    for( i = 0 ; i < *row ; i++ ) {
        for( j = 0 ; j < *col ; j++ ) {
            scanf( "%d" , &(*value)[ i * *row + j ] ) ;
        }// end j for loop
    }//end i for loop
}//end GetMatrix function