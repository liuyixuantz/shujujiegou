#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<windows.h>
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量
#define MAXQsize 100 //队列空间初始化分配量
#define LH +1  //左边高
#define RH -1  //右边高
#define EH  0  //等高
bool taller ; //树是否长高
typedef int ElemType;
typedef int  Status;



/* 二叉树的二叉链表结点结构定义 */
typedef struct BiTNode
{
    int data;
    int bf;	//平衡因子
    struct BiTNode *lchild, *rchild;	//左右孩子
} BiTNode, *BiTree;

/*层次遍历时候使用到的辅助队列*/
typedef struct
{
    BiTree data[STACK_INIT_SIZE];
    int head;
    int rear;
    int len;
} Queue;

void color(short x);	//自定义函根据参数改变颜色
Status InsertAVL(BiTree *T, int e, Status *taller);     //创建平衡二叉树
void PreOrderTraverse( BiTree T);                       //前序递归遍历平衡二叉树
void InOrderTraverse( BiTree T);                        //中序递归遍历平衡二叉树
void PostOrderTraverse( BiTree T);                      //后序递归遍历平衡二叉树
void LeftShow(BiTree T);                                //非递归算法的先序遍历
void MiddleShow(BiTree T);                              //非递归算法的中序遍历
void RightShow(BiTree T);                               //非递归算法的后续遍历
Queue InitQueue();                                      //初始化队列
int IsEmptyQueue(Queue cengci);                         //队列判空
int IsFullQueue(Queue cengci);                          //队列判满
void PushQueue(Queue *cengci, BiTree T);                //入队
void PopQueue(Queue *cengci, BiTree *T);                //出队
void LayerOrder(BiTree T);                              //层序遍历
Status Find_keyword(BiTree T,int e);                    //在二叉树中查找给定关键字
void Exchange(BiTree T);                                //交换左右二叉树
int Depth (BiTree T);                                   //求平衡二叉树的深度
int LeafNumber(BiTree T);                               //统计二叉树的叶子结点个数

