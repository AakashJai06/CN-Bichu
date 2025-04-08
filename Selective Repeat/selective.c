#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int ack() {
    return rand() % 2;
}

int main() {
    int n,ws,wt,i,j;
    srand(time(0));
    printf("Packets to send: ");
    scanf("%d",&n);
    printf("Window size: ");
    scanf("%d",&ws);
    printf("Wait time: ");
    scanf("%d",&wt);
    int sent[n+1];
    for(i=1;i<=n;i++) sent[i]=0;
    i=1;
    while(i<=n) {
        for(j=0;j<ws&&i+j<=n;j++) {
            int pkt=i+j;
            if(!sent[pkt]) {
                printf("Sending packet %d\n",pkt);
                sleep(1);
            }
        }
        for(j=0;j<ws&&i+j<=n;j++) {
            int pkt=i+j;
            if(!sent[pkt]) {
                if(ack()) {
                    printf("ACK received for packet %d\n",pkt);
                    sent[pkt]=1;
                } else {
                    printf("ACK lost for packet %d. Retry in %d sec\n",pkt,wt);
                }
            }
        }
        while(sent[i]&&i<=n) i++;
        if(i<=n) sleep(wt);
    }
    printf("All packets sent successfully with Selective Repeat\n");
    return 0;
}
