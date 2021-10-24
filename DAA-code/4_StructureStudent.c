#include<stdio.h>
#include<stdlib.h>

struct student {
	char name[50];
	int age;
	int roll_no;
	float marks;
};

void print(char name[], int age, int roll, float marks) {
	printf("%s %d %d %.2f",name, age, roll, marks);
}
int main() {
    struct student s1 = {"Nick", 16, 2, 21};
    print(s1.name, s1.age, s1.roll_no, s1.marks);
    return 0;
}
