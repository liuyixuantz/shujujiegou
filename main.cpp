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
#define STACK_INIT_SIZE 100 // �洢�ռ��ʼ������
#define STACKINCREMENT 10 // �洢�ռ��������
#define MAXQsize 100 //���пռ��ʼ��������
#define LH +1  //��߸�
#define RH -1  //�ұ߸�
#define EH  0  //�ȸ�
bool taller ; //���Ƿ񳤸�
typedef int ElemType;
typedef int  Status;



/* �������Ķ���������ṹ���� */
typedef struct BiTNode
{
    int data;
    int bf;	//ƽ������
    struct BiTNode *lchild, *rchild;	//���Һ���
} BiTNode, *BiTree;

/*��α���ʱ��ʹ�õ��ĸ�������*/
typedef struct
{
    BiTree data[STACK_INIT_SIZE];
    int head;
    int rear;
    int len;
} Queue;

void color(short x);	//�Զ��庯���ݲ����ı���ɫ
Status InsertAVL(BiTree *T, int e, Status *taller);     //����ƽ�������
void PreOrderTraverse( BiTree T);                       //ǰ��ݹ����ƽ�������
void InOrderTraverse( BiTree T);                        //����ݹ����ƽ�������
void PostOrderTraverse( BiTree T);                      //����ݹ����ƽ�������
void LeftShow(BiTree T);                                //�ǵݹ��㷨���������
void MiddleShow(BiTree T);                              //�ǵݹ��㷨���������
void RightShow(BiTree T);                               //�ǵݹ��㷨�ĺ�������
Queue InitQueue();                                      //��ʼ������
int IsEmptyQueue(Queue cengci);                         //�����п�
int IsFullQueue(Queue cengci);                          //��������
void PushQueue(Queue *cengci, BiTree T);                //���
void PopQueue(Queue *cengci, BiTree *T);                //����
void LayerOrder(BiTree T);                              //�������
Status Find_keyword(BiTree T,int e);                    //�ڶ������в��Ҹ����ؼ���
void Exchange(BiTree T);                                //�������Ҷ�����
int Depth (BiTree T);                                   //��ƽ������������
int LeafNumber(BiTree T);                               //ͳ�ƶ�������Ҷ�ӽ�����

