1. 查询emp表中数据，列出一列，内容为名字与职位
  显示格式：ename:job

2. 查看每个员工职位的字符个数

3. 将所有员工的名字以小写形式，与首字母大写形式
   查询出来，第一列为小写形式，第二列为首字母大写

4. 将字符串'aaaaaabaaaaa'中左右两边的a去除

5. 显示每个员工的名字，要求显示10位，第一列左对齐效果，第二列    右对齐效果
6. 截取字符串'DOCTOR WHO'中的'WHO'
7. 查看'DOCTOR WHO'中'WHO'的位置
8. 分别查看55.789四舍五入保留小数点后2位，整数位，十位后的
   数字，显示成三列。
9. 分别查看55.789截取后保留小数点后2位，整数位，十位后的
   数字，显示成三列。
10. 查看每名员工工资百位以下的数字?
11. 查看每名员工从入职到今天一共多少天，若有小数则向上取整。
12. 查看从2008-08-08号到今天为止一共经历了多少天?
13. 将每名员工入职时间以例如:
     1981年12月3日
     的形式显示
14. 查看每个员工入职所在月的月底是哪天?
15. 查看每名员工转正日期(入职后3个月)
16. 查看每名员工入职至今共多少个月?
17. 查看从明天开始一周内的周日是哪天?
18. 查看82年以后入职的员工的入职日期，82年以前的按照
     1982年01月01号显示。格式都是DD-MON-RR(默认格式)
19. 查看每名员工的入职年份?
20. 显示每个员工的总收入(工资加奖金)，奖金为NULL的只看工资
21. 使用NVL2实现20题的需求
```sql
1
Select ename||':'||job From emp_mason;
2
Select length(job) From emp_mason;
3
select lower(ename),upper(ename) from emp_mason;
4
Select trim('a' From 'aaaaaaaaabaaaaaaa') From dual;
5
Select RPAD(ename,10,' '),LPAD(ename,10,' ') From emp_mason;
6
Select Substr('DOCTOR WHO',8) From dual;
7
Select Instr('DOCTOR WHO','WHO') From dual;
8
Select Round(55.789,2),Round(55.789,0),Round(55.789,-1) From dual;
9
Select ename,Mod(sal,100) From emp_mason;
10
Select ename,Ceil(Sysdate-hiredate) From emp_mason;
11
Select Sysdate-To_Date('2008-08-08','YYYY-MM-DD') From dual;
12
Select ename,To_Char(hiredate,'YYYY"年"MM"月"DD"日"') From emp_mason;
13
Select ename,Add_Months(hiredate,3) From emp_mason;
14
Select ename,Months_Between(Sysdate,hiredate) From emp_mason;
15
Select Next_Day(Sysdate,1) From dual;
16
Select ename,Greatest(hiredate,To_date('1982-01-01','YYYY-MM-DD')) From emp_mason;
17
Select ename,Extract(Year From hiredate) From emp_mason;
19
Select ename,sal,comm,sal+NVL(comm,0) From emp_mason;
20
Select ename,sal,comm,NVL2(comm,comm+sal,sal) From emp_mason;
```
