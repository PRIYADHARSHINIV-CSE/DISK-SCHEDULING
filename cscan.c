#include <stdio.h>
#include <stdlib.h>

int main()
{
    int req[20], n, head, disk_size;
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

    /* Move towards higher cylinders */
    for(i = 0; i < n; i++)
    {
        if(req[i] >= head)
        {
            seek += abs(req[i] - head);
            head = req[i];
            printf("%d ", head);
        }
    }

    /* Move to the end of disk */
    seek += abs((disk_size - 1) - head);
    head = disk_size - 1;

    /* Jump to beginning */
    seek += disk_size - 1;
    head = 0;

    /* Service remaining requests */
    for(i = 0; i < n; i++)
    {
        if(req[i] < head)
        {
            seek += abs(req[i] - head);
            head = req[i];
            printf("%d ", head);
        }
    }

    printf("\nTotal Head Movement = %d\n", seek);

    return 0;
}
