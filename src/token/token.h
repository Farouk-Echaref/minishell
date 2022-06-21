# ifndef TOKEN_H
# define TOKEN_H

# include "libft/libft.h"
# include <stdlib.h>

typedef enum e_type t_type;
typedef struct s_token t_token;

enum    e_type
{
    COMMAND = 1,
	CMD_OPTION = 2,
    CMD_ARG = 3,
	REDIR_RIGHT = 4,
	REDIR_LEFT = 5,
	SHIFT_LEFT = 6,
	SHIFT_RIGHT = 7,
	AND_OPR = 8,
	OR_OPR = 9,
	STAR = 10,
	LEFT_PAR = 11,
	RIGHT_PAR = 12,
	SING_QUOT = 13,
	DOUB_QUOT = 14,
	PIPE = 15,
    FILE_NAME = 16,
    EXPRESSION = 17,
    OTHER = 18
};

struct s_token
{
    t_type		type;
    const char	*value;
    int			length;
};

t_token *ft_new_token(const char *value, t_type type, int length);

#endif
