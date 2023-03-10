# 交通信息查询系统TrafficGraph

## 声明
**请勿抄袭！！！仅供参考！！！！课程作业请自己写！！！！！**

## 一、题目介绍

### [问题描述]

​今天铁路交通网络非常发达，人们在出差、旅游时，不仅关注交通费用，还关注里程和时间。请按照下图设计一个交通查询系统，能够满足旅客查询从任一个城市到另一个城市的最短里程、最低花费、最短时间、最少中转次数等问题。

### [基本要求]

​设计合适的数据结构和算法编写程序完成上述功能，并具有查询界面，能够按照下拉菜单选项进行选择查询。
![图片0](/photo/图片0.png)

## 二、解决的思路和算法思想

为了“满足旅客查询从任一个城市到另一个城市的最短里程、最低花费、最短时间、最少中转次数等问题”的要求，因为每个城市之间里程、时间、花费是呈线性的，三个问题可以归结为一个最短路径问题。可以采用Floyed算法计算多源最短路径，可以达到一次调用即可算出所有点之间的最短路径。虽然Floyed算法时间复杂度达到O(n^3 )，但是与Dijkstra算法对比，其不需要每次计算，在查询系统中显得更加便捷，一次计算后面就无需等待。我的思路是将距离、耗时、花费、边长（固定为1）分别当做权值调用Floyed()得到图类中的Dist[][]与Path[][]。运用FindPath()递归打印路径得到的最优路径，再从Dist[][]矩阵中得到最优路径下的最小权值。

## 三、选择或设计的数据结构说明

首先分析题目的要求，题干给定的是一幅交通图，图的基本存储结构有邻接矩阵法或者邻接表法。本题选用邻接矩阵法存储交通图，我设计了一个图类TrafficGraph，包含顶点信息数组VertexType Vex[]（存储城市名）、邻接矩阵EdgeType Edge[][]、顶点数int VexNum、边数int ArcNum，以及EdgeType Dist[][]矩阵、int Path[][]矩阵。   

其次题干中所给的图中每一条边拥有距离distance、耗时time、花费cost、边长len三种信息，我设计了一个结构体EdgeType存储边的信息，并且为了实现最少中转次数的计算添加了一个数据成员边长len.  
​  
再者，为了方便构造邻接矩阵，我设计一个结构体GraphInfo来输入图的每一条边，GraphInfo包含了起点Vex1、终点Vex2以及边权值EdgeType Weight。初始化一个GraphInfo类型的数组放入每一条边及其信息，然后图类的构造函数会构造出图的邻接矩阵。

## 四、主程序的流程图和主要功能模块流程图

### 主程序流程图
![图片2](/photo/图片2.png)

### 功能模块图
![图片3](/photo/图片3.png)

## 五、运行结果
![图片1](/photo/图片1.png)