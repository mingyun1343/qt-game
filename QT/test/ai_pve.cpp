#include "DataStruct.h"

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <windows.h>

#define PI 3.1415926
#define UNUSED(x) (void)x;
#define random(x) rand() % (x)
#define SIGN(x) ((x < 0 ) ? 1 : 0 )

//产生超时故障
void timeoutFault()
{
    Sleep(1000);
}

//产生崩溃故障
void crashFault()
{
    exit(0);
}

//随机生成故障
void randGenFault()
{
    //创建静态初始化标志
    static bool initFlag = false;
    //产生随机数种子
    if (!initFlag)
    {
        srand((int)time(NULL));
        initFlag = true;
    }
    //随机生成故障
    switch (random(3)) {
    case 0:
        timeoutFault();
    case 1:
        crashFault();
    }
}

//角度坐标系转换
inline double angleConver(double angle)
{
    return -90 - angle;
}

//抽取向量点乘
inline double vecMul(double x0, double y0, double x1, double y1)
{
    return x0 * x1 + y0 * y1;
}

//抽取向量取模
inline double vecMod(double x, double y)
{
    return sqrt(x * x + y * y);
}

/* 瞄准某个球
 * 参数：data：游戏数据，ball_x、ball_y：球当前位置，ball_v_x、ball_v_y：球当前速度，leftward、rightward：返回动作
 * 返回值：0：瞄准成功，-1：瞄准失败
 */

bool prebollsPos(BALLSTRUCT*, int, float& , float& ,float&,float&);
int AimBall(DataStruct *data, BallStruct &ball, int &leftward, int &rightward)
{

    float ball_x = ball.x, ball_y = ball.y;
    float ball_v_x = ball.v_x, ball_v_y = ball.v_y;
    float ball_v=vecMod(ball_v_x,ball_v_y);

    double distance_x=fabs(data->plane1.x-ball_x);
    double distance_y=fabs(data->plane1.y-ball_y);
    double distance=vecMod(distance_x,distance_y);

    //瞄准的角度
    double angleTo, angleDiff;
    //球运动方向和飞机与球位置向量的夹角余弦
    double cosPosV;
    //两向量点乘除以两向量的模
    cosPosV = vecMul(ball_v_x, ball_v_y, data->plane1.x - ball_x, data->plane1.y - ball_y)
            / vecMod(ball_v_x, ball_v_y) / vecMod(data->plane1.x - ball_x, data->plane1.y - ball_y);

    double a=1500*1500-ball_v*ball_v;
    double b=2*cosPosV*distance*ball_v;
    double c=-1*distance*distance;
    double t1=(-1*b-sqrt(b*b-4*a*c))/(2*a);
    double t2=(-1*b+sqrt(b*b-4*a*c))/(2*a);
    double t;
    if(t1>=0){t=t1;}
    else{t=t2;}

         int ball_r=ball.r;
        int yy=ball_y + t * ball_v_y - data->plane1.y,xx=ball_x + t * ball_v_x - data->plane1.x;

        if((ball_y + t * ball_v_y) > 1500){
            yy=3000-2*ball_r-ball.v_y*t-ball.y- data->plane1.y;
        }
        if((ball_y + t * ball_v_y) < 0){
            yy=2*ball_r-ball.y-ball.v_y*t- data->plane1.y;
        }
        if((ball_x + t * ball_v_x) > 2000){
            xx=4000-2*ball_r-ball.v_x*t-ball.x- data->plane1.x;
        }
        if((ball_x + t * ball_v_x) < 0){
            xx=2*ball_r-ball.x-ball.v_x*t- data->plane1.x;
        }

        angleTo=angleConver(atan2(yy,xx)*180/PI);
    //计算飞机朝向与该角度之差
    angleDiff = fmod(fmod(data->plane1.angle - angleTo, 360) + 360, 360);


    //根据角度差选择更优旋转方向
    if (angleDiff<3.6||angleDiff>360-3.6)
    {
        return 1;
    }
    else if (angleDiff < 180)
    {
        leftward = false;
        rightward = true;
    }
    else
    {
        leftward = true;
        rightward = false;
    }

    return 0;
}


/* 预测飞机位置
 * 参数：data：游戏数据，x、y：返回位置，time：给定时间
 * 返回值：0：预测成功，-1：预测失败
 */
