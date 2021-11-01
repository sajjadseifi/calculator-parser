#ifndef PARSER_HEADER
#define PARSER_HEADER

typedef int Operator;

typedef struct _expression {
    char type;
    int value;
    Operator oper;    
    struct _experssion *left,*right;
} Expression;

typedef Expression AST_node;

extern void parse_program(AST_node **);

#endif