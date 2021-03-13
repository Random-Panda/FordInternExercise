#include <stdio.h>
#include <stdlib.h>

#define SIZE 50 //Currently will only accept files with up to 50 sets
                //of points
struct Point
{
    int x;
    int y;
};
typedef struct Point point;

int manhattenDistance(point a, point b);
int readInput(FILE *ifp, point a[], point b[]);
void printOutput(FILE *ofp, point a[], point b[], int arrSize);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error: proper syntax is {input.txt} {output.txt}");
        exit(1);
    }

    FILE *ifp = fopen(argv[1], "r");
    if (ifp == NULL)
    {
        printf("Error: Input file does not exist");
        exit(1);
    }

    FILE *ofp = fopen(argv[2], "w+");
    if (ofp == NULL)
    {
        printf("Error: cannot open output file");
    }

    point a[SIZE];
    point b[SIZE];

    int arrSize = readInput(ifp, a, b);
    printOutput(ofp, a, b, arrSize);

    fclose(ofp);
    fclose(ifp);

    return 0;
}

int manhattenDistance(point a, point b)
{
    int distance = 0;
    distance = abs(a.x - b.x) + abs(a.y - b.y);
    return distance;
}

int readInput(FILE *ifp, point a[], point b[])
{
    char buffer[50];
    for (int i = 0; i < SIZE; i++)
    {
        if (fgets(buffer, 50, ifp) == NULL) //stop reading at EOF
        {
            return i;
        }
        sscanf(buffer, "%d,%d %d,%d", &a[i].x, &a[i].y, &b[i].x, &b[i].y); //Input MUST follow this format "x,y x,y"
    }
    return SIZE;
}

void printOutput(FILE *ofp, point a[], point b[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        int distance = manhattenDistance(a[i], b[i]);
        fprintf(ofp, "%d\n", distance);
    }
}