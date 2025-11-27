#include <stdio.h>

int main() {
  int n , i ;

  if( scanf( "%d" , &n ) != 1 ||  n <= 0  ) {
    return 0 ;
  }

  for( i = 0 ; i < n ; i++ ) {
    printf( "[%d] Hello world\n" , i + 1 ) ;
  }

  return 0 ;
}