# UILayout

## LinearLayout 线性布局
 - 默认`android:orientation="horizontal"`
 - layout_gravity 对齐方式
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
