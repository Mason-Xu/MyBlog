# WebView用法

1. 布局文件添加WebView控件
2. MainActivity.java添加代码
  1. 使用findViewId() 获取WebView实例
  2. 调用WebView的getSetting()方法设置一些浏览器的属性
  3. 调用setJavaScriptEnabled() 方法让WebView支持JavaScript脚本
  4. 调用WebView的setWebViewClient() 方法,并传入一个WebViewClient实例 --- 当需要从一个网页跳转到另一个网页时,我们希望目标网页仍在WebView上运行,而不是系统浏览器
  5. 调用WebView的loadUri()方法,并将网址传入


```java
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        WebView webView = (WebView) findViewById(R.id.web_view);
        webView.getSettings().setJavaScriptEnabled(true);
        webView.setWebViewClient(new WebViewClient());
        webView.loadUrl("http://www.baidu.com");
    }
}
```


>这是我学习Android的笔记,参考书<<第一行代码-第二版>>,感谢郭霖大神  
如有不足之处,可以一起讨论    
附上郭霖的blog http://blog.csdn.net/guolin_blog
