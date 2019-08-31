# uestc-msc.github.io

💡 因为hexo是安装在当前文件夹, 因此不会在路径里, 无法通过`hexo`命令直接调用,
hexo位于 **./node_modules/hexo/bin/hexo** (相对于根目录)

## 配置记录

📖 [hexo官方文档](https://hexo.io/zh-cn/docs/)

📖 [NexT官方文档](https://theme-next.org/docs/getting-started/)

### hexo插件

- 一键git部署插件 [hexo-deployer-git](https://github.com/hexojs/hexo-deployer-git)
- emoji渲染插件 [hexo-filter-github-emojis](https://www.npmjs.com/package/hexo-filter-github-emojis)
- 文章阅读时间估计, 字数统计插件 [hexo-symbols-count-time](https://github.com/theme-next/hexo-symbols-count-time)
- 站内搜索功能数据库 [hexo-generator-searchdb](https://github.com/theme-next/hexo-generator-searchdb)
- 站内搜索功能 [hexo-generator-search](https://github.com/wzpan/hexo-generator-search)
- RSS订阅功能插件 [hexo-generator-feed](https://github.com/hexojs/hexo-generator-feed)

### 更多

#### 文章管理

##### 更改静态文件中asset文件夹地址

这样插入图片不再一定要用hexo提供的语法, 就用markdown语法就可以

🔗 [更改方
式](https://leojhonsong.github.io/About-My-Custom-Settings-of-My-Next-Theme-Blog-and-Problem-Killing/#Improved-the-arrangement-of-images-in-asset-folder)

##### 将文章md文件按年, 月分类

这样能便于管理文章, 更改`new_post_name`的值就可以了

🔗 [参考](https://www.githang.com/2018/12/22/hexo-new-post-path/)

##### 集成Travis服务

上传写作文件自动生成并部署. 后续考虑采用merge要更新文章的文件到Root分支, 由
travis自动部署的方式进一步减少需要下载到本地的文件数量

🔗 [参考一](https://blessing.studio/deploy-hexo-blog-automatically-with-travis-ci/)
🔗 [参考二](https://www.jianshu.com/p/630d75e4697e)

❗️ 在 travis-ci.com 管理, 而不是 travis-ci.org

#### 站点内容

##### 生成about和categories页面

🔗 [参考](https://theme-next.org/docs/theme-settings/custom-pages)

##### 简约而不硬核的友链页面

next主题的样式会覆盖文章markdown文件中的样式, 需要在
**/themes/uestc-msc/source/css/_common/components/post/post.styl**中设置需要的样
式 (因为友链的元素是在post-body里)

🔗 [参考方案](https://blog.asucreyau.xyz/2018/12/29/hexo-next-customize-link-page)

##### 彩色字体图标

font awesome似乎只提供单色字体图标, 也不够丰富, 而
[Iconfont](https://www.iconfont.cn/?spm=a313x.7781069.1998910419.d4d0a486a)就很
牛皮了, 有丰富的图标, 有多色图标, 也能很容易的集成到网页.

此处采用[symbol引用](https://www.iconfont.cn/help/detail?spm=a313x.7781069.1998910419.d8cf4382a&helptype=code)

1. 首先图省事直接把项目生成的symbol代码添加到整个站点的head, 即
**themes/uestc-msc/layout/_partials/head/head.swig** (目前在line54):

   ```swig
   {%- if theme.iconfont.source %}
   <script src = "https:{{ theme.iconfont.source }}"></script>
   {%- endif%}
   ```

2. 更改**sidebar**中的社交链接使用iconfont

   **themes/uestc-msc/layout/_partials/sidebar/site-overview.swig** line 101:

   ❗️只注释掉原本的font awesome语句, 万一以后还用呢 🤷 ‍

   ```swig
        {#%- set sidebarIcon = '<i class="fa fa-fw fa-' + link.split('||')[1] | trim | default('globe') + '"></i>' %#}
        {% set sidebarIcon = '<svg class="icon" aria-hidden="true"><use xlink:href="#' + link.split('||')[1] | trim + '"></use></svg>' %}
   ```

3. 更改footer中的用户图标使用iconfont

   **themes/uestc-msc/layout/_partials/footer.swig** line13:

   ```swig
       <!-- <i class="fa fa-{{ theme.footer.icon.name }}"></i> -->
       <svg class="icon" aria-hidden="true"><use xlink:href="#{{ theme.footer.icon.name }}"></use></svg>
    ```

4. 将彩色字体图标的样式添加到**`themes/uestc-msc/source/css/main.styl**:

   ```styl
   svg.icon {
       width: 1.5em !important;
       height: 1.5em !important;
       vertical-align: -0.4em;
       fill: currentColor;
       overflow: hidden
   }
   ```

   🔗 [参考操作](https://leojhonsong.github.io/About-My-Custom-Settings-of-My-Next-Theme-Blog-and-Problem-Killing/#Colorful-icons-for-social-links-in-sidebar)
