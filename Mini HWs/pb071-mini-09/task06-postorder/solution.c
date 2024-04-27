#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Postorder print of n-ary tree
 * 
 * \author Martin Piatka <445597@mail.muni.cz>
 * \author Roman Lacko <xlacko1@fi.muni.cz>
 */

/*
 * Printing out on different levels of recursion depth is sort of flattening
 * of the tree which can come in handy sometimes.
 */

/**
 * The n-ary tree node structure.
 *
 * The 'children' attribute is simply an array of 'degree' pointers to
 * children. E.g, given 'struct node *node', and degree of at least 1,
 * the expression
 *
 *      node->children[0]
 *
 * is of type 'struct node *' and points to the first child.
 * Expression 'node->children[i]' for 'i >= degree' has no defined value.
 */
struct node
{
    int value; ///< value of the node

    size_t degree;           ///< number of children nodes
    struct node *children[]; ///< array of pointers to child nodes
};

static void post_order_print_aux(const struct node *node)
{
    for (size_t i = 0; i < node->degree; i++) {
        post_order_print_aux(node->children[i]);
        printf(", ");
    }

    printf("%d", node->value);
}

void post_order_print(const struct node *node)
{
    post_order_print_aux(node);
    putchar('\n');
}

//=============================================================================

#define MINVALUE (-15) // minimum node value
#define MAXVALUE 30 // maximum node value
#define MAXDEGREE 10 // maximum node degree

//--  Forward declarations  ---------------------------------------------------

/**
 * Creates a tree with (maxdepth + 1) layers. Value of maxdepth 0 hence
 * creates a single node.
 *
 * The node and subtrees are filled with random values.
 */
struct node *mktree(size_t maxdepth);

/**
 * Safely releases the tree and all subtrees.
 */
void rmtree(struct node *node);

/**
 * Returns true if the node is a leaf or a an ancestor of leaf nodes.
 */
bool is_L1_node(const struct node *node);

/**
 * Prints out the tree.
 */
void dumptree(unsigned level, const struct node *node);

//--  Implementation  ---------------------------------------------------------

struct node *mktree(size_t maxdepth)
{
    size_t degree = maxdepth > 0 ? rand() % MAXDEGREE : 0;
    struct node *node = malloc(sizeof(struct node) + degree * sizeof(void *));

    if (node == NULL) {
        perror("calloc");
        return NULL;
    }

    node->value = (rand() % (MAXVALUE + 1 - MINVALUE)) + MINVALUE;
    node->degree = degree;

    for (size_t i = 0u; i < degree; ++i) {
        if ((node->children[i] = mktree(maxdepth - 1)) == NULL) {
            perror("mktree");
            rmtree(node);
            return NULL;
        }
    }

    return node;
}

void rmtree(struct node *node)
{
    for (unsigned i = 0; i < node->degree && node->children[i] != NULL; ++i)
        rmtree(node->children[i]);

    free(node);
}

bool is_L1_node(const struct node *node)
{
    for (size_t i = 0u; i < node->degree; ++i) {
        if (node->children[i]->degree > 0u)
            return false;
    }

    return true;
}

void dumptree(unsigned level, const struct node *node)
{
    printf("%*s*%3d\n", 2 * level, "", node->value);

    if (node->degree == 0)
        return;

    if (is_L1_node(node)) {
        printf("%*s>", 2 * level + 2, "");
        for (size_t i = 0; i < node->degree; ++i) {
            printf("%3d", node->children[i]->value);

            if (i + 1 < node->degree)
                putchar(' ');
        }
        putchar('\n');
    } else {
        for (size_t i = 0; i < node->degree; ++i)
            dumptree(level + 1, node->children[i]);
    }
}

//=============================================================================

int main(void)
{
    int retval;
    long seed, maxdepth;

    errno = 0;
    while ((retval = scanf(" %ld %ld", &seed, &maxdepth)) == 2 && seed >= 0 && maxdepth >= 0) {
        srand(seed);
        struct node *root = mktree(maxdepth);

        if (root == NULL) {
            fprintf(stderr, "Failed to create tree, aborting");
            return EXIT_FAILURE;
        }

        printf("Input:\n");
        dumptree(0, root);
        post_order_print(root);
        rmtree(root);
    }

    if (retval == EOF && errno != 0) {
        perror("scanf");
        return EXIT_FAILURE;
    }

    if (retval != EOF) {
        fprintf(stderr, "Invalid number format\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
