# ListView

## ListView 简单用法
  - width和height是match_parent
  - 数据可以从数据库,网上下载.也可以是数组
  - 数组中的数据是 无法直接传递给ListView的,要借助适配器,其中**ArrayAdapter**最好用
  - ArrayAdapter可以用泛型指定数据类型,在构造函数中吧要适配的数据传入
  - ArrayAdapter有多个构造函数重载,要选择最适合的一种.因为传入数据是字符串,所以`ArrayAdapter<String>`
  - 构造函数传入(上下文,ListView子项布局id,适配数据)
  - 最后调用ListView的setAdapter()方法,将构建好的适配器对象传递进去 ,**这样ListView和数据之间的关联就建立完成 了**
    ```xml
    <ListView
      android:id="@+id/list_view"
      android:layout_width="match_parent"
      android:layout_height="match_parent"></ListView>
    ```
    ```java
    public class MainActivity extends AppCompatActivity {

    private String[] data = {"Apple","Banana","Orange","Watermelon","Pear","Grape",
                                "Pineapple","Strawberry","Cherry","Mango","Apple",
                                 "Banana","Orange","Watermelon","Pear","Grape",
                                "Pineapple","Strawberry","Cherry","Mango"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(
                MainActivity.this,android.R.layout.simple_list_item_1,data);
        ListView listView = (ListView) findViewById(R.id.list_view);
        listView.setAdapter(adapter);
       }
    }
    ```
## 定制ListView的界面
  1. 定义一个实体类,作为ListView适配器的适配类型,新建Fruit
     ```java
     public class Fruit {
         private String name;
         private int imageId;

     public Fruit(String name, int imageId) {
         this.name = name;
         this.imageId = imageId;
     }

     public String getName() {
         return name;
     }

     public int getImageId() {
         return imageId;
     }
     }

  2. 自定义布局  LinearLayout 要 TextVIew垂直布局居中
     ```xml
     <ImageView
       android:id="@+id/fruit_image"
       android:layout_width="wrap_content"
       android:layout_height="wrap_content" />

      <TextView
       android:id="@+id/fruit_name"
       android:layout_width="wrap_content"
       android:layout_height="wrap_content"
       android:layout_gravity="center_vertical"
       android:layout_marginLeft="10dp" />
      ```
  3. 创建适配器
     1. 继承自ArrayAdapter 泛型Fruit  新建类FruitAdapter
     2. Fruit重写一组父类的构造函数,用于将 上下文,ListView子项布局的id和数据传递进来
     3. 重写getView()方法,这个方法每个子项被滚动到屏幕内的时候会被调用.
     4. 在getView()方法中,首先通过getItem()方法得到当前项的Fruit实例,然后使用LayoutInflater 来为这个子项加载传入的布局
     5. inflate()接收三个参数 ()
     6. 调用View的findViewById() 获取ImageView和TextView的实例,并分别调用他们的setImageResource()和setText()方法来设置显示的图片和文字,最后布局返回
         ```java
        public class FruitAdapter extends ArrayAdapter {
                private int resourceId;

        public FruitAdapter(Context context, int textViewResourceId, List<Fruit> objects) {
                super(context, textViewResourceId, objects);
                resourceId = textViewResourceId;
        }

        @NonNull
        @Override
        public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
                Fruit fruit = (Fruit) getItem(position); // 获取当前项的Fruit实例
                View view = LayoutInflater.from(getContext()).inflate(resourceId, parent, false);
                ImageView fruitImage = (ImageView) view.findViewById(R.id.fruit_image);
                TextView fruitName = (TextView) view.findViewById(R.id.fruit_name);
                fruitImage.setImageResource(fruit.getImageId());
                fruitName.setText(fruit.getName());
                return view;

        }
        }  

      7. initFruit()方法  初始化所有水果数据
      8. onCreat() 方法中创建FruitAdapter对象,并将FruitAdapter作为适配器传递给ListVIew,这样定制ListView界面的任务就完成了
          ```java
          public class MainActivity extends AppCompatActivity {

          private List<Fruit> fruitList = new ArrayList<>();

           @Override
           protected void onCreate(Bundle savedInstanceState) {
               super.onCreate(savedInstanceState);
               setContentView(R.layout.activity_main);
               initFruits(); // 初始化水果数据
               FruitAdapter adapter = new FruitAdapter(MainActivity.this,R.layout.fruit_item,fruitList);
               ListView listView = (ListView) findViewById(R.id.list_view);
               listView.setAdapter(adapter);
           }

           private void initFruits() {
               for (int i = 0; i < 2; i++) {
                   Fruit apple = new Fruit("Apple", R.drawable.apple_pic);
                   fruitList.add(apple);
                   Fruit banana = new Fruit("banana", R.drawable.banana_pic);
                   Fruit orange = new Fruit("orange", R.drawable.orange_pic);
                   fruitList.add(orange);
                   Fruit watermelon = new Fruit("watermelon", R.drawable.watermelon_pic);
                   fruitList.add(watermelon);
                   Fruit pear = new Fruit("pear", R.drawable.pear_pic);
                   fruitList.add(pear);
                   Fruit grape = new Fruit("grape", R.drawable.grape_pic);
                   fruitList.add(grape);
                   Fruit pineapple = new Fruit("pineapple", R.drawable.pineapple_pic);
                   fruitList.add(pineapple);
                   Fruit strawberry = new Fruit("strawberry", R.drawable.strawberry_pic);
                   fruitList.add(strawberry);
                   Fruit cherry = new Fruit("cherry", R.drawable.cherry_pic);
                   fruitList.add(cherry);
                   Fruit mango = new Fruit("mango", R.drawable.mango_pic);
                   fruitList.add(mango);
               }
           }
          }
          ```
