#include "../libs/minishell.h"
#include "../libs/my_lib.h"
#include "../libs/structs.h"

t_command    *parsing(char *input)
{
    char    **tokens = tokenize(input);
    
}