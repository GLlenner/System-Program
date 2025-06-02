# 线程相关

## 线程的终止
1.  线程从启动例程返回,
2.  线程被同一进程中的其他进程取消
3.  线程调用pthread_exit()退出

## 栈的清理
`pthread_cleanip_push()` ` pthread_cleanup_pop()`
类似于钩子函数，一定要成对出现，不然宏展开后会报错

## 线程的取消
`pthread_cancel` 
    cancel点: 防止在不应该cancel时 cancel
      