# 更加强大的滚动控件 RecyclerView  #P123

## 基本用法
  - 需要在build.gradle添加依赖库 recyclerview
  - activity_main.xml文件添加RecyclerView
  - 图片,Furit类,fruit_item.xml
  - 新建FruitAdapter类,作为适配器,继承自RecyclerView.Adapter ,并且泛型指定为FruitAdapter.ViewHolder  ViewHolder是内部类
      ```xml
      <android.support.v7.widget.RecyclerView
        android:id="@+id/recycler_view"
        android:layout_width="match_parent"
        android:layout_height="match_parent" />
      ```

  ###新建FruitAdapter
   1. 定义内部类ViewHoler ,继承自RecyclerView.ViewHolder
   2. ViewHoler的构造函数传入一个View参数,这个参数通常就是RecyclerView子项的最外层布局,通过findViewById() 方法来获取布局中的Imageiew和TextView的实例
   3. FruitAdapter 中也有构造函数,这个方法用于把要展示的数据源传进来,并赋值给一个全部变量mFruitList
   4. FruitAdapter继承自RecyclerView.Adapter,所以要重写`onCreatViewHolder(),onBingViewHolder(),getItemCount()`
      1. `onCreatViewHolder()`用来创建ViewHolder实例,将fruit_item布局加载进来,然后创建一个ViewHoler实例,并把加载出来的布局传入构造函数中,最后将ViewHoler的实例返回
      2. `onBingViewHolder()`用于对RecyclerView子项的数据进行赋值,会在每个子项被滚动到屏幕内的时候执行,通过position 参数得到当前项的Fruit实例,然后将数据设置到ViewHolder的ImageView和TextView当中即可
      3. getItemCount() 告诉RecyclerView有多少子项 ,返回  mFruitList.size()
      ```java
      public class FruitAdapter extends RecyclerView.Adapter<FruitAdapter.ViewHolder> {
        private List<Fruit> mFruitList;

        /**
         * Created by Mason on 2017/11/16.
         */

        static class ViewHolder extends RecyclerView.ViewHolder {
            ImageView fruitImage;
            TextView fruitName;

            public ViewHolder(View view) {
                super(view);
                fruitImage = (ImageView) view.findViewById(R.id.fruit_image);
                fruitName = (TextView) view.findViewById(R.id.fruit_name);
            }
          }   

        public FruitAdapter(List<Fruit> fruitList) {

            mFruitList = fruitList;
        }

        @Override
        public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
            View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.fruit_item, parent, false);
            ViewHolder holder = new ViewHolder(view);
            return holder;
        }

        @Override
        public void onBindViewHolder(ViewHolder holder, int position) {
            Fruit fruit = mFruitList.get(position);
            holder.fruitImage.setImageResource(fruit.getImageId());
            holder.fruitName.setText(fruit.getName());
        }

        @Override
        public int getItemCount() {
            return mFruitList.size();
        }
      }
        ```
## 改变为横向RecyclerView
  - fruit_item.xml 的LinearLayout布局改为`orientation:"vertical" ` 垂直布局 ,默认`horizontal`水平布局
  - 修改TextView和ImageView的layout_gravity  修改成水平居中center_horizontal
  - MainActivity.java文件 调用LinearLayoutManager的setOrientation()方法设置布局排列方向 添加`layoutManager.setOrientation(LinearLayoutManager.HORIZONTAL)`
    - xml
    ```xml
    <LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:orientation="vertical"
    android:layout_width="100dp"
    android:layout_height="wrap_content" >

    <ImageView
        android:id="@+id/fruit_image"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_gravity="center_horizontal" />

    <TextView
        android:id="@+id/fruit_name"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_gravity="center_horizontal"
        android:layout_marginTop="10dp" />
    </LinearLayout>
      ```
    - MainActivity.java
    ```java
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        intiFruits();
        RecyclerView recyclerView = (RecyclerView) findViewById(R.id.recycler_view);
        LinearLayoutManager layoutManager = new LinearLayoutManager(this);
        layoutManager.setOrientation(LinearLayoutManager.HORIZONTAL);
        recyclerView.setLayoutManager(layoutManager);
        FruitAdapter adapter = new FruitAdapter(fruitList);
        recyclerView.setAdapter(adapter);
    }
     ```

## RecyclerView 点击事件
 - 需要自己给子项具体的View注册点击事件
 - 虽然比ListView繁琐,但是ListView给单独按钮注册事件更加繁琐
   1. 修改ViewHolder,添加fruitView变量来保存子项最外层布局的实例
   2. 然后在onCreatViewHolder()方法中注册点击事件就行了.
   3. 这里项目分别为最外层布局和image注册了点击事件.
 - RecyclerView强大在于,可以轻松实现子项中任意控件或布局的点击事件
   1. 我们先获取用户点击的position
   2. 通过position拿到相应的Fruit实例
   3. 再使用Toast弹出两种不同的内容
   ```java
   public class FruitAdapter extends RecyclerView.Adapter<FruitAdapter.ViewHolder> {
       private List<Fruit> mFruitList;

       /**
        * Created by Mason on 2017/11/16.
        */

       static class ViewHolder extends RecyclerView.ViewHolder {
           View fruitView;  // 添加
           ImageView fruitImage;
           TextView fruitName;

           public ViewHolder(View view) {
               super(view);
               fruitView = view;  //添加
               fruitImage = (ImageView) view.findViewById(R.id.fruit_image);
               fruitName = (TextView) view.findViewById(R.id.fruit_name);
           }
       }

       public FruitAdapter(List<Fruit> fruitList) {

           mFruitList = fruitList;
       }

       @Override
       public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
           View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.fruit_item, parent, false);
           final ViewHolder holder = new ViewHolder(view);  // 添加
           holder.fruitView.setOnClickListener(new View.OnClickListener() {
               @Override
               public void onClick(View v) {
                   int position = holder.getAdapterPosition();
                   Fruit fruit = mFruitList.get(position);
                   Toast.makeText(v.getContext(), "you click view   " + fruit.getName(), Toast.LENGTH_SHORT).show();
               }
           });
           holder.fruitImage.setOnClickListener(new View.OnClickListener() {
               @Override
               public void onClick(View v) {
                   int position = holder.getAdapterPosition();
                   Fruit fruit = mFruitList.get(position);
                   Toast.makeText(v.getContext(), "you click image   " + fruit.getName(), Toast.LENGTH_SHORT).show();
               }
           });
           return holder;
       }
       ...
   }
   ```     
