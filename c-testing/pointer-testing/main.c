//TO RUN FILE ----> 
//   1.  Assuming the name of this file is main.c otherwise adjust the following steps accordingly
//   2.  In terminal while in this directory type:  gcc -o main main.c
//   3.  type ./main to run the program.
//--------------------------------------------------------------------

#include <stdio.h>   //include for printf
#include <stdlib.h>  //include for malloc


void changeInt(int *ptr) {

    *ptr = 5;

}

void changeStr(char *str[]) {

    *str = "Here is the new message";

}

void changeArr(void *array){

    int *tempArray =(int *)array;           //New variable = typecasted INT version of array param
    tempArray[1] = 10;                      //Changing tempArray also changes val of array param
}

int main() {

    //CHANGE INT POINTER
    int x = 0;
    int *ptr = &x;                          //ptr is equal to address of x (equal to dereferenced X)
    changeInt(ptr);                         //pass in ptr without dereference
    printf("ptr is %d\n",*ptr);

    //CHANGE STRING POINTER
    char message[] = "this is a c string"; 
    char *str = message;                   //ptr equal to c string, unlike INT example^^^
    changeStr(&str);                       //dereference pointer string when passing in
    printf("message: %s\n",str);

    //CHANGE DYNAMIC ARRAY OF INTS POINTER
    int *array;
    array = (int *)malloc(sizeof(int)*10); //allocate 10 ints
    array[1] = 0;
    changeArr((void *) array);             //Type cast to void when passing in.. IDK WHY
    printf("array[1]  is: %d\n",array[1]);

    //ACESSING ARRAY OF ARRAY
    int *arrayofarrays[2];
    arrayofarrays[0] = array;
    int *num = arrayofarrays[0];
    
    printf("buffer[0] is %d\n",num[1]);

}