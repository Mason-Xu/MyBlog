# Toolbar

1. 修改style.xml文件的theme属性  `Theme.AppCompat.Light.NoActionBar`
2. 同时可以修改colorPrimary,colorPrimaryDark,colorAccent的属性颜色
3. 布局文件添加Toolbar

- 主题设置深色主题
- popupTheme设置菜单浅色主题
- 注意xmlns:app 指定新的命名空间  兼容低版本
```xml
<FrameLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    >

    <android.support.v7.widget.Toolbar
        android:id="@+id/toolbar"
        android:layout_width="match_parent"
        android:layout_height="?attr/actionBarSize"
        android:background="?attr/colorPrimary"
        android:theme="@style/ThemeOverlay.AppCompat.Dark.ActionBar"
        app:popupTheme="@style/ThemeOverlay.AppCompat.Light"
        />

</FrameLayout>
```

![](http://oz2u8kxpt.bkt.clouddn.com/17-12-10/75184454.jpg)

- label修改标题栏文字
>这是我学习Android的笔记,参考书<<第一行代码-第二版>>,感谢郭霖大神  
如有不足之处,可以一起讨论    
附上郭霖的blog http://blog.csdn.net/guolin_blog
