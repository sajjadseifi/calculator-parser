#ifndef LEX_HEDAER
#define LEX_HEDAER
#define EOF 256
#define DIGIT 257

typedef struct {
    int class;
    char reper;
} token_type;

extern token_type token;
extern void get_next_token(void);

#endif