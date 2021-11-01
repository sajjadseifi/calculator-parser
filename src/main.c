#include <stdio.h>
#include "include/parser.h"
#include "include/backend.h"
#include "include/error.h"

int main(int argc, char **argv)
{
    AST_node *icode;
    int stauts = 0;
    if(argc >1 && argv[1] == 1) 
    {
        stauts = 1;
    }
    if(!parse_program(&icode))
    {
        printf("no top-level experssion\n");
        return 1;
    }

    process(icode,stauts);
        
    return 0;
}