// structure bank using linkedlist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//QSORT
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// defining enum for account type
typedef enum Account_type
{
    current = 0,
    savings
} Account_type;

// structure account info
typedef struct AccountInfo
{
    int ac_num;
    Account_type act;
    char name[50];
    float balance;
} AccountInfo;

//Node containing accountinfo
typedef struct node
{
    AccountInfo aci;
    struct node *next;
} node;

//linkedlist
typedef struct node *linkedlist;

// defining a structure bank to store account details using linkedlist
typedef struct bank
{
    linkedlist members;
} bank;
bank b;

// APPEND
linkedlist append(AccountInfo p, linkedlist l)
{
    if (l == NULL)
    {
        node *fourth = (node *)malloc(sizeof(node));
        fourth->aci = p;
        fourth->next = NULL;
        return fourth;
    }
    else
    {
        l->next = append(p, l->next);
    }
    return l;
}

// PRINT ACCOUNT
void print(AccountInfo p)
{
    char s[2][10] = {"current", "savings"};

    printf("%d\t\t\t%s\t\t\t%s\t\t%f\t", p.ac_num, s[p.act], p.name, p.balance);
    printf("\n");
}

// SORT
void sort()
{
    int i = 0;
    node *head = b.members;
    node *current;
    int count = 0;
    while (b.members != NULL)
    {
        if (i == 0)
        {
            head = b.members;
            i++;
        }
        count++;
        b.members = b.members->next;
    }
    b.members = head;
    if (count > 1)
    {
        while (b.members->next != NULL)
        {
            if (i == 0)
            {
                head = b.members;
                i++;
            }
            current = b.members;
            b.members = head;

            while (b.members->next != NULL)
            {
                if ((b.members->next->aci.ac_num) < b.members->aci.ac_num)
                {
                    int temp = b.members->next->aci.ac_num;
                    Account_type temp2 = b.members->next->aci.act;
                    char temp3[100];
                    strcpy(temp3, b.members->next->aci.name);
                    float temp4 = b.members->next->aci.balance;
                    b.members->next->aci.ac_num = b.members->aci.ac_num;
                    b.members->aci.ac_num = temp;

                    b.members->next->aci.balance = b.members->aci.balance;
                    b.members->aci.balance = temp4;

                    b.members->next->aci.act = b.members->aci.act;
                    b.members->aci.act = temp2;

                    strcpy(b.members->next->aci.name, b.members->aci.name);
                    strcpy(b.members->aci.name, temp3);
                }
                b.members = b.members->next;
            }
            b.members = current;
            b.members = b.members->next;
        }
        b.members = head;
    }
}

// LOWBALANCE
void lowBalanceAccounts()
{
    int i = 0;
    node *head;
    while (b.members != NULL)
    {
        if (i == 0)
        {
            head = b.members;
            i++;
        }
        if (b.members->aci.balance < 100)
        {
            printf("Account Number: %d, Name: %s, Balance: %f\n", b.members->aci.ac_num, b.members->aci.name, b.members->aci.balance);
        }
        b.members = b.members->next;
    }

    b.members = head;
}

// TRANSACTION
void transaction(int accountNumber, float amount, int code)
{
    int c = 0;
    int d = 0;
    int i = 0;
    node *head;
    float bal;
    while (b.members != NULL)
    {
        if (i == 0)
        {
            head = b.members;
            i++;
        }
        if (b.members->aci.ac_num == accountNumber)
        {
            c = 1;
            if (code == 0)
            {
                if (b.members->aci.balance - amount < 100)
                {
                    printf("The balance is insufficient for the specified withdrawal.\n");
                    d = 1;
                }
                else
                {
                    b.members->aci.balance = b.members->aci.balance - amount;
                    bal = b.members->aci.balance;
                }
            }
            if (code == 1)
            {
                b.members->aci.balance = b.members->aci.balance + amount;
                bal = b.members->aci.balance;
            }
        }
        b.members = b.members->next;
    }
    if (c == 1 && d == 0)
    {
        printf("Updated balance is Rs %f\n", bal);
    }
    else if (c == 0)
    {
        printf("Invalid: User does not exist\n");
    }
    b.members = head;
}

// PRINT BANK
void display()
{
    int i = 0;
    node *head = b.members;
    if (head == NULL)
    {
        printf("No Accounts to Display\n");
    }
    else
    {
        sort();
        printf("Account Number\t\tAccount type\t\tName\t\tBalance\t\n");
        for (int i = 0; i < 73; i++)
        {
            printf("-");
        }
        printf("\n");

        while (b.members != NULL)
        {
            if (i == 0)
            {
                head = b.members;
                i++;
            }
            print(b.members->aci);
            b.members = b.members->next;
        }
        b.members = head;
    }
}

