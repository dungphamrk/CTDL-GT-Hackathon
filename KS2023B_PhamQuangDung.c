#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode()
{
    return NULL;
}
void pressEnterToContinue()
{
    printf("\nNhan Enter de tiep tuc");
    while (getchar() != '\n')
        ;
    getchar();
}

int lengthOfNodeList(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

Node *insertHead(Node *head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    printf("Them phan tu thanh cong");
    return newNode;
}

Node *insertTail(Node *head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Them phan tu thanh cong");
    return head;
}

Node *insertNodeByPos(Node *head, int value, int pos)
{
    if (lengthOfNodeList(head) < pos || pos < 0)
    {
        printf("Vi tri ko phu hop ");
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }

    Node *temp = head;
    int count = 0;
    while (temp->next != NULL)
    {
        if (count == pos - 1)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
        count++;
    }
    printf("Them phan tu thanh cong");
    return head;
}

Node *delHead(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;
    free(temp);
    printf("Xoa phan tu thanh cong");
    return head;
}

Node *delTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        free(head);
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Xoa phan tu thanh cong");

    return head;
}
Node *delByValue(Node *head, int value)
{
    if (head == NULL)
    {
        printf("Danh sach rong.\n");
        return NULL;
    }
    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("Da xoa phan tu co gia tri: %d\n", value);
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == value)
        {
            Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
            printf("Da xoa phan tu co gia tri: %d\n", value);
            return head;
        }
        temp = temp->next;
    }
    printf("Khong tim thay phan tu co gia tri: %d\n", value);
    return head;
}
void find(Node *head, int value)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Tim thay phan tu: %d\n", value);
            count = 1;
            break;
        }
        temp = temp->next;
    }
    if (!count)
    {
        printf("Khong tim thay phan tu: %d\n", value);
    }
}

void printNodeList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeNodeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *nodeList = createNode();
    int choice, value, position;

    do
    {
        printf("\n==============Menu=============\n");
        printf("1. Them vao dau danh sach\n");
        printf("2. Them vao cuoi danh sach\n");
        printf("3. Chen phan tu vao vi tri cu the\n");
        printf("4. Xoa phan tu dau\n");
        printf("5. Xoa phan tu cuoi\n");
        printf("6. Xoa phan tu theo gia tri\n");
        printf("7. Tim kiem phan tu theo gia tri\n");
        printf("8. Hien thi danh sach\n");
        printf("9. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Nhap gia tri can them vao dau: ");
            scanf("%d", &value);
            nodeList = insertHead(nodeList, value);
            pressEnterToContinue();
            system("cls");
            break;
        case 2:
            printf("Nhap gia tri can them vao cuoi: ");
            scanf("%d", &value);
            nodeList = insertTail(nodeList, value);
            pressEnterToContinue();
            system("cls");

            break;
        case 3:
            printf("Nhap gia tri can chen : ");
            scanf("%d", &value);
            printf("Nhap vi tri can chen vao danh sach : ");
            scanf("%d", &position);
            printf("%d", lengthOfNodeList(nodeList));
            nodeList = insertNodeByPos(nodeList, value, position);
            pressEnterToContinue();
            system("cls");

            break;
        case 4:
            nodeList = delHead(nodeList);
            printf("Da xoa phan tu dau danh sach.\n");
            pressEnterToContinue();
            system("cls");

            break;
        case 5:
            nodeList = delTail(nodeList);
            printf("Da xoa phan tu cuoi danh sach.\n");
            pressEnterToContinue();
            system("cls");

            break;
        case 6:
            printf("Nhap gia tri can xoa: ");
            scanf("%d", &value);
            nodeList = delByValue(nodeList, value);
            pressEnterToContinue();
            system("cls");
            break;
        case 7:
            printf("Nhap gia tri can tim: ");
            scanf("%d", &value);
            find(nodeList, value);
            pressEnterToContinue();
            system("cls");
            break;
        case 8:
            printf("Danh sach hien tai: ");
            printNodeList(nodeList);
            pressEnterToContinue();
            system("cls");
            break;
        case 9:
            printf("Thoat chuong trinh.\n");
            freeNodeList(nodeList);
            pressEnterToContinue();
            system("cls");
            break;
        default:
            printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 8);

    return 0;
}
