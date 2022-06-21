#include "lexer.h"

void    ft_move_content(t_lexer *lxr, int length)
{
    lxr->content += length;
}

int ft_is_command(char *s)
{

}

t_type  ft_get_type(t_lexer *lxr)
{
    if (*lxr->content == '>')
        return (ft_move_content(lxr, 1), REDIR_RIGHT);
    if (*lxr->content == '<')
        return (ft_move_content(lxr, 1), REDIR_LEFT);
    if (ft_strncmp(lxr->content, "<<", 2) == 0)
        return (ft_move_content(lxr, 2), SHIFT_LEFT);
    if (ft_strncmp(lxr->content, ">>", 2) == 0)
        return (ft_move_content(lxr, 2), SHIFT_RIGHT);
    if (ft_strncmp(lxr->content, "&&", 2) == 0)
        return (ft_move_content(lxr, 2), AND_OPR);
    if (ft_strncmp(lxr->content, "||", 2) == 0)
        return (ft_move_content(lxr, 2), OR_OPR);
    if (*lxr->content == '*')
        return (ft_move_content(lxr, 1), STAR);
    if (*lxr->content == '(')
        return (ft_move_content(lxr, 1), LEFT_PAR);
    if (*lxr->content == ')')
        return (ft_move_content(lxr, 1), RIGHT_PAR);
    if (*lxr->content == '\'')
        return (ft_move_content(lxr, 1), SING_QUOT);
    if (*lxr->content == '"')
        return (ft_move_content(lxr, 1), DOUB_QUOT);
    if (*lxr->content == '|')
        return (ft_move_content(lxr, 1), PIPE);
}
