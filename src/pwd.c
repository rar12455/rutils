#include <stdio.h>
#include <unistd.h>

int main(){
	char pwd[256];
	if (getcwd(pwd, sizeof(pwd)) != NULL) {
		printf("%s",pwd);	
		return 0;
	}
	else {
		printf("error!");
		return 1;
	}
	return 0;
}
