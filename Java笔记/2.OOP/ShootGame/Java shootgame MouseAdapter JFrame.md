# 鼠标监听 #

- JFrame  
`JPanel flyings  = Arrays.copyof(flyings,flyings.lengtth-1) `// 缩容
```java
    this.addMouseListener(l);
    this.addMouseMotionListener(l);
```
## **MouseAdapter 包含 MouseListener(); MouseMotionListener();**
```java
    MouseAdapter l = new MouseAdapter(){
    	重写mouseMoved(){
    	}
    }
```

> 为什么 对象 没有消失,因为还在数组中  
> 所以将存在的对象的数组保存下来到新的数组,然后缩容,就是删除这个对象