int main()
{
    printf("\n\n\t\t★-·-·-·-·-·-·-·-·-·-·-·-·-·-★\n");
    printf("\t\t丨                 ");
    color(14);
    printf("主菜单");
    color(7);
    printf("                 丨\n");
    printf("\t\t·-·-·-·-·-·-·-·-·-·-·-·-·-·-·\n");
    printf("\t\t丨      1、创建平衡二叉树                 丨\n");
    printf("\t\t丨      2、插入新结点                     丨\n");
    printf("\t\t丨      3、前序遍历二叉树                 丨\n");
    printf("\t\t丨      4、中序遍历二叉树                 丨\n");
    printf("\t\t丨      5、后序遍历二叉树                 丨\n");
    printf("\t\t丨      6、层次遍历二叉树                 丨\n");
    printf("\t\t丨      7、在二叉树中查找给定关键字       丨\n");
    printf("\t\t丨      8、交换各结点的左右子树           丨\n");
    printf("\t\t丨      9、求二叉树的深度                 丨\n");
    printf("\t\t丨      10、叶子结点数                    丨\n");
    printf("\t\t丨      11、删除某结点                    丨\n");
    printf("\t\t★-·-·-·-·-·-·-·-·-·-·-·-·-·-★\n");
    BiTree T = NULL;	//指向BiTNode的指向置空
    Status taller;	//树是否长高标志
    int ch;
    ch=1;
    while(ch==1)
    {
        color(3);
        printf("请选择所需功能：");
        color(7);
        int n;
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("请输入需要插入的元素的个数：");
            int a,i;
            scanf("%d",&a);
            printf("请输入插入的元素：");
            for(i=0; i<a; i++)
            {
                int b;
                scanf("%d",&b);
                InsertAVL(&T, b, &taller);
            }//插入结点到AVL树
            printf("成功创建平衡二叉树！\n\n");
            break;
        case 2:
            int b;
            printf("请输入需要插入的元素：");
            scanf("%d",&b);
            InsertAVL(&T, b, &taller);
            printf("成功插入元素！\n\n");
            break;
        case 3:
            printf("前序遍历平衡二叉树结果如下：\n");
            printf("递归： ");
            PreOrderTraverse(T);
            printf("\n");
            printf("非递归： ");
            LeftShow(T);
            printf("\n\n");
            break;
        case 4:
            printf("中序遍历平衡二叉树结果如下：\n");
            printf("递归： ");
            InOrderTraverse(T);
            printf("\n");
            printf("非递归： ");
            MiddleShow(T);
            printf("\n\n");
            break;
        case 5:
            printf("后序遍历平衡二叉树结果如下：\n");
            printf("递归： ");
            PostOrderTraverse(T);
            printf("\n");
            printf("非递归： ");
            RightShow(T);
            printf("\n\n");
            break;
        case 6:
            printf("层次遍历输出结果如下：\n");
            LayerOrder(T);
            printf("\n\n");
            break;
        case 7:
            printf("请输入要查找的关键字：");
            int e;
            scanf("%d",&e);
            if(Find_keyword(T,e)==TRUE)
                printf("查找成功！\n\n");
            else
            {
                color(12);
                printf("查找失败，没有该关键字！\n\n");
                color(7);
            }
            break;
        case 8:
            printf("交换前的平衡二叉树的先序遍历为如下：\n");
            PreOrderTraverse(T);
            printf("\n");
            Exchange(T);
            printf("交换后的平衡二叉树的先序遍历为如下：\n");
            PreOrderTraverse(T);
            printf("\n\n");
            break;
        case 9:
            printf("该平衡二叉树的深度为：");
            printf("%d\n", Depth(T));
            printf("\n\n");
            break;
        case 10:
            printf("该平衡二叉树的叶子节点数为：%d\n\n",LeafNumber(T));
            break;
        case 11:
            int yuansu[100];
            printf("请输入要删除的关键字：");
            scanf("%d",&e);
            if(Find_keyword(T,e)==TRUE)
            {
                //层序遍历
                Queue cengci;
                cengci = InitQueue();
                BiTree tmp;
                tmp = T;
                T=NULL;
                PushQueue(&cengci, tmp);
                while(!IsEmptyQueue(cengci))
                {
                    if(e!=tmp->data)
                    InsertAVL(&T, tmp->data, &taller);
                    if (tmp->lchild != NULL)
                    {
                        PushQueue(&cengci, tmp->lchild);
                    }
                    if (tmp->rchild != NULL)
                    {
                        PushQueue(&cengci, tmp->rchild);
                    }
                    PopQueue(&cengci, &tmp);
                }
                printf("删除完成后的平衡二叉树的先序遍历结果如下：");
                PreOrderTraverse(T);
                printf("\n\n");
            }
            else
            {
                color(12);
                printf("查找失败，没有该关键字！\n\n");
                color(7);
            }
            break;
        default:
            printf("输入错误，退出程序");
        }
        getchar();
        printf("如需继续输入请输入“1”，退出输出其他数字\n");
        scanf("%d",&ch);
    }
    return 0;
}
void color(short x)	//自定义函根据参数改变颜色
{
    if(x>=0 && x<=15)//参数在0-15的范围颜色
//       0:黑色     1 :蓝色    2 :绿色    3 :湖蓝色  4 :红色      5 :紫色   6 :黄色
//       7 :白色    8 :灰色    9 :淡蓝色  10 :淡绿色 11 :淡浅绿色
//       12 :淡红色 13 :淡紫色 14 :淡黄色 15 :亮白色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色
    else//默认的颜色白色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

/* 对以p为根的二叉排序树作右旋处理，
	处理之后p指向新的树根节点，即旋转处理之前的左子树的根节点 */
void R_Rotate(BiTree *p)
{
    BiTree L;
    L = (*p)->lchild;	//L指向P的左子树根节点
    (*p)->lchild = L->rchild;
    L->rchild = (*p);
    *p = L;	//P指向新的根节点
}

/* 左旋 */
void L_Rotate(BiTree *p)
{
    BiTree R;
    R = (*p)->rchild;	//指向p的右子树根结点
    (*p)->rchild = R->lchild;
    R->lchild = (*p);
    *p = R;
}

/* 左平衡处理 */
void LeftBalance(BiTree *T)
{
    BiTree L, Lr;
    L = (*T)->lchild;	//L指向T的左子树根结点，也就是新插入结点的父节点
    switch(L->bf) 	//检查T的左子树的平衡度，并作相应平衡处理
    {
    case LH:	//新结点插入在T的左孩子的左子树上，要作单右旋处理，单右旋的结果就是，平衡度变为0,0,0
        (*T)->bf = L->bf = EH;
        R_Rotate(T);
        break;
    case RH:		//新结点插入在T的左孩子的右子树上，要作双旋处理
        Lr = L->rchild;	//Lr指向T的左孩子的右子树根
        switch(Lr->bf) 	//修改T及其左孩子的平衡因子
        {
        case LH:
            (*T)->bf = RH;
            L->bf = EH;
            break;
        case EH:
            (*T)->bf = L->bf = EH;
            break;
        case RH:
            (*T)->bf = EH;
            L->bf = LH;
            break;
        }
        Lr->bf = EH;	//平衡因子设为0
        L_Rotate(&(*T)->lchild);	//对T的左子树作左旋平衡处理，这步是为了平衡因子bf的符号统一
        R_Rotate(T);	//对T作右旋平衡处理
    }
}

/* 右平衡处理 */
void RightBalance(BiTree *T)
{
    BiTree R, Rl;
    R = (*T)->rchild;	//L指向T的左子树根结点
    switch(R->bf) 	//检查T的左子树的平衡度，并作相应平衡处理
    {
    case RH:		//新结点插入在T的左孩子的右子树上，要作左旋处理
        (*T)->bf = R->bf = EH;
        L_Rotate(T);
        break;
    case LH:	//新结点插入在T的左孩子的左子树上，要作单右旋处理
        Rl = R->lchild;	//Lr指向T的左孩子的右子树根
        switch(Rl->bf) 	//修改T及其左孩子的平衡因子
        {
        case LH:
            (*T)->bf = RH;
            R->bf = EH;
            break;
        case EH:
            (*T)->bf = R->bf = EH;
            break;
        case RH:
            (*T)->bf = EH;
            R->bf = LH;
            break;
        }
        Rl->bf = EH;	//平衡因子设为0
        R_Rotate(&(*T)->rchild);	//对T的右子树作右旋平衡处理
        L_Rotate(T);	//对T作左旋平衡处理
    }
}

/* 若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入一个 */
/* 数据元素为e的新结点并返回1，否则返回0。若因插入而使二叉排序树失去平衡，则作平衡旋转处理，布尔变量taller反映T长高与否 */
Status InsertAVL(BiTree *T, int e, Status *taller)//创建平衡二叉树
{
    if(!*T) 	//插入新结点，树"长高"，置taller为TRUE
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;	//新结点左右孩子为空
        (*T)->bf = EH;	//新结点平衡因子为0
        *taller = TRUE;	//插入结点后，树长高
    }
    else
    {
        if(e < (*T)->data) 	//应继续在T的左子树中进行搜索
        {
            if(!InsertAVL(&(*T)->lchild, e, taller))	//未插入结点
                return FALSE;
            //已插入到T的左子树中且左子树"长高"，如果已经插入了结点，但是树没有长高（即在子树中已经调整了平衡度
            if(taller)
            {
                switch((*T)->bf) 	//检查T的平衡度
                {
                case LH:
                    //原本左子树比右子树高，需要作左平衡处理，那么插入一个结点在左子树里，
                    //左子树高度变为2，需要调整
                    LeftBalance(T);		//左平衡调整
                    *taller = FALSE;	//调整后树没有长高
                    break;
                case EH:	//原本左右子树等高，现因左子树增高而树增高
                    (*T)->bf = LH;
                    *taller = TRUE;	//左子树多了一个孩子，肯定长高了，但是平衡度为1，是最小不平衡树，无需调整
                    break;
                case RH:	//原本右子树比左子树高，现在左右子树等高
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                }
            }
        }
        else 	//继续在T的右子树中进行搜索
        {
            if(!InsertAVL(&(*T)->rchild, e, taller))	//未插入
                return FALSE;
            if(*taller) 	//已插入到T的右子树且右子树"长高"
            {
                switch((*T)->bf) 	//检查T的平衡度
                {
                case LH:	//原本左子树比右子树高
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                case EH:	//原本左右子树等高，现因右子树增高而树增高
                    (*T)->bf = RH;
                    *taller = TRUE;
                    break;
                case RH:	//原本右子树比左子树高，需要作右平衡处理
                    RightBalance(T);
                    *taller = FALSE;
                    break;
                }
            }
        }
    }
    return TRUE;
}

