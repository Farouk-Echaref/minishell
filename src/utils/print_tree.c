#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include "token/token.h"

typedef struct Trunk Trunk;

t_list	*trunks;

char	*ft_get_type_name(t_type t)
{
	switch (t)
	{
		case COMMAND:
			return "CMD";
		case CMD_OPTION:
			return "CMD_OPT";
		case CMD_ARG:
			return "CMD_ARG";
		case WHITE_SPACE:
			return "SPACE";
		case REDIR_RIGHT:
			return "REDR";
		case REDIR_LEFT:
			return "REDL";
		case SHIFT_LEFT:
			return "SHL";
		case SHIFT_RIGHT:
			return "SHR";
		case AND_OPR:
			return "AND";
		case OR_OPR:
			return "OR";
		case STAR:
			return "STAR";
		case SUB_CMD:
			return "SUB_CMD";
		case SING_QUOT:
			return "SING_Q";
		case DOUB_QUOT:
			return "DOUB_Q";
		case PIPE:
			return "PIPE";
		case VAR:
			return "VAR";
		case FILE_NAME:
			return "FILE_NAME";
		case EXPRESSION:
			return "EXPR";
		default:
			return "OTHER";
	}
}

struct Trunk
{
    Trunk	*prev;
    char	*str;
};

static Trunk	*ft_new_trunk(Trunk *prev, char *str)
{
	Trunk	*trunk;

	trunk= (Trunk *)malloc(sizeof(Trunk));
	trunk->prev = prev;
	trunk->str = str;
	return (trunk);
}

static void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;
    showTrunks(p->prev);
	printf("%s", p->str);
}

static void printTreeRec(t_tree* root, Trunk *prev, int isLeft)
{
	char	*str;
	Trunk	*trunk;
	char	*prev_str;

    if (root == NULL)
        return;
    prev_str = "    ";
    trunk = ft_new_trunk(prev, prev_str);
	ft_lstadd_back(&trunks, ft_lstnew(trunk));
    printTreeRec(root->right, trunk, 1);
    if (!prev)
        trunk->str = "———";
    else if (isLeft) {
        trunk->str = ".———";
        prev_str = "   |";
    } else {
        trunk->str = "`———";
        prev->str = prev_str;
    }
    showTrunks(trunk);
	t_token	*token = root->content;
	str = ft_str(token->value, token->length);
	printf(" %s(%s)\n", str, ft_get_type_name(token->type));
    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";
	printTreeRec(root->left, trunk, 0);
	free(str);
}

void	print_tree(t_tree *root)
{
	printTreeRec(root, NULL, 0);
	ft_lstclear(&trunks, free);
}