int prePlanePos(DataStruct *data, int time, float &x, float &y)
{
    double v_x0, v_y0, v_x1, v_y1, a_x, a_y;
    //获取初速度
    v_x0 = data->plane1.v_x;
    v_y0 = data->plane1.v_y;
    //无速度则无需预测
    if (v_x0 == 0 && v_y0 == 0)
    {
        x = data->plane1.x;
        y = data->plane1.y;
        return 0;
    }
    //计算加速度
    a_x = -v_x0 / vecMod(v_x0, v_y0) * 4000;
    a_y = -v_y0 / vecMod(v_x0, v_y0) * 4000;
    //计算末速度
    v_x1 = v_x0 + a_x * time / 100;
    if (SIGN(v_x1) != SIGN(v_x0))
    {
        v_x1 = 0;
    }
    v_y1 = v_y0 + a_y * time / 100;
    if (SIGN(v_y1) != SIGN(v_y0))
    {
        v_y1 = 0;
    }
    //计算位置
    x = data->plane1.x + (v_x1 * v_x1 - v_x0 * v_x0) / 2 / a_x;
    y = data->plane1.y + (v_y1 * v_y1 - v_y0 * v_y0) / 2 / a_y;
    return 0;
}


//预测球的位置
bool prebollsPos(BALLSTRUCT *ball, int time, float &x, float &y,float& v_x,float& v_y)
{
    bool flag=0;

    double v_x0, v_y0;
    //获取初速度
    v_x0 =  ball->v_x;
    v_y0 = ball->v_y;
    //无速度则无需预测
    if (v_x0 == 0 && v_y0 == 0)
    {
        x = ball->x;
        y = ball->y;
        return 0;
    }
    v_x=v_x;
    v_y=v_y;
    //计算位置

    double x0=ball->x+v_x0*time;
    double y0=ball->y+v_y0*time;
    if(x0>2000){
        flag=1;
        x0=2000-(x0-2000);
    }
    if(x0<0){
        flag=1;
        x0=-x0;
    }
    if(y0>1500){
        flag=1;
        y0=1500-(x0-1500);
    }
    if(y0<0){
        flag=1;
        y0=-y0;
    }

    x = x0;
    y = y0;


    return flag;

}

/* 转向某点
 * 参数：data：游戏数据，x、y：目标点，leftward、rightward：返回动作
 * 返回值：0：正在转向，1：完成转向，-1：转向失败
 */
int turnTo(DataStruct *data, float x, float y, int &leftward, int &rightward)
{
    //飞机到目的地的角度
    double angleTo, angleDiff;

    //计算飞机到目的地的角度并改变坐标系
    angleTo = angleConver(atan2(y - data->plane1.y, x - data->plane1.x) * 180 / PI);
    //计算飞机朝向与该角度之差
    angleDiff = fmod(fmod(data->plane1.angle - angleTo, 360) + 360, 360);

    //根据角度差选择更优旋转方向
    if (angleDiff < 1.8 || angleDiff > 360-1.8)
    {
        return 1;
    }
    else if (angleDiff < 180)
    {
        leftward = false;
        rightward = true;
    }
    else
    {
        leftward = true;
        rightward = false;
    }

    return 0;
}

/* 移动至某点
 * 参数：data：游戏数据，x、y：目标点，forward、leftward、rightward：返回动作
 * 返回值：0：正在移动，1：完成移动，-1：移动失败
 */
int moveTo(DataStruct *data, float x, float y, int &forward, int &leftward, int &rightward, int precision = 1)
{
    //计算当前点到终点距离
    double dis = vecMod(y - data->plane1.y, x - data->plane1.x);
    //已到达目标点则终止动作
    if (dis < precision)
    {
        return 1;
    }

    //预测飞机位置
    float pre_x, pre_y;
    prePlanePos(data, 3000, pre_x, pre_y);

    //正在转向则不加速
    if (!turnTo(data, data->plane1.x + x - pre_x, data->plane1.y + y - pre_y, leftward, rightward))
    {
        forward = false;
        return 0;
    }

    dis = vecMod(y - pre_x, x - pre_y);
    //停下时未到达目标点
    if (dis >= precision)
    {
        forward = true;
        leftward = false;
        rightward = false;
    }

    return 0;
}

/* 判断是否需要移动
 * 参数：data：游戏数据、des_x：目标点横坐标、des_y：目标点纵坐标
 * 返回值：0：无需移动，1：需要移动
 */
