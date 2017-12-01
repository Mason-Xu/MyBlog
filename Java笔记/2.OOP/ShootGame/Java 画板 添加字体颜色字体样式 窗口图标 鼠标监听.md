# 笔记 #

## **画板添加字.设置字体,颜色**
```java
    public void paintScoreAndLife(Graphics g) {
        g.setColor(new Color(0xFF0000)); //设置颜色(纯红)
        g.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 24)); //设置字体样式(字体:SANS_SERIF 样式:BOLD加粗  字号:24)
        g.drawString("SCORE: " + score, 10, 25);
        g.drawString("LIFE: " + hero.getLife(), 10, 45);//数据,x轴,y轴
    }
```
## **窗口图标设置**
```java
    ImageIcon icon = new ImageIcon(<image name>);
    frame.setIconImage(icon.getImage());
```




## **鼠标监听方法**
```java
    MouseAdapter l = new MouseAdapter() {
            /** 重写mouseMoved()鼠标移动事 */
            public void mouseMoved(MouseEvent e) {
                if (state == RUNNING) {
                    int x = e.getX(); //获取鼠标的x坐标
                    int y = e.getY(); //获取鼠标的y坐标
                    hero.moveTo(x, y); //英雄机随着鼠标移动
                }
            }

            public void mouseClicked(MouseEvent e) {//鼠标点击事件
                switch (state) {  //判断是何状态，并选择
                    case START:
                        state = RUNNING;
                        break;
                    case GAME_OVER:
                        hero = new Hero();//对象清0
                        flyings = new FlyingObject[0];//敌人清0
                        bullets = new Bullet[0];//子弹清0
                        state = START;//状态从GAME_OVER变为RUNNING
                        break;
                }
            }

            public void mouseExited(MouseEvent e) {
                if (state == RUNNING) {//当状态为运行时，鼠标移出面板
                    state = PAUSE;//状态变为暂停
                }
            }

            public void mouseEntered(MouseEvent e) {
                if (state == PAUSE) {//当状态为暂停时，鼠标进入面板
                    state = RUNNING;//状态变为运行
                }
            }
    };
```



## **子弹也消失的实现方法**
```java
    bangAction() {
        for () {//遍历子弹数组
        	bang(b, i);//传入数组和i
        }
    }

    bang(Bullet b, int k) {
        int indexBu = -1;
        for () { // 遍历敌机数组
            当碰撞时:
            indexBu = k
            缩容
        }
    }
```
![](https://i.imgur.com/TRDV8sQ.jpg)