## 提升ListView运行效率   修改FruitAdapter
  ### 在getView() 方法中还有 convertView参数,用于将之前加载好的布局进行缓存,以后可重用
  - 对getView()方法进行判断,如果convertView为null,则使用LayoutInflater 加载布局,不为null则直接对convertView进行重用
    ```java
    public class FruitAdapter extends ArrayAdapter {
      ...
      @Override
      public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
          Fruit fruit = (Fruit) getItem(position); // 获取当前项的Fruit实例
          View view;
          if(convertView == null){
              view = LayoutInflater.from(getContext()).inflate(resourceId, parent, false);
          }else{
              view = convertView;
          }
          ImageView fruitImage = (ImageView) view.findViewById(R.id.fruit_image);
          TextView fruitName = (TextView) view.findViewById(R.id.fruit_name);
          fruitImage.setImageResource(fruit.getImageId());
          fruitName.setText(fruit.getName());
          return view;
      }
    }
      ```
  ### 继续优化 借助**ViewHolder**来对部分性能进行优化  修改FruitAdapter 📖P120
  1. 新建一个内部类ViewHolder,用于对控件的实例进行缓存
  2. 当converView为null时,创建一个ViewHolder对象,并将控件的实例都存放在ViewHolder里
  3. 然后调用View的setTag() 方法,将ViewHolder对象存储在View中.
  4. 当convertView不为null时,则调用View的getTag()方法,吧ViewHolder重新取出.
  5. 这样所有空间的实例都缓存在了ViewHolder里,就**没有必要每次都通过findViewById() 方法来获取控件实例**
      ```java
      public class FruitAdapter extends ArrayAdapter {
        ...
        @Override
        public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
            Fruit fruit = (Fruit) getItem(position); // 获取当前项的Fruit实例
            View view;
            ViewHoler viewHolder;
            if(convertView == null){
                view = LayoutInflater.from(getContext()).inflate(resourceId, parent, false);
                viewHolder = new ViewHoler();
                viewHolder.fruitImage = (ImageView)   view.findViewById(R.id.fruit_image);
                viewHolder.fruitName = (TextView) view.findViewById(R.id.fruit_name);
                view.setTag(viewHolder); // 将ViewHolder存储在View中
            }else{
                view = convertView;
                viewHolder = (ViewHoler) view.getTag(); // 重新获取ViewHolder
            }
            viewHolder.fruitImage.setImageResource(fruit.getImageId());
            viewHolder.fruitName.setText(fruit.getName());
            return view;
        }
        class ViewHoler{
            ImageView fruitImage;
            TextView fruitName;
          }
      }
## 为ListView添加点击事件
  - 在MainActivity 添加 点击事件 Toast
  1. 使用setOnItemClickListener() 方法为ListView 注册一个监听器
  2. 点击任何一个子项是,回调onItemClick() 方法
  3. 这个方法可以通过position 参数判断用户点击的是哪个子项,然后获取相应的水果
  4. 通过Toast将水果的名字显示出来
      ```java
      public class MainActivity extends AppCompatActivity {

        private List<Fruit> fruitList = new ArrayList<>();

        @Override
        protected void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            setContentView(R.layout.activity_main);
            initFruits(); // 初始化水果数据
            FruitAdapter adapter = new FruitAdapter(MainActivity.this,R.layout.fruit_item,fruitList);
            ListView listView = (ListView) findViewById(R.id.list_view);
            listView.setAdapter(adapter);
            listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
              @Override
              public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                  Fruit fruit = fruitList.get(position);
                  Toast.makeText(MainActivity.this,fruit.getName(),Toast.LENGTH_SHORT).show();
              }
          });
        }

        ...
      }




>这是我学习Android的笔记,参考书<<第一行代码-第二版>>,感谢郭霖大神  
      如有不足之处,可以一起讨论    
      附上郭霖的blog http://blog.csdn.net/guolin_blog
