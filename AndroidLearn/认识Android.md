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

 1. .gradle 和 .idea  IDE自动生成,不要管也不要修改
 2. app 项目中的代码,资源
 3. build 编译时生成的文件  
 4. gradle gradle wrapper的配置文件, 需要下载gradle ,设置 : file->Setting->build->Execution,Deployment->Gradle
 5. .gitignore  指定目录和文件排除在版本控制外
 6. build.gradle 项目全局的gradle构建脚本,不需要修改  
 7. gradle.properties
