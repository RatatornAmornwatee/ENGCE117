#include <stdio.h>
#include <string.h>

char *reverse( char str1[] ) ;

int main() {

    char text[ 50 ] = "I Love You" ;
    char *out ;
    out = reverse( text ) ;

    printf( "%s" , out ) ;

    delete [] out ;

    return 0 ;

}// end main function

char *reverse( char str1[] ) {

    int str_size = strlen( str1 ) ;
    
    char *str2 ;
    str2 = new char[ str_size + 1 ] ;

    int i = 0 ;

    for( i = 0 ; i < str_size ; i++ ) {
        str2[ str_size - i - 1 ] = str1[ i ] ;
    }// end for loop

    str2[ str_size ] = '\0' ;

    return str2 ;
    
}// end reverse function