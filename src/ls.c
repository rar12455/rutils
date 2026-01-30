#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h> // for getopt

bool a_par = 0;
bool l_par = 0;

void listdir(){

	DIR *dir = opendir(".");

	if (!dir){
		perror("error opening dir\n");
		return;
	}

	struct dirent *entry;

	while ((entry = readdir(dir)) != NULL) {

		if (a_par == 0 && l_par == 0){
			if (strncmp(entry->d_name,".",1) == 0){
				continue;
			}
			if (strcmp(entry->d_name,".") == 0){
				printf("%s ",entry->d_name);
			}
			printf(" %s ",entry->d_name);
		}
		else if (a_par == 1 && l_par == 0){
			if (strcmp(entry->d_name,".") == 0){
				printf("%s ",entry->d_name);
			}
			printf(" %s ",entry->d_name);
		}


		if (a_par == 0 && l_par == 1){
			if (strncmp(entry->d_name,".",1) == 0){
				continue;
			}
			printf(" %s \n",entry->d_name);
		}
		if (a_par == 1 && l_par == 1){
			printf(" %s \n",entry->d_name);
		}
	}

	putchar('\n');
}

int main(int argc, char *argv[]){

	int opt;
	
	while ((opt = getopt(argc,argv,"al")) != -1) {
		switch (opt) {
			case 'a':	
				a_par = 1;
				break;
			case 'l':
				l_par = 1;
				break;
			case '?':
				// getopts prints out error message
				return 1;
		}
		
	
	}
	listdir();
	return 0;
}
