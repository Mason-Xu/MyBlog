# Android TextView 添加下划线的简单方法

## 在res的values资源文件夹下，给String.xml文件添加  
  `<string name="userlicense"><u>用户协议</u></string>`

##  然后在布局文件TextView控件 属性中设置android:text
  `android:text="@string/userlicense"`


### **需要注意的是,下划线不会出现在可视化界面,要在手机或者模拟器上运行才可见**

## 效果:     ![](http://oz2u8kxpt.bkt.clouddn.com/17-11-25/8124584.jpg)
