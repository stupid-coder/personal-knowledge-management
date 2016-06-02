#include <unistd.h>
#include <time.h>
#include <stdio.h>

#define CLOCK_FUNCTION(clk_id,function,para) do {                       \
    if ( function (clk_id,&para) != 0 )                                 \
      {                                                                 \
        printf("[ERROR] failure to " #function "\n");                   \
      }                                                                 \
    else                                                                \
      {                                                                 \
        printf("[INFO] success to " #function ": %ld - %ld\n",para.tv_sec,para.tv_nsec); \
      }                                                                 \
  } while(0)

#define TEST(clk_id)                                                    \
  void test##clk_id () {                                                \
    struct timespec begin;                                              \
    struct timespec end;                                                \
    printf("                   " #clk_id "                    \n");     \
    printf("==================================================\n");     \
    CLOCK_FUNCTION(clk_id,clock_getres,begin);                          \
    CLOCK_FUNCTION(clk_id,clock_gettime,begin);                         \
    CLOCK_FUNCTION(clk_id,clock_gettime,end);                           \
    sleep(5);                                                           \
    printf("[INFO] after sleep(5)\n");                                  \
    CLOCK_FUNCTION(clk_id,clock_gettime,end);                           \
    CLOCK_FUNCTION(clk_id,clock_settime,begin);                         \
    printf("==================================================\n");     \
  }

#define CALL(clk_id)                            \
  test##clk_id ()

TEST(CLOCK_REALTIME)
TEST(CLOCK_REALTIME_COARSE)
TEST(CLOCK_MONOTONIC)
TEST(CLOCK_MONOTONIC_COARSE)
TEST(CLOCK_MONOTONIC_RAW)
TEST(CLOCK_BOOTTIME)
TEST(CLOCK_PROCESS_CPUTIME_ID)
TEST(CLOCK_THREAD_CPUTIME_ID)

int
main()
{
  CALL(CLOCK_REALTIME);
  CALL(CLOCK_REALTIME_COARSE);
  CALL(CLOCK_MONOTONIC);
  CALL(CLOCK_MONOTONIC_COARSE);
  CALL(CLOCK_BOOTTIME);
  CALL(CLOCK_PROCESS_CPUTIME_ID);
  CALL(CLOCK_THREAD_CPUTIME_ID);
  return 0;
}
