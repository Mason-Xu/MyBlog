# 安装Android Studio 时遇到  Buileing "xxx" Gradle project info 的解决方法

我第一次启动Android Studio的时候,遇到 Grale 一直下载不下来,后来找到解决方法

![](https://github.com/Mason-Xu/PictureLibrary/blob/master/Picture/android1.png)


 1.首先在 `C:\Users\用户名\.gradle\wrapper\dists` 文件夹中查看需要下载那个版本的Gradle

 ![](https://github.com/Mason-Xu/PictureLibrary/blob/master/Picture/android4.png)

 2.之后去http://services.gradle.org/distributions/  下载你需要的版本

![](https://github.com/Mason-Xu/PictureLibrary/blob/master/Picture/android2.png)

 3.下载后，将压缩包放到  `C:\Users\用户名\.gradle\wrapper\dists\gradle-x.x-all\xxxxxxxxxxxxxxx`

  https://github.com/Mason-Xu/PictureLibrary/blob/master/Picture/android3.png

 4.重写启动Studio即可
