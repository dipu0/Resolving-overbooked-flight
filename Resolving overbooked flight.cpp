#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<stdlib.h>
#define STACK_MAX_SIZE 100
#define QUEUE_MAX_SIZE 100
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
#define TRUE_VALUE 1
#define FALSE_VALUE 0
using namespace std;
typedef struct
{
    char name[50];
    int miles;
    int years;
    int sequence;
    double priority;
} PASSENGER;
int Number_of_Passenger=0;

class Priority_Queue
{
public:
    void Min_heapify(PASSENGER arr[], int n, int i)
    {
        int smallest=i;
        int l= 2*i;
        int r= 2*i+1;
        if (l<n && arr[l].priority < arr[smallest].priority)
        {
            smallest = l;
        }
        if (r < n && arr[r].priority < arr[smallest].priority)
        {
            smallest = r;
        }
        if (smallest!= i)
        {
            swap(arr[i], arr[smallest]);
            Min_heapify(arr, n, smallest);
        }
    }

    void Max_heapify(PASSENGER arr[], int n, int i)
    {
        int largest = i;
        int l=2*i;
        int r = 2*i + 1;


        if (l < n && arr[l].priority > arr[largest].priority)
            largest = l;


        if (r < n && arr[r].priority > arr[largest].priority)
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            Max_heapify(arr, n, largest);
        }
    }

    void Min_BuildHeap(PASSENGER arr[],int n)
    {
        for (int i = n/2 ; i >=1; i--)
            Min_heapify(arr, n+1, i);

    }

    void Max_BuildHeap(PASSENGER arr[],int n)
    {
        for (int i = n/2 ; i >=1; i--)
            Max_heapify(arr, n+1, i);

    }

    PASSENGER Extract_Max(PASSENGER arr[], int n)
    {

        PASSENGER start=arr[1];

        PASSENGER end = arr[n];

        arr[1] = end;
        Max_heapify(arr, n, 1);
        Number_of_Passenger--;
        return start;
    }
};

class Stack
{
private:
    PASSENGER data[STACK_MAX_SIZE];
    int top;
public:
    Stack()
    {
        top=0;
    }
    int push (PASSENGER item)
    {
        data[top] = item ;
        top++ ;
        return SUCCESS_VALUE ;
    }
    PASSENGER pop()
    {
        if(top == 0) return data[0];
        top-- ;
        return data[top] ;
    }
    int isEmpty()
    {
        if(top == 0) return TRUE_VALUE;
        else return FALSE_VALUE ;
    }
    int isFull()
    {
        if(top == STACK_MAX_SIZE) return TRUE_VALUE;
        else return FALSE_VALUE;
    }
    int getLength()
    {
        return top;
    }
};

int main()
{
    Priority_Queue pq;
    Stack st;
    PASSENGER Data[25];
    FILE* file;
    char First_Name[50],Last_Name[50];
    int i=0,j,k,A,B,C;
    file = fopen("overbooked flights.txt", "r");
    if(file==NULL)
    {
        printf("Problems opening the file!");
        exit(0);
    }
    printf("\nREADING FROM OVERBOOKED FLIGHTS FILE: \n\n");

    printf("    NAME             MILEAGE  YEARS  SEQUENCE NUMBER  PRIORITY NUMBER\n");

    //A total mileage
    //B years
    //C sequence number

    while( fscanf( file,"%s %s %d %d %d", &First_Name, &Last_Name, &A, &B, &C ) != EOF )
    {
        i++;
        strcat(First_Name," ");
        strcat(First_Name,Last_Name);
        printf("%-20s %-5d %5d %10d   ",First_Name,A,B,C);
        strcpy( Data[i].name, First_Name );
        //printf("%-20s",First_Name);
        Data[i].miles=A;
        //printf(" %-5d",Data[i].miles);
        Data[i].years=B;
        //printf(" %d",Data[i].years);
        Data[i].sequence=C;
        //printf(" %2d = ",Data[i].sequence);
        Data[i].priority=((A/1000)+B-C);
        printf("      =   %5.1f\n", Data[i].priority);
        pq.Max_BuildHeap(Data,i); //heapify each time enter a new data in heap.
    }
    fclose(file);
    Number_of_Passenger=i;

    //pq.Max_BuildHeap(Data,i);// heapify full heap

    printf("\nLIST OF WAITING PASSENGER IN PRIORITY SEQUENCE.\n\n");
    for(j=1; j<=i; j++)
    {
        printf("%3d   %-20s %.1f\n",j,Data[j].name,Data[j].priority);

    }

    for(j=1; j<=i; j++)
    {

        PASSENGER waiting_passenger=pq.Extract_Max(Data,i-(j-1));

        //printf("\nExtract value: %0.1f sequence %d  Priority number %d",waiting_passenger.priority,waiting_passenger.sequence, j);

       // if(waiting_passenger.sequence > j) //here j is the count of Passenger who took there ticket already
        {
            for(k=1; k<=Number_of_Passenger; k++)
            {

                if(Data[k].sequence==j)
                {

                    st.push(Data[k]);
                    //printf("\nPushing K %d and data %.1f",Data[k].sequence,Data[k].priority);
                    break;
                }


            }

        }

    }
    PASSENGER ps;
    int Stack_length=st.getLength();
    printf("\nPASSENGER WHO TOOK FLIGHT TICKET LATER\n\n");
    printf("      NAME                MILEAGE    YEARS  PRIORITY NUMBER\n");
    for(j=0; j<Stack_length; j++)
    {
        ps =st.pop();
        printf("%3d   %-20s %-5d %5d %15.1f  \n",ps.sequence,ps.name,ps.miles,ps.years,ps.priority);
    }

}

