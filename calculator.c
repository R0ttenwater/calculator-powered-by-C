#include<stdio.h>
#include<stdlib.h> //加载入本代码需要的库

int main ()        //主函数如下
{
    double num1,num2,rslt,memo;         //设置变量 两算子和结果 支持小数
    char cal;

    printf("欢迎使用计算器\n");
    printf("请输入计算方式\n\n");

    printf("加法请输入    +\n");
    printf("减法请输入    -\n");
    printf("乘法请输入    *\n");
    printf("除法请输入    /\n\n");

    printf("取倒数请输入  ~\n");
    printf("取平方请输入  !\n");
    printf("取根号请输入  @\n\n");   //设置七个计算方式供人挑选

    printf("直接退出请输入#\n");
     //设置引导文字

    printf("计算方式：");

    scanf(" %c",&cal);           //从键盘读取计算方法






    if (cal=='+'){               //加法路径

        printf("请输入第一个数=  ");//设置引导文字
        scanf("%lf",&num1);        //从键盘读取数字1

        printf("请输入第二个数=  ");//设置引导文字
        scanf("%lf",&num2);          //从键盘读取数字2

        rslt = num1 + num2;         //得到结果

        printf("结果为%.2f\n",rslt);        //显示结果
        printf("%.2f%c%.2f=%.2f\n",num1,cal,num2,rslt) ;//显示计算式


    }

    else if(cal=='-'){              //减法路径

        printf("请输入第一个数=  ");//设置引导文字
        scanf("%lf",&num1);          //从键盘读取数字1

        printf("请输入第二个数=  ");//设置引导文字
        scanf("%lf",&num2);          //从键盘读取数字1

        rslt = num1 - num2;          //得到结果

        printf("结果为%.2f\n",rslt);        //显示结果
        printf("%.2f%c%.2f=%.2f\n",num1,cal,num2,rslt) ;//显示计算式

    }

    else if(cal=='*'){              //乘法路径

        printf("请输入第一个数=  ");//设置引导文字
        scanf("%lf",&num1);          //从键盘读取数字1

        printf("请输入第二个数=  ");//设置引导文字
        scanf("%lf",&num2);          //从键盘读取数字1

        rslt = num1 * num2;          //得到结果

        printf("结果为%.2f\n",rslt);        //显示结果
        printf("%.2f%c%.2f=%.2f\n",num1,cal,num2,rslt) ;//显示计算式

    }

    else if(cal=='/'){              //除法路径

        printf("请输入第一个数=  ");//设置引导文字
        scanf("%lf",&num1);          //从键盘读取数字1

        printf("请输入第二个数=  ");//设置引导文字
        scanf("%lf",&num2);          //从键盘读取数字1


        while (num2 == 0){
            printf("被除数为0，算式无意义！\n");//这里设置防御算法，避免等式无意义
            printf("请重新输入数字！\n");
            while (getchar() != '\n');           //清空缓存区内容，保证不会死循环
            scanf("%lf",&num2);                   //重新读取数字2
        }
        rslt = num1 / num2;          //得到结果


        printf("结果为%.2f\n",rslt);        //显示结果
        printf("%.2f%c%.2f=%.2f\n",num1,cal,num2,rslt) ;//显示计算式
    }




    system("pause");                       //空格结束
    return 0;                              //结束main函数的运行

}




