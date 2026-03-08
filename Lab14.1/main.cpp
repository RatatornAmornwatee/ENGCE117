#include <stdio.h>

int KnapsackBT( int *w, int *v, int n, int wx, int i, int *x ) ;

int main() {
    int n = 5 ;
    int i = 0 ;
    int wx = 11 ;
    int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
    int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
    int x[ 5 ] ;
    int vx ;
    vx = KnapsackBT( w, v, n, wx, 0, x ) ;
    printf( "Value = %d\n", vx ) ;
    for( i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
    return 0 ;
}// end main function

int KnapsackBT( int *w, int *v, int n, int wx, int i, int *x ) {
    int b = 0 ;
    int k ;
    int a ;
    int j ;
    int y[ 100 ] ;
    for( k = 0 ; k < n ; k++ ) x[ k ] = 0 ;
    for( k = i ; k < n ; k++ ) {
        if( w[ k ] <= wx ) {
            a = v[ k ] + KnapsackBT( w, v, n, wx - w[ k ], k + 1, y ) ;
            if( a > b ) {
                b = a ;
                for( j = 0 ; j < n ; j++ ) x[ j ] = y[ j ] ;
                x[ k ] = 1 ;
            }// end if
        }// end if
    }// end for
    return b ;
}//end KnapsackBT function