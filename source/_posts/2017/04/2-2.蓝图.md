---
title: 【Bot Framework完全攻略】2-2.蓝图（Bot Framework项目结构）
date: 2017-04-30 02:00:00
author: 谷亚奇
categories:
  - Bot Framework
tags:
  - 谷亚奇
---

当你导入Bot Framework项目时，你就看到了一大堆东西。这节教程我们就从Bot Framework项目的解决方案管理器出发，来讲讲项目中代码之外的一切东西。

<!-- More -->

首先你要知道Bot是一个基于ASP.NET的网络应用，它有一个固有格式，不是所有东西都需要做修改的。下面我先列出你能看到的所有东西的用途：

- Connected Services：从Visual Studio直接连接微软的一些服务（我们应该用不到这些高级的东西）
- Properties中的Assembly.cs：项目信息（用不到）
- ***引用：右键点击引用可以管理引用和Nuget程序包，Nuget默认开启了你缺什么包就自动下载的功能，但是就像我之前提到的，使用一些功能时需要手动添加引用。
- App_Start中的WebApiConfig.cs：Api配置（用不到）
- ***Controllers中的MessagesController.cs
- ***Dialogs中的RootDialog.cs
- **default.htm：Bot的首页，已经被我们修改成了与Bot对话的地方
- Global.asax：响应网络应用的应用级和模块级事件（太高级以至于用不到）
- packages.config：文本方式管理应用程序使用的包（你不摸它可以包你没事）
- **Web.config：网络应用的配置信息，比如我们之前就把AppID和AppSecret加了进去，但是之后我们也用不到它了

所有用到过的东西我都打了“*”，其他的东西基本是不需要你改的（摸坏了后果自负）。
