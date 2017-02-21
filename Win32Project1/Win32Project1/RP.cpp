#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <ctime> 
using namespace std;

void queenHorse(int x1, int y1, int x2, int y2) {
	// queen beats horse:
	if ((x1 - x2 == 0) || (y1 - y2 == 0) || (x1 - x2 == y1 - y2))
		printf("Queen beats horse");
	else
		if ((abs(x1 - x2) == 1 && abs(y1 - y2) == 2) ||
			(abs(y1 - y2) == 1 && abs(x1 - x2) == 2))
			printf("Horse beats queen");
}

int fishTank(int vol, int num) {
	int excess = 0;
	int b = (int)(vol / 3);
	if ( b < num)
		return num - b;
	return excess;
}

int poultry(int N, int d) {
	int eggs = 0;
	eggs = (int)(d * N / (1.5 * 1.5) * 1.5);
	return eggs;
}

void theSum(int sum, int &x, int &y) {
	/*float rem = sum / 3;
	if (sum - (int)(sum / 3) * 3 == 0)
		return;
	if (rem > (int)(sum / 3) - 0.5)

	else
		if (rem > (int)(sum / 3) - 0.5)*/

	int rem = sum - (int)(sum / 3) * 3;
	if (rem == 0) {
		x = sum / 3; y = 0;
	}
	else
		if (rem == 1) {
			x = (sum - 10) / 3; y = 2;
		}
		else {
			x = (sum - 5) / 3; y = 1;
		}
}

void durabilityTest(int d, int rot, int dist) {
	int diff = rot - dist / 0.0008;
	printf("\n%d", diff);
}

void monitor(int w, int l, int colnum, int mem) {
	int memKb = w * l * 11;
	int memBuf = mem * 1024 * 1024 * 8; // in bites;
	printf("diff = %d", memBuf - memKb);
}

void allPairs(int sum, int x, int y) {
	int mult = sum / y;
	if (sum - (int)(sum / y) * y == 0)
	printf("x*%d + y*%d = %d", 0, sum / y, sum);
	if (sum - (int)(sum / x) * x == 0)
		printf("x*%d + y*%d = %d", sum / x, 0, sum);
	for (int i = 0; i < mult; i++) {
		if (sum - y * i - (int)((sum - y * i) / x) == 0)
			printf("x*%d + y*%d = %d", (sum - y * i) / x, i, sum);
	}
}

int factorial(int n) {
	int f = 1;
	for (int i = 2; i <= n; i++) {
		f = f * i;
	}
	return f;
}
int factorial_rec(int f, int n) {
	if (n == 1) return f;
	f = factorial_rec(f, n - 1) * n;
	return f;
}

void combinations(int n, int m) {
	int c;
	c = factorial(n) / (factorial(m) * factorial(m - n));
	printf("combinations = %d\n", c);
	c = factorial_rec(1, n) / (factorial_rec(1, m) * factorial_rec(1, n - m));
	printf("combinations fact= %d\n", c);
}


int search(char src[], char str[]) {
	int i, j, firstOcc;
	i = 0, j = 0;

	while (src[i] != '\0') {

		while (src[i] != str[0] && src[i] != '\0')
			i++;

		if (src[i] == '\0')
			return (0);

		firstOcc = i;

		while (src[i] == str[j] && src[i] != '\0' && str[j] != '\0') {
			i++;
			j++;
		}

		if (str[j] == '\0')
			return (firstOcc);
		if (src[i] == '\0')
			return (0);

		i = firstOcc + 1;
		j = 0;
	}

}

int checkNegPos(int* A, int size) {
	int count = 0;
	int zero = 0;
	for (int i = 0; i < size; i++) {
		if (A[i] > 0)
			count++;
		else
			if (A[i] == 0)
				zero++;
	}
	if (count > size - zero)
		return 1;
	else
		return 0;
}

void snowOrRain(int* temp, int* prec, int& rain, int& snow) {
	for (int i = 0; i < 10; i++) {
		if (temp[i] < 0) snow += prec[i];
		else
			rain += prec[i];
	}
}

void trainTakeOff(char** takeOff, int& count) {
	for (int i = 0; i < 6; i++) {
		// 5:00 < x < 21:07
		if ((*(*(takeOff + i)) - '5' >= 0) && (*(*(takeOff + i) + 1) - ':' == 0))
			count++;
		else
			if ((*(*(takeOff + i) + 2) - ':' == 0) && (*(*(takeOff + i)) - '1' == 0))
				count++;
			else
				if ((*(*(takeOff + i) + 2) - ':' == 0) && (*(*(takeOff + i) + 3) - '0' == 0) && (*(*(takeOff + i) + 4) - '7' <= 0))
					count++;

		printf("%c\n", *(*(takeOff + i)));
		printf("%c\n", *(*(takeOff + i)+1));
	}
}

