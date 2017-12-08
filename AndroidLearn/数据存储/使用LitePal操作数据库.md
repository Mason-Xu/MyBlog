# 使用LitePal操作数据库
 - 使用LitePal开源库来简化数据库操作
##配置LitePal
- 以前,要下载jar包,导入jar包
- 现在,一般开发则都会把开源项目上传提交到jcenter上,只要在app/build.gradle文件中声明引用即可:  版本在github上查询
```gradle
dependencies {
    implementation fileTree(dir: 'libs', include: ['*.jar'])
    implementation 'com.android.support:appcompat-v7:26.0.0-beta1'
    implementation 'com.android.support.constraint:constraint-layout:1.0.2'
    implementation 'org.litepal.android:core:1.6.0'

    ...
}
```
- 配置litepal.xml文件.
  - 右击app/res/main 目录->new->Directory ,创建一个assets目录,在assets下创建一个litepal.xml文件:
  - \<dbname\> 指定数据库名,\<version\>标签指定数据库版本号,\<list\>标签用于指定所有的映射模型
```xml
<?xml version="1.0" encoding = "utf-8" ?>
<litepal>
    <dbname value = "BookStore"></dbname>
    <version value = "1"></version>
    <list>

    </list>
</litepal>
```

- 配置LitePalApplication,修改AndroidManifest.xml
  - 修改android:name = "org.litepal.LitePalApplication"

```xml
<application
        android:name="org.litepal.LitePalApplication"
        android:allowBackup="true"
        android:icon="@mipmap/ic_launcher"
        android:label="@string/app_name"
        android:roundIcon="@mipmap/ic_launcher_round"
        android:supportsRtl="true"
        android:theme="@style/AppTheme">
        <activity android:name=".MainActivity">
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />

                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
    </application>
```
## 创建和升级数据库
LitePal采取的是对象关系映射(ORM)的模式
1. 创建一个Book类
2. 使用面向对象的思维来实现,声明字段和实现getter和setter构造方法
3. 每个字段对应数据库中的Book表的每一列,这就是对象关系映射最直观的体验
4. 将Book类添加到映射模型列表中,修改litepla.xml的\<list\> ---
5. 这里使用\<mapping\>标签来声明我们要配置的映射模型类,注意一定要使用完整的类名.不管有多少模型类需要映射,都使用同样的方式配置\<list\>标签下
6. 修改MainActivity,使数据库能自动创建出来,调用Connector.getDatabase()方法就是最简单的数据库操作.点击Creat 按钮,查看数据库的创建情况.
```java
public class Book {
    private int id;
    private String author;
    private double price;
    private int pages;
    private String name;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    ...
}
```

```xml
<?xml version="1.0" encoding = "utf-8" ?>
<litepal>
    <dbname value = "BookStore"></dbname>
    <version value = "1"></version>
    <list>
        <mapping class = "com.example.mason.litepaltest.Book"></mapping>
    </list>
</litepal>
```


```java
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button createDatabase = (Button) findViewById(R.id.create_database);
        createDatabase.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                LitePal.getDatabase();
            }
        });
    }
}
```

### 更新数据库

 - 添加属性,在类里面添加变量
 - 添加新的表 --- 新建类
 - version  =2
 - 在\<list\>中添加`<mapping class = "com.example.mason.litepaltest.<new databasemap name>"></mapping>`

```java
public class Book {
    private int id;
    private String author;
    private double price;
    private int pages;
    private String name;
    private String press;

    public String getPress() {
        return press;
    }

    public void setPress(String press) {
        this.press = press;
    }

    ...
}
```

```java
public class Category {
    private String categoryName;
    private int categoryCode;
    private int id;

    public String getCategoryName() {
        return categoryName;
    }

    public void setCategoryName(String categoryName) {
        this.categoryName = categoryName;
    }

    ...
}
```


```xml
<?xml version="1.0" encoding = "utf-8" ?>
<litepal>
    <dbname value = "BookStore"></dbname>
    <version value = "2"></version>
    <list>
        <mapping class = "com.example.mason.litepaltest.Book"></mapping>
        <mapping class="com.example.mason.litepaltest.Category"></mapping>
    </list>
</litepal>
```


##使用LitePal添加数据

`public class Book extends DataSupport{...}`

```java
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button createDatabase = (Button) findViewById(R.id.create_database);
        Button addData = (Button) findViewById(R.id.add_data);
        ...
        addData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Book book = new Book();
                book.setName("The Da Vinci Code");
                book.setAuthor("Dan Bownn");
                book.setPages(454);
                book.setPrice(16.96);
                book.setPress("Unknow");
                book.save();
            }
        });

    }
}
```

## 使用LitePal更新数据

```java
Button updateData = (Button) findViewById(R.id.update_data);
updateData.setOnClickListener(new View.OnClickListener() {
    @Override
    public void onClick(View v) {
        Book book = new Book();
        book.setPrice(14.95);
        book.setPress("Anchor");
        book.updateAll("name = ? and author = ?", "The Da Vinci Code", "Dan Brown");
    }
});
```

##删除数据

```java
Button deleteData = (Button) findViewById(R.id.delete_data);
deleteData.setOnClickListener(new View.OnClickListener() {
    @Override
    public void onClick(View v) {
        DataSupport.deleteAll(Book.class, "price<?","15");
    }
});
```

deteteAll后面不加参数则删除所有数据

## 查询数据
```java
Button queryData = (Button) findViewById(R.id.query_data);
queryData.setOnClickListener(new View.OnClickListener() {
    @Override
    public void onClick(View v) {
        List<Book> books = DataSupport.findAll(Book.class);
        for (Book book:books
             ) {
            Log.d("MainActivity", "book name is :" + book.getName());
        }
    }
});
```

findAll()返回的是一个Book的List



## 所有代码:

```java
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button createDatabase = (Button) findViewById(R.id.create_database);
        createDatabase.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                LitePal.getDatabase();
            }
        });
        Button addData = (Button) findViewById(R.id.add_data);
        addData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Book book = new Book();
                book.setName("The Da Vinci Code");
                book.setAuthor("Dan Brown");
                book.setPages(454);
                book.setPrice(16.96);
                book.setPress("Unknow");
                book.save();
            }
        });
        Button updateData = (Button) findViewById(R.id.update_data);
        updateData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Book book = new Book();
                book.setPrice(14.95);
                book.setPress("Anchor");
                book.updateAll("name = ? and author = ?", "The Da Vinci Code", "Dan Brown");
            }
        });
        Button deleteData = (Button) findViewById(R.id.delete_data);
        deleteData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                DataSupport.deleteAll(Book.class, "price<?","15");
            }
        });
        Button queryData = (Button) findViewById(R.id.query_data);
        queryData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                List<Book> books = DataSupport.findAll(Book.class);
                for (Book book:books
                     ) {
                    Log.d("MainActivity", "book name is :" + book.getName());
                }
            }
        });

    }
}
```

## LitePal的其他方法
- Book firstBook = DataSupport.findFirst(Book.class);  找到第一条数据
- Book lastBook = DataSupport.findLast(Book.class);  找到最后一条数据
- 连缀查询 select()查那]哪几列 where()约束条件 order()指定排序 desc降序,asc升序 limit()查询数量,从第一条开始 offset()指定偏移量  从第几条开始


> 连缀查询
 ```java
 List<Book> books = DataSupport.select("name","author","pages")
.where("pages>?","400")
.order("pages desc")
.limit(10)
.offset(5)
.find(Book.class);
```
