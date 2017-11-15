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
