# 如何实现当光标不在目标EditText控件时,editText的下划线的变换?

1. 首先要用到style.xml文件,新建自定义EditText控件style  
  res->values->style.xml 添加
    ```xml
    <style name="MyEditText" parent="Theme.AppCompat.Light">
        <item name="colorControlNormal">@android:color/white</item>
        <item name="colorControlActivated">@android:color/holo_blue_dark</item>
    </style>
    ```
    不点击时设置white,点击时设置blue


2. 然后在布局中的EditText控件中添加theme属性  
    `android:theme="@style/MyEditText"`

    ```xml
    <?xml version="1.0" encoding="utf-8"?>
    <LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:background="@color/orange">


    <EditText
        android:id="@+id/login_edittext_phonenumber"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_marginLeft="10dp"
        android:layout_marginRight="10dp"
        android:paddingTop="16dp"
        android:paddingBottom="8dp"
        android:gravity="center_horizontal"
        android:hint="手机号"
        android:inputType="number"
        android:textColorHint="#fff"
        android:theme="@style/MyEditText" />
    <EditText
        android:id="@+id/login_edittext_password"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:layout_marginLeft="10dp"
        android:layout_marginRight="10dp"
        android:paddingTop="16dp"
        android:paddingBottom="8dp"
        android:gravity="center_horizontal"
        android:hint="密码"
        android:inputType="textPassword"
        android:textColorHint="#fff"
        android:theme="@style/MyEditText" />
      </LinearLayout>
    ```


效果 :
![](http://oz2u8kxpt.bkt.clouddn.com/17-11-25/20556267.jpg)
