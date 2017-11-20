## 🕑SimpleDateFormat 24小时和12小时转换 

## HH 代表 24 小时制 , hh 表示 12 小时制

```java
public class SimpleDateFormat_12_24_ {
	public static void main(String[] args) {
		SimpleDateFormat sdf_24 = new SimpleDateFormat("HH:mm:ss");
		System.out.println(sdf_24.format(new Date()));  // 15:00:00

		SimpleDateFormat sdf_12 = new SimpleDateFormat(" a hh:mm:ss");
		System.out.println(sdf_12.format(new Date()));  // 下午 3:00:00
	}
}
```

##Date 已经很少用了  现在多数使用Calender 来获取

```java
Calendar date = Calendar.getInstance();

System.out.println(date.get(Calendar.HOUR_OF_DAY)); // 15  24 小时制
System.out.println(date.get(Calendar.HOUR));   // 3  12 小时制
```
