#include<stdio.h>

#define WR_DATA  _IOW('a','a',int32_t*)
#define RD_DATA  _IOR('a','b',int32_t*)

int main()
{
      int fd;
      unsigned int32_t val ,num;
      printf("\n ioctl based character device operation from user space");
      fd =open("/dev/driver2_device",O_RDWR);
      if(fd=0)
      {
        printf("cannot open the file...\n");
        return 0;
      }
      printf("enter the data to send");
      scanf("%d",&num);
      printf("wrting value to driver ..\n");
      ioctl(fd,WR_DATA,(int32_t*)&num);
      printf("reading value from driver ...\n");
      ioctl(fd,RD_DATA,(int32_t*)&val);
      printf("closing driver ...\n");
      close (fd);


}

}