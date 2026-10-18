/* CS100 Fall 2026 - HW2 Problem 5: CPU emulator
 *
 * Emulate a toy CPU with registers x0..x5 (16-bit signed, x0 always 0)
 * executing add/sub/mul/div/let/print instructions read as hex words.
 * Do not use <math.h>. Do not rename this file.
 */
#include <stdio.h>

int main(void)
{
    int arr[6]={0,0,0,0,0,0};
    int n;
    scanf("%d",&n)
    for (int i=0;i<n;i++){
        int a;
        scanf("%x",&a);
        int opcode=a>>13;
        int r1=(a>>10) & 0x7;
        int r2=(a>>7) & 0x7;
        int imm=a & 0x7F;
        
        if (opcode==0) arr[r1]+=arr[r2];
        else if (opcode==1) arr[r1]-=arr[r2];
        else if (opcode==2) arr[r1]*=arr[r2];
        else if (opcode==3) arr[r1]/=arr[r2];
        else if (opcode==4) arr[r1]=imm;
        else if (opcode==5) printf("%d",arr[r1]); 


    }
    return 0;
}
