#include"comm.h"

int main()
{
    key_t k = ftok (PATHNAME, PROJ_ID);
    if(k < 0){
        perror( "ftok" );
        return 1;
    }
    int shmid = shmget(k, SIZE, IPC_CREAT | IPC_EXCL | 0644);
    if( shmid < 0){
          perror ( "shmget" );
          return 2;
    }
    
    //shmat获取共享内存的起始地址，返回的是映射的虚拟地址
    char *mem =(char*) shmat(shmid,NULL,0);

    //通信
    while(1)
    {
      printf("client msg# %s\n", mem);
      sleep(1);
    }

    //取消关联，虚拟地址和共享内存的关系
    shmdt(mem);
    

    //删除共享内存
    //shmctl(shmid, IPC_RMID,NULL);
     

    return 0;
}
