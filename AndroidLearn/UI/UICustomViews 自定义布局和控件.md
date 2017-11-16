# 自定义控件  
## 引入布局
  - 创建title.xml
    - `android:background="@drawable/back_bg"`  背景图片
    - `android:layout_margin="5dp" ` 控件上下左右偏移距离 也可以marginTop单独指定
    - `<include layout="@layout/title"/>` 在activity_main.xml 中 就可以显示title.xml 标题栏
    ```xml
    <android.support.constraint.ConstraintLayout       xmlns:android="http://schemas.android.com/apk/res/android"
        xmlns:app="http://schemas.android.com/apk/res-auto"
        xmlns:tools="http://schemas.android.com/tools"
        android:layout_width="match_parent"
        android:layout_height="match_parent"
        tools:context="com.example.mason.uicustomviews.MainActivity">

        <include layout="@layout/title"/>

    </android.support.constraint.ConstraintLayout>
    ```

    - 设置系统自带标题栏隐藏
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

## 创建自定义控件  
 - 相同功能的控件  
 - 新建TitleLayout 继承自LinearLayout
 - 重写LinearLayout中带有两个参数的构造函数
 - 布局引入TitleLayout 调用这个函数,
 - 通过LinearLayout的from()方法构建一个LayoutInflater对象
 - 调用inflate()方法加载布局文件
 - inflate()接收两个参数 要加载布局的id和加载好的布局再添加一个父布局
   - 新建TitleLayout.java
   ```java
   public class TitleLayout extends LinearLayout{
    public TitleLayout(Context context, AttributeSet attrs){
        super(context,attrs);
        LayoutInflater.from(context).inflate(R.layout.title,this);
     }
    }
   ```    
   - xml 文件
   ```xml
     <com.example.mason.uicustomviews.TitleLayout
     android:layout_width="match_parent"
     android:layout_height="wrap_content"/>
   ```
   - TitleLayout.java设置点击事件  getContext()
   ```java
   public class TitleLayout extends LinearLayout {
    public TitleLayout(Context context, AttributeSet attrs) {
        super(context, attrs);
        LayoutInflater.from(context).inflate(R.layout.title, this);
        Button titleEdit = (Button) findViewById(R.id.title_edit);
        titleEdit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(getContext(), "you click edit", Toast.LENGTH_SHORT).show();
            }
        });
        Button titleBack = (Button) findViewById(R.id.title_back);
        titleBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ((Activity) getContext()).finish();
            }
        });
     }
   }
   ```
