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

struct student a[];
int x;      // input from user to select whether to create students with random data or enter the data from keybaord
char y;     // input from user to select where to insert
int pos;     // holds the index to insert to
int N;          //Number of students
clock_t ss;   //  holds the time of execution at a certain moment
struct student *ptr, *first;

// function to insert data at the beginning of the array
void insert_begin()
{
    struct student s;           // this structure will hold the data that the user will input
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

    ss = clock();       // calculate the time in ticks at the start of the insertion process
    // increase one on the number of students then allocate memory slots for the new number of students pointed at by first
    N++;
    first = (struct student *)realloc(first, N * sizeof(struct student));
   // shift each element in the array to the right and add the new inserted student at the beginning of the array
    for (int i = N; i > 0; i--)
        *(first + i) = *(first + i - 1);
    *first = s;
    ss = clock() - ss;      // calculate the total time in ticks of the insertion process
}

// function that inserts data at any position in the array
void insert()
{
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

    ss = clock();       // calculate the time in ticks at the start of the insertion process
    // increase the number of students by one then allocate memory for the new number of students
    N++;
    first = (struct student *)realloc(first, N * sizeof(struct student));
    // shift the elements after the required position
    for (int i = N - 1; i > 0; i--)
    {
        if (i == pos)
            break;
        first[i] = first[i - 1];
    }
    first[pos] = s;     // insert at the required position after shifting the other elements
    ss = clock() - ss;        // calculate the total time in ticks of the insertion process
}

// function to insert data at last position of the array
void insert_last()
{

    struct student s;       // this structure will hold the data that the user will input
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

    ss = clock();       // calculate the time in ticks at the start of the insertion process
    // increase the number of students by one then allocate memory for the new number of students
    N++;
    first = (struct student *)realloc(first, N * sizeof(struct student));
    *(first + N - 1) = s;           // insert the student's data at the last position
    ss = clock() - ss;              // calculate the total time in ticks of the insertion process
}

// displays the students of the array
void disp(struct student *p)
{
    for (int i = 0; i < N; i++)
    {
        printf("\nID is %d\n", p->ID);
        printf("score is %d\n", p->score);
        printf("name is %s\n", p->name);
        printf("DB is %d %d %d\n", p->db[0], p->db[1], p->db[2]);
        p++;
    }
}

// function that takes input from the user to indicate whether to create many nodes with trash data or the user wants to input the students' data manually
void input_data()
{
    printf("To input student data from keyboard press 1 ");
    printf("\nTo create many students with random data press 0\n ");
    scanf("%d", &x);
    printf("\nEnter the number of students: ");
    scanf("%d", &N);
    ptr = (struct student *)calloc(N, sizeof(struct student));      //allocate N number of slots to hold students data
    first = ptr;
    if (x == 1)     // if the user wants to enter the students' data manually
    {
        for (int i = 0; i < N; i++)
        {
            printf("Enter the student name:");
            getchar();
            scanf("%50[^\n]s", ptr->name);
            getchar();
            printf("\nEnter the ID of student:");
            scanf("%d", &ptr->ID);
            printf("\nEnter the student score:");
            scanf("%d", &ptr->score);
            printf("\nEnter the student date of birth(day/month/year):");
            scanf("%d%d%d", &ptr->db[0], &ptr->db[1], &ptr->db[2]);
            ptr++;
        }
    }

    else                // if user wants to insert many students without inputting data manually
    {
        //insert a students with trash data to an array pointed to by ptr
        struct student s;
        for (int i = 0; i < N; i++)
        {
            *ptr = s;
            ptr++;
        }
    }

    // ask the user for the position of insertion
    printf("To insert a student at the first position press 0\n");
    printf("To insert a student at the last position press 1 \n");
    printf("To insert a student at any index position press 2 \n");
    getchar();
    scanf("%d", &y);
    if (y == 0)
        insert_begin();
    else if (y == 1)
        insert_last();
    else if (y == 2)
        insert();
}


int main()
{
    printf("********WELCOME********\n");
    input_data();
   disp(first);
    printf("\nTime taken by the operation: %.12lf sec\n", (double)ss / CLOCKS_PER_SEC);           // calculates time of insertion in seconds
   printf("Size taken is %ld bytes\n",sizeof(struct student)*N);  // calculates the size taken by the array
    return 0;
}
