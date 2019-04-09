//参考：http://www.cplusplus.com/reference/list/list/
#include <iostream>
#include <list>
#include <utility>//for move

int main(int argc, char **argv) {
    //std::list是基于双向链表的顺序容器
    //构造函数
    //空；n；n，val；范围；copy；move；初始化列表
    std::list<int> list1;
    std::list<int> list2(2);//两个元素
    std::list<int> list3(2,1);//两个元素，都赋值1
    std::list<int> list4(list3);//复制构造
    std::list<int> list5(list3.begin(),list3.end());//范围构造
    std::list<int> list6(std::move(list3));//移动构造，list3不可用
    std::list<int> list7({1,2,3,4});//初始化列表构造
    
    //打印双向链表
    for(int &x:list4)std::cout << x << " ";
    std::cout << std::endl;

    //assign()为双向链表分配新的值，链表大小被修改
    //范围；n，val；初始化列表
    list2.assign(list4.begin(),list4.end());
    list1.assign(5,3);//大小5，全部赋值3
    list3.assign({1,2,3,4,5});

    for(int &x:list3)std::cout << x << " ";
    std::cout << std::endl;

    //back()返回最后一个元素的引用，若list为空，未定义行为
    int back_elem = list3.back();
    std::cout << back_elem << std::endl;
    //front()
    int front_elem = list3.front();
    std::cout << front_elem << std::endl;

    //begin()返回指向第一个元素的（双向）迭代器
    //若list中对象为const的，则返回一个const迭代器
    //若容器为空，返回的迭代器不能被解引用
    std::list<int>::iterator it1 = list3.begin();
    std::cout << *it1 << std::endl;
    //end()返回理论上在最后一个元素后边的迭代器
    //若容器空，返回begin()相同
    std::list<int>::iterator it2 = list3.end();
    std::cout << *(--it2) << std::endl;//这是bidirectional_iterator，不支持it+n操作，但是支持++和--操作
    it2 = list3.end();
    ++it2;++it2;
    std::cout << *(++it2) << std::endl;//神奇的是，end指向的是双向链表的头，这说明list实现的是双向循环链表



}
