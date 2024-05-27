#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include<cstring>

//void count (char* )

int main()
{
	FILE* file = fopen("in.txt", "r");
	int len = 0;
	int w = 0;
	char* l = (char*)malloc(sizeof(char) * len);
	if (file)
	{
		while (!feof(file))
		{
			char c = ' ';
			fscanf(file, "%c", &c);
			len++;
		}
	}
	else
	{
		printf("file not found");

	}

	

	fclose(file);
	printf("%d", len);
	return 0;
}
