## 进程环境

1.  main函数
2.  进程的终止
    
    正常终止:
    1.  从main函数返回
    2.  调用exit()
    3.  调用_exit 或 _Exit
    4.  最后一个线程从启动历程返回
    5.  最后一个线程调用pthread_eixt

    异常终止:
    1.  调用abort
    2.  接到一个信号并终止
    3.  最后一个线程对其取消请求作出响应
3.  命令行参数: `getopt()`
4.  环境变量`environ` ` getenv()` `setenv()`
