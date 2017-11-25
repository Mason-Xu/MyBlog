# 如何做到沉浸式状态栏---更加准确的说是透明状态栏 Translucent Bar  

## 设置imageView图片 高宽 match_parent  但是没有隐藏ActionBar

效果:  
 <img src="http://oz2u8kxpt.bkt.clouddn.com/17-11-25/50680464.jpg" width = "216" height = "384" alt="图片名称" align=center />

## 透明状态栏和隐藏ActionBar

- 在activity文件中添加

```java
// 显示activity_main布局
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);

//透明状态栏
if (Build.VERSION.SDK_INT >= 21) {
    View decorView = getWindow().getDecorView();
    int option = View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
            | View.SYSTEM_UI_FLAG_LAYOUT_STABLE;
    decorView.setSystemUiVisibility(option);
    getWindow().setStatusBarColor(Color.TRANSPARENT);
}

// 隐藏系统自带应用栏
ActionBar actionBar = getSupportActionBar();
actionBar.hide();
```
1. 这种效果只有5.0及以上系统支持
2. 使用了SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN和SYSTEM_UI_FLAG_LAYOUT_STABLE，注意两个Flag必须要结合在一起使用，表示会让应用的主体内容占用系统状态栏的空间
3. 最后再调用Window的setStatusBarColor()方法将状态栏设置成透明色就可以了。

> 需要注意的是，这一种变成透明状态栏的方法要注意你设置的自定义的ActionBar(一般为56dp)的高度要加上状态栏的高度（一般为20dp)

效果：

 <img src="http://oz2u8kxpt.bkt.clouddn.com/17-11-25/985985.jpg" width = "216" height = "384" alt="图片名称" align=center />
