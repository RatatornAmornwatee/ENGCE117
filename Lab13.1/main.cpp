#include <stdio.h>

int *KnapsackDP( int *w, int *v, int n, int wx ) ;

int main(){
    int n = 5 ;
    int i = 0 ;
    int wx = 11 ;
    int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
    int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
    int *x ;
    x = KnapsackDP( w, v, n, wx ) ;
    for( i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
    return 0 ;
} // end main function

int *KnapsackDP( int *w, int *v, int n, int wx ) {
    int u[ n ][ wx + 1 ] ;
    int *y[ n ][ wx + 1 ] ;
    int i, j, k ;

    for( i = 0 ; i < n ; i++ ) {
        for( j = 0 ; j <= wx ; j++ ) {
            int a, b ;
            int *Sa, *Sb ;

            if ( i - 1 < 0 ) {
                a = 0 ;
                Sa = new int[ n ]() ; 
            } else {
                a = u[ i - 1 ][ j ] ;
                Sa = y[ i - 1 ][ j ] ;
            } // end if else

            if ( j - w[ i ] < 0 ) {
                b = -999999 ;
                Sb = new int[ n ]() ;
            } else if ( j - w[ i ] == 0 || i - 1 < 0 ) {
                b = v[ i ] ;
                Sb = new int[ n ]() ;
                Sb[ i ] = 1 ;
            } else {
                b = u[ i - 1 ][ j - w[ i ] ] + v[ i ] ;
                Sb = new int[ n ] ;
                for ( k = 0 ; k < n ; k++ ) Sb[ k ] = y[ i - 1 ][ j - w[ i ] ][ k ] ;
                Sb[ i ] = 1 ;
            } // end if else

            if ( a > b ) {
                u[ i ][ j ] = a ;
                y[ i ][ j ] = Sa ;
            } else {
                u[ i ][ j ] = b ;
                y[ i ][ j ] = Sb ;
            } // end if else
        } // end for loop
    } // end for loop

    return y[ n - 1 ][ wx ] ;
} // end KnapsackDP function