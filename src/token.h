# ifndef TOKEN_H
# define TOKEN_H

typedef enum e_type t_type;
typedef struct s_token t_token;

enum    e_type
{
    COMMAND ,
	CMD_OPTION ,
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
	PIPE
};

struct s_token
{
    t_type  type;
    char    *value;
    int     length;
};



#endif