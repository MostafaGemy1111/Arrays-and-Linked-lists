#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Team Members : Khaled Khalifa - Mostafa Gamal - Micheal Safwat

// Creating a structure to hold student's data
struct student
{

    char name[50];
    int ID;
    int db[3];
    int score;
};

int x;  // input from user to select whether to create students with random data or enter the data from keybaord
int pos;  // holds the index to insert to
int N; //Number of students in the array
struct student *a;  // pointer to an array that holds student's data to put in nodes afterwards
char y;  // input from user to select where to insert
clock_t sec;//  holds the time of execution at a certain moment

// creating a structure that represents a node
struct Node
{
    struct student data;
    struct Node *next;
};

// creating and initializing head and tail pointers to Null
struct Node *head = NULL;
struct Node *tail = NULL;

// function to insert a node at the first position of the LL which will now be the head node
void insert_head()
{
    struct student s;                   // this structure will hold the data that the user will input
    printf("Enter the student name:");
    getchar();
    scanf("%50[^\n]s", s.name);
    getchar();
    printf("\nEnter the ID of student:");
    scanf("%d", &s.ID);
    printf("\nEnter the student score:");
    scanf("%d", &s.score);
    printf("\nEnter the student date of birth(day/month/year):");
    scanf("%d%d%d", &s.db[0], &s.db[1], &s.db[2]);
    sec = clock();      // calculate the time in ticks at the start of the insertion process

    if(N==0){           // if the number of students to create is zero then the inserted node will be the only node in the LL

    // creating a node and whose data will be the data stored from the user in the structure s and this node's next pointer points to NULL
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = s;
    t->next = NULL;
    head = t;
    sec = clock() - sec;        // calculate the total time in ticks of the insertion process
    }

    // if the number of students to be created is not zero then the inserted node at the beginning will point to the head then it will be the head
    else {
        struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = s;
    t->next = head;
    head = t;
    sec = clock() - sec;            // calculate the total time in ticks of the insertion process


    }
}

// function that inserts a node at a position in the middle(any index) of the LL
void insert()
{
    // take data from user
    printf("Enter position of insertion: ");
    scanf("%d", &pos);
    struct student s;
    printf("Enter the student name:");
    getchar();
    scanf("%50[^\n]s", s.name);
    getchar();
    printf("\nEnter the ID of student:");
    scanf("%d", &s.ID);
    printf("\nEnter the student score:");
    scanf("%d", &s.score);
    printf("\nEnter the student date of birth(day/month/year):");
    scanf("%d%d%d", &s.db[0], &s.db[1], &s.db[2]);

    sec = clock();              // calculate the time in ticks at the start of the insertion process

    struct Node *t, *p;     // t pointer to create node with and p pointer to traverse to position of insertion
    p = head;               // p will point to first node then moves till it reaches the position
    for (int i = 0; i < pos - 1; i++)
        p = p->next;
    t = (struct Node *)malloc(sizeof(struct Node));         // creating a node whose data is the inserted student and its next pointer points at p's next
    t->data = s;
    t->next = p->next;
    p->next = t;                        // now p's next points at t so insertion at the required position is done
    sec = clock() - sec;                // calculate the total time in ticks of the insertion process
}


// function that inserts a node at the end of the LL
void insert_last()
{
    // take the data from the user and store it in the structure
    struct student s;
    printf("Enter the student name:");
    getchar();
    scanf("%50[^\n]s", s.name);
    getchar();
    printf("\nEnter the ID of student:");
    scanf("%d", &s.ID);
    printf("\nEnter the student score:");
    scanf("%d", &s.score);
    printf("\nEnter the student date of birth(day/month/year):");
    scanf("%d%d%d", &s.db[0], &s.db[1], &s.db[2]);

    sec = clock();          // calculate the time in ticks at the start of the insertion process

    struct Node *t;         // create a node whose data is the inserted student and its next points to NULL
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = s;
    t->next = NULL;
    tail->next = t;         // tail's next will point to the new created node then tail will point to that node so it's the last one
    tail = t;
    sec = clock() - sec;            // calculate the total time in ticks of the insertion process
}


// function that takes input from the user to indicate whether to create many nodes with trash data or the user wants to input the students' data manually
void input_data()
{
    printf("To input student data from keyboard press 1 ");
    printf("\nTo create many students with random data press 0\n ");
    scanf("%d", &x);
    printf("\nEnter the number of students: ");
    scanf("%d", &N);

    a = (struct student *)malloc(N * sizeof(struct student));  // pointer that allocates memory for N number of students to hold their data
    if (x == 1)         // if the user wants to enter the students' data manually
    {
        for (int i = 0; i < N; i++)
        {
            printf("\nEnter the student name:");
            getchar();
            scanf("%50[^\n]s", a[i].name);
            getchar();
            printf("\nEnter the ID of student:");
            scanf("%d", &a[i].ID);
            printf("\nEnter the student score:");
            scanf("%d", &a[i].score);
            printf("\nEnter the student date of birth(day/month/year):");
            scanf("%d%d%d", &a[i].db[0], &a[i].db[1], &a[i].db[2]);
        }
    }
    else
        return; // call create() function to start creating students with trash data
}


// function that enables the user to create large number of nodes without the need to enter each student's data manually
void create()
{
    // creates a node which will be the head node and the tail will point to it as well then create N number of nodes following it
                                                                                                     //and at the end tail points to the last node

    int i;
    struct Node *t;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = *a;
    head->next = NULL;
    tail = head;
    for (i = 1; i < N; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        tail->next = t;    // move tail till reaching the last node
        tail = t;
    }
    // ask the user for the position of insertion
    printf("To insert a student at the first position press 0\n");
    printf("To insert a student at the last position press 1 \n");
    printf("To insert a student at any index position press 2 \n");
    getchar();
    scanf("%c", &y);
    if (y == '0')
        insert_head();
    else if (y == '1')
        insert_last();
    else if (y == '2')
        insert();
}


// function to display all students' data that exist in the LL by traversing the LL using p pointer
void Display_LL(struct Node *p)
{
    while (p != NULL)
    {
        printf("\nID is %d\n", p->data.ID);
        printf("score is %d\n", p->data.score);
        printf("name is %s\n", p->data.name);
        printf("DB is %d %d %d\n", p->data.db[0], p->data.db[1], p->data.db[2]);
        p = p->next;
    }
}
int main()
{
    printf("***WELCOME***\n");
    input_data();
    create();
    Display_LL(head);
    printf("\nTime taken by the operation: %.12lf sec\n", (double)sec / CLOCKS_PER_SEC);    // calculates time in seconds
    printf("Size taken is %ld\n",sizeof(struct student)*(N+1)+16+8*(N+1));       // calculates size taken  which is the size of each node plus head and tail pointers
    return 0;
}
