### <center> 进程管理

-   [进程的用户与组概念](./User%20Group/)
-   [exec函数一族](#exec函数) `execl` `execp`
-   [写时复制](#写时复制copy-on-write)


#### exec函数
`int execl(const char *pathname, const char *arg, ...);`

调用会将pathname指向的映像载入内存,替换当前的用户进程



#### 写时复制(copy-on-write)
1.  当进程创建子进程时,不会第一时间将父进程的所有属性复制一份,而是父子进程先共享,当父进程或子进程修改属性时,才发生复制拷贝
2.  