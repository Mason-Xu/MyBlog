---
title: "Git和Github使用札记"  
date: 2018-01-04T13:01:52+08:00  
tags: [git,github]  
categories: [git]  
---
# Git 和 Github的使用札记

## git

```git
git init   // 创建本地仓库
git status // 掌握仓库当前的状态
git add    // 添加修改文件到stage
git commit -m"text"// 提交文件到Git仓库
```

## github

```git
git remote add origin git@github.com:username/repository.git  // 让本地仓库与远程仓库连接
git clone  git@github.com:username/repository.git  // 从远程仓库clone
git push -u origin master // 推送本地仓库文件到远程仓库
git push -f origin master // 强制推送
```

## 连接多个远程仓库
```git
git remote -v  // 查看目前远程库信息
git remote rm origin // 删除远程库

git remote add github git@github.com:username/repository.git  // 关联github
git remote add gitee git@github.com:username/repository.git  // 关联gitee

//推送
git push github master
git push gitee master
```

## 自定义 git
```
.gitignore  // 配置.gitignore 忽略特殊文件

//设置别名
$ git config --global alias.st status
$ git config --global alias.co checkout
$ git config --global alias.ci commit
$ git config --global alias.br branch
```
