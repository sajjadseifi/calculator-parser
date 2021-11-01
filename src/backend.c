#include <stdio.h>
#include "include/parser.h"
#include "include/backend.h"
static void code_gen_operator(Operator *oper)
{
    switch (*oper)
    {
        case '+':printf("plus\n"); break;
        case '-':printf("min\n"); break;
        case '/':printf("div\n"); break;
        case '*':printf("mult\n"); break;
    }
}
static void code_gen_experssion(Expression *expr)
{
    switch (expr->type)
    {
    case 'D': 
        printf("push %d\n",expr->value);
        break;
    case 'P': 
        code_gen_experssion(expr->left);
        code_gen_experssion(expr->right);
        code_gen_operator(expr->oper);
        break;
    }
}
static int interpret_experssion(Expression *expr)
{
    switch (expr->type)
    {
    case 'D': 
        return expr->value;
    case 'P': 
        int left_expr = interpret_experssion(expr->left);
        int right_expr =interpret_experssion(expr->right);
        switch (expr->oper)
        {
            case '+': return left_expr + right_expr; 
            case '-': return left_expr - right_expr; 
            case '*': return left_expr * right_expr; 
            case '/': return left_expr / right_expr; 
        }
        break;
    }
    return 0;
}

void process(AST_node *icode,int status)
{
    if(status == 0)
    {
        code_gen_experssion(icode);
        printf("print\n");
    }
    else {
        int res = interpret_experssion(icode);
        printf("result : %d",res);
    }
}