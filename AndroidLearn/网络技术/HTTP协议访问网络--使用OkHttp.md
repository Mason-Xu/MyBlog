# 使用OkHttp 开源库
`implementation'com.squareup.okhttp3:okhttp:3.9.1'`
`<uses-permission android:name="android.permission.INTERNET"/>`

```java
public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    TextView responseText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button sendRequest = (Button) findViewById(R.id.send_request);
        responseText = (TextView) findViewById(R.id.response_text);
        sendRequest.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.send_request) {
            //sendRequestWithHttpURLConnection();
            sendRequestWithOkHttp();
        }
    }

    private void sendRequestWithOkHttp() {
        new Thread(new Runnable() {
            @Override
            public void run() {
                try{
                    //创建OkHttpClient实例
                    OkHttpClient client = new OkHttpClient();
                    //如果想要发起请求,就要创建一个Request对象,连缀,通过uri来设置目标网址
                    Request request = new Request.Builder().url("http://www.baidu.com").build();
                    //调用newCall()方法来创建一个Call对象,并调用它的execute()方法来发送请求并获取服务器返回的数据
                    Response response = client.newCall(request).execute();
                    String responseData = response.body().string();
                    showResponse(responseData);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }).start();
    }

    ...
    private void showResponse(final String response) {
        //runOnUiThread() Android不允许在子线程上进行UI操作,通过这个方法切换到主线程
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                // 在这里进行UI操作，将结果显示到界面上
                responseText.setText(response);
                Log.d("MainActivity", "setText");
            }
        });
    }
}
```
