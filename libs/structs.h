#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum    s_tokens
{
    PIPE,
    
}   t_tokens;

typedef struct s_redirect
{
    char    *type;
    char    *filename;
}   t_redirect;


typedef struct s_command
{
    char        **args;
    t_redirect   *redirects;
    int         redirect_count;
    struct s_command    *next;
}   t_command;

#endif