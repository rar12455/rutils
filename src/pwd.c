#include <linux/limits.h> // FOR PATH_MAX
#include <unistd.h> 

int getpwd(){
	char pwd[PATH_MAX];
	if (getcwd(pwd,PATH_MAX)){

		/* BOILERPLATE:
		 * the write() doesn't stop at '\0'
		 * so we need do it 
		 * and also, write(1,foo,foo2);
		 * that 1 in write means STDOUT.
		 */

		int len = 0;
		while (pwd[len] != '\0') { // calcultate
			len++;	
		}
		pwd[len] = '\n'; 
		len++; // stop the string 

		write(1,pwd,len); // FINALLY: write

		return 0;
	}
	else {
		return 1;
	}
}

int main(){
	getpwd();
	return 0;
}
