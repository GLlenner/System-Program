### Input Output 输入输出

### **索引**

- IO多路复用函数
  - [IO多路复用函数select](#IO多路复用函数select) 
  - [IO多路复用函数poll](#IO多路复用函数select)
- [分散聚集函数](#分散聚集函数scattergather-io)
- [内存映射](#内存映像函数-mmap)
[最大缓存时效](#最大缓存时效)

[同步IO与直接IO的区别?](#同步io与直接io的区别?)



#### 最大缓存时效
1.  系统调用 write 后,不会第一时间写入磁盘,而是将 write 的buf参数缓冲区的数据写入**内核缓冲区**,除手动刷新外,为保证按时写入,内核按最大缓冲时效,定期刷新内核缓冲区到磁盘
2.  如果长时间留在磁盘,如果系统奔溃,应用可能认为已经写入磁盘导致出错
3.  ` cat /proc/sys/vm/dirty_expire_centisecs `可以查看当前的最大缓冲时效
   

#### 同步IO与直接IO的区别
1.  区别
    1.  同步IO: 写或读操作时，调用线程会被阻塞，直到 I/O 完成（也就是说，read() / write() 不返回）。
    2.  直接IO: 直接 I/O 是一种绕过内核页缓存的机制。数据从用户缓冲区直接写入设备或从设备直接读入用户空间。
   
#### IO多路复用函数select
1.  当文件阻塞时,通常我只能监视一个文件,而使用select可以监视多个文件描述符
2.  如果多个连接到来，你需要开多个线程或进程（成本高、效率低）,而select效率高
3.  [select 的使用](./Multiplexing/select.cpp)


#### IO多路复用函数select
1.  同select
2.  同select
3.  [poll 的使用](./Multiplexing/poll.cpp)
  

#### 分散聚集函数(Scatter/Gather I/O)
1.  用户一次系统调用,能够对多个缓冲区进行读写
2.  减少系统调用陷入内核的调用时间
3.  `readv` `writev` [使用](./Scatter%20Gather%20IO/)
  

#### 内存映像函数 `mmap`
1.  