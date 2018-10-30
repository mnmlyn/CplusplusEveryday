每天学习C++，将各种容易遗忘的知识点，进行总结和重复
# 001.函数指针(7.10节)
```cpp
//函数原型
const double * func1(const double *,int);
//声明函数指针，赋值
const double * (*fp1)(const double *,int);
fp1 = func1;//函数指针赋值
const double * (*fp2)(const double *,int) = func1;//声明并赋值
auto fp3 = func1;//可以使用自动类型推断
//使用函数指针调用函数
const double * p1 = (*fp1)(1.1, 2);
const double * p2 = fp1(1.1, 2);//可以省略解引用运算符*
//包含三个函数指针的数组
const double * (*arfp1[3])(const double *,int) = {func1,fp1,fp2};
auto arfp2 = arfp1;
//调用函数指针数组中的函数
const double * pa = (*arfp1[0])(1.1, 2);
const double * pb = arfp1[0](1.1, 2);//可以省略*
//得到函数返回值的指针（const double *）指向的double数值
double a = *(*arfp1[0])(1.1, 2);
double b = *arfp1[0](1.1, 2);
//指向整个指针数组的指针
//在上边的声明中，arfp1是数组名，所以类型与指向数组元素的指针相同
auto parfp1 = &arfp1;//指向数组arfp1的指针
const double * (*(*parfp2)[3])(const double *,int) = &arfp1;
//使用指向函数指针数组的指针，调用函数
const double * pc = (*(*parfp1)[0])(1.1, 2);
const double * pd = (*parfp1)[0](1.1, 2);//使用函数指针可以省略*
//使用typedef进行简化
typedef const double * (*P_Func_t)(const double *,int);
						//函数指针类型，别名为P_Func_t
P_Func_t fp4 = func1;//函数指针声明及赋值
//简化上边的变量定义
P_Func_t arfp3[3] = {func1,fp1,fp2};//函数指针数组
P_Func_t (*parfp3)[3] = &arfp1;//指向‘3个函数指针组成的数组’的指针
```
1. 声明函数指针的数组，第一次声明，不能用auto。**自动类型推断只能用于单值初始化，而不能用于初始化列表**。已经声明数组fpar1之后，再次声明fpar2，则可以使用auto。
2. 运算符优先级，**方括号和圆括号，比\*的优先级高**。举例：

   + `int * p[3];`p首先与方括号结合，p首先是一个数组，数组中的每个元素都是`int *`类型。因此，p是一个int \*指针组成的数组。
   + `int (*p)[3];`p首先与*结合，p首先是一个指针，指向的元素为3个整形元素的数组。
3. 数组名arr和数组名取地址&arr的差别。`int arr[3];`中，arr为数组名，也是数组第一个元素的地址。&arr为整个数组的地址。从数字上来说，arr与&arr的值相同，但是他们的类型不同。arr+1为数组中下标为1的元素的地址，*(arr+1)为下标为1的元素的值。&arr+1为arr之后的int [3]类型的地址块的地址。
4. 三个相同的函数原型
```
const double * f1(const double ar[],int n);
const double * f1(const double [],int);
const double * f1(const double *,int);
```
# 002.数组名和指针的区别(7.3节)
对于函数声明和定义，`int arr[]`和`int * arr`是等价的。
```cpp
int func1(int arr[],int n);
int func2(int *arr,int n);
```
数组名和指针的区别：

- sizeof作用于数组名，得到整个数组的大小（字节为单位）
- 地址运算符&作用于数组名，将返回整个数组的地址

`arr[i]`与`*(arr + i)`总是相同
# 003.使用cin输入数据并处理错误(7.3节)
```cpp
//示例输入一个double型数据，并判断输入是否合法
double temp;
cout << "Input:";
cin >> temp;
if(!cin){	//bad input
	cin.clear();
	while(cin.get() != '\n')
		continue;
}
cout << "Input Error!\n";
```
或者，一直要求输入，直到输入正确
```cpp
double temp;
cout << "Input:";
while(!(cin >> temp)){
	cin.clear();
	while(cin.get() != '\n')
		continue;
	cout << "Input:";
}
cout << "Input = " << temp << endl;
```
# 004.指向const值的指针和const指针(7.3节)
```cpp
int age = 20;
const int * p1 = &age;
int * const p2 = &age;
const int * const p3 = &age;
```
`p1`为，指向const int类型的指针，因此，不能通过`*p1`来修改`age`
`p2`为，指向int类型的const指针，因此，不能修改`p2`指向其他地址
`p3`为，指向const int类型的const指针，因此，`*p3`和`p3`均不能修改
# 005.二维数组与函数(7.4节)
二维数组，即预期函数调用如下
```cpp
int data[3][2] = {{1,2},{3,4},{5,6}};
int total = sum(data,3);
```
则传入参数为二维数组的函数声明应如下
```cpp
int sum(int (*arr)[2],int n);
//或者
int sum(int arr[][2],int n);
```
如何看待这些符号呢？按照结合顺序即可。
`int data[3][2]`，data先与[3]结合，再与int [2]结合，因此，data是一个有3个元素的数组，数组中的每个元素为“有2个整形元素的数组”。
`int (*arr)[2]`，arr先与*结合，再与int [2]结合，因此，arr是一个指针，指向“有2个整形元素的数组”。
`int arr[][2]`，与`int (*arr)[2]`相同，在函数声明中，`arr[]`与`*arr`是相同的，都指示arr是一个数组

另外，
`arr[r][c]`与`*(*(arr + r) + c)`相同
因为，`arr[r]`==`*(arr + r)`



