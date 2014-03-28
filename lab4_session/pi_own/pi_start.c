#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

int N, N4;
char a[10240], b[10240], c[10240];
char string[100];

unsigned quo_239[2650];
unsigned rest_239[2650];
unsigned quo_25[497];
unsigned rest_25[497];
unsigned quo_5[297];
unsigned rest_5[297];

void DIVIDE_239( char *x )                           
{                                                
    int k = 0;
    unsigned q, r, u, r_aux;
    r = x[k];                                       
    for( k = 0; k < N4; k++ )                  
    {   
 //       u = (r << 3) + r + r + x[k];                       
        q = quo_239[r];  
        r_aux = rest_239[r];
        r = (r_aux << 3) + r_aux + r_aux + x[k + 1] ;                         
        x[k] = q;                                
    }
    q = quo_239[r];                      
    x[k] = q;
}


void DIVIDE_25( char *x )                           
{                                                
    int k = 0;
    unsigned q, r, u, r_aux;
    
    r = x[k];                                       
    for( k = 0; k < N4; k++ )                  
    {   
        x[k] = quo_25[r];    
        r_aux = rest_25[r];
        r = (r_aux << 3) + r_aux + r_aux + x[k + 1] ;                           
                                        
    }                   
    x[k] = quo_25[r]; 
}

void DIVIDE_5( char *x )                           
{                                                
    int k = 0;
    unsigned q, r, r_aux, u;
    r = x[k];                                       
    for( k = 0; k < N4; k++ )                  
    {   
 //       u = (r << 3) + r + r + x[k];                       
        q = quo_5[r]; 
        r_aux = rest_5[r];
        r = (r_aux << 3) + r_aux + r_aux + x[k + 1] ;                           
        x[k] = q;                                
    }
    q = quo_5[r];                      
    x[k] = q;
}

void INI_DIVIDE_25()
{
    int i;
    for (i = 0; i < 497; i++) {
           quo_25[i] = i/25;
           rest_25[i] = i%25;
    }   
}

void INI_DIVIDE_5()
{
    int i;
    for (i = 0; i < 297; i++) {
           quo_5[i] = i/5;
           rest_5[i] = i%5;
    }
}

void INI_DIVIDE_239()                           
{        
    int i;
    for (i = 0; i < 2650; i++) {
           quo_239[i] = i/239;
           rest_239[i] = i%239;
    }                                 
}

void DIVIDE( char *x, int n )                           
{                                                
    int j, k;
    unsigned q, r, u;
    long v;

    r = 0;                                       
    for( k = 0; k <= N4; k++ )                  
    {                                            
        u = (r << 3) + r + r + x[k];                       
        q = u / n;                               
        r = u - q * n;                           
        x[k] = q;                                
    }                                           
}

void LONGDIV( char *x, int n )                          
{                                                
    int j, k;
    unsigned q, r, u;
    long v;

    if( n < 6553 )                               
    {                                            
        r = 0;                                   
        for( k = 0; k <= N4; k++ )               
        {                                        
            u = r * 10 + x[k];                   
            q = u / n;                           
            r = u - q * n;                       
            x[k] = q;                            
        }                                       
    }                                            
    else                                         
    {                                            
        r = 0;                                   
        for( k = 0; k <= N4; k++ )              
        {                                       
            if( r < 6553 )                      
            {                                   
                u = r * 10 + x[k];              
                q = u / n;                      
                r = u - q * n;                  
            }                                   
            else                                
            {                                   
                v = (long) r * 10 + x[k];       
                q = v / n;                      
                r = v - q * n;                  
            }                                   
            x[k] = q;                           
        }                                       
    }                                           
}

void MULTIPLY( char *x, int n )                        
{                                            
    int j, k;
    unsigned q, r, u;
    long v;
    r = 0;                                   
    for( k = N4; k >= 0; k-- )               
    {                                        
        q = n * x[k] + r;                    
        r = q / 10;                          
        x[k] = q - r * 10;                   
    }                                        
}

void SET( char *x, int n )                              
{                                                
    memset( x, 0, N4 + 1 );                      
    x[0] = n;                                    
}


void SUBTRACT( char *x, char *y, char *z )                      
{                                                
    int j, k;
    unsigned q, r, u;
    long v;
    for( k = N4; k >= 0; k-- )                   
    {                                            
        if( (x[k] = y[k] - z[k]) < 0 )           
        {                                        
            x[k] += 10;                          
            z[k-1]++;                            
        }                                        
    }                                            
}


void calculate( void );
void progress( void );
void epilog( void );


int main( int argc, char *argv[] )
{
    N = 10000;
    if (argc>1)
      N = atoi(argv[1]);
    
    setbuf(stdout, NULL);

    calculate();

    epilog();

    return 0;
}

void calculate( void )
{
    int j;

    N4 = N + 4;
    INI_DIVIDE_239();
    INI_DIVIDE_25();
    INI_DIVIDE_5();
    SET( a, 0 );
    SET( b, 0 );

    for( j = 2 * N4 + 1; j >= 3; j -= 2 )
    {
        SET( c, 1 );
        LONGDIV( c, j );

        SUBTRACT( a, c, a );
        
        DIVIDE_25( a);
        
        SUBTRACT( b, c, b );
        DIVIDE_239( b);
        DIVIDE_239( b);

        progress();
    }

    SET( c, 1 );

    SUBTRACT( a, c, a );
    DIVIDE_5( a);

    SUBTRACT( b, c, b );
    DIVIDE_239(b);

    MULTIPLY( a, 4 );
    SUBTRACT( a, a, b );
    MULTIPLY( a, 4 );

    progress();
}

/*

 N = 10000                      
 A = 0                          
 B = 0                          
 J = 2 * (N + 4) + 1            
 FOR J = J TO 3 STEP -2         
     A = (1 / J - A) / 5 ^ 2    
     B = (1 / J - B) / 239 ^ 2  
 NEXT J                         
 A = (1 - A) / 5                
 B = (1 - B) / 239              
 PI = (A * 4 - B) * 4           

*/

void progress( void )
{
    printf(".");
}

void epilog( void )
{
    int j;

    {
        fprintf( stdout, " \n3.");
        for( j = 1; j <= N; j++ )
        {
            fprintf( stdout, "%d", a[j]);
            if( j % 5  == 0 )
                if( j % 50 == 0 )
                    if( j % 250  == 0 )
                        fprintf( stdout, "    <%d>\n\n   ", j );
                    else
                        fprintf( stdout, "\n   " );
                else
                    fprintf( stdout, " " );
        }
    }
}

