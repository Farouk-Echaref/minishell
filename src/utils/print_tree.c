#include "utils.h"

typedef struct Trunk Trunk;

t_list	*trunks;

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
	if (token->is_list) {
		printf("(tokens list)\n");
	} else {
		str = ft_str(token->value, token->length);
		printf(" %s(%s)", str, ft_get_type_name(token->type));
		if (token->is_filename)
			printf("(FILE_NAME)");
		printf("\n");
		free(str);
	}
    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";
	printTreeRec(root->left, trunk, 0);
}

void	print_tree(t_tree *root)
{
	printTreeRec(root, NULL, 0);
	ft_lstclear(&trunks, free);
}
