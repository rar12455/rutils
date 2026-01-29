#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>

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


		if (l_par == 1 && a_par == 0){
			if (strncmp(entry->d_name,".",1) == 0){
				continue;
			}
			printf(" %s \n",entry->d_name);
		}
	}

	putchar('\n');
}

int main(int argc, char *argv[]){
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-v") == 0) {
      printf("ls from rutils - alpha\n");
      return 0;
    }
    else if (strcmp(argv[i], "-h") == 0){
      printf("usage: [-v = version] [-h = help] [<path> = path to listdir]\n");
      return 0;
    }
    else if (strcmp(argv[i],"-a") == 0) {
      a_par = 1;
	  listdir();
      return 0;
    }
	else if (strcmp(argv[i],"-l") == 0) {
	  l_par = 1;
	  listdir();
	  return 0;
	}
    else if (argv[i][0] == '-') {
      printf("undefined argument: %s\n", argv[i]);
      return 1;
    }
    else {
      printf("not an argument: %s\n", argv[i]);
      return 1;
    }
  }

	listdir();
	return 0;
}
