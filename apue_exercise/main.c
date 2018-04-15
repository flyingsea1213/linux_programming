#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>

#include "apue.h"

/*
 * chapter 3 is about file read/write/lseek/
 *
 *
 * */
void
chpt3(void)
{
	
	int fd;
	int i = 0;
	int wr_num = 0, rd_num = 0, sk_num = 0;
	char *path = "test.txt";
	char wr_buf[64] = "HelloWorld!!! Here is a programmer!";
	char rd_buf[64] = {0x00};
	int dup_r = 0, dup_r2 = 0;

	//memset(wr_buf, 0x00, sizeof wr_buf);
	memset(rd_buf, 0x00, sizeof rd_buf);
#if 0
	for (i = 0; i < sizeof wr_buf; i ++) {
		wr_buf[i] = i + 40;	
	}
#endif
	fd = open(path, O_RDWR);
	printf("fd: %d\n", fd);

	wr_num = write(fd, wr_buf, strlen(wr_buf));
	printf("wr_num is %d\n", wr_num);

	sk_num = lseek(fd, 0, SEEK_SET );
	printf("sk_num : %d\n", sk_num);

	rd_num = read(fd, rd_buf, strlen(wr_buf));
	//rd_buf[10] = '\0';
	printf("%s\n", rd_buf);
	for (i = 0; i < strlen(wr_buf); i ++)
		printf("%c", rd_buf[i]);
	
	printf("\nrd_num is %d\n", rd_num);
	
	dup_r = dup(fd); // dup_r is the new file descriptor of fd, and it can be operated as fd.
	printf("dup: %d\n", dup_r);
	dup_r2 = dup2(fd, 8); // 8 is the specified fd num of new fd dup_r2
	printf("dup2: %d\n", dup_r2);
	// write dup_r
	
	unsigned char *str = "this is the dup content";

	if((wr_num = write(dup_r, str, strlen(str))) != strlen(str))
		printf("write dup_r failed, write bytes is %d\n", wr_num);

	if((wr_num = write(dup_r2, str, strlen(str))) != strlen(str))
		printf("write dup_r failed, write bytes is %d\n", wr_num);

	printf("get fd flag: %d\n", fcntl(fd, F_GETFD));
	fcntl(fd, F_SETFD, 1); // fd flag only can be 0 or 1, 0 is default.
	printf("get fd flag after set: %d\n", fcntl(fd, F_GETFD));
	printf("get the status flag: 0x%x\n", fcntl(fd, F_GETFL));	
	printf("get the process id: %d\n", fcntl(fd, F_GETOWN));

	close(fd);
	
	fd = open(path, O_RDWR);
	int fd_new = dup(fd);
	int fd2 = open(path, O_RDONLY);
	printf("fd is %d, fd_new is %d, fd2 is %d\n", fd, fd_new, fd2);
	close(fd);
	int r;
	if ((r = close(fd_new)) < 0)
		printf("close failed\n");
	close(fd2);

}

void
chpt4()
{
	char * path = "/dev/tty";
	struct stat buf;
	int i = 0;
	char *ptr;

	i = lstat(path, &buf);
	printf("i: %d\n", i);
	printf("buf.st_mode is 0x%x\n", buf.st_mode & S_IFMT);
	if (S_ISREG(buf.st_mode))
		ptr = "regular";
	else if (S_ISDIR(buf.st_mode))
		ptr = "directory";
	else if (S_ISCHR(buf.st_mode))
		ptr = "character special";
	else if (S_ISBLK(buf.st_mode))
		ptr = "block special";
	else if (S_ISFIFO(buf.st_mode))
		ptr = "fifo";
	else if (S_ISLNK(buf.st_mode))
		ptr = "symbolic link";
	else if (S_ISSOCK(buf.st_mode))
		ptr = "socket";
	else
		ptr = "** unknown mode **";
	printf("%s\n", ptr);

	// create a dir, like mkdir
	char *c_path = "created_path\\";
	int fd;
	if ((fd = open(c_path, O_CREAT | O_WRONLY, S_IWUSR | S_IXUSR)) < 0)
		printf("create path failed");
}




int
main(int c, char **v)
{
#if 0
	int i;
	printf("c is %d\n", c);
	for (i = 0; i < c; i ++) {
		printf("%s\n", *v);	
	}
#endif	
	//chpt3();

	chpt4();
	
	exit(0);
}
