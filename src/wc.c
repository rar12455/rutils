#include <linux/limits.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char FILE_CONTENT[PATH_MAX];

void open_file(char FILE_PATH[]){
	FILE *file;
	file = fopen(FILE_PATH,"r");
	if (!file){
		perror("error opening file");
		return;
	}
	size_t bytesRead = fread(FILE_CONTENT, 1, sizeof(FILE_CONTENT) - 1, file);
    FILE_CONTENT[bytesRead] = '\0';
	fclose(file);
}
void newline_count(char buffer[]){
	int len_s = strlen(buffer);
	int newline_count = 0;
	for (int i = 0; i < len_s; i++) {
		if (buffer[i] == '\n'){
			newline_count = newline_count + 1;
		}
	}
	printf("%d",newline_count);
}

int main(int argc,char *argv[]){
	open_file(argv[PATH_MAX]);
	newline_count(FILE_CONTENT);
	return 0;
}
