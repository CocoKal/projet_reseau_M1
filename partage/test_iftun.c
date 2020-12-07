#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iftun.h"

int main (int argc, char** argv){
  if(argc < 2){
    printf("Usage: ./test_iftun name_tun\n");
    return 1;
  }
  int t;

  int fd_tun = tun_alloc(argv[1]);
  if(fd_tun < 0){
    printf("error tun_alloc \n");
    return 1;

  }
  char cmd[128];


  strcpy(cmd, "./configure-tun.sh");
  strcat(cmd, " ");
  strcat(cmd, argv[1]);


  printf("Configuration ...\n");
  system("chmod +x configure-tun.sh");
  system(cmd);


  printf("Configuration complete\n");
  write_in_fd(fd_tun, 1);
  printf("Press a key for quit : ");
  scanf("%d", &t);

  return 0;
}