// DELETE
void delete(char actype[], char name[])
{
    int i = 0;
    node *head = b.members;
    int count = 0;
    int f = 0;
    Account_type t;
    int flag=0;

    if (strcmp(actype, "current") == 0)
    {
        t = 0;
    }
    else
    {
        t = 1;
    }

    while (b.members != NULL)
    {
        if (i == 0)
        {
            head = b.members;
            i++;
        }
        count++;

        if (strcmp(name, b.members->aci.name) == 0 && (t == b.members->aci.act))
        {
            f = count;
            flag=1;
        }
        b.members = b.members->next;
    }
    count = 0;

    b.members = head;
    while (b.members != NULL)
    {
        count++;
        if ((f - 1) == 0)
        {
            head = b.members->next;
            b.members = NULL;
        }
        else
        {
            if (count == (f - 1))
            {

                if (b.members->next->next != NULL)
                {
                    b.members->next = b.members->next->next;
                }
                else
                {
                    b.members->next = NULL;
                }
            }
            b.members = b.members->next;
        }
    }
    b.members = head;
    if(flag==0){
        printf("Invalid: User does not exist\n");
    }
    else{
        printf("Account deleted succesfully\n");
    }
}

// CREATE
void create(char accounttype[], char name[], float amount)
{   
    AccountInfo ac;
    if (strcmp("current", accounttype) == 0)
    {
        ac.act = 0;
    }
    else
    {
        ac.act = 1;
    }
    int i = 0;
    int count = 0;
    node *head = b.members;
    ac.balance = amount;
    int w=0;
    node* current;
    strcpy(ac.name, name);
    while(b.members!=NULL){
        if(i==0){
            head=b.members;
            i++;
        }

        current=b.members;
        b.members=head;
        while(b.members!=NULL){
        if(strcmp(b.members->aci.name,name)==0 && ac.act==b.members->aci.act){
            w=1;
        }
        b.members=b.members->next;}
        b.members=current;
        b.members=b.members->next;
    }
    b.members=head;
    if(w!=1){
    while (b.members != NULL)
    {
        count++;
        b.members = b.members->next;
    }
    int arr[count];
    b.members = head;
    for (int j = 0; j < count; j++)
    {
        arr[j] = b.members->aci.ac_num;
        b.members = b.members->next;
    }
    int number = 100;
    int flag = 0;
    for (int k = 0; k < count; k++)
    {
        for (int j = 0; j < count; j++)
        {
            if (arr[j] == number)
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            break;
        }
        number++;
        flag = 0;
    }
    ac.ac_num = number;
    b.members = head;
    b.members = append(ac, b.members);
    printf("Account number: %d\nAccount holder: %s\nAccount type: %s\nBalance: Rs %f\n",ac.ac_num,name,accounttype,amount);
}
else{
    printf("Invalid: User alreay exists\n");
   // b.members=head;
}
}
int main()
{
    b.members = NULL;
    char choice[10] = "0";
    printf("What do you want to do?\n\n1. Create account - CREATE AccountType(current or savings) Name Amount\n2. Delete account - DELETE AccountType Name\n3. Transaction - TRANSACTION AccountNumber Amount Code(1 for deposit,0 for withdrawal)\n4. Lowbalance - LOWBALANCE\n5. Display records - DISPLAY\n6. Exit - EXIT\n");
    while (strcmp(choice, "-1") != 0)
    {
        char s[20];
        scanf("%s", s);
        if (strcmp(s, "CREATE") == 0)
        {
            ;
            char act[50];
            char name[100];
            float balance;
            scanf("%s", act);
            scanf("%s", name);
            scanf("%f", &balance);
            create(act, name, balance);
        }
        if (strcmp(s, "DISPLAY") == 0)
        {
            display();
        }
        if (strcmp(s, "DELETE") == 0)
        {
            char act[50];
            char name[50];
            scanf("%s", act);
            scanf("%s", name);
            delete (act, name);
        }
        if (strcmp(s, "EXIT") == 0)
        {
            strcpy(choice, "-1");
        }
        if (strcmp(s, "LOWBALANCE") == 0)
        {
            lowBalanceAccounts();
        }
        if (strcmp(s, "TRANSACTION") == 0)
        {
            int acn;
            float amount;
            int code;
            scanf("%d %f %d", &acn, &amount, &code);
            transaction(acn, amount, code);
        }
    }
    return 0;
}
