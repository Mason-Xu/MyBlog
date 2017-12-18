# UILayout

## LinearLayout 线性布局
 - 默认`android:orientation="horizontal"` 水平布局
 - `layout_gravity` 对齐方式  `center_vertical` 垂直居中` center_horizontal` 水平居中
   - center
   - bottom
   - top
   - left
   - right
 - weight 比例 - 牢记剩余空间 比例时,width设置0dp


## RelativeLayout 相对布局
 - 相对父布局
   - `android:layout_alignParentLeft`
   - `android:layout_alignParentRight`
   - `android:layout_alignParentTop`
   - `android:layout_alignParentBotton`
   - `android:layout_centerInParent`
 - 相对控件
   - `android:layout_above="@+id/xxxxx"` 上
   - `android:layout_blow="@+id/xxxxx"`  下
   - `android:layout_toLeftOf="@+id/xxxxx"`  左
   - `android:layout_toRightOf="@+id/xxxxx"` 右

## FrameLayout 帧布局
 - 全部控件都在左上角,应用很少
 - layout_gravity 对齐方式也可以用  碎片中有应用

##  百分比布局
  - layout_weight只有在LinearLayout中可以使用,在其他布局很难实现,所以引入百分比布局,直接定义控件所占百分比
  - PercentFrameLayout 和 PercentRelativeLayout

  >这是我学习Android的笔记,参考书<<第一行代码-第二版>>,感谢郭霖大神  
  如有不足之处,可以一起讨论    
  附上郭霖的blog http://blog.csdn.net/guolin_blog
