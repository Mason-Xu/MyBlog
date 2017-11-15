# 认识Android

## Android四层架构 :
  1. Linux内核层  --- 底层驱动 显卡,蓝牙,声卡驱动 电源管理
  2. 系统运行类库 --- 通过一些C/C+库来为Android系统提供主要的特性支持
  3. 应用框架层 --- 构建应用是需要用到的各种API
  4. 应用层 --- 手机上的APP

## Android的版本
  目前5.0的系统已经占据了98%的Android市场,所以开发的程序面向5.0以上的系统

## Android应用开发特色
  1. 四大组件  活动(Activity), 服务(Service) ,广播接收器(Broadcast Receiver),内容提供器(Content Provider).  
  2. 丰富的系统控件  
  3. SQLite数据库
  4. 强大的多媒体  
  5. 地理位置定位

## 开发环境  
  1. JDK  需要JDK8  
  2. Android SDK Android开发工具包  有Android的API
  3. Android Studio IDE

## 分析项目文件

- 总目录
   1. .gradle 和 .idea  IDE自动生成,不要管也不要修改
   1. app 项目中的代码,资源
  3. build 编译时生成的文件  
  4. gradle gradle wrapper的配置文件, 需要下载gradle ,设置 : file->Setting->build->Execution,Deployment->Gradle
  5. .gitignore  指定目录和文件排除在版本控制外
  6. build.gradle 项目全局的gradle构建脚本,不需要修改  
  7. gradle.properties 全局的gradle配置文件,属性会影响到项目中所有的gradle编译脚本
  8. gradlew和gradlew.bat 命令行执行gradle命令,gradlew 是 linux或mac系统,gradlew.bat是在windows系统中使用
  9. HelloWorld.iml idea项目都会自动生成一个文件,用啦标识是一个idea项目  
  10. local.properties 指定本机Android SDK 路径
  11. settings.gradle 项目所有引入的模块,HelloWorld项目中只有一个app模块所以只引入一个app模块  通常引入模块都是自动完成的

      ![](http://oz2u8kxpt.bkt.clouddn.com/17-11-10/1269884.jpg)
- app目录
  1. build 与外层build相似,编译自动生成的文件
  2. libs 第三方jar包  
  3. androidTest 编写AndroidTest测试用例,对项目进行一些自动化测试
  4. java java代码,有HelloWorldActivity
  5. res 图片,布局,字符串等资源  drawable 图片 layout 布局 字符串 values
  6. AndroidManifest.xml  Android项目的配置文件 ,定义的四大 组件需要在这个文件注册,另外给应用程序添加权限声明
  7. test 编写Unit Test 测试用例,自动化测试的另一种方式
  8. .gitignore app模块内指定目录和文件排除在版本控制之外
  9. app.iml IDEA自动生成
  10. build.gradle app模块的gradle构建脚本
  11. proguard-rules.pro 项目代码混淆规则
  ![](http://oz2u8kxpt.bkt.clouddn.com/17-11-10/45983605.jpg)
