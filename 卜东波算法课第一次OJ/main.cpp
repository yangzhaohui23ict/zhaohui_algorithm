#include <iostream>
#include<vector>
#include<string>
#include<cmath>
#include <iomanip>
#include<sstream>
#include<map>
#include<set>
#include <queue>
using namespace std;

//        humidex = temperature + h
//        h = (0.5555)¡Á (e - 10.0)
//        e = 6.11 ¡Á exp [5417.7530 ¡Á ((1/273.16) - (1/(dewpoint+273.16)))]


double gett(double d,double h){
    double e= 6.11 * exp (5417.7530 * ((1/273.16) - (1/(d+273.16))));
    double hcan=(0.5555)*(e - 10.0);
    return h-hcan;
}


double getd(double t,double h){
    double hcan=h-t;
    double e=hcan/0.5555+10;
    return 1/(1/273.16-log(e/6.11)/5417.7530)-273.16;
}

double geth(double t,double d){
    double e= 6.11 * exp (5417.7530 * ((1/273.16) - (1/(d+273.16))));
    double hcan=(0.5555)*(e - 10.0);
    return t+hcan;
}


void func1()
{
    string str;
    vector<string> input;
    while(1){
        getline(cin,str);
        if(str=="E"){
            break;
        }
        input.push_back(str);
    }

    for(int i=0;i<input.size();i++){
        vector<string> words;
        string data=input[i]+" ";
        int pos = data.find(" ");
        while (pos!=-1){
            string temp = data.substr(0, pos);
            words.push_back(temp);
            data=data.substr(pos+1,data.size());
            pos=data.find(" ");
        }

//        shuju[0]=stod(words[1]);
//        shuju[1]=stod(words[3]);

        map<char,double> tu;

        double data1,data2;

        stringstream sstream;
        sstream<<words[1];
        sstream>>data1;
        sstream.clear();
        sstream<<words[3];
        sstream>>data2;

        tu.insert(pair<char,double>(words[0][0],data1));
        tu.insert(pair<char,double>(words[2][0],data2));

        if(tu.find('T')==tu.end()){
            tu.insert(pair<char,double>('T',gett(tu['D'],tu['H'])));
        }
        if(tu.find('D')==tu.end()){
            tu.insert(pair<char,double>('D',getd(tu['T'],tu['H'])));
        }
        if(tu.find('H')==tu.end()){
            tu.insert(pair<char,double>('H',geth(tu['T'],tu['D'])));
        }


        cout<<"T"<<" "<< fixed << setprecision(1)<<tu['T']<<" "<<"D"<<" "<< fixed << setprecision(1)<<tu['D']<<" "<<"H"<<" "<< fixed << setprecision(1)<<tu['H']<<endl;

    }

}



void func2()
{
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int a[201]={0};
        while(N--){
            int left,right;
            cin>>left>>right;
            left=(left-1)/2;
            right=(right-1)/2;
            if(left>right){
                swap(left,right);
            }

            for(int i=left;i<=right;i++){
                a[i]++;
            }
        }
        int maxx=0;
        for(int i=0;i<200;i++){
            if(maxx<a[i]){
                maxx=a[i];
            }
        }
        cout<<10*maxx<<endl;
    }
    return;
}






void func3()
{
    int T;
    cin>>T;
    cin.ignore();
    while(T--){
        map<char,bool> judge;
        map<char,int> wei;
        for(char i='A';i<='L';i++){
            judge.insert(pair<char,bool>(i,true));
            wei.insert(pair<char,bool>(i,0));
        }
        vector<vector<string>> words_list;
        for(int i=0;i<3;i++){
            string str;
            vector<string> words;
            for(int j=0;j<3;j++){
                cin>>str;
                words.push_back(str);
            }
            if(words[2]=="even"){
                for(int j=0;j<words[0].length();j++){
                    judge[words[0][j]]=false;
                    judge[words[1][j]]=false;
                }
            }
            else{
                for(char i='A';i<='L';i++){
                    if(words[0].find(i)==-1&&words[1].find(i)==-1){
                        judge[i]=false;
                    }
                }
                for(int j=0;j<words[0].length();j++){
                    if(words[2]=="up"){
                        if(wei[words[0][j]]==0||wei[words[0][j]]==1){
                            wei[words[0][j]]=1;
                        }
                        else{
                            judge[words[0][j]]=false;
                        }
                        if(wei[words[1][j]]==0||wei[words[1][j]]==-1){
                            wei[words[1][j]]=-1;
                        }
                        else{
                            judge[words[1][j]]=false;
                        }
                    }
                    if(words[2]=="down"){
                        if(wei[words[0][j]]==0||wei[words[0][j]]==-1){
                            wei[words[0][j]]=-1;
                        }
                        else{
                            judge[words[0][j]]=false;
                        }
                        if(wei[words[1][j]]==0||wei[words[1][j]]==1){
                            wei[words[1][j]]=1;
                        }
                        else{
                            judge[words[1][j]]=false;
                        }
                    }
                }
            }
            words_list.push_back(words);
        }
        for(char i='A';i<='L';i++){
            if(judge[i]==true){
                string typee;
                for(int j=0;j<3;j++){
                    if(words_list[j][2]=="even"){
                        continue;
                    }
                    if(words_list[j][0].find(i)!=-1){
                        typee=words_list[j][2]=="up"?"heavy":"light";
                        break;
                    }
                    if(words_list[j][1].find(i)!=-1){
                        typee=words_list[j][2]=="up"?"light":"heavy";
                        break;
                    }
                }
                cout<<i<<" is the counterfeit coin and it is "<<typee<<"."<<endl;
            }
        }
    }
}

