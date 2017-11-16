# UIWidget

## 如何编写程序界面  
  - 可视化界面(不适合适配)
  - xml编写(推荐)

## 常用控件使用方法  
### TextView
  - 文本信息  
  - id width height text
  - match_parent  和父布局一样大小
  - wrap_parent 大小刚好包含里面内容
  - text 文本内容 textColor(#00ff0000) 前面两位表示透明度 textSize(xSp)
  - gravity 对齐方式 center top bottom left right

### Button
  - id text width height
  - 设置textAllCaps(false) 英文字母不自动大写
  - 在Java文件中注册监听器  可是匿名内部类或者实现接口
    ```java
    Button button = (Button) findViewById(R.id.button);
    button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ...
            }
        });

### EditText
  - 交互的重要控件
  - 输入和编辑内容
  - hint 提示内容 textColorHint
  - 设置最大行数 maxLines
  - 获取EditText输入内容
    1. findViewById 找到EditText的实例
    2. `getText().toString()`
    ```java
    public class MainActivity extends AppCompatActivity {

    private EditText editText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button = (Button) findViewById(R.id.button);
        editText = (EditText) findViewById(R.id.edit_text);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                switch (v.getId()) {
                    case R.id.button:
                        String inputText = editText.getText().toString();
                        Toast.makeText(MainActivity.this, inputText, Toast.LENGTH_SHORT).show();
                        break;
                    default:
                        break;
                }
            }
         });
      }
    }
    ```
### ImageVIew
 - 将图片资源放在drawable目录上,不知道分辨率放在drawable-xhdpi
 - android:src = "@drawable/img_1" 给ImageVIew指定一张图片
 - 通过代码点击Button来动态更改ImageVIew的图片
   1. findViewById 找到ImageVIew实例
   2. imageView.setImageResource() 来更改
   ```java
   public class MainActivity extends AppCompatActivity {

    private EditText editText;
    private ImageView imageView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button = (Button) findViewById(R.id.button);
        editText = (EditText) findViewById(R.id.edit_text);
        imageView = (ImageView) findViewById(R.id.image_view);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                switch (v.getId()) {
                    case R.id.button:
                        imageView.setImageResource(R.drawable.img_2);
                        break;
                    default:
                        break;
                }
            }
        });
    }
   }
   ```
### ProgressBar 进度条
  - setVisibility()
  - 设置View.VISIBLE,View.INVISIIBLE,View.GONE
  - button 转换
    ```java
    public class MainActivity extends AppCompatActivity {

    ...
    private ProgressBar progressBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button = (Button) findViewById(R.id.button);
        progressBar = (ProgressBar) findViewById(R.id.progress_bar);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                switch (v.getId()) {
                    case R.id.button:
                        if (progressBar.getVisibility() == View.GONE) {
                            progressBar.setVisibility(View.VISIBLE);
                        } else {
                            progressBar.setVisibility(View.GONE);
                        }
                        break;
                    default:
                        break;
                }
            }
        });
      }
    }
    ```
   - 条状progressbar和动态进度
     - xml
     ```xml
     <ProgressBar
      android:id="@+id/progress_bar"
      android:layout_width="match_parent"
      android:layout_height="wrap_content"
      style="?android:attr/progressBarStyleHorizontal"
      android:max="100"/>
     ```
     - MainActivity.java
     ```java
     public class MainActivity extends AppCompatActivity {
     ...
     private ProgressBar progressBar;

     @Override
     protected void onCreate(Bundle savedInstanceState) {
         super.onCreate(savedInstanceState);
         setContentView(R.layout.activity_main);
         Button button = (Button) findViewById(R.id.button);
         progressBar = (ProgressBar) findViewById(R.id.progress_bar);
         button.setOnClickListener(new View.OnClickListener() {
             @Override
             public void onClick(View v) {
                 switch (v.getId()) {
                     case R.id.button:
                         int progress = progressBar.getProgress();
                         progress = progress+10;
                         progressBar.setProgress(progress);
                         break;
                     default:
                         break;
                 }
             }
         });
       }
     }
     ```
### AlertDIalog 对话框
  - 置顶
  - 提示重要信息
  - Button控制
    1. AlertDialog。Builder 创建一个AlertDialog实例
    2. 设置标题
    3. 设置message内容
    4. 是否可以back返回
    5. 调用setPoitiveButton() 设置对话框确定的那个按钮的点击事件
    6. 调用setNegativeButton()方法 设置取消按钮的点击事件
    7. 调用show()方法吧对话框显示出来
      ```java
      @Override
            public void onClick(View v) {
                switch (v.getId()) {
                    case R.id.button:
                        AlertDialog.Builder dialog = new AlertDialog.Builder(MainActivity.this);
                        dialog.setTitle("This is Dialog");
                        dialog.setMessage("Something important");
                        dialog.setCancelable(false);
                        dialog.setPositiveButton("ok", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                              ...
                            }
                        });
                        dialog.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                              ...
                            }
                        });
                        dialog.show();
                        break;
                    default:
                        break;
                }
            }
      ```
### ProgressDialog 对话框进度条
  - 如果在setCancelable 为false,则表示无法使用back返回,则在代码中一定要控制好.数据加载完成后,调用ProgressDialog的dismiss() 方法来关闭对话框,否则一直存在
    ```java
    button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                switch (v.getId()) {
                    case R.id.button:
                        ProgressDialog progressDialog =new ProgressDialog(MainActivity.this);
                        progressDialog.setTitle("This is ProgressDialog");
                        progressDialog.setMessage("Loading...");
                        progressDialog.show();
                        break;
                    default:
                        break;
                }
            }
    });
    ```
