# 解决Android Studio太卡的方法

##  修改Java 虚拟机启动时的参数，用于限制最大堆内存

- 在Android Studio Help->Edit Custom VM Option   打开

![](http://oz2u8kxpt.bkt.clouddn.com/17-11-8/57241102.jpg)

- 在这里加上  -Xmx2g 或者 -Xmx4g

![](http://oz2u8kxpt.bkt.clouddn.com/17-11-8/6139501.jpg)

- 如何查看生效呢？

Settings设置
![](http://oz2u8kxpt.bkt.clouddn.com/17-11-8/91451257.jpg)

- 重新启动Android Studio 在右下角看是否显示内存使用情况

![](http://oz2u8kxpt.bkt.clouddn.com/17-11-8/51258398.jpg)


还有不懂得可以查看官方文档：🔎
[developer.android](https://developer.android.com/studio/intro/studio-config.html)