#include <algorithm>
bool cmp(pair<double,double> a,pair<double,double> b)
{
    return a.first<b.first;
}

void func4()
{
    int hao=0;
    while(1){
        hao++;
        int n,l;
        cin>>n>>l;
        if(n==0&&l==0){
            break;
        }
        int candoit=1;
        vector<pair<double,double>> link;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            if(y>l){
                candoit=0;
            }
            link.push_back(pair<double,double>(x-sqrt((double)l*l-y*y),x+sqrt((double)l*l-y*y)));
        }
        if(candoit==0){
            cout<<"Case "<<hao<<": "<<"-1"<<endl;
            continue;
        }
        else{
            sort(link.begin(),link.end(),cmp);
            int ans=0;
            double right;
            for(int i=0;i<link.size();i++){
    //            cout<<link[i].first<<"  "<<link[i].second<<endl;
                right=link[i].second;
                ans++;
                while(link[i].first<=right){
                    i++;
                    right=min(right,link[i].second);
                }
                i--;
            }
            if(candoit==0){
                continue;
            }
            cout<<"Case "<<hao<<": "<<ans<<endl;
        }

    }


}


#include<list>




class Edge; // 前向声明

class Node {
public:
    int value;
    int in;
    int out;
    list<Node*> nexts;
    list<Edge*> edges;

    Node(int value, int in, int out, list<Node*> nexts, list<Edge*> edges) {
        this->value = value;
        this->in = in;
        this->out = out;
        this->nexts = nexts;
        this->edges = edges;
    }
};

class Edge {
public:
    int weight;
    Node* from;
    Node* to;

    Edge(int weight, Node* from, Node* to) {
        this->weight = weight;
        this->from = from;
        this->to = to;
    }
};

class Graph {
public:
    map<int, Node*> nodes;
    set<Edge*> edges;

    Graph(map<int, Node*> nodes, set<Edge*> edges) {
        this->nodes = nodes;
        this->edges = edges;
    }
};



//这个是不可以放到优先队列里面的
bool cmp2(Edge* e1, Edge* e2) {
    return e1->weight < e2->weight;
}


//这个可以
struct CompareEdges {
    bool operator()(const Edge* e1, const Edge* e2) {
        return e1->weight > e2->weight;
    }
};

void Prim(Graph& graph) {

    int min_sum=0;

    map<int, Node*> nodes = graph.nodes;
    set<Edge*> edges = graph.edges;

    set<Node*> visited;


    priority_queue<Edge*, std::vector<Edge*>, CompareEdges> bianji;

//    vector<Edge*> bianji;

    Node* startNode = nodes.begin()->second;

    visited.insert(startNode);

    for (list<Edge*>::iterator it=startNode->edges.begin();it!=startNode->edges.end();it++) {
        bianji.push(*it);
    }

    while(!bianji.empty()){
        Edge* bian=bianji.top();
        bianji.pop();

        Node* toNode = bian->to;

        if(visited.count(toNode)==0){
            visited.insert(toNode);
            min_sum+=bian->weight;
            for(list<Edge*>::iterator it=toNode->edges.begin();it!=toNode->edges.end();it++){
                bianji.push(*it);
            }
        }

    }

    cout<<"The highest possible quality is 1/"<<min_sum<<"."<<endl;


}



