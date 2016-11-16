#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define FIELD_WIDTH 3
#define STR_LEN 256
#define STR_MASK "%255[^\n]%*c"

int main(void){
	char str[STR_LEN];

	while (printf("String: ") && scanf_s(STR_MASK, str) == 1){
		if (strlen(str) < FIELD_WIDTH)
			printf("2short!\n");
		else {
			char * p;
			for (p = str + FIELD_WIDTH; p > str && !isspace(*p); --p)
				;
			if (p == str)
				printf("Mission imposible!\n");
			else {
				*p = '\n';
				printf("Result:\n%s\n", str);
			}
		}
	}

	return 0;
}