void PreOrderTraverse( BiTree T)//前序递归遍历平衡二叉树
{
    if(T)
    {
        printf("%d ",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse( BiTree T)//中序递归遍历平衡二叉树
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        printf("%d ",T->data);
        InOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse( BiTree T)//后序递归遍历平衡二叉树
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%d ",T->data);
    }
}

//非递归算法的先序遍历
void LeftShow(BiTree  T)
{
    BiTNode* rchildlist[STACK_INIT_SIZE];		//创建一个用于储存右孩子的栈。因为输出父节点，然后输出左孩子。所以需要将右孩子储存起来。
    BiTNode* show=T;				//将show指针初始化为T的地址。 show用于遍历时储存正在遍历的节点。从根节点开始遍历。
    int i=0;						//i为rchildlist栈顶。
    while(1)
    {
        if(show==NULL) 				//当遍历到的节点是NULL时。进行分情况判定
        {
            if(i==0)						//如果栈此时也为空。则已经遍历完整个树。就可以退出循环。
                break;
            else 							//如果栈此时不为空。则执行退栈操作。将退栈的值赋值为下一个需要遍历的节点。此时是左孩子已经遍历完，需要遍历右孩子。
            {
                show=rchildlist[i];						//将退栈的值赋值为下一个需要遍历的节点。
                i--;									//执行退栈操作
            }
        }
        else  						//当遍历到的节点不为NULL时。
        {
            printf("%d ",show->data);		//输出该节点储存的值
            if(show->rchild!=NULL) 			//判断该节点有没有右孩子。如果有右孩子则使右孩子进栈。
            {
                i++;									//执行进栈操作
                rchildlist[i]=(BiTNode *)show->rchild;	//将右孩子进栈。
            }
            show=(BiTNode *)show->lchild;	//将该节点的左孩子赋值为下一个需要遍历的节点。
        }
    }
}

//非递归算法的中序遍历
void MiddleShow(BiTree  T)
{
    BiTNode* fatherlist[STACK_INIT_SIZE];		//创建一个用于储存父节点的栈。因为需要先输出左孩子。所以需要将父节点储存起来。同时可以通过父节点找到右孩子。
    BiTNode* show =T;			//将show指针初始化为T的地址。 show用于遍历时储存正在遍历的节点。从根节点开始遍历。
    int i=0;						//i为fatherlist的栈顶。
    while (1)
    {
        if(show ==NULL) 			//当遍历到的节点是NULL时。进行分情况判定。
        {
            if(i==0)						//如果此时栈也为空。则已经遍历完整个树。就可以退出循环。
                break;
            else 							//如果此时栈不为空。进行退栈操作。将退栈的值赋值为当前便利的节点。此时左孩子已经遍历完，需要最后一个输出父节点的值。
            {
                show=fatherlist[i];						//将退栈的值赋值为当前便利的节点。
                printf("%d ",show->data);				//输出该节点的data值。
                i--;									//执行退栈操作。
                if(show->rchild!=NULL) 		//判断该节点是否存在右孩子。
                {
                    show=(BiTNode *)show->rchild;		//如果有右孩子。则将右孩子赋值为下一个需要遍历的节点。
                }
                else
                {
                    show=NULL;							//否则继续返回为NULL。此时的目的为继续退栈。用于输出上一个父节点的值。
                }
            }
        }
        else  						//当遍历到的节点不为NULL时。
        {
            i++;							//执行进栈操作。
            fatherlist[i]=show;				//将该遍历节点进栈。
            show=(BiTNode *)show->lchild;	//将该遍历节点的左孩子赋值为下一个需要遍历的节点。
        }
    }
}

//非递归算法的后续遍历
void RightShow(BiTree  T)
{
    BiTNode* fatherlist[STACK_INIT_SIZE];		//创建一个用于储存父节点的栈。因为需要先输出左、右孩子。所以需要将父节点储存起来。
    BiTNode* show=T;				//将show指针初始化为T的地址。 show用于遍历时储存正在遍历的节点。从根节点开始遍历。
    int taglist[50];				//创建一个与父节点同步的栈。用于判断该父节点是第几次被访问。因为父节点需要退出两次。只有第二次才需要输出值。第一次用于寻找右孩子。
    int i=0;						//i为fatherlist的栈顶。同时也是taglist的栈顶。
    int tag=0;						//tag用于判断父节点被访问的次数。第一次被取出为0，第二次被取出为1。为1时可以输出值。
    while (1)
    {
        if(show==NULL) 				//当遍历到的节点是NULL时。进行分情况判定。
        {
            if(i==0)						//如果此时栈也为空。则已经遍历完整个树。就可以退出循环。
                break;
            else 							//如果此时栈不为空。进行退栈操作。将退栈的值赋值为当前遍历的节点。此时左孩子已经遍历完，需要分情况判断。
            {
                show=fatherlist[i];						//将退栈的值赋值为当前遍历的节点。
                if(taglist[i]==0) 						//如果此时该父节点是第一次访问则为其tag值+1。并将该节点的右孩子赋值为下一个需要遍历的节点。
                {
                    taglist[i]++;								//为其tag值+1。
                    show=(BiTNode *)show->rchild;				//将该节点的右孩子赋值为下一个需要遍历的节点。
                }
                else 									//如果此时该父节点是第二次访问。则输出该节点对应的data值，并执行退栈操作。
                {
                    printf("%d ",show->data);					//输出该节点对应的data值。
                    i--;										//执行退栈操作。
                    show=NULL;									//继续返回为NULL。此时的目的为继续退栈。用于输出上一个父节点的值。
                }
            }
        }
        else 						//当遍历到的节点不为NULL时。
        {
            i++;							//执行进栈操作
            fatherlist[i]=show;				//将该遍历到的节点进栈。
            taglist[i]=tag;					//同时将该节点的tag值进栈。初始为0.
            show=(BiTNode *)show->lchild;	//将该遍历节点的左孩子赋值为下一个需要遍历的节点。
        }
    }
}

//层次遍历代码
Queue InitQueue()
{
    //初始化队列
    Queue cengci;
    for(int i = 0; i < STACK_INIT_SIZE; i++)
    {
        cengci.data[i] = NULL;
    }
    cengci.head = 0;
    cengci.rear = -1;
    cengci.len = 0;
    return cengci;
}

int IsEmptyQueue(Queue cengci)
{
    //队列判空
    if (cengci.len == 0)
    {
        return 1;
    }
    return 0;
}

int IsFullQueue(Queue cengci)
{
    //队列判满
    if (cengci.len == STACK_INIT_SIZE)
    {
        return 1;
    }
    return 0;
}

void PushQueue(Queue *cengci, BiTree T)
{
    //入队
    if (IsFullQueue(*cengci))
    {
        printf("ErrorFull");
        return;
    }
    cengci->rear = (cengci->rear + 1) % STACK_INIT_SIZE;
    cengci->len++;
    cengci->data[cengci->rear] = T;
}

void PopQueue(Queue *cengci, BiTree *T)
{
    //出队
    if (IsEmptyQueue(*cengci))
    {
        printf("ErrorEmpty");
        return;
    }
    cengci->head = (cengci->head + 1) % STACK_INIT_SIZE;
    *T = cengci->data[cengci->head];
    cengci->len--;
}

void LayerOrder(BiTree T)
{
    //层序遍历
    Queue cengci;
    cengci = InitQueue();
    BiTree tmp;
    tmp = T;
    PushQueue(&cengci, tmp);
    while(!IsEmptyQueue(cengci))
    {
        printf("%d ", tmp->data);
        if (tmp->lchild != NULL)
        {
            PushQueue(&cengci, tmp->lchild);
        }
        if (tmp->rchild != NULL)
        {
            PushQueue(&cengci, tmp->rchild);
        }
        PopQueue(&cengci, &tmp);
    }
}

//在二叉树中查找给定关键字
Status Find_keyword(BiTree T,int e)
{
    BiTree tem=T;
    while(tem)//如果T不空则继续找
    {
        if(tem->data==e)
            return TRUE;
        else if(tem->data>e)
            tem=tem->lchild;
        else if(tem->data<e)
            tem=tem->rchild;
    }
    return FALSE;
}

//交换左右二叉树；
void Exchange(BiTree T)
{
    if(T->lchild==NULL&&T->rchild==NULL)
        ;
    else    //三种情况，1.都不为空，2.左为空，3.右为空；
    {
        //交换左右子树；
        BiTree tem=T->lchild;
        T->lchild=T->rchild;
        T->rchild=tem;
    }

    //如果交换后的这个结点左子树不为空，则继续向下寻找可以交换的结点；
    if(T->lchild)
        Exchange(T->lchild);
    if(T->rchild)
        Exchange(T->rchild);
}

//求平衡二叉树的深度
int Depth (BiTree T)
{
    if(T==NULL)
    {
        return 0;
    }
    else
    {
        if(Depth(T->lchild) > Depth(T->rchild)) return (Depth(T->lchild) + 1);
        else return (Depth(T->rchild) + 1);
    }
}

//统计二叉树的叶子结点个数
int LeafNumber(BiTree T)
{
    int c=0;

    if(T==NULL) //空树
    {
        return 0;
    }
    else if(T->lchild==NULL && T->rchild==NULL)  //只有一个根节点
    {
        return c+1;
    }
    else
    {
        c=LeafNumber(T->lchild)+LeafNumber(T->rchild);//关系为左右相加求和
        return c;
    }
}
