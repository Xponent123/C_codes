
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//NODE
typedef struct node
{
    float number;
    struct node *next;
} node;
typedef struct node *linkedlist;

//PRINT
void print(linkedlist l)
{
    while (l != NULL)
    {
        printf("%f ", l->number);
        l = l->next;
    }
}

//APPEND
linkedlist append(float n, linkedlist l)
{
    if (l == NULL)
    {
        node *D = (node *)malloc(sizeof(node));
        D->number = n;
        D->next = NULL;
        return D;
    }
    else
    {
        l->next = append(n, l->next);
    }
    return l;
}

//ADD
linkedlist add(linkedlist l1, linkedlist l2)
{
    linkedlist l = NULL;
    while (l1 != NULL)
    {
        float c = l1->number + l2->number;
        l = append(c, l);
        l1 = l1->next;
        l2 = l2->next;
    }
    return l;
}

//SUB
linkedlist sub(linkedlist l1, linkedlist l2)
{
    linkedlist l = NULL;
    while (l1 != NULL)
    {
        float c = l1->number - l2->number;
        l = append(c, l);
        l1 = l1->next;
        l2 = l2->next;
    }
    return l;
}

//DOT
float dot(linkedlist l1, linkedlist l2)
{
    linkedlist l = NULL;
    while (l1 != NULL)
    {
        float c = l1->number * l2->number;
        l = append(c, l);
        l1 = l1->next;
        l2 = l2->next;
    }

    float ans = 0;
    while (l != NULL)
    {
        ans = ans + (l->number);
        l = l->next;
    }
    return ans;
}

//MOD
float mod(linkedlist l)
{
    float mod = 0;
    while (l != NULL)
    {
        mod = mod + (l->number * l->number);
        l = l->next;
    }
    float root = sqrtf(mod);
    return root;
}

//COSINE SIMILARITY
float cosineSimilarity(linkedlist l1, linkedlist l2)
{
    float root1 = mod(l1);
    float root2 = mod(l2);
    float ans = dot(l1, l2);
    float final_ans = ans / (root1 * root2);
    return final_ans;
}

int main()
{
    char i[10] = "0";
    while (strcmp(i, "-1") != 0)
    {
        char s[10];
        int n;
        scanf("%s", s);
        if (strcmp("-1", s) == 0)
        {
            strcpy(i, "-1");
        }
        else
        {
            scanf("%d", &n);
            linkedlist l1 = NULL;
            linkedlist l2 = NULL;
            for (int i = 1; i <= n; i++)
            {
                float c1;
                scanf("%f", &c1);
                l1 = append(c1, l1);
            }
            for (int i = 1; i <= n; i++)
            {
                float c2;
                scanf("%f", &c2);
                l2 = append(c2, l2);
            }
            if (strcmp(s, "ADD") == 0)
            {
                printf("Result: ");
                print(add(l1, l2));
                printf("\n");
            }
            if (strcmp(s, "SUB") == 0)
            {
                printf("Result: ");
                print(sub(l1, l2));
                printf("\n");
            }
            if (strcmp(s, "COSINE") == 0)
            {
                printf("Result: %f", cosineSimilarity(l1, l2));
                printf("\n");
            }
            if (strcmp(s, "DOT") == 0)
            {
                printf("Result: %f", dot(l1, l2));
                printf("\n");
            }
        }
    }
    return 0;
}
