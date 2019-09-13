#include <stdio.h>

struct point{
	int x;
	int y;
	int z;
};

void printPoint(struct point pt);
void readPoint(struct point *);
void printAngle(struct point *, int);

int main(void) {
	printf("Enter the number of angles of a shape you want co-ordinates of:\n");
	int k;
	scanf("%d", &k);
	printf("You are working with a shape of %d angles\n", k);
	struct point angle[k];
	int i;
	for (i=0; i<k; i++){
		readPoint(&angle[i]);
	}
	printAngle(angle, k);
	return 0;
}

void readPoint(struct point * ptr) {
	printf("\nEnter a new point: \n");
	printf("x-coordinate: ");
	scanf("%d", &ptr->x);
	printf("y-coordinate: ");
	scanf("%d", &ptr->y);
	printf("z-coordinate: ");
}

void printAngle(struct point *ptr, int k) {
	int i;
	for (i=0; i<k; i++) {
		printPoint(ptr[i]);
	}
}

void printPoint(struct point pt){
	printf("(%d, %d, %d)\n", pt.x, pt.y, pt.z);
}