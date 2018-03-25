#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>


int
main(int c, char **v)
{
	
	int fd;
	int i = 0;
	int wr_num = 0, rd_num = 0, sk_num = 0;
	char *path = "test.txt";
	char wr_buf[64] = "HelloWorld!!! Here is a progreammer!";
	char rd_buf[64] = {0x00};

	//memset(wr_buf, 0x00, sizeof wr_buf);
	memset(rd_buf, 0x00, sizeof rd_buf);
#if 0
	for (i = 0; i < sizeof wr_buf; i ++) {
		wr_buf[i] = i + 40;	
	}
#endif
	fd = open(path, O_RDWR);

	wr_num = write(fd, wr_buf, 16);
	printf("wr_num is %d\n", wr_num);

	sk_num = lseek(fd, 0, SEEK_SET );
	printf("sk_num : %d\n", sk_num);

	rd_num = read(fd, rd_buf, 10);
	//rd_buf[10] = '\0';
	printf("%s\n", rd_buf);
	for (i = 0; i < 20; i ++)
		printf("%d: %c\n", i, rd_buf[i]);
	
	printf("rd_num is %d\n", rd_num);
	

	close(fd);
	return 0;

}



