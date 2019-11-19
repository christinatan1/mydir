#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]){
  struct stat *x = malloc(sizeof(struct stat));
  struct dirent *d;
  int bytes;
  DIR *dir = opendir(argv[1]);
  if (dir == NULL){
    printf("errno: %d error: %s\n", errno, strerror(errno));
    return 0;
  } else {
    printf("****** Statistics for directory: %s ******\n", argv[1]);
    while ((d= readdir(dir)) != NULL){
      if (d->d_type != 4){
        printf("%s (Regular File)\n", d->d_name);
        stat(d->d_name, x);
        bytes += x->st_size;
      } else {
      printf("%s (Directory)\n", d->d_name);
      }
    }
  }
  closedir(dir);
  printf("Total Directory Size: %d Bytes \n", bytes);
}
