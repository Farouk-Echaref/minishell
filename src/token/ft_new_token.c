#include "token.h"

t_token *ft_new_token(const char *value, t_type type, int length)
{
    t_token *t;

    t = malloc(sizeof(t_token));
    t->length = length;
    t->type = type;
    t->value = value;
    return (t);
}
