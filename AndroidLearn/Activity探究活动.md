# 活动

## 活动是什么
 - 活动是包含用户界面的组件 ,用于和用户交互,一个应用程序可以有0个或多个活动

## 创建活动
  1. 空白layout和 no activity  创建后 onCreat()已经自动重写
  2. 创建和加载布局 新建layout目录,新建layout文件 layout文件下有 可视化布局(Design)和Text
  3. 在布局layout文件中添加button 控件, 定义 button的ID ,尺寸 , text .甚至可以定义background 等
  4. **要在java文件中添加代码使布局加载**  
  `setOnCreatView(R.layout.xxx_layout)`

## 在AndroidManifest文件中注册  
  部分代码已经自动生成    
  - 要在`<acticity></activity>`中添加`<intent-filter>`
  - android:lable 可以改变标题栏,主活动的话同时改变应用程序显示名称

    ```java
      <activity android:name=".FirstActivity"
          android:label="This is FirstActivity">
          <intent-filter>
              <action android:name="android.intent.action.MAIN" />
              <category android:name="android.intent.category.LAUNCHER" />
          </intent-filter>
      </activity>

## 在活动中添加Toast  
  1. 在java文件中找到在布局中定于的button  `findViewById()`
  2. 添加监听器  `onClick()` `setOnClickListener()`
  3. Toast 方法 makeText 显示  ,传入三个参数 `(ConText对象,显示文字,显示时间).show();`

## 在活动重添加Menu  ---- 右上角三点
  1. 在res目录新建menu目录,新建main菜单文件  
      ```xml
      <item
          android:id="@+id/add_item"
          android:title="Add"/>
      <item
          android:id="@+id/remove_item"
          android:title="Remove"/>
      ```

 2. 在FirstActicity中重写onCreatOptionsMenu()  
      ```java
      public  boolean onCreatOptionsMenu(){
          getMenuInflater().inflate(R.menu.main , menu);
          return true;
      }
      ```
 3. 定义Menu响应事件,在FirstActivity重写onOptionsItemSelected()
    ```java
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()){
            case R.id.add_item:
                Toast.makeText(this,"You click add",Toast.LENGTH_SHORT).show();
                break;
            case R.id.remove_item:
                Toast.makeText(FirstActivity.this,"You click remove",Toast.LENGTH_SHORT).show();
                break;
                default:
        }
        return true;
    }
    ```

## 销毁一个活动 Activity
  1. `finash();`

## 使用Intent在活动件穿梭
  -  显式Intent  
      1. 在FirstActivity重写 onCreat  
      2. 添加Button鼠标监听(看前面)  
      3. Inentt(上下文,目标活动)  
      4. 使用startActivity()方法来执行intent
      ```java
      Intent intent = new Intent(FirstActivity.this,SecendActivity,class);
      startActivity(intent);
      ```

 - 隐式Intent
   1.  在AndroidManifest.xml中添加` <activity> <intent inflater>`
        ```xml
        <activity android:name=".SecendActivity">
            <intent-filter>
                <action android:name="com.example.mason.activity.ACTION_START"/>
                <category android:name="android.intent.category.DEFAULT"/>
                <category android:name="com.example.mason.activity.MY_CATEGORY"/>
            </intent-filter>
        </activity>

   2. 修改FirstActivity0中按钮点击事件
      ```java
      Intent intent = new Intent("com.example.mason.activity.ACTION_START");
      ntent.addCategory("com.example.mason.activity.MY_CATEGORY");
      startActivity(intent);
      ```

      > 只能指定一个action,但是可以指定多个category,要相互匹配,在FirstActivity和AndroidManifest都要有

    3. 更多隐式Intent用法
       1. 指定Intent的action是Intent.ACTION_VIEW ,常量值是android.intent.action.VIEW
       2. 通过setData  和 Uri.parse() 将一个网址字符串解析成一个Uri对象,主要用于指定当前Intent正在操作的数据
       3. 在<intent-filter> 中可以配置 <data>标签 指定当前活动 响应什么类型数据  
         - 打开网址
        ```java
        Intent intent = new Intent(Intent.ACTION_VIEW);
        intent.setData(Uri.parse(http://github.com));
        startActivity(intent);
        ```  
        -  tel:
        ```java
        Intent intent = new Intent(Intent.ACTION_DIAL);
        intent.setData(Uri.parse("tel:10086"));
        startActivity(intent);
        ```
### 向下一个活动传递数据
  1. FirstActivity putExtra()方法
  2. SecendActivity getIntent 获取Intent
  3. getStringExtra() 传入获取相应键值  getIntExtra() getBooleanExtra()
  4. 在logcat查看打印信息
      ```java
      FirstActivity:
      button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String data = "Hello SecondActivity";
                Intent intent = new Intent(FirstActivity.this,SecendActivity.class);
                intent.putExtra("extra_data",data);
                startActivity(intent);
            }
        });

      SecondActivity:
      protected void onCreate(Bundle savedInstanceState) {
          super.onCreate(savedInstanceState);
          setContentView(R.layout.secend_activity);
          Intent intent = getIntent();
          String data = intent.getStringExtra("extra_data");
          Log.d("SecondActivity", data);
     }  
### 返回数据给上一个活动

>这是我学习Android的笔记,参考书<<第一行代码-第二版>>,感谢郭霖大神  
如有不足之处,可以一起讨论    
附上郭霖的blog http://blog.csdn.net/guolin_blog
