#include <stdio.h>
#include <stdlib.h>

struct human{
	char name[20];
	int age;
};

typedef struct human H;

void age_increment(H* h){
	h->age++;
}

int main(){
	H human1 = { "Iron man", 48 };
	H human2 = { "Thanos", 50 };

	human1.age = 17;
	human2.age = 200;

	printf("name is %s, and age is %d\n", human1.name, human1.age);
	printf("name is %s, and age is %d\n", human2.name, human2.age);

	H* hp1 = (H*)malloc(sizeof(H));
	H* hp2 = (H*)malloc(sizeof(H));

	hp1->age = 12;
	hp2->age = 25;
	

	printf("name is %s, and age is %d\n", hp1->name, hp1->age);
	printf("name is %s, and age is %d\n", hp2->name, hp2->age);

	return 0;
}