int main()
{
    printf("\n\n\t\t��-��-��-��-��-��-��-��-��-��-��-��-��-��-��\n");
    printf("\t\tح                 ");
    color(14);
    printf("���˵�");
    color(7);
    printf("                 ح\n");
    printf("\t\t��-��-��-��-��-��-��-��-��-��-��-��-��-��-��\n");
    printf("\t\tح      1������ƽ�������                 ح\n");
    printf("\t\tح      2�������½��                     ح\n");
    printf("\t\tح      3��ǰ�����������                 ح\n");
    printf("\t\tح      4���������������                 ح\n");
    printf("\t\tح      5���������������                 ح\n");
    printf("\t\tح      6����α���������                 ح\n");
    printf("\t\tح      7���ڶ������в��Ҹ����ؼ���       ح\n");
    printf("\t\tح      8��������������������           ح\n");
    printf("\t\tح      9��������������                 ح\n");
    printf("\t\tح      10��Ҷ�ӽ����                    ح\n");
    printf("\t\tح      11��ɾ��ĳ���                    ح\n");
    printf("\t\t��-��-��-��-��-��-��-��-��-��-��-��-��-��-��\n");
    BiTree T = NULL;	//ָ��BiTNode��ָ���ÿ�
    Status taller;	//���Ƿ񳤸߱�־
    int ch;
    ch=1;
    while(ch==1)
    {
        color(3);
        printf("��ѡ�����蹦�ܣ�");
        color(7);
        int n;
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("��������Ҫ�����Ԫ�صĸ�����");
            int a,i;
            scanf("%d",&a);
            printf("����������Ԫ�أ�");
            for(i=0; i<a; i++)
            {
                int b;
                scanf("%d",&b);
                InsertAVL(&T, b, &taller);
            }//�����㵽AVL��
            printf("�ɹ�����ƽ���������\n\n");
            break;
        case 2:
            int b;
            printf("��������Ҫ�����Ԫ�أ�");
            scanf("%d",&b);
            InsertAVL(&T, b, &taller);
            printf("�ɹ�����Ԫ�أ�\n\n");
            break;
        case 3:
            printf("ǰ�����ƽ�������������£�\n");
            printf("�ݹ飺 ");
            PreOrderTraverse(T);
            printf("\n");
            printf("�ǵݹ飺 ");
            LeftShow(T);
            printf("\n\n");
            break;
        case 4:
            printf("�������ƽ�������������£�\n");
            printf("�ݹ飺 ");
            InOrderTraverse(T);
            printf("\n");
            printf("�ǵݹ飺 ");
            MiddleShow(T);
            printf("\n\n");
            break;
        case 5:
            printf("�������ƽ�������������£�\n");
            printf("�ݹ飺 ");
            PostOrderTraverse(T);
            printf("\n");
            printf("�ǵݹ飺 ");
            RightShow(T);
            printf("\n\n");
            break;
        case 6:
            printf("��α������������£�\n");
            LayerOrder(T);
            printf("\n\n");
            break;
        case 7:
            printf("������Ҫ���ҵĹؼ��֣�");
            int e;
            scanf("%d",&e);
            if(Find_keyword(T,e)==TRUE)
                printf("���ҳɹ���\n\n");
            else
            {
                color(12);
                printf("����ʧ�ܣ�û�иùؼ��֣�\n\n");
                color(7);
            }
            break;
        case 8:
            printf("����ǰ��ƽ����������������Ϊ���£�\n");
            PreOrderTraverse(T);
            printf("\n");
            Exchange(T);
            printf("�������ƽ����������������Ϊ���£�\n");
            PreOrderTraverse(T);
            printf("\n\n");
            break;
        case 9:
            printf("��ƽ������������Ϊ��");
            printf("%d\n", Depth(T));
            printf("\n\n");
            break;
        case 10:
            printf("��ƽ���������Ҷ�ӽڵ���Ϊ��%d\n\n",LeafNumber(T));
            break;
        case 11:
            int yuansu[100];
            printf("������Ҫɾ���Ĺؼ��֣�");
            scanf("%d",&e);
            if(Find_keyword(T,e)==TRUE)
            {
                //�������
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
                printf("ɾ����ɺ��ƽ����������������������£�");
                PreOrderTraverse(T);
                printf("\n\n");
            }
            else
            {
                color(12);
                printf("����ʧ�ܣ�û�иùؼ��֣�\n\n");
                color(7);
            }
            break;
        default:
            printf("��������˳�����");
        }
        getchar();
        printf("����������������롰1�����˳������������\n");
        scanf("%d",&ch);
    }
    return 0;
}
void color(short x)	//�Զ��庯���ݲ����ı���ɫ
{
    if(x>=0 && x<=15)//������0-15�ķ�Χ��ɫ
//       0:��ɫ     1 :��ɫ    2 :��ɫ    3 :����ɫ  4 :��ɫ      5 :��ɫ   6 :��ɫ
//       7 :��ɫ    8 :��ɫ    9 :����ɫ  10 :����ɫ 11 :��ǳ��ɫ
//       12 :����ɫ 13 :����ɫ 14 :����ɫ 15 :����ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//ֻ��һ���������ı�������ɫ
    else//Ĭ�ϵ���ɫ��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

/* ����pΪ���Ķ�������������������
	����֮��pָ���µ������ڵ㣬����ת����֮ǰ���������ĸ��ڵ� */
void R_Rotate(BiTree *p)
{
    BiTree L;
    L = (*p)->lchild;	//Lָ��P�����������ڵ�
    (*p)->lchild = L->rchild;
    L->rchild = (*p);
    *p = L;	//Pָ���µĸ��ڵ�
}

/* ���� */
void L_Rotate(BiTree *p)
{
    BiTree R;
    R = (*p)->rchild;	//ָ��p�������������
    (*p)->rchild = R->lchild;
    R->lchild = (*p);
    *p = R;
}

/* ��ƽ�⴦�� */
void LeftBalance(BiTree *T)
{
    BiTree L, Lr;
    L = (*T)->lchild;	//Lָ��T������������㣬Ҳ�����²�����ĸ��ڵ�
    switch(L->bf) 	//���T����������ƽ��ȣ�������Ӧƽ�⴦��
    {
    case LH:	//�½�������T�����ӵ��������ϣ�Ҫ�������������������Ľ�����ǣ�ƽ��ȱ�Ϊ0,0,0
        (*T)->bf = L->bf = EH;
        R_Rotate(T);
        break;
    case RH:		//�½�������T�����ӵ��������ϣ�Ҫ��˫������
        Lr = L->rchild;	//Lrָ��T�����ӵ���������
        switch(Lr->bf) 	//�޸�T�������ӵ�ƽ������
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
        Lr->bf = EH;	//ƽ��������Ϊ0
        L_Rotate(&(*T)->lchild);	//��T��������������ƽ�⴦���ⲽ��Ϊ��ƽ������bf�ķ���ͳһ
        R_Rotate(T);	//��T������ƽ�⴦��
    }
}

/* ��ƽ�⴦�� */
void RightBalance(BiTree *T)
{
    BiTree R, Rl;
    R = (*T)->rchild;	//Lָ��T�������������
    switch(R->bf) 	//���T����������ƽ��ȣ�������Ӧƽ�⴦��
    {
    case RH:		//�½�������T�����ӵ��������ϣ�Ҫ����������
        (*T)->bf = R->bf = EH;
        L_Rotate(T);
        break;
    case LH:	//�½�������T�����ӵ��������ϣ�Ҫ������������
        Rl = R->lchild;	//Lrָ��T�����ӵ���������
        switch(Rl->bf) 	//�޸�T�������ӵ�ƽ������
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
        Rl->bf = EH;	//ƽ��������Ϊ0
        R_Rotate(&(*T)->rchild);	//��T��������������ƽ�⴦��
        L_Rotate(T);	//��T������ƽ�⴦��
    }
}

/* ����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬�����һ�� */
/* ����Ԫ��Ϊe���½�㲢����1�����򷵻�0����������ʹ����������ʧȥƽ�⣬����ƽ����ת������������taller��ӳT������� */
Status InsertAVL(BiTree *T, int e, Status *taller)//����ƽ�������
{
    if(!*T) 	//�����½�㣬��"����"����tallerΪTRUE
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;	//�½�����Һ���Ϊ��
        (*T)->bf = EH;	//�½��ƽ������Ϊ0
        *taller = TRUE;	//�������������
    }
    else
    {
        if(e < (*T)->data) 	//Ӧ������T���������н�������
        {
            if(!InsertAVL(&(*T)->lchild, e, taller))	//δ������
                return FALSE;
            //�Ѳ��뵽T������������������"����"������Ѿ������˽�㣬������û�г��ߣ������������Ѿ�������ƽ���
            if(taller)
            {
                switch((*T)->bf) 	//���T��ƽ���
                {
                case LH:
                    //ԭ�����������������ߣ���Ҫ����ƽ�⴦����ô����һ��������������
                    //�������߶ȱ�Ϊ2����Ҫ����
                    LeftBalance(T);		//��ƽ�����
                    *taller = FALSE;	//��������û�г���
                    break;
                case EH:	//ԭ�����������ȸߣ��������������߶�������
                    (*T)->bf = LH;
                    *taller = TRUE;	//����������һ�����ӣ��϶������ˣ�����ƽ���Ϊ1������С��ƽ�������������
                    break;
                case RH:	//ԭ�����������������ߣ��������������ȸ�
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                }
            }
        }
        else 	//������T���������н�������
        {
            if(!InsertAVL(&(*T)->rchild, e, taller))	//δ����
                return FALSE;
            if(*taller) 	//�Ѳ��뵽T����������������"����"
            {
                switch((*T)->bf) 	//���T��ƽ���
                {
                case LH:	//ԭ������������������
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                case EH:	//ԭ�����������ȸߣ��������������߶�������
                    (*T)->bf = RH;
                    *taller = TRUE;
                    break;
                case RH:	//ԭ�����������������ߣ���Ҫ����ƽ�⴦��
                    RightBalance(T);
                    *taller = FALSE;
                    break;
                }
            }
        }
    }
    return TRUE;
}

