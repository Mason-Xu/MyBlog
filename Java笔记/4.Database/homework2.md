
```sql
--1:查看与CLARK相同职位的员工

Select job,ename From emp_mason
where job = (Select job from emp_mason
             where ename = 'CLARK')
And ename <> 'CLARK' ;

--2:查看低于公司平均工资的员工

Select ename,sal
From emp_mason
Where sal < (Select Avg(sal) From emp_mason);


--3:查看与ALLEN同部门的员工

Select ename,deptno From emp_mason
Where deptno = (Select deptno From emp_mason
                 Where ename = 'ALLEN' )
And ename<> 'ALLEN';


--4:查看平均工资低于20号部门平均工资的部门平均工资

Select deptno,Avg(sal) From emp_mason
Group By deptno
Having Avg(sal) < (Select Avg(sal) From emp_mason
                   where deptno = 20);

--5:查看低于自己所在部门平均工资的员工

Select e.ename,e.sal,e.deptno
From emp_mason e,(select Avg(sal) avg_sal,deptno
                  From emp_mason
                  Group By deptno) t
where e.deptno = t.deptno
and e.sal>t.avg_sal;

--6:查看公司工资排名的第1-5名

Select *
From (Select ROWNUM rn,t.*
      From (Select ename,sal,deptno
            From emp_mason
            order by sal) t
      )
where rn <=5;



--7:查看CLERK职位的人数和其他职位的总人数各多少?

Select
  count(1),decode(job,'CLERK','CLERK','OTHER')
From emp_mason
Group by decode(job,'CLERK','CLERK','OTHER');

--8:查看每个职位的工资排名

Select ename,sal,job,
  ROW_NUMBER() over(
    Partition By job
    order by sal desc
  )rank
From emp_mason;


--9:查看每个职位的工资排名，若工资一致，排名一致

Select sal,job,ename,deptno ,
rank() over(
  Partition By job
  order by sal desc
)rank
From emp_mason;


--10:查看每个职位的工资排名，若工资一致，排名一致，不跳名次。

Select sal,job,ename,deptno ,
dense_rank() over(
  Partition By job
  order by sal desc
)rank
From emp_mason;

--11:分别查看:同部门同职位，同职位，以及所有员工的工资总和

Select job,deptno,sum(sal)
From emp_mason
group by ROLLUP(job,deptno);


--12:分别查看:同部门同职位，同职位，同部门以及所有员工的工资总和

Select deptno,job,sum(sal)
From emp_mason
group by CUBE(deptno,job);

--13:分别查看同部门同职位和同职位的员工的工资总和

Select deptno,job,sum(sal)
From emp_mason
group by grouping sets((deptno,job),(job))
order by deptno,job;


--14:查看公司最高工资的员工的名字以及所在部门名称

Select ename,deptno,sal
From emp_mason
Where sal = (Select Max(sal) from emp_mason);




--15:查看每个部门的最高工资的员工名字

Select ename,sal,deptno
From emp_mason

Select Max(sal),deptno from emp_mason group by deptno

Select e.ename,e.deptno,e.sal
    From emp_mason e,(Select Max(sal) max_sal,deptno from emp_mason group by deptno) t
Where e.deptno = t.deptno
and e.sal = t.max_sal

--16:查看有下属的员工信息

Select m.ename,m.deptno,m.sal,m.job
From emp_mason m
where exists(Select * From emp_mason e
              Where e.mgr = m.empno)
```
