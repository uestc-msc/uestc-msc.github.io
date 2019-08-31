---
title: 【Bot Framework完全攻略】1-7.向政府注册你的旗帜（注册一个你的Bot）
date: 2017-04-24 00:00:00
author: 谷亚奇
categories:
  - Bot Framework
tags:
  - 谷亚奇
---

上一篇文章中我们实现的本地的Bot搭建及测试，为了能让小伙伴们也能看一看我们的Bot，我们需要到Bot官网注册一个Bot，官网提供了一些丰富的能让小伙伴们与Bot交流的方式，最简单的就是在网页上聊天，还有Skye等等，通过复杂一点的实现，也可以将Bot连接至微信公众号。

这一节我们只做准备工作，就是到官网注册一个Bot，并且我会告诉你一些配置的用途

<!-- More -->

首先登陆Bot官网：https://dev.botframework.com/

你会看到顶部有一个导航栏

- Bot Framework PREVIEW 官网的Bot概述
- My Bots 管理你注册过的Bot
- Register a bot 注册一个新的Bot
- Documentaton 官方开发文档，佐以谷歌翻译食用风味更佳
- Bot Directory 一个有趣的地方，有好多别人的Bot，更有趣的是你还可以用它们
- Blog 官网的信息发布博客，如果你将来成为了一名高级的开发者，可以关注一下

初来乍到你可以逛逛

现在我们就来注册第一个Bot。进入Register a bot（登录过程跳过）:

![img](【Bot Framework完全攻略】1-7.向政府注册你的旗帜（注册一个你的Bot）/dfa1b981fv96arbe-15.png)

![img](【Bot Framework完全攻略】1-7.向政府注册你的旗帜（注册一个你的Bot）/dfa1b981fv96arbe-16.png)

- Name：Bot的名字 ，这个名字只有你把你的Bot公布到Directory才会被看到
- Bot handle：你可以理解成ID，就像你在游戏中起的不能和别人重复的名字一样
- Description：这个描述也是只有你把你的Bot公布到Directory才会被看到
- Messaging endpoint：就是上一个教程中的endpoint，只不过这里肯定不能用localhost了，因为那是测试用的本地网址。这里暂且空下不填
- App ID and password 部分：点那个蓝色按钮，微软会为你生成AppID还有密钥，你要妥善保管
- Admin部分：Owners是主人。这个不用改，上面写的应该就是你的微软账号，如果想填多个账号用逗号分隔。下面的AppInsight xxxxxxxxxx是只有把你的Bot发布到Azure云时才会用到的，是一个用来分析请求的东西。

做好配置，勾选接受协议，点击Register注册。

至此你的Bot就注册完成了，你在My Bots那里应该就能找到了。
