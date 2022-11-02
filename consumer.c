/*consumer.c*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
int main(int argc, char * argv[]) {
    int fd;
    int VALUE=1;
    sem_t * mutex;
    mutex = sem_open("mutex", O_CREAT, 0666, VALUE);
    printf("Dad comes home.\n");
    sleep(rand()%2+1);
    sem_wait(mutex);
    printf("Dad checks the fridge.\n");
    fd=open("fridge", O_CREAT|O_RDWR|O_APPEND, 0777);
    if(lseek(fd,0,SEEK_END)==0){
        printf("Oops! There is no milk\n");
    }else{
      // Get the size of the file to check if it is not empty
       int count = lseek(fd,0,SEEK_END);
    if(count>0){
        for(int i=1;i<=2;i++){
         sleep(2);
             write(fd,"milk ",i);
         printf("Dad takes milk %d \n",i);
        }
      }
     // After milk is removed from the fridge the file is set to size 0
     ftruncate(fd,0);
    }
    printf("Dad closes the fridge and leaves.\n");
    close(fd);
    sem_post(mutex);
    sem_close(mutex);
    sem_unlink("mutex");
    return 0;
}
