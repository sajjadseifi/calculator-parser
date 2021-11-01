#include <stdio.h>
#include <stdlib.h>
#include "include/lex.h"
#include "include/parser.h"
#include "include/error.h"

// private 
static Expression *new_experssion(void){
    return (Expression *) malloc(sizeof(Expression));
}
static void free_experssion(Expression *expr); 
static int parse_operator(Operator *oper_p); 
static int parse_experssion(Expression **eper_p); 

//public 
int parse_program(AST_node **icode_p)
{
    Expression *expr;
    get_next_token();
    if(parse_experssion(&expr))
    {   
        if(token.class != EOF)
        {
            printf("garbage after end of program\n");
        }

        *icode_p = expr;
        return 1;
    }
    return 0;
}

static void free_experssion(Expression *expr)
{
    free(expr);
}

static int parse_operator(Operator *oper_p) 
{
    switch (token.class)
    {
    case '+': case '-':case '*':case '/':
        *oper_p = token.class;
        get_next_token();
        return 1;    
    default:
        return 0;
    }
}

static int parse_experssion(Expression **expr_p)
{
    Expression *expr = *expr_p = new_experssion();
    
    if(token.class == DIGIT)
    {   
        expr->type  = 'D';
        expr->value = token.reper - '0';
        get_next_token();
        return 1;
    }

    if(token.class == '(')
    {
        expr->type = 'P';
        get_next_token();
        if(!parse_experssion(&expr->left))
        {
            printf("missing experssion");
        }
        if(!parse_operator(&expr->oper))
        {
            printf("missing operator");
        }
        if(!parse_experssion(&expr->right))
        {
            printf("missing experssion");
        }
        if(token.class == ')')
        {
            printf("missing )");
        }
        get_next_token();
        return 1;
    }

    free_experssion(expr);
    return 0;
}