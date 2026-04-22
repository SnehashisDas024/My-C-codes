#include <stdio.h>
#include <stdlib.h>
void main(){
    FILE *rptr,*wptr;
    char ch;
    rptr=fopen("C:\\Users\\sneha\\OneDrive\\Desktop\\My Apps\\Coding\\c(college)\\Profile.txt","r");
    if(rptr==NULL){
        perror("Source file could not be opened");
        exit(0);
    }
    wptr=fopen("MyProfile.txt","w");
    if(wptr==NULL){
        printf("Destinationn file could not be opened");
        fclose(rptr);
        exit(0);
    }
    while(1){
        ch=fgetc(rptr);
        if(ch==EOF){
            break;
        }
        fputc(ch,wptr);
    }
    fclose(rptr);
    fclose(wptr);
}
