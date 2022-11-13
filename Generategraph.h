#ifndef GENERATEGRAPH_H
#define GENERATEGRAPH_H
#pragma once
#include <string>
#include <fstream>
#include<iostream>
#include<QMessageBox>
using namespace std;
class GenerateGraph
{
private:
    string file_for_tmp = "./temp_for_dot.tp";
public:
    static const int Elliptical=0,Rectangle=1;
    static const int Graph = 0,DiGraph = 1;

    void Draw_Start(int linemode);//画图模式
    void Node_Create(string node_name,int nodemode);//创建一个节点，并且节点名称为node_name,结点模式为nodemode
    void Line_Create(string start_name, string left_name,string right_name, int nodemode=0,int linemode = 0, string label = "");
    //支持自定义label,需自行设置参数
    void Draw_End();//结束画图

    void Make_Dot(string file_path);//写dot
    void Get_Jpg(string file_path);//画图

    bool Draw_for_Tree(string* s,int n,int nodemode=0,int linemode = 0, string label = "");//默认数据以树的层序遍历结果传入
    bool Make_Tree(string*s,int n,int nodemode=0,int linemode = 0, string label = "");
    bool Draw_for_Free(string*s,int n,int nodemode=0,int linemode = 0, string label = "");//数据自由传入
    bool Make_Free(string*s ,int n,int nodemode=0,int linemode = 0, string label = "");
};
#pragma once
#endif // GENERATEGRAPH_H
