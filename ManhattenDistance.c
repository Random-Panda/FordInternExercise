#include <stdio.h>
#include <stdlib.h>

struct Point
{
    int x;
    int y;
};
typedef struct Point point;

int manhattenDistance(point a, point b);

int main()
{
    char escape = 'y';
    point a, b;
    int distance = 0;

    while (escape == 'y')
    {

        printf("Please enter point 'a' {x,y}\n");
        scanf("%d,%d", &a.x, &a.y);

        printf("Please enter point 'b' {x,y}\n");
        scanf("%d,%d", &b.x, &b.y);

        distance = manhattenDistance(a, b);

        printf("The distance between point 'a' and 'b' is %d\n", distance);
        printf("Would you like to find a new distance ('y'/'n')\n");

        scanf(" %c", &escape);
    }

    return 0;
}

int manhattenDistance(point a, point b)
{
    int distance = 0;
    distance = abs(a.x - b.x) + abs(a.y - b.y);
    return distance;
}
