#include <stdio.h>
#include <stdlib.h>
int main ( int argc , char * argv [ argc +1]) {
    int ret = EXIT_FAILURE;
    
    fprintf_s( stderr , " freopen of %s:", argv [1]) ;
    if ( freopen ( argv [1] , "a", stdout ) ) {
    ret = EXIT_SUCCESS ;
    puts ("feeling fine today") ;
    }
    perror (0) ;
    return ret ;
    }