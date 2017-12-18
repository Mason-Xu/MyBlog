# SharedPreferences存储
- 不同于文件存储,SharedPreferences存储是使用键值对的方式来存储数据的
- 支持不同数据类型存储
## 将数据存储到SharedPreferences中
- 获取SharedPreferences对象
  1. **Context类中的getSharedPreferences()方法**
    接收两个参数,第一个参数指定SharedPreferences文件的名称,/data/data/\<package name\>/shared_preds/ 第二个参数是指定操作模式,只有MODE_PRIVATE可选,表示只有当前的应用程序可以对这个SharedPreferences文件进行读写
  2. **Activity类的getPreferences()方法**  
    这个方法和Context类中的getSharedPreferences()方法很相似,不过只接收操作模式参数,因为使用这个方法会自动将当前活动的类名当文件名
  3. **PreferencesManager类中的getDegfaultSharedPreferences()方法**  
    这是一个静态方法,接收一个Context参数,并自动使用当期啊应用程序的包名作为前缀来命名SharedPreferences文件名,得到SharedPreferences对象后,开始向SharedPreferences文件中存储数据分为三步实现:
     1. 调用SharedPreferences对象的edit()方法来获取一个SharedPreferences.Editor对象
     2. 向SharedPreferences.Editor对象中添加数据,比如添加一个布尔类型数据及使用putBoolean()方法,添加字符串则使用putString()方法
     3. 调用apply()方法将添加的数据提交,从而完成数据存储操作


 - 实现:
   1. 注册一个点击事假
   2. 点击事件通过getSharedPreferences()方法指定SharedPreferences的文件名叫data,并得到SharedPreferences.Editor对象
   3. 添加三条数据
   4. apply()方法提交
```java
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button savaData = (Button) findViewById(R.id.save_data);
        savaData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                SharedPreferences.Editor editor = getSharedPreferences("data", MODE_PRIVATE).edit();
                editor.putString("name", "Tom");
                editor.putInt("age", 28);
                editor.putBoolean("married", false);
                editor.apply();
            }
        });
    }
}
```

![](http://oz2u8kxpt.bkt.clouddn.com/17-12-2/16975939.jpg)
## 将数据存储从SharedPreferences读取
 - get方法,对应put方法
 - get方法都接收两个参数 键和默认值--表示当传入的键找不到对应的值时会以什么样的默认值返回

- 实现:
  1. 首先通过getSharedPreferences()方法得到SharedPreferences对象
  2. 分别调用getString,getInt,getBoolean方法得到数据,设置默认值
  3. 通过Log打印

```java
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ...
        Button restoreData = (Button)findViewById(R.id.restore_data);
        restoreData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                SharedPreferences pref = getSharedPreferences("data",MODE_PRIVATE);
                String name = pref.getString("name","");
                int age = pref.getInt("age",0);
                boolean married = pref.getBoolean("married",false);
                Log.d("MainActivity", "name is :" + name);
                Log.d("MainActivity", "age is :" + age);
                Log.d("MainActivity", "married is :" + married);
            }
        });
    }
}
```

## 实现记住密码功能
- CheckBox 是一个复选框控件，用户可以点击取消或选中
- 实现：
  1. onCreate()方法中获取SharedPreferences对象,调用getBoolean()方法获取remember_password这个键对应的值,默认false
  2. 登录成功后,调用CheckBox的isChecked()方法来检查复选框是否被选中.如果选中了 ,将remember_password设置为true,没有选中,则调用clear()方法,将SharedPreferences文件中的数据全部清除
  3. 选中记住密码复选框后,并且成功登录一次后,再次启动这个活动,就会从SharedPreferences文件中读取密码和账户数据---完成记住密码功能

> 将密码以明文的形式存储在SharedPreferences文件中是非常不安全的,在正式项目中要结合一定的加密算法来防止盗窃

```java
public class LoginActivity extends AppCompatActivity {

    private SharedPreferences pref;
    private SharedPreferences.Editor editor;
    private EditText accountEdit;
    private EditText passwordEdit;
    private Button login;
    private CheckBox rememberPass;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.login_layout);
        pref = PreferenceManager.getDefaultSharedPreferences(this);
        accountEdit = (EditText) findViewById(R.id.account);
        passwordEdit = (EditText) findViewById(R.id.password);
        rememberPass = (CheckBox) findViewById(R.id.remember_pass);
        login = (Button) findViewById(R.id.login);
        boolean isRemember = pref.getBoolean("remember_password", false);
        if (isRemember) {
            //将账号和密码都存储到文本框
            String account = pref.getString("account", "");
            String password = pref.getString("password", "");
            accountEdit.setText(account);
            passwordEdit.setText(password);
            rememberPass.setChecked(true);
        }
        login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String account = accountEdit.getText().toString();
                String password = passwordEdit.getText().toString();
                //如果账号密码是 admin,123456,就认为登录成功
                if (account.equals("admin") && password.equals("123456")) {
                    editor = pref.edit();
                    if (rememberPass.isChecked()) {// 检查复选框是否被选中
                        editor.putBoolean("remember_password", true);
                        editor.putString("account", account);
                        editor.putString("password", password);
                    } else {
                        editor.clear();
                    }
                    editor.apply();
                    Intent intent = new Intent(LoginActivity.this, MainActivity.class);
                    startActivity(intent);
                    finish();
                } else {
                    Toast.makeText(LoginActivity.this, "密码错误", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}

```



>这是我学习Android的笔记,参考书<<第一行代码-第二版>>,感谢郭霖大神  
如有不足之处,可以一起讨论    
附上郭霖的blog http://blog.csdn.net/guolin_blog