int moveNeeded(DataStruct *data, int &des_x, int &des_y, int preTime = 200)
{
    float min_t = INT_MAX;
    //预测每一个球的移动
    for (int i = 0; i < data->ball_size; i++)
    {
        //获取当前球的引用
        BallStruct &ball = data->ball[i];
        //获取当前球的坐标和速度
        float ball_x = ball.x, ball_y = ball.y, ball_v_x = ball.v_x, ball_v_y = ball.v_y;
        //计算球运动直线方程
        float A, B, C;
        A = -1;
        B = ball_v_y / ball_v_x;
        C = ball_y - ball_x * ball_v_y / ball_v_x;
        //计算飞机到直线距离
        float dis = fabs((A * data->plane1.y + B * data->plane1.x + C) / vecMod(A, B));
        //计算垂点坐标
        float cross_x = (data->plane1.y - ball_y + ball_v_y / ball_v_x * ball_x + ball_v_x / ball_v_y * data->plane1.x)
                / (ball_v_x / ball_v_y + ball_v_y / ball_v_x);
        float cross_y = (ball_v_y / ball_v_x) * (cross_x - ball_x) + ball_y;
        //计算到垂点的时间
        float t = (cross_x - ball_x) / ball_v_x * 100;
        //反向运动或时间过久则忽略该球
        if (t < 0 || t > preTime)
        {
            continue;
        }
        //判断该球是否有威胁
        if (dis < data->plane1.r + ball.r + 10 && t < min_t)
        {
            //设置最紧迫威胁
            min_t = t;
            //向相反方向移动球半径的距离
            des_x = data->plane1.x +  ball.r * (data->plane1.x - cross_x)
                    / vecMod(data->plane1.x - cross_x, data->plane1.y - cross_y);
            des_y = data->plane1.y +  ball.r * (data->plane1.y - cross_y)
                    / vecMod(data->plane1.x - cross_x, data->plane1.y - cross_y);
            //如果x越界
            if (des_x < data->plane1.r || des_x > 2000 - data->plane1.r)
            {
                des_x = data->plane1.x;
                if (data->plane1.y - cross_y > 0)
                    des_y = cross_y + ball.r + data->plane1.r;
                else
                    des_y = cross_y - ball.r - data->plane1.r;
            }
            //如果y越界
            if (des_y < data->plane1.r || des_y > 1500 - data->plane1.r)
            {
                des_y = data->plane1.y;
                if (data->plane1.x - cross_x > 0)
                    des_x = cross_x + ball.r + data->plane1.r;
                else
                    des_x = cross_x - ball.r - data->plane1.r;
            }
        }
    }

    if (min_t<100)
    {
        return 1;
    }

    //给定时间内无危险
    return 0;
}

int cho_ball(DATASTRUCT *data){
    int max=0;
    int value[data->ball_size];
    memset(value,0,sizeof(value));
    for(int i=0;i<data->ball_size;i++){
        if(data->ball[i].type==2){value[i]+=300;}
        if(data->ball[i].type==1){value[i]+=500;}
        if(data->ball[i].type==0){value[i]+=500;}
        value[i]-=(fabs(data->ball[i].x-data->plane1.x)+fabs(data->ball[i].y-data->plane1.y));

        BallStruct &ball = data->ball[i];
        //获取当前球的坐标和速度
        float ball_x = ball.x, ball_y = ball.y, ball_v_x = ball.v_x, ball_v_y = ball.v_y;
        //计算垂点坐标
        float cross_x = (data->plane1.y - ball_y + ball_v_y / ball_v_x * ball_x + ball_v_x / ball_v_y * data->plane1.x)
                / (ball_v_x / ball_v_y + ball_v_y / ball_v_x);
        //计算到垂点的时间
        float t = (cross_x - ball_x) / ball_v_x * 100;
        //朝飞机飞来
        if (t>0){
            value[i]+=1000;
        }


    }
    for(int i=0;i<data->ball_size;i++){

        double distance_x=fabs(data->plane1.x-data->ball[i].x);
        double distance_y=fabs(data->plane1.y-data->ball[i].y);
        double distance=vecMod(distance_x,distance_y);

        if(distance>700){value[i]-=1000;}
        if(value[max]<value[i]){max=i;}
        if(distance<200){max=i;}
    }
    return max;
}
bool aroundDanger(DATASTRUCT*data){
    for(int i=0;i<data->ball_size;i++){
        double distance_x=fabs(data->plane1.x-data->ball[i].x);
        double distance_y=fabs(data->plane1.y-data->ball[i].y);
        double distance=vecMod(distance_x,distance_y);
        if(distance<100||(distance<200&&data->ball[i].type==3)){
            return 1;
        }
    }
    return 0;
}

void ai_pve(DataStruct*data,KeyStruct*key){
    //默认不移动且恒发射子弹
    key->forward = false;
    key->rotate_left = false;
    key->rotate_right = false;
    key->shoot = true;


    //创建静态移动标志
    static int  des_x, des_y;

    if (moveNeeded(data, des_x, des_y)&&aroundDanger(data)){
        key->shield=true;
    }

    //如果球个数不为零
    if (data->ball_size)
    {
        int max=0;
        max=cho_ball(data);

        AimBall(data, data->ball[max], key->rotate_left, key->rotate_right);
    }
}
void ai1_pvp(DataStruct*data,KeyStruct*key){
    UNUSED(data)
    UNUSED(key)
}
