#include <stdio.h>
#include <stdlib.h>
void main(){
    FILE *rptr,*wptr;
    int i;
    char c;
    char ch[30]="Happy new year";
    wptr=fopen("Test .txt","w");
    if(wptr==NULL){
        perror("Could not be opened");
        exit(0);
    }
    for(i=0;ch[i]!=0;i++){
        c=ch[i];
        fputc(c,wptr);
    }
    fclose(wptr);

} 