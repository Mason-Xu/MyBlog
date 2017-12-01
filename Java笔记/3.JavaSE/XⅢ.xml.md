# XML

## XML语法

### xml用途
 - 可扩展标记语言,独立于软件和硬件方面的信息传输工具
 - 简化数据共享
 - 简化数据传输
 - 简化平台的变更
### 基本语法
 - 指令
 - 元素与属性
 - 大小写敏感
 - 元素必须有关闭标签
 - 必须有根标签
 - 元素必须正确嵌套
 - 实体引用  
 - CDATE端  
    ```xml
    <![CDATA[
        无论这里打什么都是文本
    ]]>
    ```

## XML解析  
### XML解析方式
- SAX解析方式 速度快,逐行解析
- DOM解析方式 速度慢,构造成树状结构,遍历和修改节点,----- 官方推荐

### 读取XML

- SAXReader 读取xml文件 ,需要导入dom4j.jar
- Emp类

```java
public class ParseXmDemo {
    public static void main(String[] args) {
        /*
         * 解析XML文档大致流程
         * 1. 创建SAXReader
         * 2. 使用SAXReader读取XML文档并返回一个
         *    Document对象
         *    这一步也是DOM解析耗时资源的地方
         * 3. 通过Document对象获取根元素
         * 4. 通过根元素按照XML文档结构逐级
         *    获取子元素,以达到遍历XML文档数据的目的
         *
         */
        /*
         * 将emplist.xml文档中的每个员工信息都解析为一个Emp实例
         */

        try {
            // 1 创建SAXReader
            SAXReader reader = new SAXReader();

            // 2 读取指定文件 ,返回Documnet实例
            Document doc = reader.read(new File("F:\\workspace\\Java\\JavaTedu\\JSD1703_XML\\emplist.xml"));

            // 3 每对标签都是一个Element实例 <name>张三</name>
            /*
             * String getName()
             * 获取当前元素的名字(标签名)
             *
             * Element element(String name)
             * 获取当前元素中指定名字的子元素
             *
             * List elements()
             * 获取当前元素中所有子元素
             *
             * List elements(String name)
             * 获取当前元素中所有同名子元素
             *
             * String getText()
             * 获取当前元素中间的文本
             *
             * String elementText(String name)
             * 获取当前标签下指定名字的子标签中间的文本
             *
             * Attibute attribute(String name)
             * 获取当前标签中指定名字的属性
             */
            Element root = doc.getRootElement();

            //用来保存XML文档中解析出来的所有的员工信息
            List<Emp> emplist = new ArrayList<Emp>();

            /*
             * 获取<list>标签中的所有子标签<emp>,并将
             * 这些<emp>标签中的员工信息以若干emp实例
             * 表示并存入emplist集合
             */

            List<Element> list = root.elements();
            for (Element empEle : list
                    ) {
                // 获取员工名字
                Element nameEle = empEle.element("name");
                String name = nameEle.getText();

                // 获取员工年龄
                Integer age = Integer.parseInt(empEle.element("age").getText());

                // 获取员工性别
                String gender = empEle.elementText("gender");

                //获取员工薪水

                Integer salary = Integer.parseInt(empEle.elementText("salary"));
                /*
                 * 获取id属性
                 * Attribute 的每一个实例用于表示一个元素中的一个属性
                * 常用方法:
                * String getName()
                * 获取属性的名字
                *
                 * String getValue()
                 * 获取属性的值
                 */

                Attribute attr = empEle.attribute("id");
                Integer id = Integer.parseInt(attr.getValue());

                Emp emp = new Emp(id, name, age, gender, salary);
                emplist.add(emp);
            }

            System.out.println("解析完毕");

            for (Emp emp: emplist
                 ) {
                System.out.println(emp);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```
### 写XML
```java
public class ParseXmDemo {
    public static void main(String[] args) {
        /*
         * 解析XML文档大致流程
         * 1. 创建SAXReader
         * 2. 使用SAXReader读取XML文档并返回一个
         *    Document对象
         *    这一步也是DOM解析耗时资源的地方
         * 3. 通过Document对象获取根元素
         * 4. 通过根元素按照XML文档结构逐级
         *    获取子元素,以达到遍历XML文档数据的目的
         *
         */
        /*
         * 将emplist.xml文档中的每个员工信息都解析为一个Emp实例
         */

        try {
            // 1 创建SAXReader
            SAXReader reader = new SAXReader();

            // 2 读取指定文件 ,返回Documnet实例
            Document doc = reader.read(new File(".\\JSD1703_XML\\emplist.xml"));

            // 3 每对标签都是一个Element实例 <name>张三</name>
            /*
             * String getName()
             * 获取当前元素的名字(标签名)
             *
             * Element element(String name)
             * 获取当前元素中指定名字的子元素
             *
             * List elements()
             * 获取当前元素中所有子元素
             *
             * List elements(String name)
             * 获取当前元素中所有同名子元素
             *
             * String getText()
             * 获取当前元素中间的文本
             *
             * String elementText(String name)
             * 获取当前标签下指定名字的子标签中间的文本
             *
             * Attibute attribute(String name)
             * 获取当前标签中指定名字的属性
             */
            Element root = doc.getRootElement();

            //用来保存XML文档中解析出来的所有的员工信息
            List<Emp> emplist = new ArrayList<Emp>();

            /*
             * 获取<list>标签中的所有子标签<emp>,并将
             * 这些<emp>标签中的员工信息以若干emp实例
             * 表示并存入emplist集合
             */

            List<Element> list = root.elements();
            for (Element empEle : list
                    ) {
                // 获取员工名字
                Element nameEle = empEle.element("name");
                String name = nameEle.getText();

                // 获取员工年龄
                Integer age = Integer.parseInt(empEle.element("age").getText());

                // 获取员工性别
                String gender = empEle.elementText("gender");

                //获取员工薪水

                Integer salary = Integer.parseInt(empEle.elementText("salary"));
                /*
                 * 获取id属性
                 * Attribute 的每一个实例用于表示一个元素中的一个属性
                * 常用方法:
                * String getName()
                * 获取属性的名字
                *
                 * String getValue()
                 * 获取属性的值
                 */

                Attribute attr = empEle.attribute("id");
                Integer id = Integer.parseInt(attr.getValue());

                Emp emp = new Emp(id, name, age, gender, salary);
                emplist.add(emp);
            }

            System.out.println("解析完毕");

            for (Emp emp: emplist
                 ) {
                System.out.println(emp);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```

### XPath

- **要导入  jaxen.jar 包**

#### 路径表达式
- 斜杠(/)作为路径内部的分隔符
- 同一个节点有绝对路径和相对路径的两种写法
  - 路径,必须以 / 起首 ,后面紧跟节点
  - 相对路径 不适用 . 起首
- "." 表示当前节点
- ".." 父节点
- nodename(节点名称) 该节点的所有子节点
- "/" 选择根节点
- "//" 任意位置的某个节点
- "@" 表示某个属性
####  谓语 []
- 对路径表达式的附加条件
- 所有的条件,都写在你[]里,表示对节点进行进一步筛选

#### 通配符
- "*" 表示匹配任何元素节点
- "@*" 表示匹配任何属性值
- node() 表示匹配任何类型的节点
```java
public class XPathDemo {
    public static void main(String[] args) {
        try {
            SAXReader reader = new SAXReader();
            Document doc = reader.read(
                    new FileInputStream("myemp.xml")
            );
            String xpath = "/list/emp[salary>3000 and gender='男']/name";
            List<Element> list = doc.selectNodes(xpath);
            for(Element e : list){
                System.out.println(e.getText());
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```
