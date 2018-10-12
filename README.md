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

