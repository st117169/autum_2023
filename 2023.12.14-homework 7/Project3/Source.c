#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	FILE* pf = fopen("in.txt", "r");
	if (!pf) {
		printf("Error!");
		return 1;
	}

	int cnt = 0;
	char* buf = (char*)malloc(sizeof(char) * cnt);
	int count = 0;
	while (!feof(pf))
	{
		char c;
		fscanf(pf, "%c", &c);
		if (isalpha(c)) {
			buf = (char*)realloc(buf, cnt + 1);
			buf[cnt] = c;
			cnt++;
		}
		else if(cnt != 0) {
			buf = (char*)realloc(buf, cnt + 1);
			buf[cnt] = '\0';
			printf("%s\n", buf);
			cnt = 0;
			buf = (char*)realloc(buf, 0);
			count++;
		}
	}

	if (cnt != 0) {
		buf = (char*)realloc(buf, cnt + 1);
		buf[cnt] = '\0';
		printf("%s\n", buf);
		cnt = 0;
		buf = (char*)realloc(buf, 0);
		count++;
	}

	printf("%d", count);

	return 0;
}