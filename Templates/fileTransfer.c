#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
	char *a = "A.txt";
	char *b = "B.txt";
	
	//int f1 = creat(a, 0644);
	//int f2 = creat(b, 0644);
	
	int fd1 = open(a, O_RDONLY);
	int fd2 = open(b, O_WRONLY);
	
	char buff;
	
	while(read(fd1, &buff, 1)){
		write(fd2, &buff, 1);
	}
	
	close(fd1);
	close(fd2);
	return 0;
}
