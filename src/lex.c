#include "include/lex.h"

static int is_whitespace(int ch)
{
    if(ch == ' ' || ch == '\t' || ch == '\t')
        return 1;
    return 0;
}

token_type token;
void get_next_token()
{
    int ch;

    do {
        ch = getchar();
        if(ch < 0 )
        {
            token.class = EOF;
            token.reper = '#';
            return;
        }
    } while(is_whitespace(ch));

    if(ch >= '0' && ch <= '9')
        token.class = DIGIT;
    else 
        token.class = ch;

    token.reper = ch;
}