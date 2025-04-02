#ifndef STRUCTS_H
# define STRUCTS_H

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
    struct s_command    *next; //next comando for pipe
}   t_command;

#endif