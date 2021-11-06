#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#define handle_error_en(en, msg) \
        do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

#define handle_error(msg) \
        do { perror(msg); exit(EXIT_FAILURE); } while (0)




static void *thread_ota(void *arg)
{
  int x = 5;

  printf("OTA Thread created\n");

  while(x)
  {
    printf("Ota thread running count: %d\n", x);

    sleep(1);
    x--;
  }

  return NULL;
}


 int main(int argc, char *argv[])
{
  int error = 0;
  pthread_t thread_id;
  pthread_attr_t attr;
  ssize_t stack_size = -1;


  /* Initialize thread creation attributes. */
  error = pthread_attr_init(&attr);
  if (error != 0)
  {
    handle_error_en(error, "pthread_attr_init\n");
  }
      
  if (stack_size > 0)
  {
      error = pthread_attr_setstacksize(&attr, stack_size);
      
      if (error != 0)
      {
        handle_error_en(error, "pthread_attr_setstacksize");
      }   
  }

  /*Create a thread*/
  error = pthread_create(&thread_id, &attr, &thread_ota, NULL);
  if (error != 0)
  {
    handle_error_en(error, "Error in creating thread: ");
  }
  
  void *res;
  error = pthread_join(thread_id, &res);
  if (error != 0)
  {
    handle_error_en(error, "pthread_join");
  }

  printf("The thread (%ld) is terminated\n", thread_id);

  return 0;
}