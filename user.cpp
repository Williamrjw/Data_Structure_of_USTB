#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int N = 524288;
class HashTable {
private:
    string *elem;
    int size;
public:
    HashTable() {//构造函数
       size = N;
       elem = new string[size];
    }
    ~HashTable() {delete[] elem;}//析构函数
    int hash(string& index) {//求哈希地址
       int code = 0;
       for (size_t i = 0; i <= (index.length()); i++) {  
           code = (code *128 + i*256) % size;
       }
       return code;
    }
    bool search(string& index, int& pos, int& times) {//哈希查找
       pos = hash(index);   //获取哈希地址
       times = 0;//限制最多找size次，否则陷入死循环
       while (elem[pos] != "" && elem[pos] != index) {    //发生冲突
          times++;
           if (times < size) {
              pos = (pos + 1) % size;   //哈希表的开放地址法的线性探测法,解决冲突的一种方法
           } else {
              return false;
           }
       }
       if (elem[pos] == index) {
           return true;
       } else {
           return false;
       }
    }
    int insert(string& index) {//哈希插入
       int pos, times;
       if (search(index, pos, times)) {//如果找到了，就说重复yes
           return 2;     //表示已经存在
       } else if (times < size / 2) {
           elem[pos] = index;
           return 1;   //表示插入成功
       } else {
           cout<<"重新构建吧，睿智死大蒜"<<endl;
           return 0;  //表示插入失败
       }
    }
};
int main() {
	int n;
	int i, j;
    HashTable hashtable;
	string id;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> id;
		transform(id.begin(), id.end(), id.begin(), ::toupper);
        j=hashtable.insert(id);
        switch(j){
            case 0:cout<<"Yes"<<endl;break;
            case 1:cout<<"No"<<endl;break;
            case 2:cout<<"Yes"<<endl;break;
            default:break;
        };
	}
	return 0;
}
//YOU SHIT GARLIC ! DON'T LET ME HIT YOU
//Thank for the hint and help of 
//http://blog.sina.com.cn/s/blog_a3fb1fe30102vw1j.html