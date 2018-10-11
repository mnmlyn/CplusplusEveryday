每天学习C++，将各种容易遗忘的知识点，进行总结和重复
```
	dfs
	fdsf
```
# 001.函数指针(7.10节)
1. 获取函数地址  
函数`double func(int x);`，函数的地址为func。  
2. 声明函数指针  
 - 声明函数指针*pf，写为`double (*pf)(int);`  
 - 函数为`double *func1(int x);`，函数指针pf1声明为`double *(*pf1)(int);`  
 赋值`pf1=func1`;
3. 使用函数指针来调用函数  
 - `(*pf)(2)`或`pf(2)`都是正确的。  
 第一种可能更符合指针的概念，pf为指向函数的指针，使用*进行解引用得到指针。
4. 三个相同的函数原型

  

  
```
const double * f1(const double ar[],int n);
const double * f1(const double [],int);
const double * f1(const double *,int);
```

