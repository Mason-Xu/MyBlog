# DrawerLayout -- 滑动菜单

- DrawerLayout 是一个布局  
- 有两个直接子控件 1. 主屏幕显示的内容 2. 滑动菜单显示的内容
- 第二子控件的layout_gravity = "start" 指定,表示根据系统语言判断滑动菜单的位置,左边还是右边

```xml
<android.support.v4.widget.DrawerLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    android:id="@+id/drawer_layout"
    android:layout_width="match_parent"
    android:layout_height="match_parent">

    <FrameLayout
        android:layout_width="match_parent"
        android:layout_height="match_parent">

        <android.support.v7.widget.Toolbar
            android:id="@+id/toolbar"
            android:layout_width="match_parent"
            android:layout_height="?attr/actionBarSize"
            android:background="?attr/colorPrimary"
            android:theme="@style/ThemeOverlay.AppCompat.Dark.ActionBar"
            app:popupTheme="@style/ThemeOverlay.AppCompat.Light" />

    </FrameLayout>

    <TextView
        android:layout_width="match_parent"
        android:layout_height="match_parent"
        android:layout_gravity="start"  // 固定start
        android:text="This is menu"
        android:textSize="30sp"
        android:background="#fff"/>


</android.support.v4.widget.DrawerLayout>
```



>这是我学习Android的笔记,参考书<<第一行代码-第二版>>,感谢郭霖大神  
如有不足之处,可以一起讨论    
附上郭霖的blog http://blog.csdn.net/guolin_blog