class Students
{
public:
	int speed;
	char* studentName;
};
void assignValues(Students* students, int cnt) {
	srand(time(NULL));
	for (int i = 0; i < cnt; i++) {
		char c[4] = { (rand() % 100), (rand() % 10), (rand() % 20), '\0' };
		students[i].studentName = c;
		students[i].speed = (int)(rand() % 100);
	}
}
void statStudent(Students* students, int cnt) {
	int max = 0;
	int indx = 0;
	int avgSpeed = 0;
	for (int i = 0; i < cnt; i++) {
		avgSpeed += students[i].speed;
		if (max < students[i].speed) {
			max = students[i].speed;
			indx = i;
		}
	}
	avgSpeed = avgSpeed / cnt;

	printf("name: %s, speed: %d", students[indx].studentName, students[indx].speed);
	printf("\navg speed: %d", avgSpeed);
	for (int i = 0; i < cnt; i++) {
		if (students[i].speed < avgSpeed)
			printf("\nname: %s, speed: %d", students[i].studentName, students[i].speed);
	}
}

void assignWeight(int* M, int cnt, int maxWeight) {
	srand(time(NULL));//time(NULL));
	for (int i = 0; i < cnt; i++) {
		M[i] = rand() % maxWeight;
	}
}

int numberOfFlights(int *M, int cnt, int maxWeight) {
	int sum = 0;
	int i = 0;
	int total = 0;
	while (i < cnt) {
		sum += M[i++];
		if (sum > maxWeight) {
			sum = 0;
			i--;
		}
		else
			total++;
	}
	return total;
}

