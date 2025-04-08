#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TIMEOUT 3
#define TOTAL_PACKETS 5

int simulate_acknowledgment() {
    return rand() % 10 < 7;
}

int main() {
    srand(time(0));
    int packet=1,ack;
    while(packet<=TOTAL_PACKETS) {
        printf("Sending packet %d\n",packet);
        sleep(1);
        ack=simulate_acknowledgment();
        if(ack) {
            printf("ACK received for packet %d\n\n",packet);
            packet++;
        } else {
            printf("ACK lost for packet %d. Retransmitting...\n\n",packet);
            sleep(TIMEOUT);
        }
    }
    printf("All packets sent successfully\n");
    return 0;
}
