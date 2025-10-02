#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node
{
    char word[50];
    char meaning[200];
    struct node *left, *right;
} Node;

void add(Node **root)
{
    char w[50], m[200];
    fgets(w, 50, stdin);
    printf("Enter your Word: ");
    fgets(w, 50, stdin);
    w[strcspn(w, "\n")] = '\0';
    printf("Meaning of your word: ");
    fgets(m, 200, stdin);

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory Allocation Failed\n");
        exit(1);
    }

    strcpy(newNode->word, w);
    strcpy(newNode->meaning, m);
    newNode->left = newNode->right = NULL;

    if (!*root)
    {
        *root = newNode;
    }
    else
    {
        Node *ptr = *root;
        if (strcmp(newNode->word, ptr->word) < 0)
        {
            if (!ptr->left)
            {
                ptr->left = newNode;
            }
            ptr = ptr->left;
        }
        else if (strcmp(newNode->word, ptr->word) > 0)
        {
            if (!ptr->right)
            {
                ptr->right = newNode;
            }
            ptr = ptr->right;
        }
    }
}

void preorder(Node *root)
{
    if (!root)
    {
        return;
    }
    preorder(root->left);
    preorder(root->right);
    printf("%s : %s\n", root->word, root->meaning);
}

void inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    printf("%s : %s\n", root->word, root->meaning);
    inorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
    {
        return;
    }
    printf("%s : %s\n", root->word, root->meaning);
    postorder(root->left);
    postorder(root->right);
}

int main()
{
    Node *root = NULL;
    bool isEnd = false;
    int choice;
    while (!isEnd)
    {
        printf("1. Add word to dictionary\n2. Print dictionary\n3. Stop\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add(&root);
            break;
        case 2:
            if (!root)
            {
                printf("Empty tree\n");
                break;
            }
            int choice2;
            printf("1. Preorder\n2. Inorder\n3. Postorder\n");
            scanf("%d", &choice2);
            switch (choice2)
            {
            case 1:
                preorder(root);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                postorder(root);
                break;
            default:
                printf("Invalid input\n");
            }
            break;
        case 3:
            isEnd = true;
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}