#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100
#define DISK_SIZE 200

int main() {
    int requests[MAX_REQUESTS];
    int num_requests;
    int head_position;
    int total_head_movement = 0;
    int direction;

    printf("Enter number of disk requests: ");
    scanf("%d", &num_requests);

    printf("Enter request sequence (space separated): ");
    for(int i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head_position);

    printf("Enter initial direction (1 for right, 0 for left): ");
    scanf("%d", &direction);

    for(int i = 0; i < num_requests - 1; i++) {
        for(int j = 0; j < num_requests - i - 1; j++) {
            if(requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    int head_index = 0;
    while(head_index < num_requests && requests[head_index] < head_position) {
        head_index++;
    }

    if(direction == 1) {
        for(int i = head_index; i < num_requests; i++) {
            total_head_movement += abs(requests[i] - head_position);
            head_position = requests[i];
        }
        if(head_position != DISK_SIZE - 1) {
            total_head_movement += abs((DISK_SIZE - 1) - head_position);
            head_position = DISK_SIZE - 1;
        }
        for(int i = head_index - 1; i >= 0; i--) {
            total_head_movement += abs(requests[i] - head_position);
            head_position = requests[i];
        }
    } else {
        for(int i = head_index - 1; i >= 0; i--) {
            total_head_movement += abs(requests[i] - head_position);
            head_position = requests[i];
        }
        if(head_position != 0) {
            total_head_movement += abs(0 - head_position);
            head_position = 0;
        }
        for(int i = head_index; i < num_requests; i++) {
            total_head_movement += abs(requests[i] - head_position);
            head_position = requests[i];
        }
    }

    printf("\nTotal Head Movement: %d cylinders\n", total_head_movement);

    return 0;
}
