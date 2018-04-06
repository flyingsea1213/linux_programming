#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>



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


	close(fd);
}

void
chpt4()
{





}




int
main(int c, char **v)
{
	chpt3();


	
	exit(0);
}
