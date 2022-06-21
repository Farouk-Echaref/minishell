# ifndef TOKEN_H
# define TOKEN_H

# include "libft/libft.h"
# include <stdlib.h>

typedef enum e_type t_type;
typedef struct s_token t_token;

enum    e_type
{
    COMMAND,
	CMD_OPTION,
    CMD_ARG,
	REDIR_RIGHT ,
	REDIR_RIGHT ,
	REDIR_LEFT ,
	SHIFT_LEFT,
	SHIFT_RIGHT,
	AND_OPR,
	OR_OPR,
	STAR,
	LEFT_PAR,
	RIGHT_PAR,
	SING_QUOT,
	DOUB_QUOT,
	PIPE,
    FILE_NAME,
    EXPRESSION,
    OTHER
};

struct s_token
{
    t_type  type;
    char    *value;
    int     length;
};

t_token *ft_new_token(const char *value, t_type *type, int length);

#endif
