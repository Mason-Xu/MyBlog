# Android开发 消除系统自带标题栏

1. 调用getSupportActionBar() 方法获得 ActionBar 实例
2. 调用ActionBar的hide()方法 隐藏标题栏

```java
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ActionBar actionBar = getSupportActionBar();
        if(actionBar!=null){
            actionBar.hide();
        }

    }
}
>这是我学习Android的笔记,参考书<<第一行代码-第二版>>,感谢郭霖大神  
如有不足之处,可以一起讨论    
附上郭霖的blog http://blog.csdn.net/guolin_blog