void main() {
	//p2.8
	int cnt = 15;
	int maxWeight = 50;

	int M[15];
	assignWeight(M, cnt, maxWeight);
	int total = numberOfFlights(M, cnt, maxWeight);
	int a = 0;
	// hm


	////p2.7
	//srand(time(NULL));
	//char c = (rand() % 100);
	//char* yo = &c;
	//const int cnt = 25;
	//Students students[25];
	//assignValues(students, cnt);
	//statStudent(students, cnt);

	////p2.6
	//char* takeOff[6] = { "1:12", "13:01", "5:27", "7:17", "21:07", "16:03" };
	//int count = 0;
	//trainTakeOff(takeOff, count);
	//printf("%d", count);
	////p2.5
	//int temp[10];
	//int prec[10];
	//srand(time(NULL));
	//for (int i = 0; i < 10; i++) {
	//	temp[i] = sin(i) * (rand() % 100);
	//	prec[i] = rand() % 50;
	//}
	//int rain = 0, snow = 0;
	//snowOrRain(temp, prec, rain, snow);
	//printf("rain: %d, snow: %d", rain, snow);
	////p2.4
	//const int size = 50;
	//int A[size];
	//time_t t;
	///* Intializes random number generator */
	////srand((unsigned)time(&t));
	//srand(time(NULL));
	//for (int i = 0; i < 50; i++) {
	//	A[i] = sin(i)*50*rand();
	//}
	//printf("%d", checkNegPos(A, size));

	//// parse the file
	//FILE *file;
	//int loc;

	//file = fopen("files_to_send/400", "r");

	//if (file == 0)
	//{
	//	//fopen returns 0, the NULL pointer, on failure
	//	perror("Canot open input file\n");
	//	exit(-1);
	//}

	//char line[256];
	//char cpu_usage1[500][4];
	//int j = 0;
	//char cpu_usage2[500][4];
	//char cpu_usage3[500][4];
	//char cpu_usage4[500][4];
	//char cpu_usage5[500][4];


	//for(int k = 0; k < 7; k++)
	//fgets(line, sizeof(line), file);

	//int cpu_loc = search(line, "%CPU"); //48
	//while (fgets(line, sizeof(line), file)) {
	//	/* note that fgets don't strip the terminating \n, checking its
	//	presence would allow to handle lines longer that sizeof(line) */

	//	// search through all the processes:
	//	int k = 0;
	//	char* first = "10147";
	//	while (*(line + k) == *(first + k)) k++;
	//	if (k == 5) {
	//		//char eba[3] = { *(line + cpu_loc + 1), *(line + cpu_loc + 2), *(line + cpu_loc + 3) };
	//		////int count = 
	//		//float ftemp = atof(eba);
	//		char* asjk = line + cpu_loc;
	//		cpu_usage1[j][0] = *(line + cpu_loc + 1);
	//		cpu_usage1[j][1] = *(line + cpu_loc + 2);
	//		cpu_usage1[j][2] = *(line + cpu_loc + 3);
	//		cpu_usage1[j][3] = '\0';

	//	}

	//	k = 0;
	//	char* second = "10148";
	//	while (*(line + k) == *(second + k)) k++;
	//	if (k == 5) {
	//		char eba[3] = { *(line + cpu_loc + 1), *(line + cpu_loc + 2), *(line + cpu_loc + 3) };
	//		//int count = 
	//		float ftemp = atof(eba);
	//		cpu_usage2[j][0] = *(line + cpu_loc + 1);
	//		cpu_usage2[j][1] = *(line + cpu_loc + 2);
	//		cpu_usage2[j][2] = *(line + cpu_loc + 3);
	//		cpu_usage2[j][3] = '\0';
	//	}

	//	k = 0;
	//	char* third = "10149";
	//	while (*(line + k) == *(third + k)) k++;
	//	if (k == 5) {
	//		cpu_usage3[j][0] = *(line + cpu_loc + 1);
	//		cpu_usage3[j][1] = *(line + cpu_loc + 2);
	//		cpu_usage3[j][2] = *(line + cpu_loc + 3);
	//		cpu_usage3[j][3] = '\0';
	//	}

	//	k = 0;
	//	char* fourth = "10150";
	//	while (*(line + k) == *(fourth + k)) k++;
	//	if (k == 5) {
	//		cpu_usage4[j][0] = *(line + cpu_loc + 1);
	//		cpu_usage4[j][1] = *(line + cpu_loc + 2);
	//		cpu_usage4[j][2] = *(line + cpu_loc + 3);
	//		cpu_usage4[j][3] = '\0';
	//	}

	//	k = 0;
	//	char* fifth = "10151";
	//	while (*(line + k) == *(fifth + k)) k++;
	//	if (k == 5) {
	//		char* asjk = line + cpu_loc;
	//		cpu_usage5[j][0] = *(line + cpu_loc + 1);
	//		cpu_usage5[j][1] = *(line + cpu_loc + 2);
	//		cpu_usage5[j][2] = *(line + cpu_loc + 3);
	//		cpu_usage5[j][3] = '\0';
	//	}		

	//	if (loc = search(line, "top")) j++;
	//	printf("%s", line);
	//}
	///* may check feof here to make a difference between eof and io failure -- network
	//timeout for instance */
	//int yuy = 306;
	//FILE *f = fopen("400-1.data", "wb");
	//for (int k = 0; k < yuy; k++)
	//	fprintf(f, "%s\r\n", &cpu_usage1[k]);
	//fclose(f);
	//FILE *f2 = fopen("400-2.data", "wb");
	//for (int k = 0; k < yuy; k++)
	//	fprintf(f2, "%s\r\n", &cpu_usage2[k]);
	//fclose(f2);
	//FILE *f3 = fopen("400-3.data", "wb");
	//for (int k = 0; k < yuy; k++)
	//	fprintf(f3, "%s\r\n", &cpu_usage3[k]);
	//fclose(f3);
	//FILE *f4 = fopen("400-4.data", "wb");
	//for (int k = 0; k < yuy; k++)
	//	fprintf(f4, "%s\r\n", &cpu_usage4[k]);
	//fclose(f4);
	//FILE *f5 = fopen("400-5.data", "wb");
	//for (int k = 0; k < yuy; k++)
	//	fprintf(f5, "%s\r\n", &cpu_usage5[k]);
	//fclose(f5);
	////fwrite(cpu_usage5, 5, sizeof(cpu_usage5), f);
	//
	//fclose(file);

	////problem 2.3:
	//int n, m;
	//while (1) {
	//		cin >> n >> m;
	//		combinations(n, m);
	//	}
	////problem 2.1:
	//int sum, x, y;
	//while (1) {
	//	cin >> sum >> x >> y;
	//	allPairs(sum, x, y);
	//}
	// problem 10:
	/*int a = 5, b = 3;
	cin >> a >> b;
	a = a - b;
	b = b + a;
	a = b - a;
	printf("\na = %d, b = %d", a, b);*/
	////problem 8:
	//int w = 800, l = 600, colnum = 2048, mem = 4;
	//monitor(w, l, colnum, mem);

	////problem 7:
	//int d = 80, rot = 200000;
	//int dist;
	//cin >> dist;
	//durabilityTest(d, rot, dist);

	////problem 5:
	//while (1) {
	//	int sum = 0;
	//	cin >> sum;
	//	int x, y;
	//	theSum(sum, x, y);
	//printf("\n%d = 3*%d + 5*%d\n", sum, x, y);
	//}

	////problem 4:
	//int N, d;
	//cin >> N >> d;
	//printf("\nnumber of eggs: %d", poultry(N, d));

	////problem 3:
	//int vol, num, excess;
	//while (1) {
	//	cin >> vol >> num;
	//	printf("%d, %d\n", (int)(vol / 3), (int)(num / 3));
	//	excess = fishTank(vol, num);
	//	printf("number of fishes required to relocate: %d", excess);
	//}

	////problem 2:
	//int x1, x2, y1, y2;
	//printf("queen: ");
	//cin >> x1 >> y1;
	//printf("\nhorse: ");
	//cin >> x2 >> y2;
	//queenHorse(x1, y1, x2, y2);

	////problem 1:
	//int m, n, reqSpace, space = 6*1024;// 6144 kB
	//cin >> m;
	//cin >> n;
	//reqSpace = n * 16 + 60 * 16 * m;
	//printf("required space: %d\n", reqSpace);
	//if (reqSpace <= space)
	//	printf("audio-recording is possible");
	//else
	//	printf("not possible");

	getchar();
	getchar();
}
