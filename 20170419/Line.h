 ///
 /// @file    Line.h
 /// @author  Xzzzh(sjzxzh@yeah.net)
 /// @date    2017-04-19 19:52:52
 ///
 
#ifndef __MY_LINE_H__
#define __MY_LINE_H__

//设计模式之：Pimpl
//优点1：实现信息隐藏,隐藏了数据成员的具体情况和函数成员的实现
//优点2：减少编译依赖，在升级版本库过程中，可以向前进行兼容（实现二进制兼容性）

class Line
{
//private:
	class LineImpl;//前向声明
public:
	Line(int x1, int y1, int x2, int y2);//构造函数
	void printLine();//打印函数
	~Line();//析构函数

private:
	LineImpl * _pimpl;//将数据成员定义为一个类，以此类的指针作为真正的成员
};

#endif
