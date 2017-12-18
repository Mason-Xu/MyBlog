# 添加menu
- res->new directory->new menu resource file
- item 的 app:showAsAction 指定按钮的显示位置
  1. always表示永远显示在Toolbar中
  2. ifRoom表示屏幕空间足够的情况下,显示在Toolbar中,不够就显示在菜单中
  3. never表示永远显示在菜单中
  > Toolbar中的action只显示图标,菜单中只显示文字
```xml
<menu xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto">
    <item
        android:id="@+id/backup"
        android:icon="@drawable/ic_backup"
        android:title="Backup"
        app:showAsAction="always"/>
    <item
        android:id="@+id/delete"
        android:icon="@drawable/ic_delete"
        android:title="Delete"
        app:showAsAction="ifRoom"/>
    <item
        android:id="@+id/settings"
        android:icon="@drawable/ic_settings"
        android:title="Settings"
        app:showAsAction="never"/>
</menu>
```

```java
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.toolbar, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.backup:
                Toast.makeText(this, "you clicked backup", Toast.LENGTH_SHORT).show();
                break;
            case R.id.delete:
                Toast.makeText(this, "you clicked delete", Toast.LENGTH_SHORT).show();
                break;
            case R.id.settings:
                Toast.makeText(this, "you clicked settings", Toast.LENGTH_SHORT).show();
                break;

            default:
        }
        return true;
    }
```



>这是我学习Android的笔记,参考书<<第一行代码-第二版>>,感谢郭霖大神  
如有不足之处,可以一起讨论    
附上郭霖的blog http://blog.csdn.net/guolin_blog
