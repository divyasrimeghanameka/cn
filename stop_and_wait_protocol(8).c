#include <stdio.h> 
int main() { 
    int total_frames, ack; 
    int frame=0; 
    printf("Enter the total number of frames to send: "); 
    scanf("%d", &total_frames); 
    while (frame < total_frames) 
    { 
        printf("Sender: Sending Frame %d\n", frame); 
        printf("Receiver: Enter received frame number (or -1 if the frame is lost): "); 
        int recv; 
        scanf("%d", &recv); 
        if (recv == frame) 
        { 
            printf("Receiver: Frame %d received. Sending ACK %d\n", recv, recv); 
            ack = recv; 
        } 
        else 
        { 
            printf("Receiver: Frame lost or out-of-order. No ACK sent.\n"); 
            ack = -1; 
        } 
        if (ack == frame) 
        { 
            printf("Sender: ACK %d received. Proceeding to next frame.\n\n", ack); 
            frame++; 
        } 
        else 
        { 
            printf("Sender: No valid ACK received. Retransmitting Frame %d...\n\n", frame); 
        } 
    } 
    printf("All frames sent and acknowledged!\n"); 
    return 0; 
} 
/*output:
Enter the total number of frames to send: 5
Sender: Sending Frame 0
Receiver: Enter received frame number (or -1 if the frame is lost): -1
Receiver: Frame lost or out-of-order. No ACK sent.
Sender: No valid ACK received. Retransmitting Frame 0...

Sender: Sending Frame 0
Receiver: Enter received frame number (or -1 if the frame is lost): 0
Receiver: Frame 0 received. Sending ACK 0
Sender: ACK 0 received. Proceeding to next frame.

Sender: Sending Frame 1
Receiver: Enter received frame number (or -1 if the frame is lost): 1
Receiver: Frame 1 received. Sending ACK 1
Sender: ACK 1 received. Proceeding to next frame.

Sender: Sending Frame 2
Receiver: Enter received frame number (or -1 if the frame is lost): 2
Receiver: Frame 2 received. Sending ACK 2
Sender: ACK 2 received. Proceeding to next frame.

Sender: Sending Frame 3
Receiver: Enter received frame number (or -1 if the frame is lost): 3
Receiver: Frame 3 received. Sending ACK 3
Sender: ACK 3 received. Proceeding to next frame.

Sender: Sending Frame 4
Receiver: Enter received frame number (or -1 if the frame is lost): 4
Receiver: Frame 4 received. Sending ACK 4
Sender: ACK 4 received. Proceeding to next frame.

All frames sent and acknowledged!
  */
