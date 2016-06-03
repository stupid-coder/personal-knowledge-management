#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <errno.h>

void test()
{
  struct timeval tv;
  
  if (gettimeofday(&tv,NULL) != 0) 
    printf("[ERROR] gettimeofday error [%d]\n",strerror(errno));
  else 
    printf("[INFO]  gettimeofday success [%ld-%ld]\n",tv.tv_sec,tv.tv_usec);
  
  struct timespec ts;
  if ( clock_gettime(CLOCK_REALTIME_COARSE,&ts) != 0 ) 
    printf("[ERROR] clock_gettime error [%s]\n",strerror(errno));
  else
    printf("[INFO]  clock_gettime success [%ld-%ld]\n",ts.tv_sec,ts.tv_nsec);
}

int main(int argc, char *argv[])
{
  test();
  return 0;
}
