#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"



int
main(int argc, char *argv[])
{
    if(argc == 2){
        int time=atoi(argv[1]);
        if(time>=0){
            sleep(time);
        }
        else{
            printf("error sleep:wrong time type\n");
        }
    }
    else{
        printf("error sleep:wrong arg number\n");
        
    }
    exit(0);

}