### <center> 进程间通信机制


### 索引
- [Futexes](#futexesfast-userspace-mutexes) 快速用户空间互斥
- 







---

#### Futexes(Fast Userspace Mutexes)
1.  用户不直接进入内核态等待唤醒,先自旋一会,超时在进入内核态等待唤醒
2.  低延迟：加锁成功时根本不需要系统调用。高性能：失败时才“慢”，而失败是少数情况。可扩展性好：适用于大量线程争用时








