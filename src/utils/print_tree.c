#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include "token/token.h"

typedef struct Trunk Trunk;
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
    if (root == NULL) {
        return;
    }
    char *prev_str = "    ";
    Trunk *trunk = ft_new_trunk(prev, prev_str);

    printTreeRec(root->right, trunk, 1);

    if (!prev) {
        trunk->str = "———";
    }
    else if (isLeft)
    {
        trunk->str = ".———";
        prev_str = "   |";
    }
    else {
        trunk->str = "`———";
        prev->str = prev_str;
    }

    showTrunks(trunk);
	t_token	*token = root->content;
	printf(" %s\n", ft_str(token->value, token->length));

    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";

    printTreeRec(root->left, trunk, 0);
}

void	print_tree(t_tree *root)
{
	printTreeRec(root, NULL, 0);
}
