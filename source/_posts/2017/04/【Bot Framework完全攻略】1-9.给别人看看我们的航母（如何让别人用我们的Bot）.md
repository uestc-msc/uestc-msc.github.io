---
title: 【Bot Framework完全攻略】1-9.给别人看看我们的航母（如何让别人用我们的Bot）
date: 2017-04-29 00:00:00
author: 谷亚奇
categories:
  - Bot Framework
tags:
  - 谷亚奇
---

这篇教程就是Bot Framework系列教程初阶部分的最后一篇，读完之后，Bot开发全部的基本流程你应该就一清二楚了。（这可是后面的基础啊）

这次我就只告诉你Web Chat的使用方法，毕竟Bot支持的那些聊天平台（Skype什么的你室友有几个在用？）在国内使用的太少了。虽然说DirectLine这个功能可以把Bot连到微信公众号，不过那个比较不好弄，是我们后面课程的内容。

<!-- More -->

首先去Bot官网，并且登陆，进入My bots，选择你的Bot

找到Web Chat 后面的Edit：

![img](【Bot Framework完全攻略】1-9.给别人看看我们的航母（如何让别人用我们的Bot）/afs5d-22.png)

点击之后进入Web Chat 的配置界面。第一次进入可能会提示你新建一个site如果没有的话，就点击左边的Add  new site。site的名字随便起，没卵用的。然后进入这个界面：

![img](【Bot Framework完全攻略】1-9.给别人看看我们的航母（如何让别人用我们的Bot）/afs5d-23.png)

你可以看到Secret keys （密钥）是隐藏的，点击后面的Show就能看到。

下面的Embed code（嵌入代码）是一段HTML代码，内容就是与你Bot聊天的聊天室。

打开你的记事本，把Embed code（嵌入代码）复制进去，然后复制Secret keys（密钥）其中的一个，替换掉记事本里的 YOUR_SECRET_HERE。这样你就得到一段可用的html代码。

接下来，打开你的VS，进入你的项目，到解决方案管理器中找到default.htm文件：

![img](【Bot Framework完全攻略】1-9.给别人看看我们的航母（如何让别人用我们的Bot）/afs5d-24.png)

打开它，把body标签里面的内容替换成你记事本里的那段代码：

![img](【Bot Framework完全攻略】1-9.给别人看看我们的航母（如何让别人用我们的Bot）/afs5d-25.png)

然后，保存你的更改。重新发布你的Bot，这样就可以通过直接访问Bot的主页（endpoint的网址去掉后面/api/messages）来直接访问Bot了。

效果图：

![img](【Bot Framework完全攻略】1-9.给别人看看我们的航母（如何让别人用我们的Bot）/afs5d-26.png)

你会发现聊天的窗口太矮了。。。

在default.htm做出如下的修改可以改变小窗口的高度：

![img](【Bot Framework完全攻略】1-9.给别人看看我们的航母（如何让别人用我们的Bot）/afs5d-27.png)

修改完记得保存，重新发布。

记得Web Chat的网址就是你发布的站点URL（你在发布页面能找到）

大功告成！你可以把聊天窗口的网址发给你的朋友们，让他们感受一下你在做的工作。
