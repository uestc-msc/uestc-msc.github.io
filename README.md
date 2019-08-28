# uestc-msc.github.io

## 配置记录

### hexo插件

- 一键git部署插件 [hexo-deployer-git](https://github.com/hexojs/hexo-deployer-git)
- emoji渲染插件 [hexo-filter-github-emojis](https://www.npmjs.com/package/hexo-filter-github-emojis)
- 文章阅读时间估计, 字数统计插件 [hexo-symbols-count-time](https://github.com/theme-next/hexo-symbols-count-time)
- 站内搜索功能数据库 [hexo-generator-searchdb](https://github.com/theme-next/hexo-generator-searchdb)
- 站内搜索功能 [hexo-generator-search](https://github.com/wzpan/hexo-generator-search)
- RSS订阅功能插件 [hexo-generator-feed](https://github.com/hexojs/hexo-generator-feed)

### 其他

- 更改静态文件中文章asset文件夹位置, 这样插入图片不再一定要用hexo提供的语法, 就
  用markdown语法就可以

  🔗 [更改方式](https://leojhonsong.github.io/About-My-Custom-Settings-of-My-Next-Theme-Blog-and-Problem-Killing/#Improved-the-arrangement-of-images-in-asset-folder)

- 简约而不硬核的友链页面. next主题的样式会覆盖文章markdown文件中的样式, 需要在
  **/themes/uestc-msc/source/css/_common/components/post/post.styl**中设置需要的
  样式 (因为友链的元素是在post-main里)

  🔗 [参考方案](https://blog.asucreyau.xyz/2018/12/29/hexo-next-customize-link-page)

- 集成Travis服务, 上传写作文件自动生成并部署. 后续考虑采用merge要更新文章的文件
  到Root分支, 由travis自动部署的方式进一步减少需要下载到本地的文件数量

  🔗 [参考一](https://blessing.studio/deploy-hexo-blog-automatically-with-travis-ci/)  
  🔗 [参考二](https://www.jianshu.com/p/630d75e4697e)
