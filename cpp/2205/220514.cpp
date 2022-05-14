#include <vector>
#include <tuple>
#include <queue>
#include <iostream>

/**
 * 743. Network Delay Time
 * You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
 * We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
 *
 * Comment: This is Dijkstra's algorithm.
 */

#define 类 class
#define 公共的 public
#define 静态 static
#define 整数 int
#define 标准 std
#define 常量 const
#define 为了 for
#define 规模 size
#define 向量 vector
#define 保留 reserve
#define 当 while
#define 自动 auto
#define 顶部 top
#define 如果 if
#define 继续 continue
#define 主函数 main
#define 真 true
#define 返回 return
#define 开始 begin
#define 结束 end
#define 更大的 greater
#define 最大元素 max_element
#define 推 push
#define 最后原地构造 emplace_back
#define 元组 tuple
#define 空 empty
#define 优先队列 priority_queue
#define 组合 pair
#define 真假 bool
#define 弹出 pop
#define 输出 cout
#define 推到末尾 push_back
#define 左中括号 [
#define 右中括号 ]
#define 左括号 (
#define 右括号 )
#define 等于 =
#define 相等 ==
#define 小于等于 <=
#define 加 +
#define 加加 ++
#define 减减 --
#define 减 -
#define 小于 <
#define 大于 >
#define 左大括号 {
#define 右大括号 }
#define 分号 ;
#define 逗号 ,

类 Solution 左大括号 
公共的:
	静态 整数 networkDelayTime 左括号 常量 标准::向量 小于 标准::向量 小于 整数 大于 大于 & 时间们 逗号 整数 结点数量 逗号 整数 开始结点 右括号 左大括号 
		常量 整数 边的数量 等于 时间们.规模 左括号 右括号 分号 
		标准::向量 小于 标准::元组 小于 整数 逗号 整数 逗号 整数 大于 大于 边们 分号 
		标准::向量 小于 标准::向量 小于 整数 大于 大于 有向图 左括号 结点数量 右括号 分号 
		边们.保留 左括号 边的数量 右括号 分号 
		为了 左括号 整数 循环计数器 等于 0 分号 循环计数器 小于 边的数量 分号 加加 循环计数器 右括号 左大括号 
			边们.最后原地构造 左括号 时间们 左中括号 循环计数器 右中括号 左中括号 0 右中括号 减 1 逗号 时间们 左中括号 循环计数器 右中括号 左中括号 1 右中括号 减 1 逗号 时间们 左中括号 循环计数器 右中括号 左中括号 2 右中括号 右括号 分号 
			有向图 左中括号 时间们 左中括号 循环计数器 右中括号 左中括号 0 右中括号 减 1 右中括号 .推到末尾 左括号 循环计数器 右括号 分号
		右大括号

		标准::向量 小于 整数 大于 距离 左括号 结点数量 逗号 0x6FFFFFFF 右括号 分号 
		标准::向量 小于 真假 大于 访问 左括号 结点数量 右括号 分号 
		减减 开始结点 分号

		标准::优先队列 小于 标准::组合 小于 整数 逗号 整数 大于 逗号 标准::向量 小于 标准::组合 小于 整数 逗号 整数 大于 大于 逗号 标准::更大的 小于 大于 大于 路径们的优先队列 分号 
		路径们的优先队列.推 左括号 左大括号 0 逗号 开始结点 右大括号 右括号 分号 
		距离 左中括号 开始结点 右中括号 等于 0 分号 
		当 左括号 !路径们的优先队列.空 左括号 右括号 右括号 左大括号 
			常量 自动 左中括号 长度 逗号 结点编号 右中括号 等于 路径们的优先队列.顶部 左括号 右括号 分号 
			路径们的优先队列.弹出 左括号 右括号 分号 

			如果 左括号 访问 左中括号 结点编号 右中括号 右括号 
				继续 分号 
			访问 左中括号 结点编号 右中括号 等于 真 分号 

			为了 左括号 整数 边的编号 : 有向图 左中括号 结点编号 右中括号 右括号 左大括号 
				常量 自动 左中括号 来源结点 逗号 目标结点 逗号 边的长度 右中括号 等于 边们 左中括号 边的编号 右中括号 分号 
				如果 左括号 距离 左中括号 目标结点 右中括号 小于等于 距离 左中括号 结点编号 右中括号 加 边的长度 右括号 
					继续 分号 
				距离 左中括号 目标结点 右中括号 等于 距离 左中括号 结点编号 右中括号 加 边的长度 分号 
				路径们的优先队列.推 左括号 左大括号 距离 左中括号 目标结点 右中括号 逗号 目标结点 右大括号 右括号 分号 
			右大括号
		右大括号

		整数 将要返回的值 等于 *标准::最大元素 左括号 距离.开始 左括号 右括号 逗号 距离.结束 左括号 右括号 右括号 分号 
		返回 将要返回的值 相等 0x6FFFFFFF ? 减 1 : 将要返回的值 分号 
	右大括号
右大括号 分号

整数 主函数 左括号 右括号 左大括号 
	标准::输出 << Solution::networkDelayTime 左括号 左大括号 左大括号 2 逗号 1 逗号 1 右大括号 逗号 左大括号 2 逗号 3 逗号 1 右大括号 逗号 左大括号 3 逗号 4 逗号 1 右大括号 右大括号 逗号 4 逗号 2 右括号 分号
	返回 0 分号
右大括号
