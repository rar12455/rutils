#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h> // for getopt

bool a_par = 0;
bool l_par = 0;
bool lsout_spaced = 0;
struct dirent *entry;

#define DIR_COLOR "\033[01;34m%s\033[0m " // DIR_COLOR = BLUE
#define DIR_COLOR_s " \033[01;34m%s\033[0m " // DIR_COLOR_s = BLUE but spaced for first
#define DEFAULT_COLOR "%s " // DEFAULT_COLOR = WHITE 
#define DEFAULT_COLOR_s " %s " // DEFAULT_COLOR_s = WHITE but spaced for first 

void paintdirs(){
	switch (entry->d_type) {
		case DT_DIR:	
			if (lsout_spaced == 1){
				printf(DIR_COLOR_s,entry->d_name);
			}
			else {
				printf(DIR_COLOR,entry->d_name);
			}
			break;
		default:
			if (lsout_spaced == 1){
				printf(DEFAULT_COLOR,entry->d_name);
			}
			else {
				printf(DEFAULT_COLOR_s,entry->d_name);
			}
			break;
	}
}

void listdir(){

	DIR *dir = opendir("/home/rar"); // TODO: Make path "user-inputable".

	if (!dir){
		perror("error opening dir\n");
		return;
	}

	while ((entry = readdir(dir)) != NULL) {

		if (a_par == 0 && l_par == 0){
			if (strncmp(entry->d_name,".",1) == 0){
				continue;
			}
			if (strcmp(entry->d_name,".") == 0){
				lsout_spaced = 1;
	  			paintdirs();
			}
			paintdirs();
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
