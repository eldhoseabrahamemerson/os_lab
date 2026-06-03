#include<stdio.h>
int mutex=1;
int full=0;
int empty,x=0;

void producer(){
    mutex--;
    full++;
    empty--;
    x++;
    printf("producer produces item %d",x);
    mutex++;
}
void consumer(){
    mutex--;
    full--;
    empty++;
    printf("consumer consumes item %d",x);
    x--;
    mutex++;
}
int main(){
    int choice;
    printf("enter the buffer size: ");
    scanf("%d",&empty);
    while(1){
        printf("1.producer\n2.consumer\n3.exit\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            if((mutex==1)&&(empty!=0)){
                producer();
            }
            else{
                printf("buffer is full");
                break;
            }
            case 2:
            if((mutex==1)&&(full!=0)){
                consumer();
            }
            else{
                printf("buffer is empty");
                break;
            }
            case 3:
            printf("exiting");
            return 0;
        }
    }
}
