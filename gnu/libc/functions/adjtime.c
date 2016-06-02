#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#define DIS(tv) if ( tv != NULL ) printf(" %ld - %d ",tv->tv_sec, tv->tv_usec); \
  else printf("NULL - NULL");

void call(para1, para2)
{
  printf("[INFO] CALL_FUNCTION with : "); DIS(para1); DIS(para2); printf("\n");
  
  if ( adjtime(para1, para2) != 0 )
    {
      printf("[ERROR] failure to adjtime\n");
    }
  else
    {
      printf("[INFO] success to adjtime : " ); DIS(para1); DIS(para2); printf("\n");
    }
}

void
test ()
{
  struct timeval delta;
  struct timeval  olddelta;
  
  call(NULL, &olddelta);
  
  delta.tv_sec=200;
  delta.tv_usec=0;
  call(&delta,&olddelta);
}    


int 
main ()
{
  test();
  return 0;
}
