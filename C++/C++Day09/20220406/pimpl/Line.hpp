 ///
 /// @file    Line.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2022-04-06 11:48:17
 ///
 
#ifndef __WD_LINE_HPP__
#define __WD_LINE_HPP__

//设计模式:PIMPL
//好处:
//1. 实现信息隐藏
//2. 在接口是固定的情况下，如果要升级库，可以以最小的代价
//完成库的升级(只需要用新的库替换原来的库即可)
//
//
//如果跨公司开发时，交给别人的是
//一个头文件和动态库/静态库
//
//当成一个接口来使用
class Line
{
public:
	Line(int,int,int,int);
	~Line();
	void printLine() const;
private:
	class LineImpl;//内部类， 类的前向声明
private:
	LineImpl * _pimpl;
};
 
 
 
#endif
