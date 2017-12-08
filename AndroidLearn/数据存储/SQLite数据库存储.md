# SQLite数据库存储

## 创建数据库


```java
public class MyDatabaseHelper extends SQLiteOpenHelper {
    public static final String CREAT_BOOK = "Creat table book("
            + "id integer primary key autoincrement,"
            + "author text,"
            + "price real,"
            + "pages integer,"
            + "name text)";
    private Context mContext;

    public MyDatabaseHelper(Context context, String name, SQLiteDatabase.CursorFactory factory, int version, Context mContext) {
        super(context, name, factory, version);
        this.mContext = context;
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(CREAT_BOOK);
        Toast.makeText(mContext, "Creat succeeded", Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }
}
```

```java
public class MainActivity extends AppCompatActivity {

    private MyDatabaseHelper dbHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        dbHelper = new MyDatabaseHelper(this, "BookStore.db", null, 1);
        Button createDatabase = (Button) findViewById(R.id.create_database);
        createDatabase.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                dbHelper.getWritableDatabase();
            }
        });
    }
}
```


## 升级数据库

```java
public class MyDatabaseHelper extends SQLiteOpenHelper {
    ...

    public static final String CREATE_CATEGORY = "create table Category("
            + "id integer primary key autoincrement"
            + "category_name text" +
            "category_code integer)";

    ...

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(CREATE_BOOK);
        db.execSQL(CREATE_CATEGORY);
        Toast.makeText(mContext, "Creat succeeded", Toast.LENGTH_SHORT).show();
    }

    ...
}
```
```java
public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
       db.execSQL("drop table if exists Book");
       db.execSQL("drop table if exists Category");
       onCreate(db);
   }
   ```

   `dbHelper = new MyDatabaseHelper(this, "BookStore.db", null, 2);`  
   version = 2 使onUpgrade()执行
