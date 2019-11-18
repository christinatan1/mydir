#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
  struct stat *x = malloc(sizeof(struct stat));
  struct dirent *d;
  int bytes;
  printf("****** Statistics for directory: . ******\n");
  DIR *dir = opendir(".");
  if (dir != NULL){
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
