#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int repeat_check( char* input )
{
    int len = 0;
    int i = 0, j = 0, walk = 0;
    int possible_repeat = 0;
    int possible_len = 0;
    char* handle = NULL;
    
    if( input == NULL )
        return -1;
    
    len = strlen((const char*)input);
    printf("input len:%d\r\n", len);
    handle = (char*)calloc( 1, len );
    if( handle == NULL )
        return -1;
    
    
    
    for( i = 0; i < len; i++ )
    {
        if( possible_repeat == 0 )
        {
            //printf("handle[0]:%c input[%d]:%c\r\n", handle[0], i, input[i] );
            if( handle[0] == input[i] )
            {
                possible_repeat = 1;
                possible_len = i;
                walk++;
            }
            else
            {
                // reset
                walk = 0;
                possible_repeat = 0;
                possible_len = 0;
            }       
        }
        else
        {
            if( walk == possible_len )
                walk = 0;
            
            if( handle[0 + walk] == input[i] )
            {
                walk++;
            }  
            else
            {
                walk = 0;
                possible_repeat = 0;
                possible_len = 0;                
                
            }    
            
        }    
            
 
        handle[i] = input[i];  
        
    }  
    printf( "handle:[%s] possible_repeat:%d possible_len:%d\r\n", handle, possible_repeat, possible_len );
    if( possible_repeat )
    {
        handle[ possible_len ] = '\0';
        printf( "pattern: %s\r\n", handle );
        free(handle);
        handle = NULL;
        return possible_len;
        
    }
    else
    {
        free(handle);
        handle = NULL;
        return 0;
    }    
}

int repeat_check_advance( char* input )
{
    int len = 0;
    int i = 0, j = 0, walk = 0;
    int possible_repeat = 0;
    int possible_len = 0;
    int repeat_times = 0;
    char* handle = NULL;
    
    if( input == NULL )
        return -1;
    
    len = strlen((const char*)input);
    printf("input len:%d\r\n", len);
    handle = (char*)calloc( 1, len );
    if( handle == NULL )
        return -1;
    
    
    
    for( i = 0; i < len; i++ )
    {
        //printf("handle[0]:%c input[%d]:%c\r\n", handle[0], i, input[i] );
        if( handle[0 + walk] == input[i] )
        {
            possible_repeat = 1;
            if( possible_repeat && possible_len == 0 )
            {    
                possible_len = i;
                repeat_times++;
            }

            if( walk == possible_len )
            {    
                walk = 0;
            }    
            walk++;
        }
        else
        {
            // reset
            walk = 0;
            possible_repeat = 0;
            possible_len = 0;
            repeat_times = 0;
        }       

        handle[i] = input[i];  
    }  

    if( possible_repeat )
    {
        handle[ possible_len ] = '\0';
        printf( ">> pattern: %s possible_len:%d repeate times: %d\r\n", handle, possible_len, repeat_times );
        free(handle);
        handle = NULL;
        return possible_len;
        
    }
    else
    {
        free(handle);
        handle = NULL;
        return 0;
    }    
}

int repeat_check_advance_v1( char* input )
{
    int len = 0;
    int i = 0, j = 0, walk = 0;
    int possible_len = 0;
    int repeat_times = 0;
    char* handle = NULL;
    
    if( input == NULL )
        return -1;
    
    len = strlen((const char*)input);
    handle = (char*)calloc( 1, len );
    if( handle == NULL )
        return -1;
    
    
    
    for( i = 0; i < len; i++ )
    {
        if( handle[0 + walk] == input[i] )
        {
            if( ! possible_len )
            {    
                possible_len = i;
                repeat_times++;
            }

            if( walk == possible_len )
            {    
                walk = 0;
                repeat_times++;
            }    
            walk++;
        }
        else
        {
            // reset
            walk = 0;
            possible_len = 0;
            repeat_times = 0;
        }       

        handle[i] = input[i];  
    }  

    if( possible_len && repeat_times )
    {
        handle[ possible_len ] = '\0';
        printf( ">> input_len:%d pattern: %s possible_len:%d repeat_times: %d\r\n", len, handle, possible_len, repeat_times );
        free(handle);
        handle = NULL;
        return possible_len;
    }
    else
    {
        free(handle);
        handle = NULL;
        return 0;
    }    
}
int main( int argc, char* argv[] )
{
    char input[]="`~!@#$%^&*()_-+=`~!@#$%^&*()_-+=";

    if( argc < 2 )
    {
        printf("you forget input check string.\r\n");
        printf( "check result: %d\r\n", repeat_check_advance_v1(input) );
        return 1;
    }
    //printf( "check result: %d\r\n", repeat_check(argv[1]) );
    printf("=============================\r\n");
    //printf( "check result: %d\r\n", repeat_check_advance(argv[1]) );
    printf( "check result: %d\r\n", repeat_check_advance_v1(argv[1]) );
    
    return 0;
}
