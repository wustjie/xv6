实验1：添加sleep功能（24.05.29）

内容：新增sleep.c文件，改动makefile

结果：

![image](https://github.com/wustjie/xv6/assets/34996802/0f5a6cc7-2ad9-4c5e-ba94-9c48272b5cbd)

问题：sleep 100理论上应该暂停0.1s，但实际上暂停了约9s左右，为什么？


实验2：进程间管道通信（24.05.30）

内容：新增pingpong.c，改动makefile

结果：

![image](https://github.com/wustjie/xv6/assets/34996802/5f9c5e80-05d4-4e9e-8732-7ff87ed7774c)

问题：父进程需要先写后读，父进程和子进程的运行顺序和内存是如何分配的？
