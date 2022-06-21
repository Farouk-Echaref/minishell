# ifndef LEXER_H
# define LEXER_H
# include "libft/libft.h"
# include "token/token.h"
# include <stdlib.h>

typedef struct s_lexer
{
    const char  *start;
	char        *content;
}	t_lexer;



t_type  ft_get_type(t_lexer *lxr);

#endif
