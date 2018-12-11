#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[]) {

	FILE *readP = fopen(argv[1], "r");
	int spaceCount = 0;
	int lineCount = 0;
	int charCount = 0;
	char buffer[1000];
	while (!feof(readP)) {
		fgets(buffer, sizeof(buffer), readP);
		for (int i = 0; buffer[i] != 0; i++) {
			int tempCharCount = 0;
			if (buffer[i] >= 33 && buffer[i] <= 126) {
				charCount++;
				//tempCharCount++;            //실제 문자개수보다 하나 작음
			}
	
			if (buffer[i] == ' ') spaceCount++;
		}
		spaceCount++;
		lineCount++;
	}
	printf("파일명:%s\n", argv[1]);
	printf("line count: %d\n", lineCount);
	printf("word count: %d\n", spaceCount);
	printf("character count: %d\n", charCount);

	argv[1][strlen(argv[1]) - 3] = 'r';
	argv[1][strlen(argv[1]) - 2] = 'e';
	argv[1][strlen(argv[1]) - 1] = 'v';

	FILE *writeP = fopen(argv[1],"w");
	rewind(readP);
	while (!feof(readP)) {
		fgets(buffer, sizeof(buffer), readP);
		for (int i = 0; buffer[i] != 0; i++) {
			if (buffer[i] >= 'A'&&buffer[i] <= 'Z') {
				buffer[i] += 32;
			}
			else if(buffer[i] >= 'a'&&buffer[i] <= 'z') {
				buffer[i] -= 32;
			}
		}
		fputs(buffer, writeP);
	}
	printf("대소문자 변환 파일 %s 저장하였음", argv[1]);
	fclose(readP);
	fclose(writeP);
}