void PreOrderTraverse( BiTree T)//ǰ��ݹ����ƽ�������
{
    if(T)
    {
        printf("%d ",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse( BiTree T)//����ݹ����ƽ�������
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        printf("%d ",T->data);
        InOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse( BiTree T)//����ݹ����ƽ�������
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%d ",T->data);
    }
}

//�ǵݹ��㷨���������
void LeftShow(BiTree  T)
{
    BiTNode* rchildlist[STACK_INIT_SIZE];		//����һ�����ڴ����Һ��ӵ�ջ����Ϊ������ڵ㣬Ȼ��������ӡ�������Ҫ���Һ��Ӵ���������
    BiTNode* show=T;				//��showָ���ʼ��ΪT�ĵ�ַ�� show���ڱ���ʱ�������ڱ����Ľڵ㡣�Ӹ��ڵ㿪ʼ������
    int i=0;						//iΪrchildlistջ����
    while(1)
    {
        if(show==NULL) 				//���������Ľڵ���NULLʱ�����з�����ж�
        {
            if(i==0)						//���ջ��ʱҲΪ�ա����Ѿ����������������Ϳ����˳�ѭ����
                break;
            else 							//���ջ��ʱ��Ϊ�ա���ִ����ջ����������ջ��ֵ��ֵΪ��һ����Ҫ�����Ľڵ㡣��ʱ�������Ѿ������꣬��Ҫ�����Һ��ӡ�
            {
                show=rchildlist[i];						//����ջ��ֵ��ֵΪ��һ����Ҫ�����Ľڵ㡣
                i--;									//ִ����ջ����
            }
        }
        else  						//���������Ľڵ㲻ΪNULLʱ��
        {
            printf("%d ",show->data);		//����ýڵ㴢���ֵ
            if(show->rchild!=NULL) 			//�жϸýڵ���û���Һ��ӡ�������Һ�����ʹ�Һ��ӽ�ջ��
            {
                i++;									//ִ�н�ջ����
                rchildlist[i]=(BiTNode *)show->rchild;	//���Һ��ӽ�ջ��
            }
            show=(BiTNode *)show->lchild;	//���ýڵ�����Ӹ�ֵΪ��һ����Ҫ�����Ľڵ㡣
        }
    }
}

//�ǵݹ��㷨���������
void MiddleShow(BiTree  T)
{
    BiTNode* fatherlist[STACK_INIT_SIZE];		//����һ�����ڴ��游�ڵ��ջ����Ϊ��Ҫ��������ӡ�������Ҫ�����ڵ㴢��������ͬʱ����ͨ�����ڵ��ҵ��Һ��ӡ�
    BiTNode* show =T;			//��showָ���ʼ��ΪT�ĵ�ַ�� show���ڱ���ʱ�������ڱ����Ľڵ㡣�Ӹ��ڵ㿪ʼ������
    int i=0;						//iΪfatherlist��ջ����
    while (1)
    {
        if(show ==NULL) 			//���������Ľڵ���NULLʱ�����з�����ж���
        {
            if(i==0)						//�����ʱջҲΪ�ա����Ѿ����������������Ϳ����˳�ѭ����
                break;
            else 							//�����ʱջ��Ϊ�ա�������ջ����������ջ��ֵ��ֵΪ��ǰ�����Ľڵ㡣��ʱ�����Ѿ������꣬��Ҫ���һ��������ڵ��ֵ��
            {
                show=fatherlist[i];						//����ջ��ֵ��ֵΪ��ǰ�����Ľڵ㡣
                printf("%d ",show->data);				//����ýڵ��dataֵ��
                i--;									//ִ����ջ������
                if(show->rchild!=NULL) 		//�жϸýڵ��Ƿ�����Һ��ӡ�
                {
                    show=(BiTNode *)show->rchild;		//������Һ��ӡ����Һ��Ӹ�ֵΪ��һ����Ҫ�����Ľڵ㡣
                }
                else
                {
                    show=NULL;							//�����������ΪNULL����ʱ��Ŀ��Ϊ������ջ�����������һ�����ڵ��ֵ��
                }
            }
        }
        else  						//���������Ľڵ㲻ΪNULLʱ��
        {
            i++;							//ִ�н�ջ������
            fatherlist[i]=show;				//���ñ����ڵ��ջ��
            show=(BiTNode *)show->lchild;	//���ñ����ڵ�����Ӹ�ֵΪ��һ����Ҫ�����Ľڵ㡣
        }
    }
}

//�ǵݹ��㷨�ĺ�������
void RightShow(BiTree  T)
{
    BiTNode* fatherlist[STACK_INIT_SIZE];		//����һ�����ڴ��游�ڵ��ջ����Ϊ��Ҫ��������Һ��ӡ�������Ҫ�����ڵ㴢��������
    BiTNode* show=T;				//��showָ���ʼ��ΪT�ĵ�ַ�� show���ڱ���ʱ�������ڱ����Ľڵ㡣�Ӹ��ڵ㿪ʼ������
    int taglist[50];				//����һ���븸�ڵ�ͬ����ջ�������жϸø��ڵ��ǵڼ��α����ʡ���Ϊ���ڵ���Ҫ�˳����Ρ�ֻ�еڶ��β���Ҫ���ֵ����һ������Ѱ���Һ��ӡ�
    int i=0;						//iΪfatherlist��ջ����ͬʱҲ��taglist��ջ����
    int tag=0;						//tag�����жϸ��ڵ㱻���ʵĴ�������һ�α�ȡ��Ϊ0���ڶ��α�ȡ��Ϊ1��Ϊ1ʱ�������ֵ��
    while (1)
    {
        if(show==NULL) 				//���������Ľڵ���NULLʱ�����з�����ж���
        {
            if(i==0)						//�����ʱջҲΪ�ա����Ѿ����������������Ϳ����˳�ѭ����
                break;
            else 							//�����ʱջ��Ϊ�ա�������ջ����������ջ��ֵ��ֵΪ��ǰ�����Ľڵ㡣��ʱ�����Ѿ������꣬��Ҫ������жϡ�
            {
                show=fatherlist[i];						//����ջ��ֵ��ֵΪ��ǰ�����Ľڵ㡣
                if(taglist[i]==0) 						//�����ʱ�ø��ڵ��ǵ�һ�η�����Ϊ��tagֵ+1�������ýڵ���Һ��Ӹ�ֵΪ��һ����Ҫ�����Ľڵ㡣
                {
                    taglist[i]++;								//Ϊ��tagֵ+1��
                    show=(BiTNode *)show->rchild;				//���ýڵ���Һ��Ӹ�ֵΪ��һ����Ҫ�����Ľڵ㡣
                }
                else 									//�����ʱ�ø��ڵ��ǵڶ��η��ʡ�������ýڵ��Ӧ��dataֵ����ִ����ջ������
                {
                    printf("%d ",show->data);					//����ýڵ��Ӧ��dataֵ��
                    i--;										//ִ����ջ������
                    show=NULL;									//��������ΪNULL����ʱ��Ŀ��Ϊ������ջ�����������һ�����ڵ��ֵ��
                }
            }
        }
        else 						//���������Ľڵ㲻ΪNULLʱ��
        {
            i++;							//ִ�н�ջ����
            fatherlist[i]=show;				//���ñ������Ľڵ��ջ��
            taglist[i]=tag;					//ͬʱ���ýڵ��tagֵ��ջ����ʼΪ0.
            show=(BiTNode *)show->lchild;	//���ñ����ڵ�����Ӹ�ֵΪ��һ����Ҫ�����Ľڵ㡣
        }
    }
}

//��α�������
Queue InitQueue()
{
    //��ʼ������
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
    //�����п�
    if (cengci.len == 0)
    {
        return 1;
    }
    return 0;
}

int IsFullQueue(Queue cengci)
{
    //��������
    if (cengci.len == STACK_INIT_SIZE)
    {
        return 1;
    }
    return 0;
}

void PushQueue(Queue *cengci, BiTree T)
{
    //���
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
    //����
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
    //�������
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

//�ڶ������в��Ҹ����ؼ���
Status Find_keyword(BiTree T,int e)
{
    BiTree tem=T;
    while(tem)//���T�����������
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

//�������Ҷ�������
void Exchange(BiTree T)
{
    if(T->lchild==NULL&&T->rchild==NULL)
        ;
    else    //���������1.����Ϊ�գ�2.��Ϊ�գ�3.��Ϊ�գ�
    {
        //��������������
        BiTree tem=T->lchild;
        T->lchild=T->rchild;
        T->rchild=tem;
    }

    //������������������������Ϊ�գ����������Ѱ�ҿ��Խ����Ľ�㣻
    if(T->lchild)
        Exchange(T->lchild);
    if(T->rchild)
        Exchange(T->rchild);
}

//��ƽ������������
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

//ͳ�ƶ�������Ҷ�ӽ�����
int LeafNumber(BiTree T)
{
    int c=0;

    if(T==NULL) //����
    {
        return 0;
    }
    else if(T->lchild==NULL && T->rchild==NULL)  //ֻ��һ�����ڵ�
    {
        return c+1;
    }
    else
    {
        c=LeafNumber(T->lchild)+LeafNumber(T->rchild);//��ϵΪ����������
        return c;
    }
}
