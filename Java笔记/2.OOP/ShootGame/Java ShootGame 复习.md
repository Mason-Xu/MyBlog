# 笔记 #

所有子类共有,创建父类  
部分子类共有,创建接口  
测试类(main)+父类+接口+子类  
包名是域名反写+模块  
图片放在包内,方便读取  

父类 flyingobject   
子类 Airplane,Hero,Bee,Bullet  
interface Award , Enemy  
测试类 ShootGame(main方法)  
Airplane,Hero,Bee,Bullet extends Flyingobject  
Airplane implements Enemy  
Bee implements Award  

常量定义,在普通类要static final,在interface中大写默认常量

`public static BufferedImage <image name>;` //准备图片

初始化静态资源  存储静态资源 静态块
```java
    static {//初始化静态资源
		try {//异常处理
			background = ImageIO.read(ShootGame.class.getResource("background.png"));
			...
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
```

**随机数两种初始化:**  

```java
    x = (int)(Math.random()*(ShootGame.WIDTH-this.width))  
    Random rand = new Random();  
    x = rand.nextInt(100);//0~99  
    x = rand.nextInt(ShootGame.WIDTH-this.width);  
```
private FlyingObject[] flyings = {};//一堆敌人  
private Bullet[] bullets = {};//一堆子弹  


swing相关知识:  
1.JFrame:框架------相框  
2.JPanel:画板------相板  

```java
    public static void main(String[] args) {
		JFrame frame = new JFrame("Fly");// 创建相框
		ShootGame game = new ShootGame();// 创建面板
		frame.add(game);// 面板添加到相框中
		frame.setSize(WIDTH, HEIGHT);// 设置相框大小
		frame.setAlwaysOnTop(true);// 设置置顶
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);// 设置默认关闭操作,退出并关闭
		frame.setLocationRelativeTo(null);
		frame.setResizable(false);// 固定相框大小
		frame.setVisible(true);// 1设置可见.2.调用paint方法
		game.action();
	}
```

paint()方法有两种方式来调用:  
1)frame.setVisible(true);  
2)repaint();  

Arrays.copyof(list,list.length+1)   扩容



**TimerTask:**

----------

```java
    Timer timer = new Timer();//创建定时器
		int intervel =10;//时间间隔,以毫秒为单位
		timer.schedule(new TimerTask() {
			public void run() {
				enterAction();//敌人入场
				repaint();//重画
			}
		},intervel,intervel);
    ```
