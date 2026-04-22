#include <stdio.h>
#include <stdlib.h>
void main(){
    FILE *rptr,*wptr;
    int i;
    char c,ce[100];
    char ch[30]="Happy new year";
    wptr=fopen("Test1.txt","w+");
    if(wptr==NULL){
        perror("Could not be opened");
        exit(0);
    }
    fputs("Happy halooo",wptr);
    fseek(wptr,0,SEEK_SET);
    fgets(ce,100,wptr);
    puts(ce);
    fseek(wptr,-5,SEEK_CUR);
    for(i=0;ch[i]!='\0';i++){
        fputc(ch[i],wptr);
    }
    fclose(wptr);
}