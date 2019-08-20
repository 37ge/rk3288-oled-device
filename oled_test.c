#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


typedef enum
{
	x_accl = 1,
	y_accl, 
	z_accl,
}MPU_ACCL;

void init_para(int *accl_x, int *accl_y, int *accl_z)
{
	*accl_x = x_accl;
	*accl_y = y_accl;
	*accl_z = z_accl;

	return;
}

struct oled_data
{
    unsigned char x;
    unsigned char y;
	unsigned char data_len;
    char data[256];
};
struct oled_data oledData;
int main(void)
{
	int fd;
	char count = 0;

	fd = open("/dev/oled-device", O_RDWR);
	if (fd < 0)
	{
		printf("open failed \n");
		return -1;
	}
		//gpio_flag = read(fd, &gpio_flag, sizeof(gpio_flag));
#if 0
	while(gpio_flag)
	{
		gpio_flag = read(fd, &flag, 1);
		/*if read voltage is low, drive the motor*/
		if (!gpio_flag)
		{
			write(fd, (void *)&c, 1);
		}
	}

#endif

oledData.x = 20;
oledData.y = 0;
oledData.data_len = strlen("hello world");
memcpy(oledData.data , "hello world",oledData.data_len);
write(fd, &oledData, oledData.data_len+3);
while(1)
{
    sleep(1);
	oledData.x = 60;
    oledData.y = 3;
    oledData.data_len = 2;
    oledData.data[0] = 0x30+count;
	oledData.data[1] = '\0';
    write(fd, &oledData, oledData.data_len+3);
	count++;
	count %= 10;
}
close(fd);
return 0;
}
