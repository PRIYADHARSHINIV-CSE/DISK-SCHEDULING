#include <stdio.h>
#include <stdlib.h>

int main()
{
    int req[20], n, head, disk_size, direction;
    int i, j, temp, seek = 0;

    printf("Enter Disk Size: ");
    scanf("%d", &disk_size);

    printf("Enter Number of Requests: ");
    scanf("%d", &n);

    printf("Enter Request Queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter Initial Head Position: ");
    scanf("%d", &head);

    printf("Enter Direction (1 = Higher, 0 = Lower): ");
    scanf("%d", &direction);

    /* Sort requests */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(req[i] > req[j])
            {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    printf("\nSeek Sequence: ");

    if(direction == 1)
    {
        for(i = 0; i < n; i++)
        {
            if(req[i] >= head)
            {
                seek += abs(req[i] - head);
                head = req[i];
                printf("%d ", head);
            }
        }

        seek += abs((disk_size - 1) - head);
        head = disk_size - 1;

        for(i = n - 1; i >= 0; i--)
        {
            if(req[i] < head)
            {
                seek += abs(req[i] - head);
                head = req[i];
                printf("%d ", head);
            }
        }
    }
    else
    {
        for(i = n - 1; i >= 0; i--)
        {
            if(req[i] <= head)
            {
                seek += abs(req[i] - head);
                head = req[i];
                printf("%d ", head);
            }
        }

        seek += abs(head - 0);
        head = 0;

        for(i = 0; i < n; i++)
        {
            if(req[i] > head)
            {
                seek += abs(req[i] - head);
                head = req[i];
                printf("%d ", head);
            }
        }
    }

    printf("\nTotal Head Movement = %d\n", seek);

    return 0;
}
