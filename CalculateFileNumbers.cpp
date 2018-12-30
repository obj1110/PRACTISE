#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int filesum = 0;

void sys_err(const char *ptr,int num)
{
    perror(ptr);
    exit(num);
}

void regFile(const char *path)
{
    DIR *dir = opendir(path);
    if(NULL == dir)
    {
        sys_err("opendir",-2);
    }

    while(1)
    {
        struct dirent *dire = NULL;
        dire = readdir(dir);
        if(NULL == dire)
        {
            break;
        }

        /* 去掉.和.. */
        if((strcmp(dire->d_name,".") == 0) || (strcmp(dire->d_name,"..") == 0))
        {
            continue;
        }

        /*普通文件，累加计算*/
        if(dire->d_type == DT_REG)
        {
            ++filesum;
            continue;
        }
        /*目录文件，继续向下遍历*/
        if(dire->d_type == DT_DIR)
        {
            char buf[1024];
            bzero(buf,sizeof(buf));
            sprintf(buf,"%s/%s",path,dire->d_name);
            regFile(buf);
        }
    }

    closedir(dir);
}


int main(int argc,char *argv[])
  {
    /* ./a.out  dstfile */
    if(argc != 2)
    {
        printf("Usage: ./a.out dstfil");
        exit(-1);
    }

    const char *path = argv[1];
    struct stat st;
    int flag = stat(path,&st);
    if(flag < 0)
    {
        sys_err("stat",-1);
    }

    if(S_ISREG(st.st_mode))
    {
        ++filesum;
        return 0;
    } else if(S_ISDIR(st.st_mode))
    {
        regFile(path);
    }

    printf("filesum = %d\n",filesum);

    return 0;
  }
//--------------------- 
//作者：lixiaogang_theanswer 
//来源：CSDN 
//原文：https://blog.csdn.net/lixiaogang_theanswer/article/details/73136376 
//版权声明：本文为博主原创文章，转载请附上博文链接！
