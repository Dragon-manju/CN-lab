#include <stdio.h>

int main() 
{ 
    int w, i, f, frames[50];  
    
    printf("Enter window size: "); 
    scanf("%d", &w);  
    
    printf("\nEnter number of frames to transmit: "); 
    scanf("%d", &f);  
    
    printf("\nEnter %d frames: ", f);  
    for (i = 0; i < f; i++) 
        scanf("%d", &frames[i]);  
    
    printf("\nWith sliding window protocol, the frames will be sent in the following manner (assuming no corruption of frames)\n\n"); 
    printf("After sending %d frames at each stage, the sender waits for acknowledgements sent by the receiver\n\n", w); 
    
    for (i = 0; i < f; i++) 
    { 
        printf("%d ", frames[i]); 
        
        if ((i + 1) % w == 0 || (i + 1) == f) 
        { 
            printf("\nAcknowledgement of above frames sent is received by sender\n\n"); 
        } 
    }  
    
    return 0; 
}
