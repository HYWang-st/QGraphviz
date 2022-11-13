#include "Generategraph.h"
void GenerateGraph::Draw_Start(int linemode)
{
    FILE* fp = fopen(file_for_tmp.c_str(), "w");
    if (linemode == DiGraph)
        fprintf(fp, " digraph my_graph{\n node [fontname=\"FangSong\"];\n");
    else if (linemode == Graph)
        fprintf(fp, "graph my_graph{\n node [fontname=\"FangSong\"];\n");
    fclose(fp);
}

void GenerateGraph::Node_Create(std::string node_name,int nodemode)
{
    FILE* fp = fopen(file_for_tmp.c_str(), "a");
    string type;//
    if(nodemode==1) type="[shape=box]";
    else if(nodemode==0) type="";
    else type="";
    string node_type=node_name.c_str()+type;
    fprintf(fp, "\t%s;\n", node_type.c_str());

    fclose(fp);
    //return node_count;//返回标号
}

void GenerateGraph::Line_Create(std::string start_name, std::string left_name, std::string right_name, int nodemode,int linemode , string label)
{
    Node_Create(start_name,nodemode);
    if(left_name!="")Node_Create(left_name,nodemode);
    if(right_name!="")Node_Create(right_name,nodemode);

    FILE* fp = fopen(file_for_tmp.c_str(), "a");
    fprintf(fp, "\t%s ", start_name.c_str());

    if (linemode == DiGraph) {
        fprintf(fp, " -> ");
    }
    else if (linemode == Graph) {
        fprintf(fp, " -- ");
    }
    fprintf(fp, " %s ", "{");
    fprintf(fp, " %s ", left_name.c_str());
    fprintf(fp, " %s ", " ");
    fprintf(fp, " %s ", right_name.c_str());
    fprintf(fp, " %s ", "}");
    if (label != std::string("")) {
        fprintf(fp, "[label=%s]", label.c_str());
    }

    fprintf(fp, ";\n");

    fclose(fp);
    //return ++relation_count;
}

void GenerateGraph::Draw_End()
{
    FILE* fp = fopen(file_for_tmp.c_str(), "a");

    fprintf(fp, "}");

    fclose(fp);
}

void GenerateGraph::Make_Dot(std::string file_path)
{
    std::ifstream in(file_for_tmp.c_str());
    std::ofstream out(file_path.c_str());
    out << in.rdbuf();
    in.close();
    out.close();
}

void GenerateGraph::Get_Jpg(std::string file_path)
{
    std::string command = "dot -Tjpg -Gdpi=500 " + file_for_tmp + " -o " + file_path;
    system(command.c_str());
}

bool GenerateGraph::Draw_for_Tree(std::string* s,int n,int nodemode,int linemode , string label) {
    int i = 0;
    if(n==0)return false;
    while (i<n)
    {
        if (i * 2 + 2 < n) {
            Line_Create(s[i], s[i*2+1], s[i*2+2],nodemode,linemode,label);
            i++;
        }
        else if (i * 2 + 1 < n) {
            Line_Create(s[i], s[i * 2 + 1], "",nodemode,linemode,label);
            i++;
        }
        else if (i < n)
        {
            Line_Create(s[i], "", "",nodemode,linemode,label);
            i++;
        }
        else break;
    }
    return true;
}

bool GenerateGraph::Make_Tree(std::string* s,int n,int nodemode,int linemode , string label ){
    Draw_Start(linemode);
    bool flag=Draw_for_Tree(s,n,nodemode,linemode,label);
    Draw_End();
    return flag;
}

bool GenerateGraph::Draw_for_Free(std::string* s,int n,int nodemode,int linemode , string label ) {
    int i = 0;
    if(n%2!=0||n==0){
        return false;
    }
    while (i<n)
    {   if(i+1<n){
            Line_Create(s[i], s[i + 1], "", nodemode,linemode,label);
            i++;
        }
        i++;
    }
    return true;
}

bool GenerateGraph::Make_Free(std::string* s,int n,int nodemode,int linemode, string label){
    Draw_Start(linemode);
    bool flag=Draw_for_Free(s,n,nodemode,linemode,label);
    Draw_End();
    return flag;
}

