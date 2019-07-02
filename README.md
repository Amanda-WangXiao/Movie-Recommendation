# Movie-Recommendation
## 说明

​	本影视推荐系统根据电影影评获取电影属性，根据用户自身的影评生成用户属性。再根据用户属性和电影属性进行匹配推荐。

## 模块

### 语料库&语料库爬取模块

​	语料库是通过语料库爬取模块爬取在豆瓣上的用户影评和电影影评而生成的。

### 数据预处理模块

​	数据预处理模块根据爬取的语料生成电影分类词典和影视词库。

### 影视推荐模块

​	此模块根据预处理模块数据用以确定用户和电影属性评分从而推荐。

## 整体流程

​	信息收集阶段通过豆瓣网站获取影评、从百科定义中获取各个类型电影的定义。之后对百科定义进行分词、去除停用词、并且构建电影分类词典。豆瓣影评也是通过分词、去除停用词后构建评论词库。最后通过这两个词库生成属性评分，再根据属性评分进行匹配推荐。

![流程图](https://github.com/clopen/Movie-Recommendation/blob/master/pic/流程图.png)

## 环境

* 整体所需要的环境是：python2、python3
* 其中用到的库有requests库、bs4库、fake_useragent库、pkuseg库
* 另外还需要pe文件执行环境

## 语料库

* 本语料库中分为“电影影评”和“用户影评”

* 其中“用户影评”为一个用户近期以来的十条评论，用以确定用户的属性

* 其中“电影影评”为一个电影的前五页的评论，用以确定电影的属性

  如果需要增加数据，请使用user_reviews.py和movie_reviews.py爬取数据  
  环境：  
  python2  
  requests库  
  fake_useragent库（可选）

  ### 爬虫程序说明

   	其中proxies可自行更改可用爬虫代理，所爬取到的数据存入的文件的文件名，请将open的第一个参数改为自己所需要的名称。如果需要更改爬取数目以增加识别精度，请修改final_page变量为想要的页数（用户评论一页10条，电影评论一页20条）。
  	本脚本文件使用方法可以参考youtube视频：[爬虫演示](https://youtu.be/pgurXdp_-T4)

  #### demo

  ​	爬取电影影评![爬取电影影评](https://github.com/clopen/Movie-Recommendation/blob/master/pic/爬取电影影评.png)
  ​	爬取结果![爬取结果](https://github.com/clopen/Movie-Recommendation/blob/master/pic/爬取结果.png)
  ​	爬取用户影评![爬取用户影评](https://github.com/clopen/Movie-Recommendation/blob/master/pic/爬取用户影评.png)
  ​	爬取用户影评结果![爬取用户影评结果](https://github.com/clopen/Movie-Recommendation/blob/master/pic/爬取用户影评结果.png)

  ### 语料说明

  ​	

|          | 来源                    | 作用             | 数目        |
| -------- | ----------------------- | ---------------- | ----------- |
| 用户评论 | 豆瓣，同一用户近期评论  | 用以确定用户属性 | 10条        |
| 电影评论 | 豆瓣，同一电影前5页评论 | 用以确定电影属性 | 5页每页20条 |

  每条评论之间以等号串进行分隔。

  ### 版权说明

  ​	本语料库出于非商业目的，如果有侵权，请在issue下面留言。

  ## 预处理模块

  Data Pre-Processing文件夹中包含5个自动化脚本：

  * seg.py 单一文件分词脚本
  
  * clean.py 去除停用词脚本
  
  * dictionary.py 构建词典脚本
  
  * count.py 词数统计脚本
  
  * whileseg.py 批量分词脚本
  
    脚本使用方法可以见：[Data Pre Processing预处理演示](https://youtu.be/vkSzZB35240)
    
    ### 所需环境
    
    python3版本，需要实现安装pkuseg库。
    
    ### demo
    
    ​	影评清洗![影评清洗](https://github.com/clopen/Movie-Recommendation/blob/master/pic/影评清洗.png)    
    ​	影评清洗结果![影评清洗结果](https://github.com/clopen/Movie-Recommendation/blob/master/pic/影评清洗结果.png)    
    ​	电影定义![电影定义](https://github.com/clopen/Movie-Recommendation/blob/master/pic/电影定义.png)    
    ​	电影分类词典![电影分类词典](https://github.com/clopen/Movie-Recommendation/blob/master/pic/电影分类词典.png)



  ## 推荐模块

  ​	使用方法及视频demo可以见：[Recommendation推荐过程演示](https://youtu.be/v9lWlXT02eY)

  ![推荐模块流程](https://github.com/clopen/Movie-Recommendation/blob/master/pic/推荐模块.png)

  ​	输入时movie-word和user-word，也就是电影评论词库和用户评论词库。输出就是用户和电影的属性以及推荐电影。

   ### 所需环境

​	  	pe文件执行环境。

   ### demo

  ​		电影-流浪地球![电影-流浪地球](https://github.com/clopen/Movie-Recommendation/blob/master/pic/电影-流浪地球.jpg)
  ​		电影-夏洛特烦恼![电影-夏洛特烦恼](https://github.com/clopen/Movie-Recommendation/blob/master/pic/电影-夏洛特烦恼.jpg)
  ​		用户-叶子阿姨![用户-叶子阿姨](https://github.com/clopen/Movie-Recommendation/blob/master/pic/用户-叶子阿姨.jpg)  
  ​		用户-彩蛋君![用户-彩蛋君](https://github.com/clopen/Movie-Recommendation/blob/master/pic/用户-彩蛋君.jpg)



  ## 使用说明

  ​	本程序使用时需要运行movie_attr.bat用以获取电影属性评分，运行user_attr.bat用以获取用户属性评分。

  ​	**注意：使用此批处理文件时一定需要预装好<u>整体</u>所需环境，否则会失败！！**

  

## 参考文献

[1]王侨云,朱广丽,张顺香.基于词间距和点互信息的影评情感词库构建[J].阜阳师范学院学报(自然科学版),2019,36(02):40-46.  
[2]王婷婷.字符串模糊匹配算法的探讨[J].现代计算机(专业版),2012(01):12-15.  
[3]S_H-A_N.基于情感词典的情感分析[EB/OL].https://blog.csdn.net/lom9357bye/article/details/79058946,2018-1--19.  
[4]刘鹏.利用网络爬虫技术获取他人数据行为的法律性质分析[J].信息安全研究,2019,5(06):548-552.  
[5]黄克敏.网站信息安全之反爬虫策略[J].保密科学技术,2018(10):62-63.
