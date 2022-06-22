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
	WHITE_SPACE = 4,
	REDIR_RIGHT = 5,
	REDIR_LEFT = 6,
	SHIFT_LEFT = 7,
	SHIFT_RIGHT = 8,
	AND_OPR = 9,
	OR_OPR = 10,
	STAR = 11,
	LEFT_PAR = 12,
	RIGHT_PAR = 13,
	SING_QUOT = 14,
	DOUB_QUOT = 15,
	PIPE = 16,
    FILE_NAME = 17,
    EXPRESSION = 18,
    OTHER = 19
};

struct s_token
{
    t_type		type;
    const char	*value;
    int			length;
};

t_token *ft_new_token(const char *value, t_type type, int length);

#endif
