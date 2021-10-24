#include<stdio.h>
#include<stdlib.h>

int *input() {
	int i;

    int *ptr = (int *)malloc(5*sizeof(int));
    
    if(ptr == NULL) {
        printf("Memory not available");
        exit(1);
    }

	printf("Enter five integer: ");
    for(i = 0; i < 5; i++ ){
        scanf("%d", ptr +i);
    }
    return ptr;
}

int main() {
    int i,sum =0;

    int *ptr = input();
    
    if(ptr == NULL) {
        printf("Memory not available");
        exit(1);
    }

    for(i = 0; i < 5; i++ ){
        sum += *(ptr+i);
    }

    printf("Sum is: %d",sum);
    free(ptr);
//    assigning null to the pointer to make sure it is not a dangling pointer
    ptr = NULL;
    return 0;
}
