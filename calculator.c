#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>                                                //加载入本代码需要的库

int main ()                                                       //主函数如下
{


    printf("欢迎使用计算器！\n");
    printf("请输入计算方式\n\n");                                 //设置引导文字

    printf("加法请输入    +\n");
    printf("减法请输入    -\n");
    printf("乘法请输入    *\n");
    printf("除法请输入    /\n\n");

    printf("取倒数请输入    ~\n");
    printf("取x的y方请输入  ^\n");
    printf("取根号请输入    @\n");
    printf("取负数请输入    #\n\n");                             //设置八个计算方式供人挑选

    printf("直接退出请输入$  \n\n");                              //设置退出键

    double num1,num2,rslt;                                        //设置变量 num1,num2两算子和rslt=result结果   支持小数
    double lst_rslt = 0.0;                                        //设置变量 lst_rslt=last result上次结果 并初始化 防止出错
    bool hs_rslt = false;                                         //初次计算将has_rslt初始化为0 has_rslt作为观测有没有计算过的标准
    char cal;                                                     //cal设置计算符号存储变量




    while (1)                                                     //保证持续演算的能力

{

    printf("\n计算方式：");

    scanf(" %c",&cal);                                            //从键盘读取计算方法
    while (getchar() != '\n');                                    // 清空残留


/*-----------------------------------------------------------------------下为两数计算代码-------------------------------------------------------------*/



    if (cal == '+' || cal == '-' ||cal == '*' || cal == '/' || cal == '^')//支持5种计算方式

    {

        if ( !hs_rslt ){                                                   //确定是否有过结果

        printf("请输入第一个数=  ");                                       //设置引导文字
        scanf("%lf",&num1);                                                 //统一从键盘读取数字1
        while (getchar() != '\n');                                          // 清空残留


        printf("请输入第二个数=  ");                                       //设置引导文字
        scanf("%lf",&num2);                                                //从键盘读取数字2
        while (getchar() != '\n');                                          // 清空残留
        }

        else{

             num1 = lst_rslt;
             printf("第一个数为 %.2f\n",num1);                                       //设置引导文字

             printf("请输入第二个数=  ");                                       //设置引导文字
             scanf("%lf",&num2);                                                //从键盘读取数字2
             while (getchar() != '\n');                                          // 清空残留
             }


            if( cal == '+'){                                               //加法
                rslt = num1 + num2;
            }

            else if( cal == '-'){                                          //减法
                rslt = num1 - num2;
            }

            else if( cal == '*'){                                          //乘法
                rslt = num1 * num2;
            }

            else if( cal == '^'){                                          //x的y次

                    while (num1 == 0 && num2 < 0){                     //防止0的负数次方出现

                        printf("算式无意义！\n");                      //这里设置防御算法，避免等式无意义
                        printf("请重新输入数字！\n\n");

                        while (getchar() != '\n');                     //清空缓存区内容，保证不会死循环
                        printf("重新输入第一个数!");
                        scanf("%lf",&num1);                            //重新读取数字1
                        while (getchar() != '\n');                                          // 清空残留
                        printf("重新输入第二个数!");
                        scanf("%lf",&num2);                            //重新读取数字2
                        while (getchar() != '\n');                                          // 清空残留
                    }

                    while (num1 < 0 && (int)num2 != num2){             //防止负数的根号出现

                        printf("算式无意义！\n");                      //这里设置防御算法，避免等式无意义
                        printf("请重新输入数字！\n\n");

                        while (getchar() != '\n');                     //清空缓存区内容，保证不会死循环
                        printf("重新输入第一个数!");                   //重新读取数字1
                        scanf("%lf",&num1);
                        while (getchar() != '\n');                                          // 清空残留
                        printf("重新输入第二个数!");
                        scanf("%lf",&num2);                             //重新读取数字2
                        while (getchar() != '\n');                                          // 清空残留
                    }

                rslt = pow(num1,num2);                                  //x的y次计算方程（来自载入的math.h库）

            }

            else if( cal == '/'){                                       //除法
                    while (num2 == 0){                                  //防止除0出现
                        printf("被除数为0，算式无意义！\n");            //这里设置防御算法，避免等式无意义
                        printf("请重新输入数字！\n");
                        while (getchar() != '\n');                      //清空缓存区内容，保证不会死循环
                        scanf("%lf",&num2);                             //重新读取数字2
                        while (getchar() != '\n');                                          // 清空残留
                    }
                rslt = num1 / num2;
            }

        printf("\n");                                                   //让画面更优美易读
        printf("结果为%.2f\n\n",rslt);                                  //显示结果
        printf("%.2f %c %.2f = %.2f \n",num1,cal,num2,rslt) ;       //显示计算式，看着专业一点
        system("pause");                                                // 加在这里，让人看清结果，再按任意键继续

    }

/*------------------------------------------------------------------------下为一数计算代码----------------------------------------------------------------*/

    else if (cal == '~' ||cal == '@' ||cal == '#'  )                     //支持3种计算方法

    {

        if ( !hs_rslt ){

        printf("请输入数字=   ");                                        //设置引导文字
        scanf("%lf",&num1);                                              //统一输入数字1
        while (getchar() != '\n');                                          // 清空残留

        }else {

        num1 = lst_rslt;

        printf("数字为 %.2f\n",num1);

        }


        if (cal == '~'){                                                 //求倒数

                while(num1 == 0){                                        //防止0的倒数

                    printf("算式无意义！\n");                            //这里设置防御算法，避免等式无意义
                    printf("请重新输入数字！");

                    while(getchar() != '\n');                            //清空缓存区内容，保证不会死循环
                    scanf("%lf",&num1);                                  //重新读取数字1
                    while (getchar() != '\n');

                }

            rslt = 1.00 / num1;                                          //倒数公式
            printf("1 / %.2f = %.2f\n",num1,rslt);                         //显示结果
            system("pause");                                             //中间有空隙，提升使用体验，防止一次接一次
        }


           else if (cal == '#'){                                          //求相反数


            rslt = 0 - num1;                                              //求相反数公式
            printf("- ( %.2f ) = %.2f\n",num1,rslt);                      //显示结果
            system("pause");                                              //中间有空隙，提升使用体验，防止一次接一次
        }

           else if (cal == '@'){                                          //求开方


                while(num1 < 0){                                          //这里设置防御算法，避免等式无意义
                    printf("算式无意义！\n");
                    printf("请重新输入数字！");

                    while(getchar() != '\n');                             //清空缓存区内容，保证不会死循环
                    scanf("%lf",&num1);                                   //重新读取数字1
                }

            rslt = sqrt(num1);                                            //求开方公式
            printf("sqrt(%.2f) = %.2f\n",num1,rslt);                       //显示结果
            system("pause");                                              //中间有空隙，提升使用体验，防止一次接一次
        }



    }


/*-----------------------------------------------------------------------下为结束和防乱输算法----------------------------------------------------------------------*/



    else if (cal == '$'){

        printf("已退出计算器，感谢您的使用！\n");                          //结束算法

        break;
    }

    else {

        printf("计算方式错误!\n请重新输入计算符号！\n");                    //防止别人乱输计算符号
        while (getchar() != '\n');                                          //防止污染下一轮循环

        continue;

    }


    lst_rslt = rslt;                                                        //新增代码！实现存储上次结果
    hs_rslt = true;                                                         //此时记为经过一次计算


}


    system("pause");                                                          //设置暂停
    return 0;                                                                 //结束main函数的运行

}




