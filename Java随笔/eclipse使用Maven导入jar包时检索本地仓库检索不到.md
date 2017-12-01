# 在eclipse的maven中搜索本地仓库中的jar包搜索不到

在下载好maven和.m创建本地仓库后,设置好环境变量后,但是在在eclipse的maven还是找不到jar包.

原因是因为maven中的本地仓库的index索引没有更新，导致在eclipse的maven插件中搜索不到。


解决方案：
在eclipse中打开菜单 window-> show view –> other –> Maven -> maven repositories
打开之后，选择local repositories –> local repository ，右击，选择Build index.

更新完索引之后，在通过右键单击pom.xml文件选择maven –> add dependency 或者是打开pom.xml文件，选择dependencies –>add 时，就可以搜索到本地仓库的jar包了。
