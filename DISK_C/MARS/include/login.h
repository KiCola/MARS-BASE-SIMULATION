#ifndef _LOGIN_H_
#define _LOGIN_H_
void func_login1();
void func_login2();
void inputid(char* id, int x1, int y1, int charnum, int color);//输入账号
void inputpassword(char* id, int x1, int y1, int charnum, int color);//输入密码
void lightbutton_admin(int x, int y, int x1, int y1, int color1, int color2, int flag);//改变按钮颜色
//void recoverbutton_admin(int status);恢复按钮颜色
int judge_login(char* id, char* pass);//判断账号密码是否正确
#endif