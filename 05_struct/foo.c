#include <stdio.h>

typedef struct student ST;

struct student{
	char name[20];
	int age;
	int score;
	struct student* friend;
};

int main(){
	ST student1 = { "Iron man", 48, 99 };
	ST student2 = { "Thanos", 50, 50 };

	student1.friend = &student2;
	student2.friend = &student1;

	printf("student1's name is %s and age is %d, and score is %d\n", student1.name, student1.age, student1. score);	
	printf("student2's name is %s and age is %d, and score is %d\n", student2.name, student2.age, student2. score);	
	printf("%s's friend's name : %s\n", student2.name, student2.friend->name);

	return 0;
}
