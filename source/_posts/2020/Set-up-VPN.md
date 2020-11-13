---
title: Set Up Vpn
date: 2020-05-24 17:12:07
author: nexustar
tags: nexustar
---

搭梯子比较频繁，记录下步骤方便重现

<!-- More -->

## 引言

代理和vpn的工作机制略有不同，代理相对更加灵活，而vpn则兼容性更强,可按需选用或我全都要.jpg

## 服务器

- 别选择没法换ip的就好，比如现在的搬瓦工。系统推荐 debian 10。

- 到手后`apt update` `apt upgrade` `reboot`

## 搭建代理

搭建shadowsocks，在服务端步骤如下

### 安装shadowsocks-libev

```
# apt install shadowsocks-libev
```

### 配置

```
# nano /etc/default/shadowsocks-libev
```
将`USER=nobody`和`GROUP=nogroup`替换成`USER=root`和`GROUP=root`

```
# nano /etc/shadowsocks-libev/config.json
```
替换"server"后的"127.0.0.1"为"0.0.0.0"，替换"password"为自己的密码，"server_port"后替换为443或其它常用端口

在客户端中，ip填写服务器的公网ip，密码、端口、加密方式同服务器配置，客户端和服务器的local_port没有关系随便填或保持默认。

### 运行

```
# systemctl restart shadowsocks-libev
```

### 开启bbr

bbr是一个更新的tcp 拥塞控制算法，在某些机房开启后可大幅提升速度

```
echo "net.core.default_qdisc=fq" >> /etc/sysctl.conf
echo "net.ipv4.tcp_congestion_control=bbr" >> /etc/sysctl.conf
sysctl -p
```

## 搭建vpn

参考 https://10101.io/2018/11/10/wireguard 就好。
其中安装部分略微过时，ubuntu20.04直接从源内安装即可无需添加ppa，debian10在开启backports源后也是直接安装