void func5()
{
    int N;
    cin>>N;
    vector<string> input;
    vector<int> node;
    map<int,Node*> nodes;
    set<Edge*> edges;
    Graph tu(nodes,edges);
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        input.push_back(str);
        node.push_back(0);
        list<Node*> nexts;
        list<Edge*> edges;
        Node* dian=new Node(0,0,0,nexts,edges);
        tu.nodes.insert(pair<int,Node*>(i,dian));
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            string a=input[i];
            string b=input[j];
            int dis=0;
            for(int k=0;k<a.length();k++){
                if(a[k]!=b[k]){
                    dis++;
                }
            }
            tu.edges.insert(new Edge(dis,tu.nodes[i],tu.nodes[j]));
            tu.edges.insert(new Edge(dis,tu.nodes[j],tu.nodes[i]));
            tu.nodes[j]->in++;
            tu.nodes[j]->out++;
            tu.nodes[i]->in++;
            tu.nodes[i]->out++;
            tu.nodes[j]->nexts.push_back(tu.nodes[i]);
            tu.nodes[i]->nexts.push_back(tu.nodes[j]);
            tu.nodes[j]->edges.push_back(new Edge(dis,tu.nodes[j],tu.nodes[i]));
            tu.nodes[i]->edges.push_back(new Edge(dis,tu.nodes[i],tu.nodes[j]));
        }
    }
    int ling;
    cin>>ling;
    //到这里，完成了数据结构和输入数据的解析，接下来生成最小生成树即可。考虑到并查集太久没用了，还是prim算法好一些。

    Prim(tu);

}



void func_chagnge()
{
    while(1){
        int N;
        cin>>N;
        if(N==0){
            break;
        }
//        vector<vector<int>> tu;
//        int tu[205][205]={0};
        char ch[2005][8];
        vector<string> input;

        for(int i=0;i<N;i++){
            cin>>ch[i];
        }

//        for(int i=0;i<N;i++){
////            vector<int> heng;
//            for(int j=i;j<N;j++){
//                int dis=0;
//                for(int k=0;k<7;k++){
//                    if(ch[i][k]!=ch[j][k]){
//                        dis++;
//                    }
//                }
//                tu[i][j]=dis;
//                tu[j][i]=dis;
//                heng.push_back(dis);
//            }
////            tu.push_back(heng);
//        }

//        vector<int> a;
        int a[2005]={0};
//        for(int i=0;i<N;i++){
//            a.push_back(0);
//        }
        int totalWeight = 0;

//        vector<int> tanc;
        int tanc[2005]={0};
        for(int i=0;i<N;i++){
//            tanc.push_back(tu[0][i]);
            tanc[i]=999;
        }
        int sum=0;
        int min_point=0;
        while(sum!=N){
            a[min_point]=1;
            int min_weight=999;

            for(int j=0;j<N;j++){

                if(a[j]==1){
                    continue;
                }
                int dis=0;
                for(int k=0;k<7;k++){
                    if(ch[j][k]!=ch[min_point][k]){
                        dis++;
                    }
                }
                if(dis<tanc[j]){
                    tanc[j]=dis;
                }
            }
            int flag=1;
            for(int j=0;j<N;j++){
//                if(j<5){
//                    cout<<tanc[j]<<" ";
//                }

                if(a[j]==1){
                    continue;
                }
                if(tanc[j]<min_weight){
                    min_weight=tanc[j];
                    min_point=j;
                    flag=0;
                }
            }

            if(flag){
                break;
            }

            totalWeight+=min_weight;
            sum++;
        }
        cout<<"The highest possible quality is 1/"<<totalWeight<<"."<<endl;
    }
}







void func8()
{
    int N;
    cin>>N;
    vector<vector<int>> bowl;
    vector<int> ans;
    for(int i=1;i<=N;i++){
        vector<int> level;
        vector<int> ceng_ans;
        for(int j=0;j<i;j++){
            int num;
            cin>>num;
            level.push_back(num);
        }
        bowl.push_back(level);
        if(i==1){
            ans=level;
        }
        else{

            ceng_ans.push_back(ans[0]+level[0]);

            for(int j=1;j<i-1;j++){
                ceng_ans.push_back(max(ans[j-1],ans[j])+level[j]);
            }

            ceng_ans.push_back(ans[i-2]+level[i-1]);
            ans=ceng_ans;
        }
    }
    cout<<ans[max_element(ans.begin(), ans.end())-ans.begin()]<<endl;
}






int main()
{
    func_chagnge();
    return 0;
}
