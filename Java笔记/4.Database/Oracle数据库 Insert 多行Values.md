# Oracle数据库INSERT 多行VALUES

```sql
Insert All Into dept values(10,'ACCOUNTING','NEW_YORK')
Into dept Values(20,'RESEARCH','DALLAS')
Into dept Values(30,'SALES','CHICAGO')
Into dept Values(40,'OPERATIONS','BOSTON')
Select 1 from dual
```

1. 使用 Insert All Into 替代 Insert Into
2. 最后的Select 1 from <table_name>  table_name 可以是不是dept的任何表
3. 不使用Mysql的逗号分格,在每个Values前面加上Into table_name VALUES

![](http://oz2u8kxpt.bkt.clouddn.com/17-12-18/93883220.jpg)
