#include <linux/limits.h>
#include <stdio.h>
#include <unistd.h>

void concat_mode(int count,char *args[]){
	int i = 1;
	for (i = 1; i < count; i++){
		FILE *file;
		file = fopen(args[i],"r");
		char buffer[PATH_MAX];

		if (!file){
			perror("error opening file.");
			return ;
		}

		while (fgets(buffer,sizeof(buffer),file)) {
			printf("%s",buffer);
		}

		fclose(file);

	}

}

void stdin_read_mode(int count,char *args[]){
	char buffer[PATH_MAX];
	while (fgets(buffer,sizeof(buffer),stdin)){	
		printf("%s",buffer);
	}
}




int main(int argc,char *argv[]){
	if (argc >= 2) {			/* if 1 or more args passed */
		concat_mode(argc,argv);	
	}
	else {						/* if no arg passed */
		stdin_read_mode(argc,argv);
	}
	return 0;
}
