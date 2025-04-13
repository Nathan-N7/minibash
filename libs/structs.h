#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum    s_tk_type
{
    WORD,
    PIPE,
    REDIR_IN,  //<
    REDIR_OUT, //>
    APPEND,  //>>
    HEREDOC //<<
}   t_tk_type;

typedef struct s_redirect
{
    t_tk_type type;
    char    *filename;
}   t_redirect;


typedef struct s_command
{
    char        **args;
    t_redirect   *redirects;
    int         redirect_count;
    struct s_command    *next;
}   t_command;

typedef struct  s_token
{
    t_tk_type       type;
    char            *value;
    struct s_token  *next;
}   t_token;

#endif